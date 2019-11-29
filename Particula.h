// Inclus�o das bibliotecas
#include "Vetor.h"
#include "Cor.h"
#include <iostream>

// M�todo para proteger a biblioteca de m�ltiplas inclus�es
#ifndef __PARTICULA_H__
#define __PARTICULA_H__

// Registro da part�cula
struct Particula {
	char nome[20];
	Posicao posicao;
	char tipo;
	VetorDeslocamento vetor;
	Cores cor;
};

// Prot�tipo da fun��o
std::istream& operator>>(std::istream& is, Particula& particula);

#endif