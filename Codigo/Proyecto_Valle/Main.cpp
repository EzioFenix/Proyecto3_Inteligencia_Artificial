#include<iostream>
#include<fstream>
#include<string>

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
				data[index] = line.substr(begin, i);
				begin = i + 1;
				index++;
			}
		}
		std::cout << std::endl;
		begin = 0;
	}
	std::cout << "Se han leido los datos correctamente...\n";
	return data;
}

int main() {
	getDataBase("PruebaSencilla.txt");
	return 0;
}