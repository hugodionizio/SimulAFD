//#include "SimulAFD.h"
#include <stdio.h>
#include "Automato.h"

#define null NULL

int terminal () {
	char seq[80];
	
	Automato aut;
	criarAutomato(&aut);
	verificarAutomato(aut);

	imprimirAutomato(aut);

	printf("Informe a sequência de símbolos: ");
	scanf("%s", (char *)&seq);
	do {
		verificarSequencia(&aut, seq);
		printf("Informe a sequência de símbolos: ");
		scanf("%s", (char *)&seq);
	} while (seq != 0);

	return 0;
}
