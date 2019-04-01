/**
 * @brief
 * @file
 * @author
 */

#ifndef LISTADINENCADCIRC_H_
#define LISTADINENCADCIRC_H_

#define MAX_NOME_LEN 30
#define MAX_NOTAS	  3

struct aluno
{
	int matricula;
	char nome[MAX_NOME_LEN];
	float notas[MAX_NOTAS];
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
int remove_lista_inicio(Lista * li);


/**
 *
 * @param li
 * @return
 */
int remove_lista_final(Lista * li);

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

#endif /* LISTADINENCADCIRC_H_ */
