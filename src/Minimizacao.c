/*
 * Minimizacao.c
 *
 *  Created on: 22/04/2016
 *      Author: hugo
 */

#include "Automato.h"

// Uma conseqüência do teste de equivalência é que podemos encontrar AFD’s <<equivalentes>> que contenham um <<número mínimo de estados>>.
bool equilvalenciaAutomatos(Automato a, Automato b) {

	return true;
}

// * Não pode ter estados inacessíveis;
bool temEstadosInacessiveis( automato) {

	return true;
}

// * (delta) deve ser total.
bool deltaTotal( automato) {

	return true;
}

// Um autômato finito, para ser minimizado, precisa satisfazer os seguintes pré-requisitos:
bool verificarAFD(Automato automato) {

	if (verificarAutomato(automato) 	// * Precisa ser um AFD;
	&& temEstadosInacessiveis(automato) && deltaTotal(automato)) {
		return true;
	} else
		return false;
}

// * Efetuar conversão de AFNs para AFD;
void converterAFN_AFD(Automato *automato) {

}

// * Eliminar os estados inacessíveis e suas correspondentes transições;
void eliminarEstadosInacessiveis(Automato *automato) {

}

// * Transformar d em total, introduzindo um estado de morte e incluindo as transições não previstas para este estado.
void transformarDeltaParaTotal(Automato *automato) {

}

// Caso o autômato não satisfaça a alguns dos pré-requisitos, é necessário gerar um autômato equivalente:
void gerarAutomatoEquivalente(Automato *automato) {

}

// * ALGORITMO DE PREENCHIMENTO DE TABELA
// 1. Construir uma tabela relacionando estados diferentes, onde cada par de estados ocorre somente uma vez;
void construirTabela(Automato *automato) {
	int **tabela;
}

// 2. Marcar estados obviamente não equivalentes: <<marcar pares de estados finais com estados não finais>>;
void marcarEstadosObviamenteNaoEquivalentes(Automato *automato) {
	int **estadoObvNaoEquivalentes;
}

bool estaMarcado(int p, int pl) {

	return false;
}

void marcar(int *lista[2], int q, int ql) {

}

bool encabeca( lista_q, q, ql) {

	return true;
}

// 3. Marcar estados não equivalentes. Para cada par {q, q’} e para cada símbolo 'a' pertencente a um alfabeto (Sigma), suponha que delta(q, a) = p e delta(q’, a) = p’ e:
void marcarEstadosNaoEquivalentes(Automato *automato) {
	int p, pl;
	int *q, *ql;
	int *lista_q[2];
	int a;

	// a) Se <<p = p’>>, então <<q é equivalente a q’ para a e não deve ser marcado>>;
	if (p == pl) {
	}

	// b) Se <<p != p’>> e o par <<{p, p’} não está marcado>>, então {q, q’} é incluído em uma lista para posterior análise;
	if (p != pl && !estaMarcado(p, pl)) {
		lista_q[p][pl] = 1;
	}

	// c) Se <<p != p’>> e o par <<{p, p’} está marcado>>:
	if (p != p && estaMarcado(p, pl)) {
		// * {q, q’} não é equivalente e deve ser marcado;
		marcar(&lista_q, q, ql);

		// * Se {q,q’} encabeça uma lista de pares, então marcar todos os pares da lista.
		if (encabeca(lista_q, q, ql)) {
			marcarTodosPares(&lista_q);
		}
	}
}

// * A equivalência é transitiva;
bool eEquivalenciaTransitiva( p, pl) {

	return true;
}

// * <<Pares de estados não finais>> equivalentes podem ser unificados como <<um único estado não final>>;
bool podeUnificarParesNaoFinais(int *listaParesNaoFinais) {

	return true;
}

// * <<Pares de estados finais>> equivalentes podem ser unificados como <<um único estado final>>;
bool podeUnificarParesFinais(int *listaParesFinais) {

	return true;
}

// * Se algum dos estados equivalentes é inicial, então o correspondente estado unificado é inicial.
bool algumEstadoEquivalenteInicial(int *listaParesNaoFinais, int *listaParesFinais) {

}

// 4. Unificar os estados equivalentes. <<Os estados dos pares não marcados são equivalentes>> e podem ser unificados como segue:
void unificarEstadosEquivalentes(Automato *automato) {
	int p, pl;
	int *listaParesNaoFinais[2];
	int *listaParesFinais[2];

	if (eEquivalenciaTransitiva(p, pl)
			&& podeUnificarParesNaoFinais(&listaParesNaoFinais)
			&& podeUnificarParesFinais(&listaParesFinais) &&
			algumEstadoEquivalenteInicial(listaParesNaoFinais, listaParesFinais)) {
	}
}

// 5. Excluir estados inúteis. Um estado q é inútil se é não final e a partir de q não é possível atingir um estado final.
// * O estado de morte é sempre inútil.
void excluirEstadosInuteis(Automato *automato) {

}
