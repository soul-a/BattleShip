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
void PosicionarBarco(int i, bool flag);
void CriaTabuleiro(bool flag);
void Legenda();
void ExibirTabuleiroInimigo(bool flag);
void Atacar(bool flag);

/*
 * Variaveis globais
 */
const int PORTA_AVIOES = 6;
const int CRUZADOR = 5;
const int DESTROYER = 4;
const int FRAGATA = 3;
const int SUBMARINO = 2;
const int CORVETA = 1;
const int LINE = 14;
const int COLUM = 14;
bool acertop1;
bool acertop2;
char Tabuleiro[LINE][COLUM];
char Tabuleiro_visto[LINE][COLUM];
char Tabuleiro_ini[LINE][COLUM];
char Tabuleiro_visto_ini[LINE][COLUM];

/*
 * Função principal
 */
int main(int argc, char **argv) {

	bool p1 = true;
	bool p2 = false;

	int jogadasCertasP1;
	int jogadasCertasP2;

	int barcosDestruidos = 21;

	CriaTabuleiro(p1);
	CriaTabuleiro(p2);

	std::cout << "Jogo de Batalha Naval\n\n";

	// ROTINA POSICIONAR BARCOS JOGADOR 1

	std::cout << "Jogador 1 posicione seus barcos" << std::endl;

	PosicionarBarco(PORTA_AVIOES, p1);
	std::cout << std::endl;
	PosicionarBarco(CRUZADOR, p1);
	std::cout << std::endl;
	PosicionarBarco(DESTROYER, p1);
	std::cout << std::endl;
	PosicionarBarco(FRAGATA, p1);
	std::cout << std::endl;
	PosicionarBarco(SUBMARINO, p1);
	std::cout << std::endl;
	PosicionarBarco(CORVETA, p1);

	system("cls");
	ExibirTabuleiro(p1);
	Legenda();

	system("pause");

	// ROTINA POSICIONAR BARCOS SEGUNDO JOGADOR


	std::cout << "Jogador 2 posicione seus barcos" << std::endl;

		PosicionarBarco(PORTA_AVIOES, p2);
		std::cout << std::endl;
		PosicionarBarco(CRUZADOR, p2);
		std::cout << std::endl;
		PosicionarBarco(DESTROYER, p2);
		std::cout << std::endl;
		PosicionarBarco(FRAGATA, p2);
		std::cout << std::endl;
		PosicionarBarco(SUBMARINO, p2);
		std::cout << std::endl;
		PosicionarBarco(CORVETA, p2);

		system("cls");
		ExibirTabuleiro(p2);
		Legenda();

		system("pause");


		while(barcosDestruidos != jogadasCertasP1 || barcosDestruidos != jogadasCertasP2) {

			Atacar(p1);

			if(acertop1 == true)
				jogadasCertasP1++;

			Atacar(p2);

			if(acertop2 == true)
				jogadasCertasP2++;
		}

		if(jogadasCertasP1 == 21)
			std::cout << "Parabéns Jogador numero 1";

		if(jogadasCertasP2 == 21)
			std::cout << "parabens jogador numero 2";

}

void Legenda() {

	std::cout << "\n>>>>Legenda<<<<" << std::endl;
	std::cout << "~\tAgua" << std::endl;
	std::cout << "$\Barcos" << std::endl;
	std::cout << "#\Errou" << std::endl;
	std::cout << "X\Acerto" << std::endl;
}

