#include<iostream>
#include<string>

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
std::string** getDataBase(const std::string name) {


}

int main() {
	std::cout << "Hola Mundo\n" << toInt("23") << std::endl;
	return 0;
}