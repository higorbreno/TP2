#pragma warning(disable : 4996)
#include <iostream>
#include <random>
#include "Vetor.h"
#include "Cor.h"
#include "Particula.h"
using namespace std;

int main() {
	system("chcp 1252 > null");
	Particula particulas[10];

	for (int i = 0; i < 10; i++) {
		cin >> particulas[i];
	}

	cout << "\nSimulação\n";
	cout << "---------\n";
	
	int colisoes[100] = { 0 };
	int indice = 0;

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 10);

	int colisaoCor[5] = { 0 };

	int i = 1;

	while (!colisoes[99]) {
		int tam = dist(mt);

		Particula** part = new Particula * [tam];
		int* pos = new int[tam];
		bool* pcol = new bool[tam];

		for (int j = 0; j < tam; j++) {
			pos[j] = dist(mt) - 1;
		}

		for (int j = 0; j < tam; j++) {
			part[j] = (particulas + pos[j]);
		}

		for (int j = 0; j < tam; j++) {
			pcol[j] = 0;
		}

		int colisao = 0;
		for (int j = 0; j < tam; j++) {
			part[j]->posicao = Deslocar(part[j]->posicao, part[j]->vetor, part[j]->tipo);
			if (part[j]->posicao.x >= 800 || part[j]->posicao.x <= 0) {

				colisao++;
				pcol[j] = 1;
				if (part[j]->tipo == 'C') {
					part[j]->vetor = InverterVetorC(part[j]->vetor, 'x');
				}
				else if (part[j]->tipo == 'P') {
					part[j]->vetor = InverterVetorP(part[j]->vetor, 'x');
				}

				int posEspaco = part[j]->nome - strchr(part[j]->nome, ' ');

				switch (part[j]->cor) {
					case Azul: {
						colisaoCor[0]++;
						break;
					}
					case Verde: {
						colisaoCor[1]++;
						break;
					}
					case Vermelho: {
						colisaoCor[2]++;
						break;
					}
					case Preto: {
						colisaoCor[3]++;
						break;
					}
					case Branco: {
						colisaoCor[4]++;
						break;
					}
				}
			}
			if (part[j]->posicao.y >= 600 || part[j]->posicao.y <= 0) {
				colisao++;
				pcol[j] = 1;
				if (part[j]->tipo == 'C') {
					part[j]->vetor = InverterVetorC(part[j]->vetor, 'y');
				}
				else if (part[j]->tipo == 'P') {
					part[j]->vetor = InverterVetorP(part[j]->vetor, 'y');
				}

				int posEspaco = part[j]->nome - strchr(part[j]->nome, ' ');

				switch (part[j]->cor) {
					case Azul: {
						colisaoCor[0]++;
						break;
					}
					case Verde: {
						colisaoCor[1]++;
						break;
					}
					case Vermelho: {
						colisaoCor[2]++;
						break;
					}
					case Preto: {
						colisaoCor[3]++;
						break;
					}
					case Branco: {
						colisaoCor[4]++;
						break;
					}
				}
			}
		}

		if (colisao) {
			colisoes[indice] = colisao;
			indice++;
		}

		cout << "#" << i << ": " << tam << " ( ";
		for (int j = 0; j < tam; j++) {
			cout << pos[j] << " ";
		}
		cout << ") = " << colisao;
			
		if (colisao > 0) {
			cout << " (";

			for (int j = 0; j < tam; j++) {
				if (pcol[j]) {
					cout << " " << strtok(part[j]->nome, " ") + strlen(strtok(part[j]->nome, " ")) + 1;
				}
			}
			cout << " ";
			cout << ")";
		}

		cout << endl;

		delete[] pcol;
		delete[] part;
		delete[] pos;
		i++;
	}
	i--;
	cout << "\nResultado\n";
	cout << "----------\n";

	int somaColisoes = 0;
	for (int i = 0; i < 100; i++) {
		somaColisoes += colisoes[i];
	}
	cout << "Colisões: " << somaColisoes << endl;
	cout << "Colisões por passo: " << float(somaColisoes) / i << endl;
	cout << "Média de passos entre as colisões: " << i / 100.0f << endl;
	cout << "Colisões por cor: "
		<< "Azul(" << colisaoCor[0]
		<< ") Verde(" << colisaoCor[1]
		<< ") Vermelho(" << colisaoCor[2]
		<< ") Preto(" << colisaoCor[3]
		<< ") Branco(" << colisaoCor[4]
		<< ")\n\n";

	return 0;
}

/*
Alan Turing:       790 101 P  40.0  20.0 0
Ada Lovelace:      480  76 P 138.0  25.0 1
Donald Knuth:      210 563 C  19.0  23.2 2
Peter Naur:        451 421 P 284.0  30.0 3
Ken Thompson:      630  46 C -22.1  14.3 4
Von Neumann:       100 500 P  89.0  17.9 0
Dennis Ritchie:     58 325 C  28.0 -25.0 1
Bjarne Stroustrup: 128 211 C -24.5 -25.9 2
Brian Kernighan:     2 182 C  35.5   2.6 3
Leslie Lamport:    737 555 P 149.0  18.2 4

*/
