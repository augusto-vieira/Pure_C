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

int main(void) {

	int num2;

	printf("****************************************\n");
	printf("*              Tabuada                 *\n");
	printf("****************************************\n");

	printf("Entre com um inteiro: ");
	scanf("%d", &num2);

	for(int i = 1; i <= 10; i++)
	{
		printf("%d x %d = %d\n", num2, i, num2 * i);
	}
	putchar('\n');


	return EXIT_SUCCESS;
}
