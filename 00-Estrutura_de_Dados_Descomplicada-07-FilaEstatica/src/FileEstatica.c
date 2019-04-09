/*
 * FileEstatica.c
 *
 *  Created on: 6 de abr de 2019
 *      Author: solid
 */

#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

struct fila{
	int inicio, final, qtd;
	struct aluno dados[MAX];
};

Fila *cria_fila(void)
{
	Fila *fi = (Fila *)malloc(sizeof(struct fila));
	if(fi != NULL)
	{
		fi->inicio = 0;
		fi->final = 0;
		fi->qtd = 0;
	}
	return fi;
}

int libera_fila(Fila *fi)
{
	free(li);
}
