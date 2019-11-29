#pragma warning(disable : 4996) // Desabilita��o do aviso a exce��o 4996

// Inclus�o das bibliotecas
#include <iostream>
#include <random>
#include "Vetor.h"
#include "Particula.h"
#include "Cor.h"
using namespace std;

// Registro que guarda os resultados
struct Resultados {
	int colisoes = 0;
	Particula* particulasColididas[10] = { 0 };
	int passos = 0;
};

void mostrarSobrenome(char*); // Prot�tipo da fun��o que mostra o sobrenome

int main() {
	system("chcp 1252 > null");
	
	Particula particulas[10]; // Vetor est�tico com 10 part�culas
	Resultados resultados[100]; // Vetor est�tico dos resultados

	// Loop para receber todas as part�culas
	for (int i = 0; i < 10; i++) {
		cin >> particulas[i];
	}

	// Cria��o do random device e colocando uma semente no mersenne twister, e criando a distribui��o uniforme entre 1 e 10;
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 10);

	int passo = 1; // Inicializando o primeiro passo como 1
	int indice = 0; // Indice para o vetor de resultados
	int passosAteColisao = 0; // Incializando a contagem de passos entre uma colis�o e outra
	int colisaoCor[5] = { 0 }; // Inicializando o vetor que conta as colis�es por cor

	// Loop que executa at� completar 100 passos com colis�o
	while (!resultados[99].colisoes) {
		int tam = dist(mt); // Tamanho do vetor din�mico
		int colisoes = 0; // Quantidade de colis�es no passo atual
		int index = 0; // Indice para as particulas colididas

		// Cria��o de um vetor din�mico de ponteiros
		Particula** particulasEscolhidas = new Particula* [tam];
		int* posicoes = new int[tam];

		// Loop para escolher aleatoriamente as particulas que se mover�o no passo atual
		for (int i = 0; i < tam; i++) {
			posicoes[i] = dist(mt) - 1;
			particulasEscolhidas[i] = &particulas[posicoes[i]];
		}

		// Loop que far� as opera��es das particulas escolhidas
		for (int i = 0; i < tam; i++) {

			// Chamada de fun��o para deslocar a particula
			particulasEscolhidas[i]->posicao = Deslocar(particulasEscolhidas[i]->posicao, particulasEscolhidas[i]->vetor, particulasEscolhidas[i]->tipo);

			if (particulasEscolhidas[i]->posicao.x >= 800 || particulasEscolhidas[i]->posicao.x <= 0) {
				colisoes++; // Soma 1 as colis�es totais do passo

				// Adiciona a particula ao vetor do resultado do passo e aumenta o indice das particulas no resultado atual por 1
				resultados[indice].particulasColididas[index] = particulasEscolhidas[i];
				index++;

				// Rebater a part�cula quando bate nas paredes laterais
				if (particulasEscolhidas[i]->tipo == 'C') {
					particulasEscolhidas[i]->vetor = InverterVetorC(particulasEscolhidas[i]->vetor, 'x');
				} else if (particulasEscolhidas[i]->tipo == 'P') {
					particulasEscolhidas[i]->vetor = InverterVetorP(particulasEscolhidas[i]->vetor, 'x');
				}

				// Checa qual a cor da particula e soma 1 ao vetor correspondente de cada cor
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
				colisoes++; // Soma 1 as colis�es totais do passo

				// Adiciona a particula ao vetor do resultado do passo e aumenta o indice das particulas no resultado atual por 1
				resultados[indice].particulasColididas[index] = particulasEscolhidas[i];
				index++;

				// Rebater a part�cula quando bate nas paredes superiores e inferiores
				if (particulasEscolhidas[i]->tipo == 'C') {
					particulasEscolhidas[i]->vetor = InverterVetorC(particulasEscolhidas[i]->vetor, 'y');
				}
				else if (particulasEscolhidas[i]->tipo == 'P') {
					particulasEscolhidas[i]->vetor = InverterVetorP(particulasEscolhidas[i]->vetor, 'y');
				}

				// Checa qual a cor da particula e soma 1 ao vetor correspondente de cada cor
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

		// Mostra o n�mero do passo atual
		cout << "#" << passo << ": " << tam << " (";

		// Loop que mostra os indices das particulas escolhidas para serem movidas no passo atual
		for (int i = 0; i < tam; i++) {
			cout << " " << posicoes[i];
		}

		// Mostra o total de colis�o no passo atual
		cout << " ) = " << colisoes;

		// Se tiver alguma colis�o, mostra os sobrenomes das part�culas que colidiram
		// Guarda as colis�es e a quantidade de passos at� entre a colis�o passada e a atual no vetor resultado
		if (colisoes) {
			cout << " (";
			for (int i = 0; i < index; i++) {
				cout << " ";
				mostrarSobrenome(resultados[indice].particulasColididas[i]->nome);
			}
			cout << " )";
			resultados[indice].colisoes = colisoes;
			resultados[indice].passos = passosAteColisao;
			if (indice) {
				resultados[indice].passos++;
			}
			passosAteColisao = 0;
			indice++;
		}
		else {
			passosAteColisao++;
		}

		cout << endl;

		passo++;

		delete[] posicoes;
		delete[] particulasEscolhidas;
	}
	passo--;

	// Inicializa o total de colis�es na simula��o e a quantidade total de passos entre as part�culas como 0
	int totalColisoes = 0;
	int somaPassos = 0;

	// Soma as colis�es e os passos entre colis�es nas vari�veis
	for (int i = 0; i < 100; i++) {
		totalColisoes += resultados[i].colisoes;
		somaPassos += resultados[i].passos;
	}

	// Diminui o total de passos entre as colis�es dos passos que vieram antes da primeira colis�o
	somaPassos -= resultados[0].passos;

	// Mostra os resultados
	cout << "Resultados\n"
		 << "----------\n";
	cout << "Colis�es: " << totalColisoes;
	cout << "\nColis�es por passo: " << float(totalColisoes) / passo;
	cout << "\nM�dia de passos entre colis�es: " << float(somaPassos) / 99;
	cout << "\nColis�es por cor: " 
		<< "Azul(" << colisaoCor[Azul]
		<< ") Verde(" << colisaoCor[Verde]
		<< ") Vermelho(" << colisaoCor[Vermelho]
		<< ") Preto(" << colisaoCor[Preto]
		<< ") Branco(" << colisaoCor[Branco]
		<< ")\n\n";
}

//Fun��o que mostra o sobrenome
void mostrarSobrenome(char* nomeComposto) {
	cout << nomeComposto + strlen(strtok(nomeComposto, " ")) + 1;
}

