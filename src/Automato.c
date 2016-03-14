/*
 * Automato.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Automato.h"
#include <string.h>

void criarAutomato(Automato *aut) {
	criarEstado(&aut->e);
	criarAlfabeto(&aut->a);
	criarFuncoes(&aut->t, aut->e, aut->a);
	inicializarFuncoes(&aut->t);
	definirFuncoes(&aut->t, aut->a);
	selecionarEstadoInicial(&aut->e);
	selecionarEstadosFinais(&aut->e);
}

void verificarSequencia(Automato aut, char *seq) {
	int tam = strlen(seq);

	if (seq[tam] == aut.e.estadosFinais[aut.e.numEstadosFinais])
		printf("O autômato é um AFD\n");
	else
		printf("O autômato não é um AFD\n");
}

void imprimirAutomato(Automato aut) {
	imprimirAlfabeto(aut.a);
	printf(" | estados \n");
	imprimirFuncoes(aut.t, aut.a);
	imprimirEstadoInicial(aut.e);
	imprimirEstadosFinais(aut.e);
}
