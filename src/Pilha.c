/*
 * Pilha.c
 *
 *  Created on: 06/11/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void criarPilha(Pilha *p) {
	p->topo = 0;
	p->celula = *(CelulaPDA *)malloc(sizeof(CelulaPDA));
}

void empilhar(Pilha *p, char entrada) {
	CelulaPDA *celula, *aux;

	celula = (CelulaPDA *)malloc (sizeof(CelulaPDA));
	celula->entrada = entrada;

	if (p->topo < 1)
		p->celula = *celula;
	else {
		aux = (CelulaPDA *)malloc(sizeof(CelulaPDA));

		*aux = p->celula;
		p->celula = *celula;
		p->celula.prox = (CelulaPDA *)malloc(sizeof(CelulaPDA));
		p->celula.prox = (CelulaPDA *)aux;
	}
	p->topo++;
}

void desempilhar(Pilha *p) {
	CelulaPDA *aux;

	if (p != NULL) {
		aux = (CelulaPDA *)malloc(sizeof(CelulaPDA));

		aux = (CelulaPDA *)p->celula.prox;
	//	p->celula = //(CelulaPDA *)p->celula->prox;
		free(aux);

		p->topo--;
	}
	else {
		printf("Pilha vazia.");
	}
}

void esvaziarPilha(Pilha *p) {
	while(p->topo > 0)
		desempilhar(p);
}

CelulaPDA verTopo(Pilha p) {
	return p.celula;
}
