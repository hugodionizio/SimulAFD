/*
 * Alfabeto.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_ALFABETO_H_
#define SRC_ALFABETO_H_

struct Alfabeto {
	int numSimbolos;

	char *simbolos;
};
typedef struct Alfabeto Alfabeto;

void criarAlfabeto(Alfabeto *);
void imprimirAlfabeto(Alfabeto);

#endif /* SRC_ALFABETO_H_ */
