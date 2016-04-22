/*
 * Minimizacao.c
 *
 *  Created on: 22/04/2016
 *      Author: hugo
 */

// Uma conseqüência do teste de equivalência é que podemos encontrar AFD’s <<equivalentes>> que contenham um <<número mínimo de estados>>.
int equilvalenciaAutomatos(Automato a, Automato b) {
	int equivalente = 0;

	return 0;
}

// Um autômato finito, para ser minimizado, precisa satisfazer os seguintes pré-requisitos:
// * Precisa ser um AFD;
// * Não pode ter estados inacessíveis;
// * (delta) deve ser total.
int verificarAFD(Automato automato) {
	int afd = 0;

	return afd;
}

// Caso o autômato não satisfaça a alguns dos pré-requisitos, é necessário gerar um autômato equivalente:
// Efetuar conversão de AFNs para AFD;
// * Eliminar os estados inacessíveis e suas correspondentes transições;
// * Transformar d em total, introduzindo um estado de morte e incluindo as transições não previstas para este estado.
void gerarAutomatoEquivalente(Automato *automato) {

}

// * ALGORITMO DE PREENCHIMENTO DE TABELA
// 1. Construir uma tabela relacionando estados diferentes, onde cada par de estados ocorre somente uma vez;
void construirTabela(Automato *automato) {

}

// 2. Marcar estados obviamente não equivalentes: <<marcar pares de estados finais com estados não finais>>;
void marcarEstadosObviamenteNaoEquivalentes(Automato *automato) {

}

// 3. Marcar estados não equivalentes. Para cada par {q, q’} e para cada símbolo 'a' pertencente a um alfabeto (Sigma), suponha que delta(q, a) = p e delta(q’, a) = p’ e:
// a) Se <<p = p’>>, então <<q é equivalente a q’ para a e não deve ser marcado>>;
// b) Se <<p != p’>> e o par <<{p, p’} não está marcado>>, então {q, q’} é incluído em uma lista para posterior análise;
// c) Se <<p != p’>> e o par <<{p, p’} está marcado>>:
// * {q, q’} não é equivalente e deve ser marcado;
// * Se {q,q’} encabeça uma lista de pares, então marcar todos os pares da lista.
void marcarEstadosNaoEquivalentes(Automato *automato) {

}

// 4. Unificar os estados equivalentes. <<Os estados dos pares não marcados são equivalentes>> e podem ser unificados como segue:
// * A equivalência é transitiva;
// * <<Pares de estados não finais>> equivalentes podem ser unificados como <<um único estado não final>>;
// * <<Pares de estados finais>> equivalentes podem ser unificados como <<um único estado final>>;
// * Se algum dos estados equivalentes é inicial, então o correspondente estado unificado é inicial.
void unificarEstadosEquivalentes(Automato *automato) {

}

// 5. Excluir estados inúteis. Um estado q é inútil se é não final e a partir de q não é possível atingir um estado final.
// * O estado de morte é sempre inútil.
void excluirEstadosInuteis(Automato *automato) {

}