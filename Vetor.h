// Inclusão das bibliotecas
#include <cmath>
#include <iostream>

// Método para proteger a biblioteca de múltiplas inclusões
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

// União do vetor deslocamento
union VetorDeslocamento {
	CPolares polar;
	CCartesianas cartesiano;
};

// Registro da posição
struct Posicao {
	float x;
	float y;
};

// Protótipos das funções
Posicao Deslocar(Posicao, VetorDeslocamento, char);

Posicao DeslocarCartesiano(Posicao, VetorDeslocamento);

Posicao DeslocarPolar(Posicao, VetorDeslocamento);

std::istream& operator>>(std::istream&, CCartesianas&);

std::istream& operator>>(std::istream&, CPolares&);

VetorDeslocamento InverterVetorC(VetorDeslocamento, char);

VetorDeslocamento InverterVetorP(VetorDeslocamento, char);

#endif