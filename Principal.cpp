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

	cout << "Simulação\n";
	cout << "---------\n";
	
	int colisoes[100] = { 0 };
	int indice = 0;

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 10);

	for (int i = 1; !colisoes[99]; i++) {
		int tam = dist(mt) + 1;

		Particula** part = new Particula* [tam];
		int* pos = new int[tam];

		for (int j = 0; j < tam; j++) {
			pos[j] = dist(mt);
		}

		for (int j = 0; j < tam; j++) {
			part[j] = &particulas[pos[j]];
		}
		int colisao = 0;
		for (int j = 0; j < tam; j++) {
			part[j]->posicao = Deslocar(part[j]->posicao, part[j]->vetor, part[j]->tipo);
			if (part[j]->posicao.x >= 800 || part[j]->posicao.x <= 0) {

				colisao++;
				if (part[j]->tipo == 'C') {
					part[j]->vetor = InverterVetorC(part[j]->vetor, 'x');
				}
				else if (part[j]->tipo == 'P') {
					part[j]->vetor = InverterVetorP(part[j]->vetor, 'x');
				}

			}
			else if (part[j]->posicao.y >= 600 || part[j]->posicao.y <= 0) {
				colisao++;
				if (part[j]->tipo == 'C') {
					part[j]->vetor = InverterVetorC(part[j]->vetor, 'y');
				}
				else if (part[j]->tipo == 'P') {
					part[j]->vetor = InverterVetorP(part[j]->vetor, 'y');
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

		cout << ") = " << colisao << endl;
		delete[] part;
		delete[] pos;
	}

	int somaColisoes = 0;
	for (int i = 0; i < 100; i++) {
		somaColisoes += colisoes[i];
	}
	cout << somaColisoes;

	return 0;
}


