/*
 * Estado.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Estado.h"

void criarEstadoTerminal(Estado *e) {
	printf("Informe a representação padrão dos estados: ");
	scanf(" %c", &e->representacao);

	printf("Informe a quantidade de estados do Autômato: ");
	scanf("%d", &e->numEstados);
	e->estados = (int *)malloc(e->numEstados*sizeof(int));

	inicializarEstado(e);
}

void inicializarEstado(Estado *e) {
	int i;

	for (i = 0; i < e->numEstados; ++i) {
		e->estados[i] = i;
	}
}

void selecionarEstadoInicialTerminal(Estado* e) {
	printf("Qual o estado inicial do Autômato: %c", e->representacao);
	scanf("%d", &e->estadoInicial);
}

void selecionarEstadosFinaisTerminal(Estado *e) {
	int i;
	printf("Insira a quantidade de estados de aceitação do Autômato: ");
	scanf("%d", &e->numEstadosFinais);
	e->estadosFinais = (int *)malloc(e->numEstadosFinais*sizeof(int));
	for (i = 0; i < e->numEstadosFinais; i++) {
		if (e->numEstadosFinais == 1) {
			printf ("Insira o estado de aceitação: %c", e->representacao);
			scanf ("%d", &e->estadosFinais[i]);
		} else {
			printf("Insira o %dº estado de aceitação: %c",i+1, e->representacao);
			scanf("%d", &e->estadosFinais[i]);
		}
	}
}

void imprimirEstados(Estado e) {
	int i;

	for (i = 0; i < e.numEstados; i++) {
		printf(" | %d ", e.estados[i]);
		printf("| Estado(s) totais do autômato");
	}
}

void imprimirEstadoInicial(Estado e) {
	printf("\n\n%c%d é o Estado Inicial.\n", e.representacao, e.estadoInicial);
}

void imprimirEstadosFinais(Estado e) {
	int i;

	printf("F = {");
	for (i = 0; i < e.numEstadosFinais; i++) {
		printf("%d", e.estadosFinais[i]);
		if(i+1 < e.numEstadosFinais)
			printf(", ");
	}
	//		printf("| Estado(s) de aceitação");
	printf("}.\n");
}
