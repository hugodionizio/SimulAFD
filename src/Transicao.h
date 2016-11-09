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

struct Producao {
	int numSimbolos;
	int numSimbolosPilha;
	int numEstados;

	int **funcoes;
};
typedef struct Producao Transicao;

void criarTransicoes(Transicao *, Estado, Alfabeto);
void inicializarTransicoes(Transicao *);
void definirTransicoes(Transicao *, Estado, Alfabeto, Alfabeto);
void liberarTransicoes(Transicao *);
Transicao getTransicao(Transicao *, int);
int buscaSequencial (int, int, int *);
int buscaSequencialStr (char, int, char *);
void imprimirTransicoes(Transicao, Alfabeto, Estado);

#endif /* SRC_TRANSICAO_H_ */
