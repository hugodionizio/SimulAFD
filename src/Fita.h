/*
 * Fita.h
 *
 *  Created on: 07/11/2016
 *      Author: Hugo Dionizio Santos
 */

#ifndef FITA_H_
#define FITA_H_

typedef struct Fita {
	int tam;

	char *seq;
} Fita;

void criarFita(Fita *, char *);
char getSimboloFita(Fita);
void retiraDaFita(Fita *);

#endif /* FITA_H_ */
