/*
 ============================================================================
 Name        : 00-Template.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct cadastro{
	char nome[30];
	char endereco[30];
	int idade;
};

int main(void) {
	FILE *f;
	f = fopen("struct.bin", "wb");
	if(f == NULL)
	{
		printf("Erro na abertura\n");
		exit(1);
	}

	struct cadastro cad = {
			.nome = "Cristiano Silva",
			.endereco = "Rua Nova Vida",
			.idade = 32
	};

	struct cadastro read;


	fwrite(&cad,sizeof(struct cadastro), 1, f);
	fclose(f);

	f = fopen("struct.bin", "rb");

	fread(&read,sizeof(struct cadastro), 1, f);

	fclose(f);

	printf("Nome: %s\nEndereço: %s\nIdade: %d\n", read.nome, read.endereco, read.idade);
}
