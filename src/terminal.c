//#include "SimulAFD.h"
#include <stdio.h>

int terminal () {
	//cout << "Trabalho da disciplina de Linguagens Formais e Autômatos" << endl;
	//cout << "SimulAFD: Simulador de Autômatos Finitos Determinísticos (AFD)" << endl

//<< endl;
	int i_qtEstados;
	char c_simbolo[2];
	int **i_funcoes;
	int i_EstadoInicial;
	int i_qtEstadosAc;
	int *i_EstadosAc;
	int i;
	
	printf("Insira a quantidade de estados do Autômato: ");
	scanf("%d", &i_qtEstados);

	for (i = 0; i<2; i++) {
		printf("Insira o %dº símbolo do alfabeto: ", i);
		scanf("%d", &c_simbolo[i]);
	}

	// Criação da Matriz
	i_funcoes = (int **)malloc(i_qtEstados);
	for (int i = 0; i < i_qtEstados; i++)
		i_funcoes[i] = (int *)malloc(2);

	// Inicialização da Matriz
	for (int i = 0; i < i_qtEstados; i++)
		for (int j = 0; j < 2; j++)
			i_funcoes[i][j] = 0;

	printf("Insira as funções de transição do Autômato:"\n);
	for (int i = 0; i < i_qtEstados; i++) {
		for (int j = 0; j < 2; j++) {
			printf("delta(q%d, %d) = q", i, c_simbolo[j]);
			scanf("%d", &i_funcoes[i][j]);
		}
	}

	printf("Qual o estado inicial do Autômato: q");
	scanf("%d", i_EstadoInicial);

	printf("Insira a quantidade de estados de aceitação do Autômato: ");
	scanf("%d", &i_qtEstadosAc);
	int i_EstadosAc[i_qtEstadosAc];
	for (int i = 0; i < i_qtEstadosAc; i++) {
		if (i_qtEstadosAc == 1) {
			cout << "Insira o estado de aceitação: q";
			cin >> i_EstadosAc[i];
		} else {
			cout << "Insira o "<<i+1<<"º estado de aceitação: q";
			cin >> i_EstadosAc[i];
		}
	}

	//imprime
	for (int i = 0; i < 2; i++)
		cout << " |  " << c_simbolo[i];
	cout << " | estados " << endl;

	for (int i = 0; i < i_qtEstados; i++) {
		for (int j = 0; j < 2; j++) {
			cout << " | q" << i_funcoes[i][j];
		}
		cout << " | q"<<i<< endl;
	}
	cout << endl << "Estado Inicial q" << i_EstadoInicial << endl << endl;
	for (int i = 0; i < i_qtEstadosAc; i++) 
		cout << " | " << i_EstadosAc[i];
	cout << " | Estado(s) de aceitação"<< endl;

	//liberar memoria da linha
	for (int i = 0; i < i_qtEstados; i++)
		delete []i_funcoes[i];
	//liberar memoria da matriz
	delete []i_funcoes;
	return 0;
}
