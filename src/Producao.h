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

struct Transicao {
	int numSimbolos;
	int numEstados;

	int **funcoes;
};
typedef struct Transicao Producao;

void criarFuncoes(Producao *, Estado, Alfabeto);
void inicializarFuncoes(Producao *);
void definirFuncoes(Producao *, Estado, Alfabeto);
void liberarFuncoes(Producao *);
void imprimirFuncoes(Producao, Alfabeto, Estado);

#endif /* SRC_PRODUCAO_H_ */
