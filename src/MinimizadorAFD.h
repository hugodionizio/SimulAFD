/*
 * SimulAFD.h
 *
 *  Created on: 02/05/2015
 *      Author: ubuntu
 */

#ifndef SIMULAFD_H_
#define SIMULAFD_H_

#include <sys/stat.h>
#include <fcntl.h> /* necessario para flags */
#include <stdio.h> // Para as classes de arquivos
#include <stdlib.h> // Para cout <<
#include <string.h> // Para strcmp

#include "Automato.h"

struct Tabela {
	char **t;
};
typedef struct Tabela Tabela;


int terminal ();

// Funções de minimização
void construirTabela(Automato *, Tabela *);
void marcarEstadosObviamenteNaoEquivalentes(Automato *, Tabela *);
void marcarEstadosNaoEquivalentes(Automato *, Tabela *, int *);
void unificarEstadosEquivalentes(Automato *, int *, int*);
void excluirEstadosInuteis(Automato *);
bool minimizarAutomato(Automato *);

#endif /* SIMULAFD_H_ */
