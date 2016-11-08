/*
 * Alfabeto.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Alfabeto.h"

void criarAlfabeto(Alfabeto *a) {
	int i;
	a->numSimbolos = 3;

	a->simbolos = (char *)malloc(a->numSimbolos*sizeof(char));
	a->simbolos[0] = 'e';
	for (i = 1; i < a->numSimbolos; i++) {
			printf("Insira o %dº símbolo do alfabeto: ", (i));
			scanf(" %c", &a->simbolos[i]);
	}
}

void imprimirAlfabeto(Alfabeto a) {
	int i;
	for (i = 0; i < a.numSimbolos; i++)
			printf(" |  %c", a.simbolos[i]);
}
