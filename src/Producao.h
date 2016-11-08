/*
 * Producao.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_PRODUCAO_H_
#define SRC_PRODUCAO_H_

#include "Alfabeto.h"
#include "Estado.h"

struct Producao {
	int numSimbolos;
	int numSimbolosPilha;
	int numEstados;

	int ***producoes;
};
typedef struct Producao Producao;

void criarProducoes(Producao *, Estado, Alfabeto);
void inicializarProducoes(Producao *);
void definirProducoes(Producao *, Estado, Alfabeto, Alfabeto);
void liberarProducoes(Producao *);
Producao getProducao(Producao *, int);
int buscaSequencial (int, int, int *);
int buscaSequencialStr (char, int, char *);
void imprimirProducoes(Producao, Alfabeto, Estado);

#endif /* SRC_PRODUCAO_H_ */
