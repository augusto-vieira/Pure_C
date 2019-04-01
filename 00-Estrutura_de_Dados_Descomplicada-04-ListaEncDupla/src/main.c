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
#include "ListaDinEncadDupla.h"


int main(void) {

	Lista *li = cria_lista();


	libera_lista(li);

	return EXIT_SUCCESS;
}
