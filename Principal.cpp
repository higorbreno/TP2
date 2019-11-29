#pragma warning(disable : 4996) // Desabilitação do aviso a exceção 4996

// Inclusão das bibliotecas
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

void mostrarSobrenome(char*); // Protótipo da função que mostra o sobrenome

int main() {
	system("chcp 1252 > null");
	
	Particula particulas[10]; // Vetor estático com 10 partículas
	Resultados resultados[100]; // Vetor estático dos resultados

	// Loop para receber todas as partículas
	for (int i = 0; i < 10; i++) {
		cin >> particulas[i];
	}

	// Criação do random device e colocando uma semente no mersenne twister, e criando a distribuição uniforme entre 1 e 10;
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(1, 10);

	int passo = 1; // Inicializando o primeiro passo como 1
	int indice = 0; // Indice para o vetor de resultados
	int passosAteColisao = 0; // Incializando a contagem de passos entre uma colisão e outra
	int colisaoCor[5] = { 0 }; // Inicializando o vetor que conta as colisões por cor

	// Loop que executa até completar 100 passos com colisão
	while (!resultados[99].colisoes) {
		int tam = dist(mt); // Tamanho do vetor dinâmico
		int colisoes = 0; // Quantidade de colisões no passo atual
		int index = 0; // Indice para as particulas colididas

		// Criação de um vetor dinâmico de ponteiros
		Particula** particulasEscolhidas = new Particula* [tam];
		int* posicoes = new int[tam];

		// Loop para escolher aleatoriamente as particulas que se moverão no passo atual
		for (int i = 0; i < tam; i++) {
			posicoes[i] = dist(mt) - 1;
			particulasEscolhidas[i] = &particulas[posicoes[i]];
		}

		// Loop que fará as operações das particulas escolhidas
		for (int i = 0; i < tam; i++) {

			// Chamada de função para deslocar a particula
			particulasEscolhidas[i]->posicao = Deslocar(particulasEscolhidas[i]->posicao, particulasEscolhidas[i]->vetor, particulasEscolhidas[i]->tipo);

			if (particulasEscolhidas[i]->posicao.x >= 800 || particulasEscolhidas[i]->posicao.x <= 0) {
				colisoes++; // Soma 1 as colisões totais do passo

				// Adiciona a particula ao vetor do resultado do passo e aumenta o indice das particulas no resultado atual por 1
				resultados[indice].particulasColididas[index] = particulasEscolhidas[i];
				index++;

				// Rebater a partícula quando bate nas paredes laterais
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
				colisoes++; // Soma 1 as colisões totais do passo

				// Adiciona a particula ao vetor do resultado do passo e aumenta o indice das particulas no resultado atual por 1
				resultados[indice].particulasColididas[index] = particulasEscolhidas[i];
				index++;

				// Rebater a partícula quando bate nas paredes superiores e inferiores
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

		// Mostra o número do passo atual
		cout << "#" << passo << ": " << tam << " (";

		// Loop que mostra os indices das particulas escolhidas para serem movidas no passo atual
		for (int i = 0; i < tam; i++) {
			cout << " " << posicoes[i];
		}

		// Mostra o total de colisão no passo atual
		cout << " ) = " << colisoes;

		// Se tiver alguma colisão, mostra os sobrenomes das partículas que colidiram
		// Guarda as colisões e a quantidade de passos até entre a colisão passada e a atual no vetor resultado
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

	// Inicializa o total de colisões na simulação e a quantidade total de passos entre as partículas como 0
	int totalColisoes = 0;
	int somaPassos = 0;

	// Soma as colisões e os passos entre colisões nas variáveis
	for (int i = 0; i < 100; i++) {
		totalColisoes += resultados[i].colisoes;
		somaPassos += resultados[i].passos;
	}

	// Diminui o total de passos entre as colisões dos passos que vieram antes da primeira colisão
	somaPassos -= resultados[0].passos;

	// Mostra os resultados
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

