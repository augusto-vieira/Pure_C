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
#include "Ponto.h"

int main(void) {

	float d;
	Ponto *p, *q;

	p = ponto_cria(10, 21);
	q = ponto_cria(7, 25);

	d = ponto_distancia(p, q);
	printf("Distancia entre dois pontos: %f\n", d);

	ponto_libera(p);
	ponto_libera(q);

	return EXIT_SUCCESS;
}
