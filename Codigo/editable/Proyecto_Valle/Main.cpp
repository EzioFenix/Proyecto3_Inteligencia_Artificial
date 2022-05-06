#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<chrono>
/**
* Funcion principal para el algoritmo de estimacion, importante tener una base de datos con el siguiente formato
* En la primera linea siempre debe tener las dimensiones de la matriz en [Ancho],[Alto]
* Los argumentos, incluidas las cabeceras deben coincidir con las dimensiones especificadas
* @author JoGEHrt
*/
int WIDTH = 0, HEIGHT = 0, REAL_HEIGHT = 0;
/**
* Potencia de 10
* @param n Grado de la potencia
* @return 10^n
*/
int X10(const int n) {
	int d = 1;
	for (int i = 0; i < n; i++) d *= 10;
	return d;
}
/**
* Conversor de Cadenas tipo String a enteros
* @param data Argumento a convertir
* @return numero entero
*/
int toInt(const std::string data){
	int r = 0;
	for (int i = 0; i < data.length(); i++)
		r += X10(data.length() - i -1) * (data[i] - 48);
	return r;
}
/**
* Es un ajuste temporal para las evaluaciones de presicion
*/
void set80p() {
	HEIGHT = (int)((REAL_HEIGHT - 1) * 0.8f) + 1;
}
/**
* Restaura las dimensiones reales
*/
void set100p() {
	HEIGHT = REAL_HEIGHT;
}
/**
* Carga los datos del archivo, debe espeficicarse su dirección relativa o absoluta, incluido la extension
* @param id Dirección del archivo
* @return Arreglo unidimensional de Cadenas
*/
std::string* getDataBase(const std::string id) {
	std::ifstream archive;
	archive.open(id, std::ios::in);
	if (archive.fail()) {
		std::cout << "No se pudo abrir el archivo: " << id << std::endl;
		return nullptr;
	}
	std::string line;
	int begin = 0, index = 0;
	std::getline(archive, line);
	for (int i = 0; i < line.length(); i++) if (line[i] == ',') begin = i;
	WIDTH = toInt(line.substr(0, begin));
	REAL_HEIGHT = toInt(line.substr(begin + 1, line.length()));
	HEIGHT = REAL_HEIGHT;
	std::string* data = new std::string[WIDTH*HEIGHT];
	std::getline(archive, line);
	begin = 0;
	while (index < WIDTH*HEIGHT) {
		for (int i = 0; i <= line.length(); i++) {
			if (line[i] == ',' || line[i] == '\0') {
				data[index] = line.substr(begin, i - begin);
				begin = i + 1;
				index++;
			}
		}
		std::getline(archive, line);
		begin = 0;
	}
	std::cout << "Se han leido los datos correctamente...\n";
	return data;
}
/**
* Imprime todos los datos
* @param matrix Base de datos
*/
void printData(std::string* matrix) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			std::cout << "|\t" << matrix[(i * WIDTH) + j] << "\t";
		std::cout << "|\n";
	}
}
/**
* Imprime la primera fila considerada como cabecera
* @param matrix Base de datos
*/
void printHeader(std::string* matrix) {
	for (int i = 0; i < WIDTH; i++)
		std::cout << "|\t" << matrix[i] << "\t";
	std::cout << "|\n";
}
/**
* Veces que existe el objetivo en dicha categoría
* @param matrix Base de datos
* @param category Nombre en la cabecera
* @return Numero de coincidencias
*/
int timesByCategory(std::string* matrix,const std::string category,const std::string name) {
	int j = 0, count = 0; bool notFound = true;
	while (notFound)
		if (!matrix[j].compare(category))
			notFound = false;
		else if (j > WIDTH)
			return count;
		else
			j++;
	for (int i = 1; i < HEIGHT; i++)
		if (!matrix[i * WIDTH + j].compare(name))
			count++;
	return count;
}
/**
* Metodo complementario para indicar si se encuentra un elemento en la lista
* @param lista coleccion de elementos
* @param obj elemento en cuestion
* @return True si se encuentra el elemento
*/
bool isOnList(const std::list<std::string> lista, const std::string obj){
	for (std::string node : lista)
		if (!node.compare(obj))
			return true;
	return false;
}
/**
* Metodo complementario para indicar si se encuentra un elemento en la lista
* @param matrix Base de datos
* @param category nombre de la categoria
* @return Coleccion de elementos por categoria
*/
std::list<std::string> getListTypes(std::string* matrix, const std::string category) {
	std::list<std::string> lista;
	int j = 0; bool notFound = true;
	while (notFound)
		if (!matrix[j].compare(category))
			notFound = false;
		else if (j > WIDTH)
			return lista;
		else
			j++;
	for (int i = 1; i < HEIGHT; i++)
		if (!isOnList(lista, matrix[i * WIDTH + j]))
			lista.push_back(matrix[i * WIDTH + j]);
	return lista;
}
/**
* Metodo para encontrar coincidencias en el formato  A dado que B
* @param matrix Base de Datos
* @param ctg1 nombre de la categoria del primer elemento
* @param nm1 nombre del primer objetivo
* @param ctg2 nombre de la categoria del segundo elemento
* @param nm2 nombre del segundo objetivo
* @return Numero de coincidencias
*/
int dueTo(std::string* matrix, const std::string ctg1, const std::string nm1, const std::string ctg2, const std::string nm2) {
	int j = 0, y = 0, coincidence = 0; bool nF1 = true, nF2 = true;
	while (nF1 || nF2) {
		if (!matrix[j].compare(ctg1)) nF1 = false;
		else if (nF1) j++;
		if (!matrix[y].compare(ctg2)) nF2 = false;
		else if (nF2) y++;
		if (j > WIDTH && y > WIDTH)
			return coincidence;
	}
	for (int i = 1; i < HEIGHT; i++)
		if (!(matrix[i * WIDTH + j].compare(nm1) || matrix[i*WIDTH + y].compare(nm2)))//Incrementa si hay coincidencias
			coincidence++;
	return coincidence;
}
/**
* Obtención de la probabilidad de un evento contra todo el conjunto
* @param matrix Base de Datos
* @param category nombre de la categoria
* @param name objetivo
* @return Probabilidad entre 0 y 1
*/
float getProbability(std::string* matrix, const std::string category, const std::string name){
	return (float)(timesByCategory(matrix, category, name)) / (float)(HEIGHT - 1);
}
/**
* Obtención de la probabilidad de un evento ocurra simultaneo a otro
* @param matrix Base de Datos
* @param ctg1 nombre de la categoria del primer elemento
* @param nm1 nombre del primer objetivo
* @param ctg2 nombre de la categoria del segundo elemento
* @param nm2 nombre del segundo objetivo
* @return Probabilidad entre 0 y 1
*/
float getProbability(std::string* matrix, const std::string ctg1, const std::string nm1, const std::string ctg2, const std::string nm2) {
	return (float)(dueTo(matrix,ctg1,nm1,ctg2,nm2))/(float)(timesByCategory(matrix, ctg1, nm1));
}
/**
* Metodo principal para obtener el principio de multiplicacion de probabilidad
* @param matrix Base de Datos
* @param conditions factores a considerar Categoria:Objetivo
* @param question Categoria de la que se desea averiguar
* @return Argumento mas probable
*/
std::string masProbable(std::string* matrix,const std::string conditions, const std::string question) {
	int begin = 0, cat = 0; float fact = 1.0f, most = 0.0f; std::string answer = "No hay coincidencia"; bool alCat = true;
	for (std::string possible : getListTypes(matrix, question)) {
		fact = getProbability(matrix, question, possible); alCat = true; cat = 0; begin = 0;
		std::cout << "Para " << possible << ": (" << timesByCategory(matrix, question, possible)<<"/"<<(HEIGHT-1)<<")";
		for (int i = 0; i <= conditions.length(); i++)
			switch (conditions[i]) {
			case  ',':
			case '\0':
				std::cout << "*("<< dueTo(matrix, conditions.substr(begin, cat - begin), conditions.substr(cat + 1, i - (cat + 1)), question, possible);
				std::cout << "/" << timesByCategory(matrix, conditions.substr(begin, cat - begin), conditions.substr(cat + 1, i - (cat + 1))) << ")";
				fact *= getProbability(matrix, conditions.substr(begin,cat - begin), conditions.substr(cat + 1, i - (cat + 1)), question, possible);
				begin = i + 1;
				cat = i + 1;
				alCat = true;
				break;
			case  ':':
				alCat = false;
				break;
			default:
				if (alCat)cat++;
			}
		if (fact > most) {
			possible.append("\tProbabilidad: ");
			possible.append(std::to_string(fact));
			answer = possible;
			most = fact;
		}
		std::cout << " = " << fact << std::endl;
	}
	return answer;
}
/**
* Version del metodo que no imprime los resultados 
* @param matrix Base de Datos
* @param conditions factores a considerar Categoria:Objetivo
* @param question Categoria de la que se desea averiguar
* @return Argumento mas probable
*/
std::string presicionP(std::string* matrix, const std::string conditions, const std::string question) {
	int begin = 0, cat = 0; float fact = 1.0f, most = 0.0f; std::string answer = "No hay coincidencia"; bool alCat = true;
	for (std::string possible : getListTypes(matrix, question)) {
		fact = getProbability(matrix, question, possible); alCat = true; cat = 0; begin = 0;
		for (int i = 0; i <= conditions.length(); i++)
			switch (conditions[i]) {
			case  ',':
			case '\0':
				fact *= getProbability(matrix, conditions.substr(begin, cat - begin), conditions.substr(cat + 1, i - (cat + 1)), question, possible); //Se acumula la probabilidad
				begin = i + 1;
				cat = i + 1;
				alCat = true;
				break;
			case  ':':
				alCat = false;
				break;
			default:
				if (alCat)cat++;
			}
		if (fact > most) {
			answer = possible;
			most = fact;
		}
	}
	return answer;
}
/**
* Extrae las condiciones en el formato indicado
* @param matrix Base de Datos
* @param exception es el indice a la categoria a ignorar
* @param fila es el nivel que recoje los objetivos
* @return Condiciones en el formato Categoria:Objetivo,*
*/
std::string getConditions(std::string* matrix,const int exception, const int fila){
	std::string args = "";
	for(int i = 0; i < WIDTH ; i++)
		if (i != exception) {
			args.append(matrix[i]);
			args.append(":");
			args.append(matrix[WIDTH*fila + i]);
			args.append(",");
		}
	args.resize(args.length() - 1);
	return args;
}
/**
* Metodo automatico para evaluar la presicion de la base de datos
* @param matrix Base de Datos
* @return Porcentaje de precision
*/
float testPresicion(std::string* matrix) {
	set80p(); 
	const int nTest = (REAL_HEIGHT - HEIGHT) * (WIDTH);
	int hits = 0;
	for (int i = 0; i < (REAL_HEIGHT - HEIGHT); i++)
		for (int j = 0; j < WIDTH; j++) {
			if (!matrix[WIDTH *(HEIGHT + i) + j].compare(presicionP(matrix, getConditions(matrix, j, i + HEIGHT), matrix[j])))
				hits++;
			std::cout << "Especulacion: " << presicionP(matrix, getConditions(matrix, j, i + HEIGHT), matrix[j]) <<"\t| Realidad: " << matrix[WIDTH * (HEIGHT + i) + j] << std::endl;
		}
	set100p();
	return ((float)hits / (float)nTest) * 100.0f;
}
/**
* Implementacion con un menu de consola
* @return Estado del programa
*/
int main() {
	std::chrono::system_clock::time_point before, after;
	std::chrono::duration<float, std::milli> time;
	char opcion; std::string* data = nullptr; std::string id, aux;
	std::cout << "Valles Sense by DynamicWare V1.10.15" << std::endl;
	do {
		std::cout << "Seleccione una opcion:\n"
			<< "1.- Cargar Hoja de Datos\n"
			<< "2.- Preguntar\n"
			<< "3.- Test de presicion\n"
			<< "4.- Salir\n";
		std::cin >> opcion;

		switch (opcion) {
		case '1':
			std::cout << "Cargar Hoja de Datos...\n";
			std::cout << "Inserte el nombre del archivo: ";
			std::cin >> id; data = getDataBase(id);
			std::cout << std::endl;
			break;
		case '2':
			std::cout << "Preguntar...\nInserte condiciones con el formato [Clasificacion]:[Objetivo],*\n";
			printHeader(data);
			std::cin >> id; std::cout << "Inserte la cuestion "; std::cin >> aux;
			printData(data);
			before = std::chrono::system_clock::now();
			std::cout << "Resultado posible: " << masProbable(data,id,aux);
			after = std::chrono::system_clock::now();
			time = after - before;
			std::cout << "\nRealizado en: " << time.count() << " milisegundos";
			std::cin >> aux;
			break;
		case '3':
			before = std::chrono::system_clock::now();
			std::cout << "La presicion es del...\t" << testPresicion(data) << "%\n";
			after = std::chrono::system_clock::now();
			time = after - before;
			std::cout << "Realizado en: " << time.count() << " milisegundos";
			std::cin >> aux;
			break;
		case '4':
			std::cout << "Saliendo del programa..\n";
			break;
		default:
			std::cout << "No se reconoce la opcion: " << opcion << std::endl;
		}
	} while (opcion != '4');
	return 0;
}