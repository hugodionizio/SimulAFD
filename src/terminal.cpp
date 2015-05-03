#include <iostream>
using namespace std;

int terminal () {
	cout << "Trabalho da disciplina de Linguagens Formais e Autômatos" << endl;
	cout << "SimulAFD: Simulador de Autômatos Finitos Determinísticos (AFD)" << endl 

<< endl;
	
	cout << "Insira a quantidade de estados do Autômato: ";
	int i_qtEstados;
	cin >> i_qtEstados;

	char c_simbolo[2];
	cout << "Insira o primeiro símbolo do alfabeto: ";
	cin >> c_simbolo[0];
	cout << "Insira o segundo símbolo do alfabeto: ";
	cin >> c_simbolo[1];

	//criando a matriz
	int **i_funcoes = new int*[i_qtEstados];
	for (int i = 0; i < i_qtEstados; i++)
		i_funcoes[i] = new int[2];

	//zerando a matriz
	for (int i = 0; i < i_qtEstados; i++)
		for (int j = 0; j < 2; j++)
			i_funcoes[i][j] = 0;

	cout << "Insira as funções de transição do Autômato:" << endl;
	for (int i = 0; i < i_qtEstados; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "delta(q"<<i<<", "<< c_simbolo[j] <<") = q";
			cin >> i_funcoes[i][j];
		}
	}

	cout << "Qual o estado inicial do Autômato: q";
	int i_EstadoInicial;
	cin >> i_EstadoInicial;

	cout << "Insira a quantidade de estados de aceitação do Autômato: ";
	int i_qtEstadosAc;
	cin >> i_qtEstadosAc;
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
