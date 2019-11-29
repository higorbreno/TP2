// Inclus�o das bibliotecas
#include <iostream>

// M�todo para proteger a biblioteca de m�ltiplas inclus�es
#ifndef __COR_H__
#define __COR_H__

// Enumera��o que guarda as cores
enum Cores { Azul, Verde, Vermelho, Preto, Branco };

// Prot�tipo da fun��o
std::istream& operator>>(std::istream& is, Cores& cor);

#endif