#include<iostream>
using std::string;
const std::string& getName(std::string name) {
	static string tired = name;
	return tired;
};

int cubic(int x, int y=1, int z=1) {
	return x * y * z;
};
int main() {
	std::string sunny = "angry";
	std::cout<<getName(sunny)<<std::endl;
	std::cout << cubic(1, 2);


}

