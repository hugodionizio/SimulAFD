/*
 * Automato.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Automato.h"
#include <string.h>
#include <math.h>

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

void verificarAutomato(Automato aut) {
	int i, j, topo, count = 0;
	int *estadosVerificados;

	estadosVerificados = (int *)malloc(aut.e.numEstados);

	for (i = 0; i < aut.e.numEstados; ++i) {
		estadosVerificados[i] = -1;
	}

	estadosVerificados[0] = aut.e.estadoInicial;
	topo = 0;
	i = estadosVerificados[0];
	while(topo < aut.e.numEstados && count < pow((double)2, (double)aut.e.numEstados)) {
		for (j = 0; j < aut.a.numSimbolos; ++j) {
			if(aut.t.funcoes[i][j] != i) {
				i = aut.t.funcoes[i][j];

				if(buscaSequencial(i, aut.e.numEstados, estadosVerificados) == aut.e.numEstados) {
					estadosVerificados[topo+1] = i;
					topo++;
				}
			}
			count++;
		}
	}

	if (topo < aut.e.numEstados)
		printf("O autômato é um AFD\n");
	else
		printf("O autômato não é um AFD\n");

}

void verificarSequencia(Automato aut, char *seq) {
	int i, j = aut.e.estadoInicial;
	int tam = strlen(seq);

	for (i = 0; i < tam; ++i) {
		j = aut.t.funcoes[j][seq[i]];
	}

	if (buscaSequencial(j, aut.e.numEstadosFinais, aut.e.estadosFinais) >= aut.e.numEstadosFinais)
		printf("Essa sequência pertence ao AFD.\n");
	else
		printf("Essa sequência não pertence ao AFD.\n");
}

// Impressão
void imprimirAutomato(Automato aut) {

	//  Alfabeto e cabeçalho "estados"
	printf(" | estados");
	imprimirAlfabeto(aut.a);
	printf(" |");

	//  Funções de transição
	imprimirFuncoes(aut.t, aut.a, aut.e);

	//  Estados Inicial e Finais
	imprimirEstadoInicial(aut.e);
	imprimirEstadosFinais(aut.e);
}
