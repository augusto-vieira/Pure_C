/*
 * ListaDinEncadDupla.c
 *
 *  Created on: 25 de mar de 2019
 *      Author: solid
 */

#include "ListaDinEncadDupla.h"
#include <stdlib.h>

struct elemento
{
	struct aluno dados;
	struct elemento *ant;
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
	if(li != NULL)
	{
		Elem * no;
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
