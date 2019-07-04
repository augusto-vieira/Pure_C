/*
 * ListaDinEnc.c
 *
 *  Created on: 22 de mar de 2019
 *      Author: solid
 */

#include "ListaDinEnc.h"
#include <string.h>
#include <stdio.h>

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};

typedef struct elemento Elem;


Lista *cria_lista()
{
	Lista *li = (Lista *)malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

int libera_lista(Lista *li)
{
	int ret = EXIT_FAILURE;
	if(li != NULL)
	{
		Elem *no;
		while((*li) != NULL)
		{
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(li);
		ret = EXIT_SUCCESS;
	}
	return ret;
}

int tamanho_lista(Lista *li)
{
	if(li == NULL)
		return 0;
	int cont = 0;
	Elem *no = *li;
	while(no != NULL)
	{
		cont++;
		no = no->prox;
	}
	return cont;
}

int lista_cheia(Lista *li)
{
	return 0;
}

int lista_vazia(Lista *li)
{
	if(li == NULL)
		return 1;
	if(*li == NULL)
		return 1;
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
	no->prox = (*li);
	*li = no;
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
	no->prox = NULL;
	if((*li) == NULL)	//Lista vazia
	{
		*li = no;
	}else
	{
		Elem *aux = *li;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = no;
	}
	return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al)
{
	if(li == NULL)
		return 0;
	Elem * no = (Elem *)malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = al;
	if(lista_vazia(li))
	{
		no->prox = (*li);
		*li = no;
		return 1;
	}
	else
	{
		Elem *ant, *atual = *li;
		while(atual != NULL && atual->dados.matricula < al.matricula)
		{
			ant = atual;
			atual = atual->prox;
		}

		if(atual == *li)	//inicio da lista
		{
			no->prox = (*li);
			*li = atual;
		}
		else
		{
			no->prox = ant->prox;
			ant->prox = no;
		}
		return 1;
	}
}

int remove_lista_inicio(Lista *li)
{
	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;

	Elem *no = *li;
	*li = no->prox;
	free(no);
	return 1;
}

int remove_lista_final(Lista *li)
{
	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;

	Elem *ant, *no = *li;
	while(no->prox != NULL)
	{
		ant = no;
		no = no->prox;
	}

	if(no == (*li))		//inicio da lista
	{
		*li = no->prox;
	}
	else
	{
		ant->prox = no->prox;
	}
	free(no);
	return 1;
}

int remove_lista(Lista *li, int mat)
{
	if(li == NULL)
		return 0;
	Elem *ant, *no = *li;

	while( no != NULL && no->dados.matricula != mat)
	{
		ant = no;
		no = no->prox;
	}

	if(no == NULL)	//não encontrado
		return 0;

	if(no == *li)	//remover o primeiro
		*li = no->prox;
	else
		ant->prox = no->prox;
	free(no);
	return 1;
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al)
{
	if(li == NULL || pos <= 0)
		return 0;
	Elem *no = *li;
	int i = 1;
	while(no != NULL && i < pos)
	{
		no = no->prox;
		i++;
	}

	if(no == NULL)
		return 0;
	else
	{
		*al = no->dados;
		return 1;
	}
}

int consulta_lista_matricula(Lista *li, int matricula, struct aluno *al)
{
	if(li == NULL)
		return 0;

	Elem *no = (*li);

	while(no != NULL && no->dados.matricula != matricula)
	{
		no = no->prox;
	}

	if(no == NULL)
		return 0;
	else
	{
		*al = no->dados;
		return 1;
	}

}

int lista_foi_criada(Lista *li)
{
	return ((li) != NULL);
}

int printLista(Lista *li)
{
	int ret = EXIT_FAILURE;
	if(li == NULL)
		return;
	if((*li) == NULL)
		return;

	Elem *no = (*li);
	while(no != NULL)
	{
		printf("Nome: %s\n", no->dados.nome);
		printf("Nome: %d\n", no->dados.matricula);
		printf("Nome: %.2f\n", no->dados.n[0]);
		printf("Nome: %.2f\n", no->dados.n[1]);
		printf("Nome: %.2f\n", no->dados.n[2]);
		no = no->prox;
		ret = EXIT_SUCCESS;
	}

	return ret;
}

struct aluno cria_aluno(const char *nome, const int matricula, float notas[3])
{
	struct aluno al;

	memset(&al, 0, sizeof(al));
	size_t nome_tam = strlen(nome);

	strncpy(al.nome, nome, nome_tam);
	al.matricula = matricula;
	memcpy(&al.n, notas, sizeof(float) * 3);

	return al;
}
