/*
 * Fita.c
 *
 *  Created on: 07/11/2016
 *      Author: Hugo Dionizio Santos
 */

#include "Fita.h"

char getSimboloFita(Fita fita) {

	return fita.seq[0];
}

void retiraDaFita(Fita *fita) {
	int i, len = fita->tam;

	if (i+1 < len) {
		for (i = 0; i+1 < len; ++i) {
			fita[i] = fita[i+1];
		}
		fita->tam--;
	}
}
