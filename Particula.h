#include "Vetor.h"
#include "Cor.h"
#include <iostream>
#ifndef __PARTICULA_H__
#define __PARTICULA_H__

struct Particula {
	char nome[20];
	Posicao posicao;
	char tipo;
	VetorDeslocamento vetor;
	Cores cor;
};

std::istream& operator>>(std::istream& is, Particula& particula);

#endif