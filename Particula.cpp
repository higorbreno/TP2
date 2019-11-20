#include "Particula.h"

std::istream& operator>>(std::istream& is, Particula& particula) {
	is.getline(particula.nome, 20, ':');
	is >> particula.posicao.x;
	is >> particula.posicao.y;
	is >> particula.tipo;
	if (particula.tipo == 'P') {
		is >> particula.vetor.polar;
	}
	else if (particula.tipo == 'C') {
		is >> particula.vetor.cartesiano;
	}
	is >> particula.cor;
	return is;
}