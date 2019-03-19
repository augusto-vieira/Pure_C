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
#include <string.h>

int main(void) {

	FILE *f;

	f = fopen("arquivo.txt", "w");
	if(f == NULL)
	{
		printf("Erro na abertura.\n");
		exit(1);
	}


	char texto[20] = "Meu programa em C";
	int i;

	for(i = 0; i < strlen(texto); i++)
	{
		fputc(texto[i], f);
	}

	fclose(f);

	f = fopen("arquivo.txt", "r");
	if(f == NULL)
	{
		printf("Erro na abertura.\n");
		exit(1);
	}

	char ch = fgetc(f);

	while( ch != EOF){
		putchar(ch);
		ch = fgetc(f);
	}

	return EXIT_SUCCESS;
}
