// Inclusão das bibliotecas
#include <iostream>

// Método para proteger a biblioteca de múltiplas inclusões
#ifndef __COR_H__
#define __COR_H__

// Enumeração que guarda as cores
enum Cores { Azul, Verde, Vermelho, Preto, Branco };

// Protótipo da função
std::istream& operator>>(std::istream& is, Cores& cor);

#endif