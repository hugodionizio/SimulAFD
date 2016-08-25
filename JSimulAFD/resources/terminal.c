//#include "SimulAFD.h"
#include <stdio.h>
#include "Automato.h"

#define null NULL

int terminal () {
	char seq[80];
	int i, tam;
	
	Automato aut;
	criarAutomato(&aut);
	verificarAutomato(aut);

	imprimirAutomato(aut);

	printf("Informe a sequência de símbolos: ");
	scanf("%s", &seq);
	do {
		verificarSequencia(aut, seq);
		printf("Informe a sequência de símbolos: ");
		scanf("%s", &seq);
	} while (seq != 0);

	return 0;
}
