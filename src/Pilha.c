/*
 * Pilha.c
 *
 *  Created on: 06/11/2016
 *      Authors: 
 *				Hugo Dionizio Santos
 */

#include <stdlib.h>
#include "Pilha.h"

void empilhar(Pilha *p, char entrada) {
	CelulaPDA *celula, *aux;

	celula = (CelulaPDA *)malloc (sizeof(CelulaPDA));
	celula->entrada = entrada;

	if (p->topo < 1)
		p->celula = *celula;
	else {
		aux = (CelulaPDA *)malloc (sizeof(CelulaPDA));

		*aux = p->celula;
		p->celula = *celula;
		p->celula.prox = (CelulaPDA *)malloc (sizeof(CelulaPDA));
		p->celula.prox = (CelulaPDA *)aux;
	}
	p->topo++;
}

CelulaPDA desempilhar(Pilha *p) {
	CelulaPDA topo = p->celula;
	p->topo--;

	return topo;
}

CelulaPDA verTopo(Pilha p) {
	return p.celula;
}
