/*
 * Estado.h
 *
 *  Created on: 13/03/2016
 *      Author: hugo
 */

#ifndef SRC_ESTADO_H_
#define SRC_ESTADO_H_

struct Estado {
	int numEstados;
	int *estados;

	char representacao;
	int estadoInicial;
	int numEstadosFinais;
	int *estadosFinais;
};
typedef struct Estado Estado;

void criarEstadoTerminal(Estado *);
void inicializarEstado(Estado *);
void selecionarEstadoInicialTerminal(Estado *);
void selecionarEstadosFinaisTerminal(Estado *);
void imprimirEstados(Estado e);
void imprimirEstadoInicial(Estado e);
void imprimirEstadosFinais(Estado e);

#endif /* SRC_ESTADO_H_ */
