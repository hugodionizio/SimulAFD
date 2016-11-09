/*
 * Transicao.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Transicao.h"

#include <stdio.h>
#include <stdlib.h>

void criarTransicoes(Transicao *t, Estado e, Alfabeto a) {
	int i, j;
	t->numEstados = e.numEstados;
	t->numSimbolos = a.numSimbolos;
	t->numSimbolosPilha = 3;

	t->funcoes = (int **)malloc(t->numEstados*sizeof(int));
	for (i = 0; i < t->numEstados; i++)
		t->funcoes[i] = (int *)malloc(t->numSimbolos*sizeof(int));
}

void inicializarTransicoes(Transicao *t) {
	int i, j, k;

	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			t->funcoes[i][j] = -1;
		}
	}
}

void definirTransicoes(Transicao *t, Estado e, Alfabeto a, Alfabeto ap) {
	int i, j;

	printf("Insira as funções de transição do Autômato:\n");
	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			printf("delta(%c%d, %c) = %c",e.representacao, i, a.simbolos[j], e.representacao);
			scanf("%d", &t->funcoes[j][i]);
		}
	}
}

// Liberar Funções da Memória Principal
void liberarTransicoes(Transicao *t) {
	int i;

	//  Liberação da memória de cada linha
	for (i = 0; i < t->numEstados; i++)
		free(t->funcoes[i]);

	//  Liberação da matriz da memória principal
	free(t->funcoes);
}

Transicao getTransicao(Transicao *producoes, int indice) {
	return producoes[indice];
}

void imprimirTransicoes(Transicao t, Alfabeto a, Estado e) {
	int i, j, k;
	for (i = 0; i < t.numEstados; i++) {
		printf("\n |");
		if (e.estados[i] == e.estadoInicial)
			printf("  ->");
		else printf("  ");
		if (buscaSequencial(e.estados[i], e.numEstadosFinais, e.estadosFinais) < e.numEstadosFinais) {
			if(e.estados[i] == e.estadoInicial)
				printf(" *");
			else
				printf(" *");
		}
		else {
			if(e.estados[i] != e.estadoInicial)
				printf(" ");
		}
		if (e.estados[i] != e.estadoInicial &&
				buscaSequencial(e.estados[i], e.numEstadosFinais, e.estadosFinais) >=
					e.numEstadosFinais)
			printf(" ");
		printf("%c%d  ",e.representacao, i);
		for (j = 0; j < a.numSimbolos; j++) {
			printf(" | %c%d",e.representacao, t.funcoes[i][j]);
		}
		printf(" |");
	}
}
