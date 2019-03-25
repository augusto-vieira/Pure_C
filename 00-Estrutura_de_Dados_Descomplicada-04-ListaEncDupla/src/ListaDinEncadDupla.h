/*
 * ListaDinEncadDupla.h
 *
 *  Created on: 25 de mar de 2019
 *      Author: solid
 */

#ifndef LISTADINENCADDUPLA_H_
#define LISTADINENCADDUPLA_H_



struct aluno
{
	int matricula;
	char nome[30];
	float notas[3];
};

typedef struct elemento *Lista;

/**
 *
 * @return
 */
Lista *cria_lista(void);

/**
 *
 * @param li
 * @return
 */
int libera_lista(Lista *li);


#endif /* LISTADINENCADDUPLA_H_ */
