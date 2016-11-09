/*
 * Automato.c
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#include "Automato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void criarAutomato(Automato *aut) {
	// Dimensionando estados do Autômato
	criarEstadoTerminal(&aut->e);

	if (aut->e.numEstados > 0) {
		// Definindo simbologia do Alfabeto
		criarAlfabeto(&aut->a, false);

		// Definindo simbologia do Alfabeto da pilha
		criarAlfabeto(&aut->ap, true);

		// Criação da Matriz de Produções
		criarTransicoes(&aut->t, aut->e, aut->a);

		// Inicialização da Matriz
		inicializarTransicoes(&aut->t);

		// Construção do Autômato
		selecionarEstadoInicialTerminal(&aut->e);
		selecionarEstadosFinaisTerminal(&aut->e);
		selecionarEstadosEmpilhar(&aut->e);
		selecionarEstadosDesempilhar(&aut->e);
		definirTransicoes(&aut->t, aut->e, aut->a, aut->ap);
	}
}

void executarPilha(Automato *aut, int estado, char simbolo) {
	if(buscaSequencial(estado, aut->e.numEstadosDesempilhar, aut->e.estadosDesempilhar) < aut->e.numEstadosDesempilhar) {
		if (simbolo == (verTopo(aut->p)).entrada)
			desempilhar(&aut->p);
	}
	else if (buscaSequencial(estado, aut->e.numEstadosEmpilhar, aut->e.estadosEmpilhar) < aut->e.numEstadosEmpilhar) {
		empilhar(&aut->p, simbolo);
	}
}

bool verificarAutomato(Automato aut) {
	int i, j, topo, count = 0;
	int* estadosVerificados;
	estadosVerificados = (int*) malloc(aut.e.numEstados * sizeof(int));
	for (i = 0; i < aut.e.numEstados; ++i) {
		estadosVerificados[i] = -1;
	}
	estadosVerificados[0] = aut.e.estadoInicial;
	topo = 0;
	i = estadosVerificados[0];
	while (topo < aut.e.numEstados
			&& count < pow((double) 2, (double) aut.e.numEstados)) {
		for (j = 0; j < aut.a.numSimbolos; ++j) {
			if (aut.t.funcoes[i][j] != i) {
				i = aut.t.funcoes[i][j];
				if (buscaSequencial(i, aut.e.numEstados, estadosVerificados)
						== aut.e.numEstados) {
					estadosVerificados[topo + 1] = i;
					topo++;
				}
			}
			count++;
		}
	}
	if (topo < aut.e.numEstados) {
		printf("O autômato é um PDA\n");
		return true;
	} else {
		printf("O autômato não é um PDA\n");
		return false;
	}
}

bool verificarSequencia(Automato *aut, char *seq) {
	bool result = false;
	CelulaPDA *aux;

	int j = aut->e.estadoInicial, s, pos;
	int tam = strlen(seq);

	criarFita(&aut->f, seq);

	for(s = 0; s < tam; s++) {
		pos = buscaSequencialStr(aut->f.seq[s], aut->a.numSimbolos, aut->a.simbolos);
		if (pos < (int)aut->a.numSimbolos) {
			j = aut->t.funcoes[j][pos];
			executarPilha(&aut->p, j, aut->f.seq[s]);
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
	aux = (CelulaPDA *)malloc(sizeof(CelulaPDA *));
	*aux = verTopo(aut->p);
	if (buscaSequencial(j, aut->e.numEstadosFinais, aut->e.estadosFinais) < aut->e.numEstadosFinais ||
			aux == NULL) {
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
	imprimirTransicoes(aut.t, aut.a, aut.e);

	//  Estados Inicial e Finais
	imprimirEstadoInicial(aut.e);
	imprimirEstadosFinais(aut.e);
}
