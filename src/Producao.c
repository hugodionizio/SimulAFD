/*
 * Producao.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Producao.h"

#include <stdlib.h>

void criarFuncoes(Producao *t, Estado e, Alfabeto a) {
	int i;
	t->numEstados = e.numEstados;
	t->numSimbolos = a.numSimbolos;

	t->producoes = (int **)malloc(t->numEstados*sizeof(int));
	for (i = 0; i < t->numEstados; i++)
		t->producoes[i] = (int *)malloc(t->numSimbolos*sizeof(int));
}

void inicializarFuncoes(Producao *t) {
	int i, j;

	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++)
			t->producoes[j][i] = -1;
	}
}

void definirFuncoes(Producao *t, Estado e, Alfabeto a) {
	int i, j;

	printf("Insira as produções do Autômato:\n");
	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			printf("delta(%c%d, %c) = %c",e.representacao, i, a.simbolos[j], e.representacao);
			scanf("%d", &t->producoes[j][i]);
		}
	}
}

// Liberar Funções da Memória Principal
void liberarFuncoes(Producao *t) {
	int i;

	//  Liberação da memória de cada linha
	for (i = 0; i < t->numEstados; i++)
		free(t->producoes[i]);

	//  Liberação da matriz da memória principal
	free(t->producoes);
}

Producao getProducao(Producao *producoes, int indice) {
	return producoes[indice];
}

void imprimirFuncoes(Producao t, Alfabeto a, Estado e) {
	int i, j;
	for (i = 0; i < t.numEstados; i++) {
		printf("\n |");
		if (e.estados[i] == e.estadoInicial)
			printf(" ->");
		else printf("  ");
		if (buscaSequencial(e.estados[i], e.numEstadosFinais, e.estadosFinais) < e.numEstadosFinais) {
			if(e.estados[i] == e.estadoInicial)
				printf("*");
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
			printf(" | %c%d",e.representacao, t.producoes[j][i]);
		}
		printf(" |");
	}
}
