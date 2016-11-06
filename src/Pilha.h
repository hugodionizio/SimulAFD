/*
 * Pilha.h
 *
 *  Created on: 06/11/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */
#ifndef SRC_PILHA_H_
#define SRC_PILHA_H_

typedef struct CelulaPDA {
	char entrada;
	char saida;

	struct CelulaPDA *prox;
} CelulaPDA;

typedef struct Pilha {
	int topo;

	CelulaPDA celula;
} Pilha;

void empilhar(Pilha *, char);
CelulaPDA desempilhar(Pilha *);
CelulaPDA verTopo(Pilha);

#endif /* SRC_PILHA_H_ */
