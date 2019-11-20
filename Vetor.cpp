#include "Vetor.h"

const float pi = 3.14159f;

Posicao DeslocarCartesiano(Posicao p, VetorDeslocamento v) {
	p.x += v.cartesiano.x;
	p.y += v.cartesiano.y;
	return p;
}

Posicao DeslocarPolar(Posicao p, VetorDeslocamento v) {
	p.x += (v.polar.magnitude * cos(v.polar.angulo * pi / 180));
	p.y -= (v.polar.magnitude * sin(v.polar.angulo * pi / 180));
	return p;
}

Posicao Deslocar(Posicao p, VetorDeslocamento v, char t) {
	Posicao temp;
	if (t == 'P') {
		temp = DeslocarPolar(p, v);
	}
	else {
		temp = DeslocarCartesiano(p, v);
	}
	return temp;
}

std::istream& operator>>(std::istream& is, CCartesianas& cc) {
	is >> cc.x >> cc.y;
	return is;
}

std::istream& operator>>(std::istream& is, CPolares& cp) {
	is >> cp.angulo >> cp.magnitude;
	return is;
}