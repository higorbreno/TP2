#include <iostream>
#ifndef __COR_H__
#define __COR_H__

enum Cores { Azul, Verde, Vermelho, Preto, Branco };

std::istream& operator>>(std::istream& is, Cores& cor);

#endif