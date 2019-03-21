/*
 * ListaSequencial.h
 *
 *  Created on: 20 de mar de 2019
 *      Author: solid
 */

#ifndef LISTASEQUENCIAL_H_
#define LISTASEQUENCIAL_H_

#define MAX 100

struct aluno{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

typedef struct lista Lista;

/* Funções */
Lista *cria_lista();
void libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);

#endif /* LISTASEQUENCIAL_H_ */
