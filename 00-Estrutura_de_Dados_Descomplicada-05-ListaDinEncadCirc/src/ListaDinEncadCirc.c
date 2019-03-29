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
