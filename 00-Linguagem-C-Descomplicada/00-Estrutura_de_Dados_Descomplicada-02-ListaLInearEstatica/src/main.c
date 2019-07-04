/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

int main(void) {

	struct aluno al = {
			.nome = "Cristiano Silva",
			.matricula = 747734,
			.n1 = 7.5,
			.n2 = 8.9,
			.n3 = 8.6
	};

	struct aluno al2 = {
				.nome = "Sara de Oliveira",
				.matricula = 104449,
				.n1 = 7.9,
				.n2 = 5.5,
				.n3 = 10.0
		};

	Lista *li = cria_lista();

	insere_lista_inicio(li, al);
	insere_lista_final(li, al2);

	imprime_lista(li);

	libera_lista(li);
	return EXIT_SUCCESS;
}
