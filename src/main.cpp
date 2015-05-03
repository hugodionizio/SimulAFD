/*
 *  Projeto: SimulAFD
 *  Programa: main.cpp
 *  Função : Gerenciar porgramas
 *  Created on: 02/05/2015
 *      Author: Hugo Dionizio Santos
 *      		Thiago da Silveira Batista
 */
#include "SimulAFD.h"

using namespace std;

// Interface do programa (Protótipos de funções)

int main (int argc, char **argv) {
// Seção de Declarações Internas
	char ch;

// Seção de Comandos
	cout << "1º Trabalho da disciplina de Linguagens Formais e Autômatos" << endl;
	cout << "SimulAFD: Simulador de Autômatos Finitos determinísticos (AFD)" << endl;
	if (argc > 1 && strcmp(argv[1], "--help") == 0) {
		ifstream fin("../src/help.txt"); // Cria arquivo para a gravação em modo texto
		while (fin.get(ch))	// Lê um caractere do teclado
			cout.put(ch);	// Grava o caractere no arquivo
	}
	else {
		int exitType = terminal();
		if (exitType != 0) {
			cout << "Finalização com erro do tipo " << exitType << "." << endl;
		}
		else
			cout << "Finalização bem sucedida." << endl;
	}

	return (0);
}

// Funções

// Fim do programa
