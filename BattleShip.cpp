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


/*
 * Assinaturas e Prototipos
 */
void CriarTabuleiro();


/*
 * Variaveis globais
 */
const int LINE = 14;
const int COLUM = 14;
char Tabuleiro[LINE][COLUM];


/*
 * Função principal
 */
int main(int argc, char **argv) {

	CriarTabuleiro();

	return 0;
}

void CriarTabuleiro(){

	// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++){

				Tabuleiro[i][j] = '~';
			}
		}

		// percorrer as linhas da matriz
			for(int i = 0; i < 14; i++) {

				// percorrer as colunas
				for(int j = 0; j < 14; j++){

					std::cout << Tabuleiro[i][j] << " | ";
				}
				std::cout << "" << std::endl;
			}
}
