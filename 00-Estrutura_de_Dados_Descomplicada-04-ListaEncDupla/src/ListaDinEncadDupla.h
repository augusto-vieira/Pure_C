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

/**
 *
 * @param li
 * @return
 */
int tamanho_lista(Lista *li);

/**
 *
 * @param li
 * @return
 */
int lista_cheia(Lista *li);

/**
 *
 * @param li
 * @return
 */
int lista_vazia(Lista *li);

/**
 *
 * @param li
 * @param al
 * @return
 */
int insere_lista_inicio(Lista *li, struct aluno al);

/**
 *
 * @param li
 * @param al
 * @return
 */
int insere_lista_final(Lista *li, struct aluno al);

/**
 *
 * @param li
 * @param al
 * @return
 */
int insere_lista_ordenada(Lista *li, struct aluno al);

/**
 *
 * @param li
 * @return
 */
int remove_lista_inicio(Lista *li);

/**
 *
 * @param li
 * @return
 */
int remove_lista_final(Lista *li);

/**
 *
 * @param li
 * @param matricula
 * @return
 */
int remove_lista(Lista *li, int matricula);

/**
 *
 * @param li
 * @param pos
 * @param al
 * @return
 */
int consulta_lista_pos(Lista *li, int pos, struct aluno *al);

/**
 *
 * @param li
 * @param matricula
 * @param al
 * @return
 */
int consulta_lista_matricula(Lista *li, int matricula, struct aluno *al);


#endif /* LISTADINENCADDUPLA_H_ */
