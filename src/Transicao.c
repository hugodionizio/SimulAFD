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

	t->transicoes = (int ***)malloc(t->numEstados*sizeof(int));
	for (i = 0; i < t->numEstados; i++) {
		t->transicoes[i] = (int **)malloc(t->numSimbolos*sizeof(int));
		for (j = 0; j < t->numSimbolos; j++)
			t->transicoes[i][j] = (int *)malloc(t->numSimbolosPilha*sizeof(int));
	}
}

void inicializarTransicoes(Transicao *t) {
	int i, j, k;

	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			for (k = 0; k < t->numSimbolosPilha; ++k) {
				t->transicoes[i][j][k] = -1;
			}
		}
	}
}

void definirTransicoes(Transicao *t, Estado e, Alfabeto a, Alfabeto ap) {
	int i, j, k;

	printf("Insira as funções de transição do Autômato:\n");
	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			for (k = 0; k < t->numSimbolosPilha; ++k) {
				if (j == 0) {
					printf("delta(%c%d, %c, %c) = {(%c", e.representacao, i, a.simbolos[j], ap.simbolos[k], e.representacao);
				}
				else
					printf("delta(%c%d, %c, %c) = {(%c%d, ", e.representacao, i, a.simbolos[j], ap.simbolos[k], e.representacao, t->transicoes[i][j][k-1]);
				scanf("%d", &t->transicoes[i][j][k]);
			}
		}
	}
}

// Liberar Funções da Memória Principal
void liberarTransicoes(Transicao *t) {
	int i;

	//  Liberação da memória de cada linha
	for (i = 0; i < t->numEstados; i++)
		free(t->transicoes[i]);

	//  Liberação da matriz da memória principal
	free(t->transicoes);
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
			for (k = 0; k < t.numSimbolosPilha; ++k) {
				printf(" | %c%d",e.representacao, t.transicoes[i][j][k]);
			}
		}
		printf(" |");
	}
}
