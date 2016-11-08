/*
 * Alfabeto.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include "Alfabeto.h"

void criarAlfabeto(Alfabeto *a, bool pilha) {
	int i;
	char daPilha[] = " da Pilha: ";
	a->numSimbolos = 3;

	a->simbolos = (char *)malloc(a->numSimbolos*sizeof(char));
	if(!pilha) {
		a->simbolos[0] = 'e';
		strcpy(daPilha, ": q");
	}
	else {
		a->simbolos[0] = 'Z';
	}
	for (i = 1; i < a->numSimbolos; i++) {
			printf("Insira o %dº símbolo do alfabeto%s", (i), daPilha);
			scanf(" %c", &a->simbolos[i]);
	}
}

void imprimirAlfabeto(Alfabeto a) {
	int i;
	for (i = 0; i < a.numSimbolos; i++)
			printf(" |  %c", a.simbolos[i]);
}
