/*
 * Estado.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_ESTADO_H_
#define SRC_ESTADO_H_

#include "Pilha.h"

struct Estado {
	int numEstados;
	int *estados;

	char representacao;
	int estadoInicial;

	int numEstadosFinais;
	int *estadosFinais;

	int numEstadosEmpilhar;
	int *estadosEmpilhar;

	int numEstadosDesempilhar;
	int *estadosDesempilhar;
};
typedef struct Estado Estado;

void criarEstadoTerminal(Estado *);
void inicializarEstado(Estado *);
void selecionarEstadoInicialTerminal(Estado *);
void selecionarEstadosFinaisTerminal(Estado *);
void selecionarEstadosEmpilhar(Estado *);
void selecionarEstadosDesempilhar(Estado *);
void imprimirEstados(Estado e);
void imprimirEstadoInicial(Estado);
void imprimirEstadosFinais(Estado);
void imprimirEstadosEmpilham(Estado);
void imprimirEstadosDesempilham(Estado);

#endif /* SRC_ESTADO_H_ */
