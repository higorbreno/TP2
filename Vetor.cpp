#include "Vetor.h"

const float pi = 3.14159f;

Posicao DeslocarCartesiano(Posicao p, VetorDeslocamento v) {
	p.x += v.cartesiano.x;
	p.y -= v.cartesiano.y;
	return p;
}

Posicao DeslocarPolar(Posicao p, VetorDeslocamento v) {
	p.x += (v.polar.magnitude * cos(v.polar.angulo * pi / 180));
	p.y -= (v.polar.magnitude * sin(v.polar.angulo * pi / 180));
	return p;
}

Posicao Deslocar(Posicao p, VetorDeslocamento v, char t) {
	Posicao temp = { 0 };
	if (t == 'P') {
		temp = DeslocarPolar(p, v);
	}
	else if (t == 'C') {
		temp = DeslocarCartesiano(p, v);
	}
	return temp;
}

VetorDeslocamento InverterVetorC(VetorDeslocamento v, char c) {
	if (c == 'x') {
		v.cartesiano.x *= -1;
	}
	else if (c == 'y') {
		v.cartesiano.y *= -1;
	}
	return v;
}

VetorDeslocamento InverterVetorP(VetorDeslocamento v, char c) {
	float dx = v.polar.magnitude * cos(v.polar.angulo * pi / 180);
	float dy = v.polar.magnitude * sin(v.polar.angulo * pi / 180);
	if (c == 'x') {
		v.polar.angulo = atan2(dy, -dx) * 180 / pi;
	}
	else if (c == 'y') {
		v.polar.angulo = atan2(-dy, dx) * 180 / pi;
	}

	return v;
}

std::istream& operator>>(std::istream& is, CCartesianas& cc) {
	is >> cc.x >> cc.y;
	return is;
}

std::istream& operator>>(std::istream& is, CPolares& cp) {
	is >> cp.angulo >> cp.magnitude;
	return is;
}