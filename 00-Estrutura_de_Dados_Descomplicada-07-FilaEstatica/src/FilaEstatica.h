/*
 * FilaEstatica.h
 *
 *  Created on: 6 de abr de 2019
 *      Author: solid
 */

#ifndef FILAESTATICA_H_
#define FILAESTATICA_H_

#define MAX 100

struct aluno{
	int matricula;
	char nome[30];
	float notas[3];
};

typedef struct fila Fila;

/**
 *
 * @return
 */
Fila *cria_fila(void);

/**
 *
 * @param fi
 * @return
 */
int libera_fila(Fila *fi);

#endif /* FILAESTATICA_H_ */
