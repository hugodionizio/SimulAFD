/*
 * busca.c
 *
 *  Created on: 15/03/2016
 *      Author: hugo
 */

/* Algoritmo de busca sequencial de Feofiloff */
/*
	Recebe um vetor crescente v[0 . . n−1] com n ≥ 1 e um inteiro x.
	Devolve um índice j em 0 . . n tal que v[j−1] < x ≤ v[j].
*/
int buscaSequencial (int x, int n, int *v) {
	int j = 0;

	while (j < n && v[j] != x) ++j;

	return j;
}

/* Algoritmo baseado no de busca sequencial de Feofiloff */
/*
	Recebe uma cadeia crescente s[0 . . n−1] com n ≥ 1 e um caractere ch.
	Devolve um índice j em 0 . . n tal que s[j−1] < ch ≤ s[j].
*/
int buscaSequencialStr (char ch, int n, char *s) {
	int j = 0;

	while (j < n && s[j] != ch) ++j;

	return j;
}
