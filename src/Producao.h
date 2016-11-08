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
	int numEstados;

	int **producoes;
};
typedef struct Producao Producao;

void criarFuncoes(Producao *, Estado, Alfabeto);
void inicializarFuncoes(Producao *);
void definirFuncoes(Producao *, Estado, Alfabeto);
void liberarFuncoes(Producao *);
Producao getProducao(Producao *, int);
void imprimirFuncoes(Producao, Alfabeto, Estado);

#endif /* SRC_PRODUCAO_H_ */
