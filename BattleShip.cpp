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


/*
 * Função principal
 */
int main(int argc, char **argv) {

	CriarTabuleiro();

	return 0;
}

void CriarTabuleiro(){

	char tabuleiro[14][14];

	// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++){

				tabuleiro[i][j] = '~';
			}
		}

		// percorrer as linhas da matriz
			for(int i = 0; i < 14; i++) {

				// percorrer as colunas
				for(int j = 0; j < 14; j++){

					std::cout << tabuleiro[i][j] << " | ";
				}
				std::cout << "" << std::endl;
			}
}
