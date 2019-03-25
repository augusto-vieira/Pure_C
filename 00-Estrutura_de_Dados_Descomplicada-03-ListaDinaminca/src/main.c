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
#include <unistd.h>
#include "menu.h"


int main(void) {

#if 0
	Lista *li = cria_lista();
	float notas[3] = {5.8,9.4,10.0};
	struct aluno al = cria_aluno("Cristiano Silva de Souza", 747734, notas);
	struct aluno sara = cria_aluno("Sara de Oliveira", 16295242, notas);
	struct aluno marcelo = cria_aluno("Marcelo Alves", 16295242, notas);
	insere_lista_inicio(li, al);
	insere_lista_inicio(li, sara);
	insere_lista_inicio(li, marcelo);

	printf("Lista Criada = %d\n", lista_foi_criada(li));

	printLista(li);

	libera_lista(li);

#endif

	while(1)
	{
		mostra_opcoes();
		if(get_opcao() < 0)
			break;
		usleep(1500000);
	}


	return EXIT_SUCCESS;
}
