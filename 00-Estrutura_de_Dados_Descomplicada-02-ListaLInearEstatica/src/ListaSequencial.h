/**
 *
 * @file ListaSequencial.h
 * @brief Implementação de uma Lista sequencial estática
 * @author Cristiano Silva de Souza
 * @date 22 mar 2019
 *
 */

#ifndef LISTASEQUENCIAL_H_
#define LISTASEQUENCIAL_H_

/** @name Group2
 *  Description of group 2.
 */
///@{
#define MAX 			100
#define OTHER			200
#define ANOTHER			300
///@}

/**
 * @brief Estrutura aluno
 */
struct aluno{
	int matricula;		/**< Matricula do aluno. */
	char nome[30];		/**< Nome do aluno. */
	float n[3];         /**< Notas do Aluno. */
};

/**
 * @brief Lista do tipo opaco
 */
typedef struct lista Lista;

/**
 * @fn Lista *cria_lista();
 * @brief Cria lista
 * @return Ponteiro para lista criada
 */
Lista *cria_lista();

/**
 * @fn void libera_lista(Lista *li); *
 * @brief Destrói lista
 * @param li
 */
void libera_lista(Lista *li);

/**
 * @brief
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
int insere_lista_final(Lista *li, struct aluno al);

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
int insere_lista_ordenada(Lista *li, struct aluno al);

/**
 *
 * @param li
 * @return
 */
int remove_lista_final(Lista *li);

/**
 *
 * @param li
 * @return
 */
int remove_lista_inicio(Lista *li);

/**
 *
 * @param li
 * @param mat
 * @return
 */
int remove_lista(Lista *li, int mat);
int consulta_lista_pos(Lista *li, int pos, struct aluno *al);
int consulta_lista_mat(Lista *li, int mat, struct aluno *al);
int imprime_lista(Lista *li);


#endif /* LISTASEQUENCIAL_H_ */
