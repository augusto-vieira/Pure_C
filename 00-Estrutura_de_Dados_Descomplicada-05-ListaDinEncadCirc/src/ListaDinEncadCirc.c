/*
 * ListaDinEncadCirc.c
 *
 *  Created on: 29 de mar de 2019
 *      Author: solid
 */

#include <stdlib.h>
#include "ListaDinEncadCirc.h"

struct elemento
{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(void)
{
	Lista *li = (Lista *)malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

int libera_lista(Lista *li)
{
	int ret = EXIT_FAILURE;
	if(li != NULL && (*li) != NULL)
	{
		Elem *aux, *no = *li;
		while((*li) != no->prox)
		{
			aux = no;
			no = no->prox;
			free(aux);
		}
		free(no);
		free(li);
		ret = EXIT_SUCCESS;
	}
	return ret;
}

int tamanho_lista(Lista *li)
{
	if(li == NULL || (*li) == NULL)
		return 0;

	int cont = 0;
	Elem *no = *li;
	do
	{
		cont++;
		no = no->prox;
	}while(no != (*li));
	return cont;
}

int lista_cheia(Lista *li)
{
	return 0;
}

int insere_lista_inicio(Lista *li, struct aluno al)
{
	if(li == NULL)
		return 0;
	Elem *no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = al;
	if((*li) == NULL) //Lista vazia
	{
		*li = no;
		no->prox = no;
	}
	else
	{
		Elem *aux = *li;
		while(aux->prox != (*li))
			aux = aux->prox;
		aux->prox = no;
		no->prox = *li;
		*li = no;
	}
	return 1;
}

int insere_lista_final(Lista *li, struct aluno al)
{
	if(li == NULL)
		return 0;
	Elem *no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = al;
	if((*li) == NULL)
	{
		*li = no;
		no->prox = no;
	}
	else
	{
		Elem *aux = *li;
		while(aux->prox != (*li))
			aux = aux->prox;

		aux->prox = no;
		no->prox = *li;
	}
	return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al)
{
	if(li == NULL)
		return 0;
	Elem *no = (Elem *) malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = al;

	if((*li) == NULL)
	{
		*li = no;
		no->prox = no;
		return 1;
	}
	else
	{
		if((*li)->dados.matricula > al.matricula)
		{
			Elem *atual = *li;
			while(atual->prox != (*li))
				atual = atual->prox;
			no->prox = *li;
			atual->prox = no;
			*li = no;
			return 1;
		}

		Elem *ant = *li , *atual = (*li)->prox;
		while(atual != (*li) && atual->dados.matricula < al.matricula)
		{
			ant = atual;
			atual = atual->prox;
		}

		ant->prox = no;
		no->prox = atual;
		return 1;
	}
}

int remove_lista_inicio(Lista * li)
{
	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;
	if((*li) == ((*li)->prox))
	{
		free(*li);
		*li = NULL;
		return 1;
	}

	Elem *atual = *li;
	while(atual->prox != (*li))
		atual = atual->prox;

	Elem *no = *li;
	atual->prox = no->prox;
	*li = no->prox;
	free(no);
	return 1;
}

int remove_lista_final(Lista * li)
{
	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;
	if((*li) == (*li)->prox)
	{
		free(*li);
		*li = NULL;
		return 1;
	}

	Elem *ant, *no = *li;
	while(no->prox != (*li))
	{
		ant = no;
		no = no->prox;
	}

	ant->prox = no->prox;
	free(no);
	return 1;
}

int remove_lista(Lista *li, int matricula)
{
	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;
	Elem *no = *li;
	if(no->dados.matricula == matricula)
	{
		if(no == no->prox)
		{
			free(no);
			*li = NULL;
			return 1;
		}
		else
		{
			Elem *ult = *li;
			while(ult->prox != (*li))
				ult = ult->prox;
			ult->prox = (*li)->prox;
			*li = (*li)->prox;
			free(no);
			return 1;
		}
	}
	Elem *ant = no;
	no = no->prox;
	while(no != (*li) && no->dados.matricula != matricula)
	{
		ant = no;
		no = no->prox;
	}

	if(no == *li)
		return 0;
	ant->prox = no->prox;
	free(no);
	return 1;
}


int consulta_lista_pos(Lista *li, int pos, struct aluno *al)
{
	if(li == NULL || (*li) == NULL || pos <= 0)
		return 0;
	Elem *no = *li;
	int i = 1;
	while(no->prox != (*li) && i < pos)
	{
		no = no->prox;
		i++;
	}
	if( i != pos)
		return 0;
	else
	{
		*al = no->dados;
		return 1;
	}
}

int consulta_lista_matricula(Lista *li, int matricula, struct aluno *al)
{
	if(li == NULL || (*li) == NULL)
		return 0;
	Elem *no = *li;
	while(no->prox != (*li) && no->dados.matricula != matricula)
		no = no->prox;
	if(no->dados.matricula != matricula)
		return 0;
	else
	{
		*al = no->dados;
		return 1;
	}
}
