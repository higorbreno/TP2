// Inclusão das bibliotecas
#include "Vetor.h"
#include "Cor.h"
#include <iostream>

// Método para proteger a biblioteca de múltiplas inclusões
#ifndef __PARTICULA_H__
#define __PARTICULA_H__

// Registro da partícula
struct Particula {
	char nome[20];
	Posicao posicao;
	char tipo;
	VetorDeslocamento vetor;
	Cores cor;
};

// Protótipo da função
std::istream& operator>>(std::istream& is, Particula& particula);

#endif