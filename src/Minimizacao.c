/*
 * Minimizacao.c
 *
 *  Created on: 22/04/2016
 *      Author: hugo
 */

#include <stdio.h>
#include <string.h>
#include "Automato.h"
#include "MinimizadorAFD.h"

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

// Função principal de Minimização de Autômatos
bool minimizarAutomato(Automato *automato) {
	Tabela tabela;
	Lista lista;
	//	char **tabela;
	int *lista_q[4];
	int *listaParesNaoFinais[2];
	int *listaParesFinais[2];

	printf("Minimizando autômato...\n");

	if (verificarAFD(*automato) == true) {
		printf("O autômato é um AFD, pronto para ser minimizado.\n");
	} else {
		gerarAutomatoEquivalente(automato);
	}

	// Algoritmo de Preenchimento de Tabela
	construirTabela(automato, &tabela);
	marcarEstadosObviamenteNaoEquivalentes(automato, &tabela);
	marcarEstadosNaoEquivalentes(automato, &tabela, &lista);
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
		tabela->t[count] = (char *) malloc(
				automato->e.numEstados * sizeof(char));
	}

	for (count = 0; count < automato->e.numEstados; count++) {
		for (count2 = 0; count2 < automato->e.numEstados; count2++) {
			tabela->t[count2][count] = ' ';
		}
	}
}

// Funções da Etapa 2
bool eEstadoFinal(int x, Estado e) {
	if (buscaSequencial(x, e.numEstadosFinais, e.estadosFinais)
			< e.numEstadosFinais)
		return true;
	else
		return false;
}

void imprimirTabela(Automato automato, Tabela tabela) {
	int count, count2;

	for (count = 0; count < automato.e.numEstados; count++) {
		for (count2 = 0; count2 < automato.e.numEstados; count2++) {
			if (count == 0 && count2 == 0)
				printf("   ");
			else if (count2 == 0 && count != 0)
				printf("%c%d ", automato.e.representacao,
						automato.e.estados[count]);

			if (count2 != automato.e.numEstados - 1) {
				if (count == 0) {
					printf("%c%d", automato.e.representacao,
							automato.e.estados[count2]);
				} else {
					printf("%c", tabela.t[count2][count]);
				}
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
			if (eEstadoFinal(count, automato->e)
					!= eEstadoFinal(count2, automato->e))
				estadoObvNaoEquivalentes->t[count2][count] = 'X';
			else if (count == count2) {
				break;
			} else if (estadoObvNaoEquivalentes->t[count2][count] == ' ')
				estadoObvNaoEquivalentes->t[count2][count] = '-';
		}
	}

	imprimirTabela(*automato, *estadoObvNaoEquivalentes);
}

// Funções da Etapa 3
int delta(Automato automato, int estado, char transicao) {
	int posEstado, posSimbolo;
	char * pch;
	int i;
	char str[automato.a.numSimbolos];

	for (i = 0; i < automato.a.numSimbolos; ++i) {
		str[i] = automato.a.simbolos[i];
	}
//	str[automato.a.numSimbolos] = '\0';

	posEstado = buscaSequencial(estado, automato.e.numEstados,
			automato.e.estados);
	pch = strchr(str, transicao);
	posSimbolo = pch - &transicao + 24;

	return automato.t.funcoes[posSimbolo][posEstado];
}

bool estaMarcado(Automato automato, Tabela tabela, int p, int pl) {
	int posP, posPl;

	printf("Verificando se o par {p, p'} está marcado...\n");

	posP = buscaSequencial(p, automato.e.numEstados, automato.e.estados);
	posPl = buscaSequencial(pl, automato.e.numEstados, automato.e.estados);

	if (tabela.t[posPl][posP] == 'X')
		return true;
	else
		return false;
}

void marcar(int *lista[4], int q, int ql) {
	printf("Incluindo par {q, q'} em uma lista...\n");

}

bool encabeca(int *lista_q[4], int q, int ql) {
	printf("Verificando se o par {q, q'} encabeça a lista...\n");

	return true;
}

// 3. Marcar estados não equivalentes. Para cada par {q, q’} e para cada símbolo 'a' pertencente a um alfabeto (Sigma), suponha que delta(q, a) = p e delta(q’, a) = p’ e:
void marcarEstadosNaoEquivalentes(Automato *automato, Tabela *tabela,
		Lista *lista) {
	int *lista_q[4];
	int p, pl;
	int q, ql;
	char a;
	int i;
	int j = 0;

	printf("Marcando Estados Não Equivalentes...\n");

//	p = delta(*automato, q, a);
//	pl = delta(*automato, ql, a);
	// a) Se <<p = p’>>, então <<q é equivalente a q’ para a e não deve ser marcado>>;
	//if (p == pl) {
	//}

	for (i = 0; i < 4; ++i) {
		lista->l[i] = (int *)malloc(automato->e.numEstados*sizeof(int));
	}

	// b) Se <<p != p’>> e o par <<{p, p’} não está marcado>>, então {q, q’} é incluído em uma lista para posterior análise;
	for (q = 0; q < automato->e.numEstados; q++) {
		for (ql = 1; ql < automato->e.numEstados; ql++) {
			if (q != ql) {
				for (i = 0; i < automato->a.numSimbolos; ++i) {
					a = automato->a.simbolos[i];
					p = delta(*automato, q, a);
					pl = delta(*automato, ql, a);

					if (p != pl && !estaMarcado(*automato, *tabela, p, pl)) {
						lista->l[0][j] = p;
						lista->l[1][j] = pl;
						lista->l[2][j] = q;
						lista->l[3][j] = ql;

						printf("[{%c%d,%c%d},{%c%d,%c%d}]\n",
								automato->e.representacao, lista->l[0][j],
								automato->e.representacao, lista->l[1][j],
								automato->e.representacao, lista->l[2][j],
								automato->e.representacao, lista->l[3][j]);
						j++;
					}
				}
			}
		}
	}
	imprimirTabela(*automato, *tabela);

	// c) Se <<p != p’>> e o par <<{p, p’} está marcado>>:
	if (p != p && estaMarcado(*automato, *tabela, p, pl)) {
		// * {q, q’} não é equivalente e deve ser marcado;
		marcar(&lista->l, q, ql);

		// * Se {count,count’} encabeça uma lista de pares, então marcar todos os pares da lista.
		if (encabeca(lista->l, q, ql)) {
			marcarTodosPares(&lista->l);
		}
	}
}

// Funções da Etapa 4
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
