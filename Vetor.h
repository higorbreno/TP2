#include <cmath>
#include <iostream>
#ifndef __VETOR_H__
#define __VETOR_H__

struct CPolares {
	float angulo;
	float magnitude;
};

struct CCartesianas {
	float x;
	float y;
};

union VetorDeslocamento {
	CPolares polar;
	CCartesianas cartesiano;
};

struct Posicao {
	float x;
	float y;
};

Posicao Deslocar(Posicao, VetorDeslocamento, char);

Posicao DeslocarCartesiano(Posicao, VetorDeslocamento);

Posicao DeslocarPolar(Posicao, VetorDeslocamento);

std::istream& operator>>(std::istream&, CCartesianas&);

std::istream& operator>>(std::istream&, CPolares&);

#endif