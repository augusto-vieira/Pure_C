/*
 * ListaDinEnc.h
 *
 *  Created on: 22 de mar de 2019
 *      Author: solid
 */

#ifndef LISTADINENC_H_
#define LISTADINENC_H_

#include <stdlib.h>

struct aluno{
	int matricula;
	char nome[30];
	float n[3];
};

typedef struct elemento* Lista;

Lista *cria_lista();
int libera_lista(Lista *li);
int tamanho_lista(Lista *li);
int lista_cheia(Lista *li);
int lista_vazia(Lista *li);
int insere_lista_inicio(Lista *li, struct aluno al);
int insere_lista_final(Lista *li, struct aluno al);
int insere_lista_ordenada(Lista *li, struct aluno al);
int remove_lista_inicio(Lista *li);
int remove_lista_final(Lista *li);
int remove_lista(Lista *li, int mat);
int consulta_lista_pos(Lista *li, int pos, struct aluno *al);
int consulta_lista_matricula(Lista *li, int matricula, struct aluno *al);
int lista_foi_criada(Lista *li);

int printLista(Lista *li);

struct aluno cria_aluno(const char *nome, const int matricula, float notas[3]);



#endif /* LISTADINENC_H_ */
