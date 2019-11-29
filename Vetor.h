// Inclus�o das bibliotecas
#include <cmath>
#include <iostream>

// M�todo para proteger a biblioteca de m�ltiplas inclus�es
#ifndef __VETOR_H__
#define __VETOR_H__

// Registro das coordenadas polares
struct CPolares {
	float angulo;
	float magnitude;
};

// Registro das coordenadas cartesianas
struct CCartesianas {
	float x;
	float y;
};

// Uni�o do vetor deslocamento
union VetorDeslocamento {
	CPolares polar;
	CCartesianas cartesiano;
};

// Registro da posi��o
struct Posicao {
	float x;
	float y;
};

// Prot�tipos das fun��es
Posicao Deslocar(Posicao, VetorDeslocamento, char);

Posicao DeslocarCartesiano(Posicao, VetorDeslocamento);

Posicao DeslocarPolar(Posicao, VetorDeslocamento);

std::istream& operator>>(std::istream&, CCartesianas&);

std::istream& operator>>(std::istream&, CPolares&);

VetorDeslocamento InverterVetorC(VetorDeslocamento, char);

VetorDeslocamento InverterVetorP(VetorDeslocamento, char);

#endif