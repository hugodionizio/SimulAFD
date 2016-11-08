/*
 * Fita.c
 *
 *  Created on: 07/11/2016
 *      Author: Hugo Dionizio Santos
 */

#include <string.h>
#include <stdlib.h>
#include "Fita.h"

void criarFita(Fita *fita, char *seq) {
	fita->tam = strlen(seq);
	fita->seq = (char *)malloc(fita->tam*sizeof(char));
	strcpy(fita->seq, seq);
}

char getSimboloFita(Fita fita) {

	return fita.seq[0];
}

void retiraDaFita(Fita *fita) {
	int i = 0, len = fita->tam;

	if (i+1 < len) {
		for (i = 0; i+1 < len; ++i) {
			fita[i] = fita[i+1];
		}
		fita->tam--;
	}
}

void limparFita(Fita *fita) {
	fita->tam = 0;
	free(fita->seq);
}
