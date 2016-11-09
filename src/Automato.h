/*
 * Automato.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_AUTOMATO_H_
#define SRC_AUTOMATO_H_

#include <math.h>
#include "Alfabeto.h"
#include "Estado.h"
#include "Pilha.h"
#include "Fita.h"
#include "Transicao.h"

// Estruturas de Dados
struct Automato {
	Alfabeto a;
	Alfabeto ap;
	Estado e; // Conjunto de Estados, Estado Inicial e Estados Finais
	Transicao t;
	Fita f;
	Pilha p;
};
typedef struct Automato Automato;

void criarAutomato(Automato *);
void executarPilha(Automato *, int, char);
bool verificarAutomato(Automato);
bool verificarSequencia(Automato *, char *);
void imprimirAutomato(Automato);

int buscaSequencial (int, int, int *);
int buscaSequencialStr (char, int, char *);

#endif /* SRC_AUTOMATO_H_ */
