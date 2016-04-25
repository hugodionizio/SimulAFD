/*
 * Minimizacao.c
 *
 *  Created on: 22/04/2016
 *      Author: hugo
 */

#include <stdio.h>
#include "Automato.h"

// Uma conseqüência do teste de equivalência é que podemos encontrar AFD’s <<equivalentes>> que contenham um <<número mínimo de estados>>.
bool equilvalenciaAutomatos(Automato a, Automato b) {
	printf("Testando equivalência de dois autômatos...\n");

	return true;
}

// * Não pode ter estados inacessíveis;
bool temEstadosInacessiveis(Automato automato) {
	printf("Verificando estados inacessíveis...\n");

	return true;
}

// * (delta) deve ser total.
bool deltaTotal(Automato automato) {
	printf("Verificando se delta é total...\n");

	return true;
}

// Um autômato finito, para ser minimizado, precisa satisfazer os seguintes pré-requisitos:
bool verificarAFD(Automato automato) {
	bool result;
	printf("Verificando se o autômato é um AFD...\n");

	if (verificarAutomato(automato) 	// * Precisa ser um AFD;
	&& temEstadosInacessiveis(automato) && deltaTotal(automato)) {
		result = true;
	} else
		result = false;

	return result;
}

// * Efetuar conversão de AFNs para AFD;
void converterAFN_AFD(Automato *automato) {
	printf("Convertendo AFN em AFD...\n");

}

// * Eliminar os estados inacessíveis e suas correspondentes transições;
void eliminarEstadosInacessiveis(Automato *automato) {
	printf("Eliminando Estados Inacessíveis...\n");

}

// * Transformar d em total, introduzindo um estado de morte e incluindo as transições não previstas para este estado.
void transformarDeltaParaTotal(Automato *automato) {
	printf("Transformando delta em total...\n");

}

// Caso o autômato não satisfaça a alguns dos pré-requisitos, é necessário gerar um autômato equivalente:
void gerarAutomatoEquivalente(Automato *automato) {
	printf("Gerando Autômato Equivalente...\n");

	converterAFN_AFD(automato);
	eliminarEstadosInacessiveis(automato);
	transformarDeltaParaTotal(automato);
}

struct Tabela {
	char **t;
};
typedef struct Tabela Tabela;

// Função principal de Minimização de Autômatos
bool minimizarAutomato(Automato *automato) {
	printf("Minimizando autômato...\n");
//	char **tabela;
	int *lista_q[2];
	int *listaParesNaoFinais[2];
	int *listaParesFinais[2];
	Tabela tabela;

	if (verificarAFD(*automato) == true) {
		printf("O autômato é um AFD, pronto para ser minimizado.\n");
	} else {
		gerarAutomatoEquivalente(automato);
	}

	// Algoritmo de Preenchimento de Tabela
	construirTabela(automato, &tabela);
	marcarEstadosObviamenteNaoEquivalentes(automato, &tabela);
	marcarEstadosNaoEquivalentes(automato, &tabela, lista_q);
	unificarEstadosEquivalentes(automato, listaParesNaoFinais,
			listaParesFinais);
	excluirEstadosInuteis(automato);

	return true;
}

// * ALGORITMO DE PREENCHIMENTO DE TABELA
// 1. Construir uma tabela relacionando estados diferentes, onde cada par de estados ocorre somente uma vez;
void construirTabela(Automato *automato, Tabela *tabela) {

	int count, count2;

	printf("Construindo tabela...\n");
//	tabela = (char **) malloc(automato->e.numEstados * sizeof(char*));
	tabela->t = (char **) malloc(automato->e.numEstados * sizeof(char*));

	for (count = 0; count < automato->e.numEstados; count++) {
		tabela->t[count] = (char *) malloc(automato->e.numEstados * sizeof(char));
	}

	for (count = 0; count < automato->e.numEstados; count++) {
		for (count2 = 0; count2 < automato->e.numEstados; count2++) {
			tabela->t[count2][count] = ' ';
		}
	}
}

bool eEstadoFinal(int x, Estado e) {
	if (buscaSequencial(x, e.numEstadosFinais,
			e.estadosFinais) < e.numEstadosFinais)
		return true;
	else
		return false;
}

void imprimirTabela(Automato automato, Tabela tabela) {
	int count, count2;

	for (count = 0; count < automato.e.numEstados; count++) {
		for (count2 = 0; count2 < automato.e.numEstados; count2++) {
			if (count == 0) {
				printf("%c%d", automato.e.representacao, count2);
			}
			else {
				printf("%c", tabela.t[count2][count]);
			}

			if (count2 + 1 < automato.e.numEstados)
				printf("\t");
			else {
				printf("\n");
			}
		}
	}
}

