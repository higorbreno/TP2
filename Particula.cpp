#include "Particula.h"

std::istream& operator>>(std::istream& is, Particula& particula) {
	for (int i = 0;i < 20; i++) {
		is >> particula.nome[i];
		if (particula.nome[i] == ':') {
			particula.nome[i] = '\0';
			break;
		}
	}
	is >> particula.posicao.x;
	is >> particula.posicao.y;
	is >> particula.tipo;
	if (particula.tipo == 'P') {
		is >> particula.vetor.polar;
	}
	else {
		is >> particula.vetor.cartesiano;
	}
	is >> particula.cor;
	return is;
}