#include "Cor.h" // Inclus�o do cabe�alho com os prot�tipos e registros declarados

// Fun��o operator que sobrecarrega o operador >> para ler vari�veis do tipo Cores
std::istream& operator>>(std::istream& is, Cores& cor) {
	int temp;
	is >> temp;
	cor = Cores(temp);
	return is;
}