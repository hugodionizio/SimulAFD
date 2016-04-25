/*
 * Transicao.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include <stdlib.h>
#include "Transicao.h"

void criarFuncoes(Transicao *t, Estado e, Alfabeto a) {
	int i;
	t->numEstados = e.numEstados;
	t->numSimbolos = a.numSimbolos;

	t->funcoes = (char **)malloc(t->numEstados*sizeof(char));
	for (i = 0; i < t->numEstados; i++)
		t->funcoes[i] = (char *)malloc(t->numSimbolos*sizeof(char));
}

void inicializarFuncoes(Transicao *t) {
	int i, j;

	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++)
			t->funcoes[j][i] = ' ';
	}
}

void definirFuncoes(Transicao *t, Estado e, Alfabeto a) {
	int i, j;

	printf("Insira as funções de transição do Autômato:\n");
	for (i = 0; i < t->numEstados; i++) {
		for (j = 0; j < t->numSimbolos; j++) {
			printf("delta(%c%d, %c) = %c",e.representacao, i, a.simbolos[j], e.representacao);
			scanf(" %c", &t->funcoes[j][i]);
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

void imprimirFuncoes(Transicao t, Alfabeto a, Estado e) {
	int i, j;
	for (i = 0; i < t.numEstados; i++) {
		printf("\n |");
		if (i == e.estadoInicial)
			printf(" ->");
		else printf("  ");
		if (buscaSequencial(i, e.numEstadosFinais, e.estadosFinais) < e.numEstadosFinais) {
			if(i == e.estadoInicial)
				printf("*");
			else
				printf(" *");
		}
		else {
			if(i != e.estadoInicial)
				printf(" ");
		}
		if (i != e.estadoInicial &&
				buscaSequencial(i, e.numEstadosFinais, e.estadosFinais) >=
					e.numEstadosFinais)
			printf(" ");
		printf("%c%d  ",e.representacao, i);
		for (j = 0; j < a.numSimbolos; j++) {
			printf(" | %c%c",e.representacao, t.funcoes[j][i]);
		}
		printf(" |");
	}
}
