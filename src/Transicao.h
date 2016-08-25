/*
 * Transicao.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_TRANSICAO_H_
#define SRC_TRANSICAO_H_

#include "Alfabeto.h"
#include "Estado.h"

struct Transicao {
	int numSimbolos;
	int numEstados;

	int **funcoes;
};
typedef struct Transicao Transicao;

void criarFuncoes(Transicao *, Estado, Alfabeto);
void inicializarFuncoes(Transicao *);
void definirFuncoes(Transicao *, Estado, Alfabeto);
void liberarFuncoes(Transicao *);
void imprimirFuncoes(Transicao, Alfabeto, Estado);

#endif /* SRC_TRANSICAO_H_ */
