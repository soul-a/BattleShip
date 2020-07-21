//============================================================================
// Name        : BattleShip.cpp
// Author      : soul-a & Luana
// Version     :
// Copyright   : 
// Description : A Battle Ship game for studing programing and algorithms
//============================================================================

/*
 * Bibliotecas
 */
#include <iostream>
#include <stdio.h>
#include <string>


/*
 * Assinaturas e Prototipos
 */
void ExibirTabuleiro(bool flag);
void PosicionarBarco(int i);
void CriaTabuleiro(bool flag);


/*
 * Variaveis globais
 */
const int PORTA_AVIOES = 6;
const int CRUZADOR = 5;
const int DESTROYER = 4;
const int FRAGATA = 3;
const int SUBMARINO = 3;
const int CORVETA = 2;
const int LINE = 14;
const int COLUM = 14;
char Tabuleiro[LINE][COLUM];
char Tabuleiro_visto[LINE][COLUM];


/*
 * Função principal
 */
int main(int argc, char **argv) {

	// jogador 1
	CriaTabuleiro(false);

	PosicionarBarco(PORTA_AVIOES);
	PosicionarBarco(CRUZADOR);
	PosicionarBarco(DESTROYER);
	PosicionarBarco(FRAGATA);
	PosicionarBarco(SUBMARINO);
	PosicionarBarco(CORVETA);

	ExibirTabuleiro(false);

	return 0;
}


// colocar como parâmetro qual barco posicionar
void PosicionarBarco(int i, bool flag){

	int linha, coluna, limiteLinhaColuna;
	char pos;
	bool sinalizador = false;

	switch(i) {
		case PORTA_AVIOES:
			limiteLinhaColuna = 5;
			break;

		case CRUZADOR:
			limiteLinhaColuna = 4;
			break;

		case DESTROYER:
			limiteLinhaColuna = 3;
			break;

		case FRAGATA:
			limiteLinhaColuna = 2;
			break;

		case SUBMARINO:
			limiteLinhaColuna = 2;
			break;

		case CORVETA:
			limiteLinhaColuna = 1;
			break;
	}

	do {
		system("cls"); // limpa o terminal

		ExibirTabuleiro(flag);
		std::cout << "Posicionar barco 6 casas" << std::endl;
		std::cout << "Posição linha 0-13:" << std::endl;
		std::cin  >> linha; //  pede para especificar a linha onde quer ser inserida

		// verifica se a linha é valida
		if(linha < LINE && linha >= 0){

			std::cout << "\nPosição da coluna 0-13:" << std::endl;
			std::cin  >> coluna; // pede para espeficicar a coluna onde quer ser inserida

			// verifica se a coluna é valida
			if(coluna < COLUM && coluna >= 0) {

				// verifica se o barco sera posicionado horizontalmente ou verticalmente
				std::cout << "Deseja posicionar o barco na vertical ou horizontal (v/h)" << std::endl;
				std::cin  >> pos;

				// verifica a variavel anterior e também se é possivel inserir o barco na posição(linha, coluna) especificada
				if(pos == 'v' && LINE - linha > limiteLinhaColuna) {

					int time = 0;

					// verifica se não há nenhum barco onde foi escolhida a posição
					for(int cont = linha; cont < linha + i; cont++){
						if(Tabuleiro[cont][coluna] == '~') {
							time++;
						}
					}

					// usa a mesma logica da verificação para preencher os lugares em que vai ficar o barco com o caracter 0
					if(time == PORTA_AVIOES) {
						for(int cont = linha; cont < linha + i; cont++){

							Tabuleiro[cont][coluna] = '0';
						}
					}

					sinalizador = true;
				}

				else {
					// mesma logica apresentada para quando a opção v (vertical) é escolhida, mudando apenas que irá preencher as colunas
					if(pos == 'h' && COLUM - coluna > limiteLinhaColuna) {

						int time = 0;

						for(int cont = coluna; cont < coluna + i; cont++){
							if(Tabuleiro[cont][coluna] == '~') {
								time++;
							}
						}

						if(time == PORTA_AVIOES) {
							for(int cont = coluna; cont < coluna + i; cont++) {
								Tabuleiro[linha][cont] = '0';
							}
						}

						sinalizador = true;
					}
				}
			}
		}

	}
	while(sinalizador == false);

	std::string s = (sinalizador == false) ? "Erro ao inserir barco" : "Barco inserido com sucesso";
	std::cout << s << std::endl;
}

// exibe tabuleiro dos dois jogadores
void ExibirTabuleiro(bool flag) {

	if(flag == false) {
		// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++){

				std::cout << Tabuleiro[i][j] << " | ";
			}
			std::cout << "" << std::endl;
		}
	}
	else {
		// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++){

				std::cout << Tabuleiro[i][j] << " | ";
			}
			std::cout << "" << std::endl;
		}
	}

	// percorrer as linhas da matriz
	for(int i = 0; i < 14; i++) {

		// percorrer as colunas
		for(int j = 0; j < 14; j++){

			std::cout << Tabuleiro_visto[i][j] << " | ";
		}
		std::cout << "" << std::endl;
	}
}

// cria tabuleiro dos dois jogadores
void CriaTabuleiro(bool flag) {

	if(flag == false) {
		// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++) {
				Tabuleiro[i][j] = '~';
			}
		}
	}
	else {
		// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++) {
				Tabuleiro_visto[i][j] = '~';
			}
		}
	}
}
