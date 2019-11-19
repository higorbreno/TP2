

struct Particula {
	char nome[20];
	Posicao posicao;
	char tipo;
	VetorDeslocamento vetor;
	Cores cor;
};

std::istream& operator>>(std::istream& is, Particula& particula);