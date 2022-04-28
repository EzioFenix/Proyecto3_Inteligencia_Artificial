#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<chrono>
//Variables globales para las dimensiones de la matriz
//La Variable REAL_HEIGHT estará reservada para respaldo
int WIDTH = 0, HEIGHT = 0, REAL_HEIGHT = 0;
//Métodos genéricos para transformar cadenas de caracteres en números enteros
int X10(const int n) {
	int d = 1;
	for (int i = 0; i < n; i++) d *= 10;
	return d;
}
int toInt(const std::string data){
	int r = 0;
	for (int i = 0; i < data.length(); i++)
		r += X10(data.length() - i -1) * (data[i] - 48);
	return r;
}
void set80p() {
	HEIGHT = (int)((REAL_HEIGHT - 1) * 0.8f) + 1;
}
void set100p() {
	HEIGHT = REAL_HEIGHT;
}
//Carga en memoria de la base de datos de cualquier archivo que tenga el formato correcto
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
	//Se extrae espeficamente la primera linea donde se almacena las dimensiones del arreglo
	for (int i = 0; i < line.length(); i++) if (line[i] == ',') begin = i;
	WIDTH = toInt(line.substr(0, begin));
	REAL_HEIGHT = toInt(line.substr(begin + 1, line.length()));
	HEIGHT = REAL_HEIGHT;
	//Este se tratará como un arreglo unidimensional
	std::string* data = new std::string[WIDTH*HEIGHT];
	std::getline(archive, line);
	begin = 0;
	while (index < WIDTH*HEIGHT) {
		for (int i = 0; i <= line.length(); i++) {
			if (line[i] == ',' || line[i] == '\0') { //Cada que detecte una , o el fin de linea, de hará corte de la subsentiencia
				data[index] = line.substr(begin, i - begin);//Almacenando en el correspondiente
				begin = i + 1;
				index++;
			}
		}
		//std::cout << std::endl;
		std::getline(archive, line);
		begin = 0;
	}
	std::cout << "Se han leido los datos correctamente...\n";
	return data;
}
void printData(std::string* matrix) {
	//Este loop se usa como ejemplo para analizar la información como una tabla en dos dimensiones
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			std::cout << "|\t" << matrix[(i * WIDTH) + j] << "\t";
		std::cout << "|\n";
	}
}
//Este método está hecho para contar las veces que se repite un objetivo en mencionada categoría
int timesByCategory(std::string* matrix,const std::string category,const std::string name) {
	int j = 0, count = 0; bool notFound = true;
	//En el primer bucle se dedica a encontrar la columna
	while (notFound)
		if (!matrix[j].compare(category))
			notFound = false;
		else if (j > WIDTH)
			return count;
		else
			j++;
	//Cuenta las veces que aparece en dicha columna
	for (int i = 1; i < HEIGHT; i++)
		if (!matrix[i * WIDTH + j].compare(name))
			count++;
	return count;
}
//Rutina complementaria para verificar la existencia de un elemento en la lista
bool isOnList(const std::list<std::string> lista, const std::string obj){
	for (std::string node : lista)
		if (!node.compare(obj))
			return true;
	return false;
}
//Retorna una colección de los elementos en formato Lista
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
		if (!isOnList(lista, matrix[i * WIDTH + j])) //Si no está en la lista
			lista.push_back(matrix[i * WIDTH + j]);  //Añade el elemento
		
	return lista;
}
//Metodo "Dado que" es una doble validación donde elementos de un par de columnas coincidan simultaneamente en sus objetivos
int dueTo(std::string* matrix, const std::string ctg1, const std::string nm1, const std::string ctg2, const std::string nm2) {
	int j = 0, y = 0, coincidence = 0; bool nF1 = true, nF2 = true;
	while (nF1 || nF2) {//Se localizan ambas columnas
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

//Calcular la probabilidad
float getProbability(std::string* matrix, const std::string category, const std::string name){
	//Se multiplica las veces que aparece el objetivo dividido entre el total de elementos
	return (float)(timesByCategory(matrix, category, name)) / (float)(HEIGHT - 1);
}
float getProbability(std::string* matrix, const std::string ctg1, const std::string nm1, const std::string ctg2, const std::string nm2) {
	//Se busca las coincidencias y se dividen entre las veces que aparece el primer argumento
	return (float)(dueTo(matrix,ctg1,nm1,ctg2,nm2))/(float)(timesByCategory(matrix, ctg1, nm1));
}

std::string masProbable(std::string* matrix,const std::string conditions, const std::string question) {
	int begin = 0, cat = 0; float fact = 1.0f, most = 0.0f; std::string answer = "No hay coincidencia"; bool alCat = true;
	//Se obtiene la lista de la columna en cuestion
	for (std::string possible : getListTypes(matrix, question)) {
		fact = getProbability(matrix, question, possible); alCat = true; cat = 0; begin = 0;
		std::cout << "Para " << possible << ": (" << timesByCategory(matrix, question, possible)<<"/"<<(HEIGHT-1)<<")";
		for (int i = 0; i <= conditions.length(); i++) //Por cada condición presente
			switch (conditions[i]) {
			case  ',': //Caracteres que indican el fin de una condicion
			case '\0':
				std::cout << "*("<< dueTo(matrix, conditions.substr(begin, cat - begin), conditions.substr(cat + 1, i - (cat + 1)), question, possible);
				std::cout << "/" << timesByCategory(matrix, conditions.substr(begin, cat - begin), conditions.substr(cat + 1, i - (cat + 1))) << ")";
				fact *= getProbability(matrix, conditions.substr(begin,cat - begin), conditions.substr(cat + 1, i - (cat + 1)), question, possible); //Se acumula la probabilidad
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
		if (fact > most) { //En caso de obtener una probabilidad mayor, se to´mará para ser devuelta
			possible.append("\tProbabilidad: ");
			possible.append(std::to_string(fact));
			answer = possible;
			most = fact;
		}
		std::cout << " = " << fact << std::endl;
	}
	return answer;
}
//Esencialmente es el mismo algoritmo, pero diseñado para pruebas de presición
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

int main() {
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
			//std::cin >> id; 
			data = getDataBase("PruebaSencilla.txt");
			std::cout << std::endl;
			break;
		case '2':
			std::cout << "Preguntar...\nInserte condiciones con el formato [Clasificacion]:[Objetivo],*\n";
			std::cin >> id; std::cout << "Inserte la cuestion "; std::cin >> aux;
			printData(data);
			std::cout << "Resultado posible: " << masProbable(data,id,aux);
			std::cin >> aux;
			break;
		case '3':
			std::cout << "La presicion es del...\t" << testPresicion(data) << "%\n";
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