// colocar como parâmetro qual barco posicionar
void PosicionarBarco(int i, bool flag) {

	int linha, coluna, limiteLinhaColuna, numBarco;
	int time = 0;
	char pos, barco = '$';
	bool sinalizador = false;

	switch(i) {
		case PORTA_AVIOES:
			limiteLinhaColuna = 5;
			numBarco = 6;
			break;

		case CRUZADOR:
			limiteLinhaColuna = 4;
			numBarco = 5;
			break;

		case DESTROYER:
			limiteLinhaColuna = 3;
			numBarco = 4;
			break;

		case FRAGATA:
			limiteLinhaColuna = 2;
			numBarco = 3;
			break;

		case SUBMARINO:
			limiteLinhaColuna = 1;
			numBarco = 2;
			break;

		case CORVETA:
			limiteLinhaColuna = 0;
			numBarco = 1;
			break;
	}

	do {
		system("cls"); // limpa o terminal

		if(flag)
			ExibirTabuleiro(true);
		else
			ExibirTabuleiro(false);

		Legenda();

		std::cout << "Posicionar barco " << numBarco << " casas" << std::endl;
		std::cout << "Posicao linha 0-13:" << std::endl;
		std::cin  >> linha; //  pede para especificar a linha onde quer ser inserida

		// verifica se a linha é valida
		if(linha < LINE && linha >= 0){

			std::cout << "\nPosicao da coluna 0-13:" << std::endl;
			std::cin  >> coluna; // pede para espeficicar a coluna onde quer ser inserida

			// verifica se a coluna é valida
			if(coluna < COLUM && coluna >= 0) {

				// verifica se o barco sera posicionado horizontalmente ou verticalmente
				std::cout << "Deseja posicionar o barco na vertical ou horizontal (v/h)" << std::endl;
				std::cin  >> pos;

				// verifica a variavel anterior e também se é possivel inserir o barco na posição(linha, coluna) especificada
				if(pos == 'v' && LINE - linha > limiteLinhaColuna) {

					// faz a verificação de qual barco foi ecolhido p1
					if(flag) {
						// verifica se não há nenhum barco onde foi escolhida a posição
						for(int cont = linha; cont < linha + i; cont++){
							if(Tabuleiro[cont][coluna] == '~') {
								time++;
							}
						}
					}
					// barco escolhido p2
					else {
						// verifica se não há nenhum barco onde foi escolhida a posição
						for(int cont = linha; cont < linha + i; cont++){
							if(Tabuleiro_visto[cont][coluna] == '~') {
								time++;
							}
						}
					}

					// verifica qual tabuleiro deve ser alterado p1 ou p2
					if(flag) {
						// usa a mesma logica da verificação para preencher os lugares em que vai ficar o barco com o caracter 0
						if(time == i) {
							for(int cont = linha; cont < linha + i; cont++){

								Tabuleiro[cont][coluna] = barco;
							}
						}
					}
					else {
						// usa a mesma logica da verificação para preencher os lugares em que vai ficar o barco com o caracter 0
						if(time == i) {
							for(int cont = linha; cont < linha + i; cont++){

								Tabuleiro_visto[cont][coluna] = barco;
							}
						}
					}

					// mostrar erro caso ja houver barco inserido no local desejado
					if(time != i)
						std::cout << "Ja possui um barco inserido na posição desejada" << std::endl;

					sinalizador = true;

				}
				else {
					// mesma logica apresentada para quando a opção v (vertical) é escolhida, mudando apenas que irá preencher as colunas
					if(pos == 'h' && COLUM - coluna > limiteLinhaColuna) {

						if(flag) {
							for(int cont = coluna; cont < coluna + i; cont++){
								if(Tabuleiro[cont][coluna] == '~') {
									time++;
								}
							}
						}
						else {
							for(int cont = coluna; cont < coluna + i; cont++){
								if(Tabuleiro_visto[cont][coluna] == '~') {
									time++;
								}
							}
						}


						if(flag) {
							if(time == i) {
								for(int cont = coluna; cont < coluna + i; cont++) {
									Tabuleiro[linha][cont] = barco;
								}
							}
						}
						else {
							if(time == i) {
								for(int cont = coluna; cont < coluna + i; cont++) {
									Tabuleiro_visto[linha][cont] = barco;
								}
							}
						}

						// mostrar erro caso ja houver um barco posicionado no loval desejado
						if(time != i)
							std::cout << "Ja possui um barco inserido na posição desejada" << std::endl;

						sinalizador = true;
					}
				}
			}
		}

		std::string s = (sinalizador == false && time != i) ? "Erro ao inserir barco, espaco invalido" : "Barco inserido com sucesso";
		std::cout << s << std::endl;
	}
	while(sinalizador == false);
}

