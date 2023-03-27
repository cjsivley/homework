#include <iostream>

void errPrint(const char* payload) {
	std::cerr << "\x1b[31m" << payload << "\x1b[0m";
	return;
}