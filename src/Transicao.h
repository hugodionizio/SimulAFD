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
void definirFuncoes(Transicao *, Alfabeto);
void imprimirFuncoes(Transicao, Alfabeto);

#endif /* SRC_TRANSICAO_H_ */