void ExibirTabuleiroInimigo(bool flag) {

	if(flag) {
			// percorrer as linhas da matriz
			for(int i = 0; i < 14; i++) {

				// percorrer as colunas
				for(int j = 0; j < 14; j++){

					std::cout << Tabuleiro_ini[i][j] << " | ";
				}
				std::cout << "" << std::endl;
			}
		}
		else {
		// percorrer as linhas da matriz
			for(int i = 0; i < 14; i++) {

				// percorrer as colunas
				for(int j = 0; j < 14; j++){

					std::cout << Tabuleiro_visto_ini[i][j] << " | ";
				}
				std::cout << "" << std::endl;
			}

		}
}

// exibe tabuleiro dos dois jogadores
void ExibirTabuleiro(bool flag) {

	if(flag) {
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

				std::cout << Tabuleiro_visto[i][j] << " | ";
			}
			std::cout << "" << std::endl;
		}

	}
}

// cria tabuleiro dos dois jogadores
void CriaTabuleiro(bool flag) {

	if(flag) {
		// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++) {
				Tabuleiro[i][j] = '~';
				Tabuleiro_ini[i][j] = '~';
			}
		}
	}
	else {
		// percorrer as linhas da matriz
		for(int i = 0; i < 14; i++) {

			// percorrer as colunas
			for(int j = 0; j < 14; j++) {
				Tabuleiro_visto[i][j] = '~';
				Tabuleiro_visto_ini[i][j] = '~';
			}
		}
	}
}

void Atacar(bool flag) {

	int coluna, linha;
	bool sinalizador = true;
	bool acertoErro;

	do {
		system("cls");

		if(flag){
			ExibirTabuleiroInimigo(true);
			std::cout << "-----------------------------" << std::endl;
			std::cout << " Atacar o Oponente jogador 1 " << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}
		else {
			ExibirTabuleiroInimigo(false);
			std::cout << "-----------------------------" << std::endl;
			std::cout << " Atacar o Oponente jogador 2 " << std::endl;
			std::cout << "-----------------------------" << std::endl;
		}


		std::cout << "\nPosicao linha (0-13): " << std::endl;
		std::cin  >> linha;

		if(linha < LINE && linha >= 0) {

			std::cout << "\nPosicao coluna (0-13): " << std::endl;
			std::cin  >> coluna;

			if(coluna < COLUM && coluna >= 0) {
				 // se flag for true (jogador 1 ataca) ele verifica e marca o ataque no tabuleiro inimigo
				if(flag) {

					if(Tabuleiro_visto[linha][coluna] == '$' && Tabuleiro_visto_ini == '~'){
						Tabuleiro_visto_ini[linha][coluna] = 'X';
						std::cout << "Voce Acertou!!!";
						system("pause");
						acertop1 = true;
					}
					else if(Tabuleiro_visto[linha][coluna] == '~' && Tabuleiro_visto_ini == '~'){
						Tabuleiro_visto_ini[linha][coluna] = '#';
						std::cout << "Voce Errou!!!";
						system("pause");
						acertop1 = false;
					}
				}
				// se não quem ataca é o jogador 2
				else {

					if(Tabuleiro[linha][coluna] == '$' && Tabuleiro_ini == '~'){
						Tabuleiro_ini[linha][coluna] = 'X';
						std::cout << "Voce Acertou!!!";
						system("pause");
						acertop2 = true;
					}
					else if(Tabuleiro[linha][coluna] == '~' && Tabuleiro_ini == '~'){
						Tabuleiro_ini[linha][coluna] = '#';
						std::cout << "Voce Errou!!!";
						system("pause");
						acertop2 = false;
					}
				}
			} else { sinalizador = false; }
		} else { sinalizador = false; }
	} while(sinalizador == true);
}
