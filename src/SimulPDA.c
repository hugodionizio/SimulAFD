/*
 *  Projeto: Autômatos Finitos com Pilha
 *  Programa: SimulPDA.c
 *  Objetivo: Implementar um simulador de autômatos finitos com pilha – PDA
 *  		que permite testar o reconhecimento de diversas cadeias para qualquer PDA de entrada.
 *  Created on: 05/11/2016
 *      Author: Hugo Dionizio Santos
 */
#include "SimulPDA.h"
#define TAMBUFF 1024 /* tamanho do buffer */
char buff[TAMBUFF + 1];

// Interface do programa (Protótipos de funções)

int main (int argc, char **argv) {
// Seção de Declarações Internas
	char ch;
	char *str="Erro: Digite o nome do arquivo na linha de comandos\n";
	int fd, BytesLidos;

// Seção de Comandos
	printf ("Trabalho da 3ª Unidade da disciplina de Linguagens Formais e Autômatos\n");
	printf ("SimulPDA: Simulador de Autômatos Finitos com Pilha (PDA)\n");
	if (argc > 1 && strcmp(argv[1], "--help") == 0) {

		if(argc !=2) {
			write(1,str,strlen(str)); /* Imprime em stdout */
			exit(1) ;
		}

		if( (fd = open("../src/help.txt", O_RDONLY)) < 0) {
	 		str = "Arquivo não existe!";
			write(1,str,strlen(str)); /* Imprime em stdout */
			exit(1);
		}

		while((BytesLidos = read(fd,buff,TAMBUFF)) > 0) {
			buff[BytesLidos + 1] = '\0';
			write(1,buff,strlen(buff));
		}
		close(fd);
	}
	else {
		int exitType = terminal();
/*
		if (exitType != 0) {
			printf("\nFinalização com erro do tipo %d.\n", exitType);
		}
		else
			printf("\nFinalização bem sucedida.\n");
*/
	}

	return (0);
}
// Funções

// Fim do programa
