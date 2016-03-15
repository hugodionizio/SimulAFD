//#include "SimulAFD.h"
#include <stdio.h>
#include "Automato.h"

int terminal () {
	char seq[80];
	int i, tam;
	
	Automato aut;
	criarAutomato(&aut);
	verificarAutomato(aut);

	printf("Informe a sequência de símbolos: ");
	scanf("%s", &seq);
	verificarSequencia(aut, seq);

	imprimirAutomato(aut);

	return 0;
}
