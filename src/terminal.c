//#include "MinimizadorAFD.h"
#include <stdio.h>
#include "Automato.h"
#include "MinimizadorAFD.h"

int terminal () {
	char seq[80];
	int i, tam;
	
	Automato aut;
	criarAutomato(&aut);
	do {
		verificarAutomato(aut);

		if (aut.e.numEstados > 0) {
			imprimirAutomato(aut);

			if (minimizarAutomato(&aut)) {
				printf("Informe a sequência de símbolos: ");
				do {
					scanf("%s", &seq);
					verificarSequencia(aut, seq);

					imprimirAutomato(aut);
					printf("Informe outra sequência: ");
				} while (strlen(seq) > 0);

				printf("Criando novo autômato...\n");
				criarAutomato(&aut);
			}
		}
	} while (aut.e.numEstados > 0);

	return 0;
}
