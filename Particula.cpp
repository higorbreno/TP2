#include "Particula.h" // Inclus�o do cabe�alho com os prot�tipos e registros declarados

// Fun��o operator que sobrecarrega o operador >> para ler vari�veis do tipo Particula
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
	is.ignore();
	return is;
}