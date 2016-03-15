/*
 * Transicao.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Transicao.h"

void criarFuncoes(Transicao *t, Estado e, Alfabeto a) {
	int i;
	t->numEstados = e.numEstados;
	t->numSimbolos = a.numSimbolos;

	t->funcoes = (int **)malloc(t->numEstados);
	for (i = 0; i < t->numEstados; i++)
		t->funcoes[i] = (int *)malloc(t->numSimbolos);
}

void inicializarFuncoes(Transicao *t) {
	int i, j;

	for (i = 0; i < t->numEstados; i++)
		for (j = 0; j < t->numSimbolos; j++)
			t->funcoes[i][j] = 0;
}

void definirFuncoes(Transicao *t, Alfabeto a) {
	int i, j;

	printf("Insira as funções de transição do Autômato:\n");
	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			printf("delta(q%d, %d) = q", i, a.simbolos[j]);
			scanf("%d", &t->funcoes[i][j]);
		}
	}
}

// Liberar Funções da Memória Principal
void liberarFuncoes(Transicao *t) {
	int i;

	//  Liberação da memória de cada linha
	for (i = 0; i < t->numEstados; i++)
		free(t->funcoes[i]);

	//  Liberação da matriz da memória principal
	free(t->funcoes);
}

void imprimirFuncoes(Transicao t, Alfabeto a) {
	int i, j;
	for (i = 0; i < t.numEstados; i++) {
		for (j = 0; j < a.numSimbolos; j++) {
			printf(" | q%d", t.funcoes[i][j]);
		}
		printf(" | q%d\n", i);
	}
}
