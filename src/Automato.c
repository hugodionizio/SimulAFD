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
	criarEstadoTerminal(&aut->e);

	if (aut->e.numEstados > 0) {
		// Definindo simbologia do Alfabeto
		criarAlfabeto(&aut->a);

		// Criação da Matriz de Funções de Produções
		criarFuncoes(&aut->t, aut->e, aut->a);

		// Inicialização da Matriz
		inicializarFuncoes(&aut->t);

		// Construção do Autômatofor
		definirFuncoes(&aut->t, aut->e, aut->a);
		selecionarEstadoInicialTerminal(&aut->e);
		selecionarEstadosFinaisTerminal(&aut->e);
	}
}

bool verificarAutomato(Automato aut) {
	int i, j, topo, count = 0;
	int *estadosVerificados;

	estadosVerificados = (int *)malloc(aut.e.numEstados*sizeof(int));

	for (i = 0; i < aut.e.numEstados; ++i) {
		estadosVerificados[i] = -1;
	}

	estadosVerificados[0] = aut.e.estadoInicial;
	topo = 0;
	i = estadosVerificados[0];
	while(topo < aut.e.numEstados && count < pow((double)2, (double)aut.e.numEstados)) {
		for (j = 0; j < aut.a.numSimbolos; ++j) {
			if(aut.t.producoes[j][i] != i) {
				i = aut.t.producoes[j][i];

				if(buscaSequencial(i, aut.e.numEstados, estadosVerificados) == aut.e.numEstados) {
					estadosVerificados[topo+1] = i;
					topo++;
				}
			}
			count++;
		}
	}

	if (topo < aut.e.numEstados) {
		printf("O autômato é um AFD\n");
		return true;
	}
	else {
		printf("O autômato não é um AFD\n");
		return false;
	}
}

bool verificarSequencia(Automato aut, char *seq) {
	bool result = false;

	int i, j = aut.e.estadoInicial, s, pos;
	int tam = strlen(seq);

	for(s = 0; s < tam; s++) {
		pos = buscaSequencialStr(seq[s], aut.a.numSimbolos, aut.a.simbolos);
		if (pos < aut.a.numSimbolos) {
			j = aut.t.producoes[pos][j];
		}
		else {
			printf("Símbolo na sequência não encontrado.\n");
			j = -1;
			break;
		}
	}

/*
	for (i = 0; i < tam; ++i) {
		j = aut.t.funcoes[j][seq[i]];
	}
*/
	if (buscaSequencial(j, aut.e.numEstadosFinais, aut.e.estadosFinais) < aut.e.numEstadosFinais) {
		printf("Essa sequência pertence ao AFD.\n");
		result = true;
	}
	else {
		printf("Essa sequência não pertence ao AFD.\n");
		result = false;
	}

	return result;
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
