#include "Vetor.h" // Inclus�o do cabe�alho com os prot�tipos e registros declarados

const float pi = 3.14159f; // Constante de pi aproximada a 6 d�gitos significativos

// Fun��o para deslocar a part�cula de vetor cartesiano
Posicao DeslocarCartesiano(Posicao p, VetorDeslocamento v) {
	p.x += v.cartesiano.x;
	p.y -= v.cartesiano.y;
	return p;
}

// Fun��o para deslocar a part�cula de vetor polar
Posicao DeslocarPolar(Posicao p, VetorDeslocamento v) {
	p.x += (v.polar.magnitude * cos(v.polar.angulo * pi / 180));
	p.y -= (v.polar.magnitude * sin(v.polar.angulo * pi / 180));
	return p;
}

// Fun��o para deslocar a part�cula
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

// Fun��o que inverte o vetor cartesiano para causar o rebatimento no eixo x ou y
VetorDeslocamento InverterVetorC(VetorDeslocamento v, char c) {
	if (c == 'x') {
		v.cartesiano.x *= -1;
	}
	else if (c == 'y') {
		v.cartesiano.y *= -1;
	}
	return v;
}

// Fun��o que muda o angulo do vetor polar para causar o rebatimento no eixo x ou y
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

// Fun��o operator que sobrecarrega o operador >> para ler vari�veis do tipo CCartesianas
std::istream& operator>>(std::istream& is, CCartesianas& cc) {
	is >> cc.x >> cc.y;
	return is;
}

// Fun��o operator que sobrecarrega o operador >> para ler vari�veis do tipo CPolares
std::istream& operator>>(std::istream& is, CPolares& cp) {
	is >> cp.angulo >> cp.magnitude;
	return is;
}