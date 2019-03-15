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

int fatorial(int n)
{
	if( n == 0)
		return 1;
	return n * fatorial(n - 1);
}

int fibonnaci(int n)
{
	if(n == 1 || n == 0)
		return n;
	else
	{
		return fibonnaci(n -1) + fibonnaci(n - 2);
	}
}

int soma(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else{
		return n + soma(n - 1);
	}
}

int main(void) {

	int num = 5;
	printf("fatorial de %d é = %d\n", num, fatorial(num));

//	printf("fibonnaci de %d é = %d\n", num, fibonnaci(num));
	printf("soma de %d é = %d\n", num, soma(num));
	return 0;
}
