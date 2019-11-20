#include "Cor.h"

std::istream& operator>>(std::istream& is, Cores& cor) {
	int temp;
	is >> temp;
	cor = Cores(temp);
	return is;
}