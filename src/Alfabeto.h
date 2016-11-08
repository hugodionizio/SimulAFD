/*
 * Alfabeto.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_ALFABETO_H_
#define SRC_ALFABETO_H_

# ifndef __cplusplus
// Lógico
enum bool {
	false,
	true
};
typedef enum bool bool;
#endif

struct Alfabeto {
	int numSimbolos;

	char *simbolos;
};
typedef struct Alfabeto Alfabeto;

void criarAlfabeto(Alfabeto *, bool);
void imprimirAlfabeto(Alfabeto);

#endif /* SRC_ALFABETO_H_ */
