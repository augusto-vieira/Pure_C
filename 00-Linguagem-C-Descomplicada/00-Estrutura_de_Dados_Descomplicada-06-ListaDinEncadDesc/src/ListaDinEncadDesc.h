/*
 * ListaDinEncadDesc.h
 *
 *  Created on: 6 de abr de 2019
 *      Author: solid
 */

#ifndef LISTADINENCADDESC_H_
#define LISTADINENCADDESC_H_

struct aluno{
	int matricula;
	char nome[30];
	float notas[3];
};

typedef struct descritor Lista;

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
 * @return
 */
int remove_lista_inicio(Lista *li);

/**
 *
 * @param li
 * @return
 */
int remove_lista_final(Lista *li);

#endif /* LISTADINENCADDESC_H_ */
