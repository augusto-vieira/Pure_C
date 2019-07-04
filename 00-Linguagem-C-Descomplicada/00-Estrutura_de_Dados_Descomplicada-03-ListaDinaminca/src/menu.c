/*
 * menu.c
 *
 *  Created on: 24 de mar de 2019
 *      Author: solid
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "ListaDinEnc.h"

typedef int (*Pfunction)(void *);

typedef struct ctx{
	Lista *li;
	struct aluno al;
	int lista_criada;
}Menu_Ctx;

Menu_Ctx menu_ctx = {
		.li = NULL,
		.lista_criada = 0,
};

static int valida_aluno(void);
static int analisa_opcao(int opcao);

static int limpa_tela(void *args);
static int cria_lista_local(void *args);
static int cria_aluno_local(void *args);
static int apaga_aluno(void *args);
static int insere_aluno_na_lista(void *args);
static int apaga_aluno_da_lista(void *args);
static int imprime_lista(void *args);
static int salva_em_arquivo(void *args);
static int sair(void *args);


Pfunction func_opcoes[] = {
		cria_lista_local,
		cria_aluno_local,
		apaga_aluno,
		insere_aluno_na_lista,
		apaga_aluno_da_lista,
		imprime_lista,
		salva_em_arquivo,
		sair
};

static int qtde_opcoes = sizeof(func_opcoes)/ sizeof(func_opcoes[0]);


void mostra_opcoes(void)
{
	limpa_tela(NULL);
	printf("+----------------------------+\n");
	printf("|       Testa Lista          |\n");
	printf("+----------------------------+\n");
	printf("| Opções                     |\n");
	printf("|[0]->Cria Lista             |\n");
	printf("|[1]->Cria Aluno             |\n");
	printf("|[2]->Apaga Aluno            |\n");
	printf("|[3]->Insere Aluno na lista  |\n");
	printf("|[4]->Apaga Aluno da lista   |\n");
	printf("|[5]->Imprime lista          |\n");
	printf("|[6]->Salva Lista em arquivo |\n");
	printf("|[7]->Sair                   |\n");
	printf("+----------------------------+\n");
}

int get_opcao(void)
{
	int escolha;
	scanf(" %d", &escolha);
	return analisa_opcao(escolha);
}

static int analisa_opcao(int opcao)
{
	int ret = EXIT_FAILURE;

	if(opcao < qtde_opcoes)
		return func_opcoes[opcao](NULL);

	return ret;
}



static int limpa_tela(void *args)
{
	return system("clear");
}

static int cria_lista_local(void *args)
{
	if(menu_ctx.lista_criada == 0)
		menu_ctx.li = cria_lista();

	if(menu_ctx.li != NULL )
	{
		printf("Lista criada com sucesso!\n");
		menu_ctx.lista_criada = 1;
		return EXIT_SUCCESS;
	}
	else
	{
		printf("Não foi possível criar lista.\n");
		return EXIT_FAILURE;
	}
}

static int cria_aluno_local(void *args)
{
	int ret = EXIT_FAILURE;
	struct aluno al;
	memset(&al, 0, sizeof(al));

	printf("Digite o nome do aluno: ");
	scanf(" ");
	fgets(al.nome,sizeof(al.nome), stdin);
	printf("Digite o numero da matricula: ");
	scanf(" %d", &al.matricula);

	int nome_tam = strlen(al.nome);

	if(nome_tam > 0 && al.matricula != 0)
	{

		menu_ctx.al = cria_aluno(al.nome, al.matricula, al.n);
		printf("Aluno criado com sucesso.\n");
		ret = EXIT_SUCCESS;
	}

	return ret;
}

static int apaga_aluno(void *args)
{

	memset(&menu_ctx.al, 0, sizeof(menu_ctx.al));
	printf("Aluno apagado com sucesso.\n");
	return EXIT_SUCCESS;
}

static int insere_aluno_na_lista(void *args)
{
	int ret = EXIT_FAILURE;
	if(lista_foi_criada(menu_ctx.li) && valida_aluno())
	{
		insere_lista_ordenada(menu_ctx.li, menu_ctx.al);
		memset(&menu_ctx.al, 0, sizeof(menu_ctx.al));
		printf("Aluno inserido com sucesso!\n");
		ret = EXIT_SUCCESS;
	}
	else{
		printf("Lista não foi criada.\n");
	}

	return ret;
}

static int apaga_aluno_da_lista(void *args)
{
	int ret = EXIT_FAILURE;
	if(lista_foi_criada(menu_ctx.li))
	{
		int matricula;
		struct aluno al;
		printf("Digite o numero da matricula: ");
		scanf(" %d", &matricula);

		printf("Procurando aluno...\n");
		if(consulta_lista_matricula(menu_ctx.li, matricula, &al))
		{
			char ch;
			printf("Aluno encontrado: %s.\n", al.nome);
			printf("Deseja realmente remover esse aluno(S/N)? ");
			scanf(" %c", &ch);
			if(toupper(ch) == 'S')
			{
				if(remove_lista(menu_ctx.li, matricula))
					printf("Aluno removido com sucesso.\n");
				else
					printf("Remoção cancelada.\n");
			}
			ret = EXIT_SUCCESS;
		}

		else{
			printf("Aluno não existe no banco de dados.\n");
		}
	}
	else{
		printf("Lista não foi criada.\n");
	}

	return ret;
}

static int imprime_lista(void *args)
{
	if(lista_foi_criada(menu_ctx.li))
	{
		return printLista(menu_ctx.li);
	}

	printf("Lista não foi criada.\n");
	return EXIT_FAILURE;
}

static int salva_em_arquivo(void *args)
{

	return EXIT_FAILURE;
}
static int sair(void *args)
{
	printf("Destruindo Lista....\n");
	if(libera_lista(menu_ctx.li) == EXIT_SUCCESS)
	{
		printf("Obrigado por usar o programa.\n");
		return -1;
	}

	printf("Lista não foi criada saindo...\n");
	return -1;
}

static int valida_aluno(void)
{
	if(menu_ctx.al.matricula != 0 && strlen(menu_ctx.al.nome) > 0)
	{
		return 1;
	}
	return 0;
}
