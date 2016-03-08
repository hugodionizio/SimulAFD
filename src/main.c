/*
 *  Projeto: Autômatos Finitos Deterministicos
 *  Programa: main.c
 *  Objetivo: Implementar um simulador de autômatos finitos determinísticos – AFD
 *  		que permite testar o reconhecimento de diversas cadeias para qualquer AFD de entrada.
 *  Created on: 08/03/2016
 *      Author: Hugo Dionizio Santos
 */
#include "SimulAFD.h"

// Interface do programa (Protótipos de funções)

int main (int argc, char **argv) {
// Seção de Declarações Internas
	char ch;

// Seção de Comandos
	printf ("1º Trabalho da disciplina de Linguagens Formais e Autômatos\n");
	printf ("SimulAFD: Simulador de Autômatos Finitos determinísticos (AFD)\n");
	if (argc > 1 && strcmp(argv[1], "--help") == 0) {
		ifstream fin("../src/help.txt"); // Cria arquivo para a gravação em modo texto
		while (fin.get(ch))	// Lê um caractere do teclado
			cout.put(ch);	// Grava o caractere no arquivo
	}
	else {
		int exitType = terminal();
		if (exitType != 0) {
			printf("Finalização com erro do tipo %d.\n", exitType);
		}
		else
			printf("Finalização bem sucedida.\n");
	}

	return (0);
}
// Funções

// Fim do programa
