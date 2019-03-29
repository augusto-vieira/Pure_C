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


#endif /* LISTADINENCADCIRC_H_ */
