#include<iostream>
#include<fstream>
#include<string>
#include<list>

int WIDTH = 0, HEIGHT = 0;

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
	HEIGHT = toInt(line.substr(begin + 1, line.length()));
	std::string* data = new std::string[WIDTH*HEIGHT];
	std::getline(archive, line);
	begin = 0;
	while (index < WIDTH*HEIGHT) {
		for (int i = 0; i <= line.length(); i++) {
			if (line[i] == ',' || line[i] == '\0') {
				data[index] = line.substr(begin, i - begin);
				//std::cout << line.substr(begin, i - begin) << "\t(" << begin << ":" << i << ")\t";
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
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++)
			std::cout << "|\t" << matrix[(i * WIDTH) + j] << "\t";
		std::cout << "|\n";
	}
}
int timesByCategory(std::string* matrix, std::string category, std::string name) {
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
bool isOnList(std::list<std::string> lista, std::string obj){
	for (std::string node : lista)
		if (!node.compare(obj))
			return true;
	return false;
}
std::list<std::string> getListTypes(std::string* matrix, std::string category) {
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
int dueTo(std::string* matrix, std::string ctg1, std::string nm1, std::string ctg2, std::string nm2) {
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
		if (!(matrix[i * WIDTH + j].compare(nm1) || matrix[i*WIDTH + y].compare(nm2)))
			coincidence++;
	return coincidence;
}

float getProbability(std::string* matrix, std::string category, std::string name){
	return (float)(timesByCategory(matrix,category,name)) / (float)(HEIGHT - 1);
}
float getProbability(std::string* matrix, std::string ctg1, std::string nm1, std::string ctg2, std::string nm2) {
	return (float)(dueTo(matrix,ctg1,nm1,ctg2,nm2))/(float)(timesByCategory(matrix, ctg1, nm1));
}

std::string masProbable(std::string* matrix,std::string conditions, std::string question) {
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

int main() {
	char opcion; std::string* data = nullptr; std::string id, aux;
	std::cout << "Valles Sense by DynamicWare V1.10.15" << std::endl;
	do {
		std::cout << "Seleccione una opcion:\n"
			<< "1.- Cargar Hoja de Datos\n"
			<< "2.- Preguntar\n"
			<< "3.- Salir\n";
		std::cin >> opcion;

		switch (opcion) {
		case '1':
			std::cout << "Cargar Hoja de Datos...\n";
			std::cout << "Inserte el nombre del archivo: ";
			std::cin >> id; data = getDataBase(id);
			break;
		case '2':
			std::cout << "Preguntar...\nInserte condiciones con el formato [Clasificacion]:[Objetivo],*\n";
			std::cin >> id; std::cout << "Inserte la cuestion "; std::cin >> aux;
			printData(data);
			std::cout << "Resultado posible: " << masProbable(data,id,aux);
			std::cin >> aux;
			break;
		case '3':
			std::cout << "Saliendo del programa..\n";
			break;
		default:
			std::cout << "No se reconoce la opcion: " << opcion << std::endl;
		}
	} while (opcion != '3');
	return 0;
}