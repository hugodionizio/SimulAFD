//#include "SimulAFD.h"
#include <stdio.h>
#include "Automato.h"

int terminal () {
	//cout << "Trabalho da disciplina de Linguagens Formais e Autômatos" << endl;
	//cout << "SimulAFD: Simulador de Autômatos Finitos Determinísticos (AFD)" << endl

//<< endl;
	int numEstados;
	int numSimbolos = 2;
	char simbolos[numSimbolos];
	int **funcoes;
	int estadoInicial;
	int numEstadosFinais;
	int *estadosFinais;
	char seq[80];
	int i, j, tam;
	
	Automato aut;
	criarAutomato(&aut);
	imprimirAutomato(aut);

	// Dimensionando estados do Autômato
	printf("Insira a quantidade de estados do Autômato: ");
	scanf("%d", &numEstados);

	// Definindo simbologia do Alfabeto
	for (i = 0; i < numSimbolos; i++) {
		printf("Insira o %dº símbolo do alfabeto: ", (i+1));
		scanf("%d", &simbolos[i]);
	}

	// Criação da Matriz de Funções de Transições
	funcoes = (int **)malloc(numEstados);
	for (i = 0; i < numEstados; i++)
		funcoes[i] = (int *)malloc(2);

	// Inicialização da Matriz
	for (i = 0; i < numEstados; i++)
		for (j = 0; j < 2; j++)
			funcoes[i][j] = 0;

	// Construção do Autômato
	printf("Insira as funções de transição do Autômato:\n");
	for (i = 0; i < numEstados; i++) {
		for (j = 0; j < 2; j++) {
			printf("delta(q%d, %d) = q", i, simbolos[j]);
			scanf("%d", &funcoes[i][j]);
		}
	}

	printf("Qual o estado inicial do Autômato: q");
	scanf("%d", &estadoInicial);

	printf("Insira a quantidade de estados de aceitação do Autômato: ");
	scanf("%d", &numEstadosFinais);
	estadosFinais = (int *)malloc(numEstadosFinais);
	for (i = 0; i < numEstadosFinais; i++) {
		if (numEstadosFinais == 1) {
			printf ("Insira o estado de aceitação: q");
			scanf ("%d", &estadosFinais[i]);
		} else {
			printf("Insira o %dº estado de aceitação: q",i+1);
			scanf("%d", &estadosFinais[i]);
		}
	}

	printf("Informe a sequência de símbolos: ");
	scanf("%s", &seq);

	for(i = 0; i<80; i++) {
		if (seq[i] == '\0') {
			tam = i;
			break;
		}
	}

	if (seq[tam] == estadosFinais[numEstadosFinais])
		printf("O autômato é um AFD\n");
	else
		printf("O autômato não é um AFD\n");

	// Impressão
	//  Alfabeto e cabeçalho "estados"
	for (i = 0; i < 2; i++)
		printf(" |  %d", simbolos[i]);
	printf(" | estados \n");

	//  Funções de transição
	for (i = 0; i < numEstados; i++) {
		for (j = 0; j < 2; j++) {
			printf(" | q%d", funcoes[i][j]);
		}
		printf(" | q%d\n", i);
	}

	//  Estados Inicial e Finais
	printf("\nEstado Inicial q%d\n\n", estadoInicial);
	for (i = 0; i < numEstadosFinais; i++) {
		printf(" | %d ", estadosFinais[i]);
		printf("| Estado(s) de aceitação");
	}

	//  Liberação da memória de cada linha
	for (i = 0; i < numEstados; i++)
		free(funcoes[i]);
		
	//  Liberação da matriz da memória
	free(funcoes);
	
	return 0;
}
