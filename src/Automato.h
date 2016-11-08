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
#include "Producao.h"

// Estruturas de Dados
# ifndef __cplusplus
// Lógico
enum bool {
	false,
	true
};
typedef enum bool bool;
#endif

struct Automato {
	Alfabeto a;
	Estado e; // Conjunto de Estados, Estado Inicial e Estados Finais
	Producao t;
	Fita f;
	Pilha p;
};
typedef struct Automato Automato;

void criarAutomato(Automato *);
bool verificarAutomato(Automato);
bool verificarSequencia(Automato *, char *);
void imprimirAutomato(Automato);

int buscaSequencial (int, int, int *);
int buscaSequencialStr (char, int, char *);

#endif /* SRC_AUTOMATO_H_ */
