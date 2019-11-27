#pragma warning(disable : 4996)
#include <iostream>
#include <random>
#include "Vetor.h"
#include "Particula.h"
#include "Cor.h"
using namespace std;

//Registro que guarda os resultados
struct Resultados {
	int colisoes = 0;
	Particula particulasColididas[10];
	int passos = 0;
};

void mostrarSobrenome(char*); // Protótipo da função que mostra o sobrenome

int main() {
	system("chcp 1252 > nul");
	
	Particula particulas[10]; //Vetor estático com 10 partículas
	Resultados resultados[100]; //Vetor estático dos resultados

	//loop para receber todas as partículas
	for (int i = 0; i < 10; i++) {
		cin >> particulas[i];
	}

	//criação do random device e colocando uma semente no mersenne twister, e criando a distribuição uniforme entre 1 e 10;
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 10);

	int passo = 1; // Inicializando o primeiro passo como 1
	int indice = 0;
	int passosAteColisao = 0;
	int colisaoCor[5] = { 0 };

	//loop que executa até completar 100 passos com colisão
	while (!resultados[99].colisoes) {
		int tam = dist(mt); // tamanho do vetor dinâmico
		//int quantPart = tam; // quantidade de particulas escolhidas
		int colisoes = 0; // quantidade de colisões no passo atual
		int index = 0;

		//criação de um vetor dinâmico de ponteiros
		Particula** particulasEscolhidas = new Particula* [tam];
		int* posicoes = new int[tam];

		//loop para escolher aleatoriamente as particulas que se moverão no passo atual
		for (int i = 0; i < tam; i++) {
			posicoes[i] = dist(mt) - 1;
			particulasEscolhidas[i] = &particulas[posicoes[i]];
		}

		//loop que fará as operações das particulas escolhidas
		for (int i = 0; i < tam; i++) {

			//chamada de função para deslocar a particula
			particulasEscolhidas[i]->posicao = Deslocar(particulasEscolhidas[i]->posicao, particulasEscolhidas[i]->vetor, particulasEscolhidas[i]->tipo);

			if (particulasEscolhidas[i]->posicao.x >= 800 || particulasEscolhidas[i]->posicao.x <= 0) {
				colisoes++; // soma 1 as colisões totais do passo

				resultados[indice].particulasColididas[index] = *particulasEscolhidas[i];
				index++;

				//Rebater a partícula quando bate nas paredes laterais
				if (particulasEscolhidas[i]->tipo == 'C') {
					particulasEscolhidas[i]->vetor = InverterVetorC(particulasEscolhidas[i]->vetor, 'x');
				} else if (particulasEscolhidas[i]->tipo == 'P') {
					particulasEscolhidas[i]->vetor = InverterVetorP(particulasEscolhidas[i]->vetor, 'x');
				}

				switch (particulasEscolhidas[i]->cor) {
					case Azul: {
						colisaoCor[Azul]++;
						break;
					}
					case Verde: {
						colisaoCor[Verde]++;
						break;
					}
					case Vermelho: {
						colisaoCor[Vermelho]++;
						break;
					}
					case Preto: {
						colisaoCor[Preto]++;
						break;
					}
					case Branco: {
						colisaoCor[Branco]++;
						break;
					}
				}
			}
			if (particulasEscolhidas[i]->posicao.y >= 600 || particulasEscolhidas[i]->posicao.y <= 0) {
				colisoes++; // soma 1 as colisões totais do passo

				resultados[indice].particulasColididas[index] = *particulasEscolhidas[i];
				index++;

				//rebater a partícula quando bate nas paredes superiores e inferiores
				if (particulasEscolhidas[i]->tipo == 'C') {
					particulasEscolhidas[i]->vetor = InverterVetorC(particulasEscolhidas[i]->vetor, 'y');
				}
				else if (particulasEscolhidas[i]->tipo == 'P') {
					particulasEscolhidas[i]->vetor = InverterVetorP(particulasEscolhidas[i]->vetor, 'y');
				}

				switch (particulasEscolhidas[i]->cor) {
					case Azul: {
						colisaoCor[Azul]++;
						break;
					}
					case Verde: {
						colisaoCor[Verde]++;
						break;
					}
					case Vermelho: {
						colisaoCor[Vermelho]++;
						break;
					}
					case Preto: {
						colisaoCor[Preto]++;
						break;
					}
					case Branco: {
						colisaoCor[Branco]++;
						break;
					}
				}
			}
		}

		cout << "#" << passo << ": " << tam << " (";

		for (int i = 0; i < tam; i++) {
			cout << " " << posicoes[i];
		}

		cout << " ) = " << colisoes;

		if (colisoes) {
			cout << " (";
			for (int i = 0; i <= index; i++) {
				cout << " ";
				mostrarSobrenome(resultados[indice].particulasColididas[i].nome);
			}
			cout << ")";
			resultados[indice].colisoes = colisoes;
			resultados[indice].passos = passosAteColisao;
			passosAteColisao = 0;
			indice++;
		}
		else {
			passosAteColisao++;
		}

		cout << endl;

		passo++;

		delete[] particulasEscolhidas;
	}

	int totalColisoes = 0;
	int somaPassos = 0;

	for (int i = 0; i < 100; i++) {
		totalColisoes += resultados[i].colisoes;
		somaPassos += resultados[i].passos;
	}

	cout << "Resultados\n"
		 << "----------\n";
	cout << "Colisões: " << totalColisoes;
	cout << "\nColisões por passo: " << float(totalColisoes) / passo;
	cout << "\nMédia de passos entre colisões: " << float(somaPassos) / 99;
	cout << "\nColisões por cor: " 
		<< "Azul(" << colisaoCor[Azul]
		<< ") Verde(" << colisaoCor[Verde]
		<< ") Vermelho(" << colisaoCor[Vermelho]
		<< ") Preto(" << colisaoCor[Preto]
		<< ") Branco(" << colisaoCor[Branco]
		<< ")\n\n";
}

//Função que mostra o sobrenome
void mostrarSobrenome(char* nomeComposto) {
	cout << nomeComposto + strlen(strtok(nomeComposto, " ")) + 1;
}

/*
					TESTE

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