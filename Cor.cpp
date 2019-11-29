#include "Cor.h" // Inclusão do cabeçalho com os protótipos e registros declarados

// Função operator que sobrecarrega o operador >> para ler variáveis do tipo Cores
std::istream& operator>>(std::istream& is, Cores& cor) {
	int temp;
	is >> temp;
	cor = Cores(temp);
	return is;
}