// 2. Marcar estados obviamente não equivalentes: <<marcar pares de estados finais com estados não finais>>;
void marcarEstadosObviamenteNaoEquivalentes(Automato *automato,
		Tabela *estadoObvNaoEquivalentes) {
	int count, count2;
	bool estadoFinal, estadoNaoFinal;

	printf("Marcando estados obviamente não equivalentes...\n");

	for (count = 0; count < automato->e.numEstados; count++) {
		for (count2 = 0; count2 < automato->e.numEstados; count2++) {
			if (eEstadoFinal(count, automato->e) != eEstadoFinal(count2, automato->e))
				estadoObvNaoEquivalentes->t[count2][count] = 'X';
			else if (count == count2)
				break;
		}
	}

	imprimirTabela(*automato, *estadoObvNaoEquivalentes);
}

bool estaMarcado(Automato *automato, Tabela *estadoObvNaoEquivalentes,
		int *lista[2], int p, int pl) {
	int i, j;

	printf("Verificando se o par {p, p'} está marcado...\n");

	if (estadoObvNaoEquivalentes->t[p][pl] == "X")
		return true;
	else
		return false;
}

void marcar(int *lista[2], int q, int ql) {
	printf("Incluindo par {q, q'} em uma lista...\n");

}

bool encabeca(int *lista_q[2], int q, int ql) {
	printf("Verificando se o par {q, q'} encabeça a lista...\n");

	return true;
}

// 3. Marcar estados não equivalentes. Para cada par {q, q’} e para cada símbolo 'a' pertencente a um alfabeto (Sigma), suponha que delta(q, a) = p e delta(q’, a) = p’ e:
void marcarEstadosNaoEquivalentes(Automato *automato, Tabela *tabela,
		int *lista_q[2]) {
	int p, pl;
	int *q, *ql;
	int a;

	printf("Marcando Estados Não Equivalentes...\n");

	// a) Se <<p = p’>>, então <<q é equivalente a q’ para a e não deve ser marcado>>;
	if (p == pl) {
	}

	// b) Se <<p != p’>> e o par <<{p, p’} não está marcado>>, então {q, q’} é incluído em uma lista para posterior análise;
	if (p != pl && !estaMarcado(automato, tabela, *lista_q, p, pl)) {
		lista_q[p][pl] = 1;
	}

	// c) Se <<p != p’>> e o par <<{p, p’} está marcado>>:
	if (p != p && estaMarcado(automato, tabela, *lista_q, p, pl)) {
		// * {q, q’} não é equivalente e deve ser marcado;
		marcar(&lista_q, q, ql);

		// * Se {q,q’} encabeça uma lista de pares, então marcar todos os pares da lista.
		if (encabeca(lista_q, q, ql)) {
			marcarTodosPares(&lista_q);
		}
	}
}

// * A equivalência é transitiva;
bool eEquivalenciaTransitiva(int p, int pl) {
	printf("Verificando se Equivalência é transitiva...\n");

	return true;
}

// * <<Pares de estados não finais>> equivalentes podem ser unificados como <<um único estado não final>>;
bool podeUnificarParesNaoFinais(int *listaParesNaoFinais) {
	printf(
			"Verificando se pares de estados <<não>> finais podem ser unificados é um único...\n");

	return true;
}

// * <<Pares de estados finais>> equivalentes podem ser unificados como <<um único estado final>>;
bool podeUnificarParesFinais(int *listaParesFinais) {
	printf(
			"Verificando se pares de estados finais podem ser unificados é um único...\n");

	return true;
}

// * Se algum dos estados equivalentes é inicial, então o correspondente estado unificado é inicial.
bool algumEstadoEquivalenteInicial(int *listaParesNaoFinais,
		int *listaParesFinais) {
	printf("Verificando se algum dos estados é inicial...\n");

	return true;
}

// 4. Unificar os estados equivalentes. <<Os estados dos pares não marcados são equivalentes>> e podem ser unificados como segue:
void unificarEstadosEquivalentes(Automato *automato,
		int *listaParesNaoFinais[2], int *listaParesFinais[2]) {
	int p, pl;

	printf("Unificando estados equivalentes...\n");

	if (eEquivalenciaTransitiva(p, pl)
			&& podeUnificarParesNaoFinais(&listaParesNaoFinais)
			&& podeUnificarParesFinais(&listaParesFinais)
			&& algumEstadoEquivalenteInicial(listaParesNaoFinais,
					listaParesFinais)) {
	}
}

// 5. Excluir estados inúteis. Um estado q é inútil se é não final e a partir de q não é possível atingir um estado final.
// * O estado de morte é sempre inútil.
void excluirEstadosInuteis(Automato *automato) {
	printf("Excluindo estados inúteis...\n");

}
