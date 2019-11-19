#include <cmath>
#include <iostream>

struct CPolares {
	float magnitude;
	float angulo;
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