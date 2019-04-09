/*
 * ListaDinEncadDesc.c
 *
 *  Created on: 6 de abr de 2019
 *      Author: solid
 */

#include <stdlib.h>
#include "ListaDinEncadDesc.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor{
	struct elemento *inicio;
	struct elemento *final;
	int qtd;
};

Lista *cria_lista(void)
{
	Lista *li = (Lista *)malloc(sizeof(Lista));
	if(li != NULL)
	{
		li->inicio = NULL;
		li->final = NULL;
		li->qtd = 0;
	}

	return li;
}

int libera_lista(Lista *li)
{
	if(li != NULL)
	{
		Elem *no;
		while((li->inicio) != NULL)
		{
			no = li->inicio;
			li->inicio = li->inicio->prox;
			free(no);
		}
		free(li);
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

int tamanho_lista(Lista *li)
{
	if(li == NULL)
		return 0;
	return li->qtd;
}

int insere_lista_inicio(Lista *li, struct aluno al)
{
	if(li == NULL)
		return EXIT_FAILURE;
	Elem *no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL)
		return EXIT_FAILURE;
	no->dados = al;
	no->prox = li->inicio;
	if(li->inicio == NULL)
		li->final = no;
	li->inicio = no;
	li->qtd++;
	return EXIT_SUCCESS;
}

int insere_lista_final(Lista *li, struct aluno al)
{
	if(li == NULL)
		return EXIT_FAILURE;
	Elem *no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL)
		return EXIT_FAILURE;
	no->dados = al;
	no->prox = NULL;
	if(li->inicio == NULL)
		li->inicio = no;
	else
		li->final->prox = no;
	li->final = no;
	li->qtd++;
	return EXIT_SUCCESS;
}

int remove_lista_inicio(Lista *li)
{
	if(li == NULL)
		return EXIT_FAILURE;
	if(li->inicio == NULL)
		return EXIT_FAILURE;
	Elem *no = li->inicio;
	li->inicio = no->prox;
	free(no);
	if(li->inicio == NULL)
		li->final = NULL;
	li->qtd--;
	return EXIT_SUCCESS;
}

int remove_lista_final(Lista *li)
{
	if(li == NULL)
		return EXIT_FAILURE;
	if(li->inicio == NULL)
		return EXIT_FAILURE;
	Elem *ant , *no = li->inicio;
	while(no->prox != NULL)
	{
		ant = no;
		no = no->prox;
	}

	if(no == li->inicio)
	{
		li->inicio = NULL;
		li->final = NULL;
	}
	else
	{
		ant->prox = no->prox;
		li->final = ant;
	}
	free(no);
	li->qtd--;
	return EXIT_SUCCESS;
}
