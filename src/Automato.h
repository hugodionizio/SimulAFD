/*
 * Automato.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_AUTOMATO_H_
#define SRC_AUTOMATO_H_

#include "Alfabeto.h"
#include "Estado.h"
#include "Transicao.h"

struct Automato {
	Alfabeto a;
	Estado e; // Conjunto de Estados, Estado Inicial e Estados Finais
	Transicao t;
};
typedef struct Automato Automato;

void criarAutomato(Automato *);
void verificarAutomato(Automato);
void verificarSequencia(Automato, char *);
void imprimirAutomato(Automato);

int buscaSequencial (int, int, int *);

#endif /* SRC_AUTOMATO_H_ */
