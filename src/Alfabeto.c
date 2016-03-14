/*
 * Alfabeto.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Alfabeto.h"

void criarAlfabeto(Alfabeto *a) {
	int i;

	a->simbolos = (int *)malloc(2);
	for (i = 0; i < a->numSimbolos; i++) {
			printf("Insira o %dº símbolo do alfabeto: ", (i+1));
			scanf("%d", &a->simbolos[i]);
	}
}

void imprimirAlfabeto(Alfabeto a) {
	int i;
	for (i = 0; i < a.numSimbolos; i++)
			printf(" |  %d", a.simbolos[i]);
}
