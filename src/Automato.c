/*
 * Automato.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Automato.h"
#include <string.h>

void criarAutomato(Automato *aut) {
	// Dimensionando estados do Autômato
	criarEstado(&aut->e);

	// Definindo simbologia do Alfabeto
	criarAlfabeto(&aut->a);

	// Criação da Matriz de Funções de Transições
	criarFuncoes(&aut->t, aut->e, aut->a);

	// Inicialização da Matriz
	inicializarFuncoes(&aut->t);

	// Construção do Autômato
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

// Impressão
void imprimirAutomato(Automato aut) {

	//  Alfabeto e cabeçalho "estados"
	imprimirAlfabeto(aut.a);
	printf(" | estados \n");

	//  Funções de transição
	imprimirFuncoes(aut.t, aut.a);

	//  Estados Inicial e Finais
	imprimirEstadoInicial(aut.e);
	imprimirEstadosFinais(aut.e);
}
