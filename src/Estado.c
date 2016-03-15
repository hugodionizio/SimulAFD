/*
 * Estado.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Estado.h"

void criarEstado(Estado *e) {
	printf("Insira a quantidade de estados do Autômato: ");
	scanf("%d", &e->numEstados);
}

void selecionarEstadoInicial(Estado *e) {
	printf("Qual o estado inicial do Autômato: q");
	scanf("%d", &e->estadoInicial);
}

void selecionarEstadosFinais(Estado *e) {
	int i;
	printf("Insira a quantidade de estados de aceitação do Autômato: ");
	scanf("%d", &e->numEstadosFinais);
	e->estadosFinais = (int *)malloc(e->numEstadosFinais);
	for (i = 0; i < e->numEstadosFinais; i++) {
		if (e->numEstadosFinais == 1) {
			printf ("Insira o estado de aceitação: q");
			scanf ("%d", &e->estadosFinais[i]);
		} else {
			printf("Insira o %dº estado de aceitação: q",i+1);
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
	printf("\n\nq%d é o Estado Inicial.\n", e.estadoInicial);
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
	printf("}.");
}
