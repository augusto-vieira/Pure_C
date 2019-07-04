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

	FILE *fd = fopen("mapa.txt", "w");

	if(fd == NULL)
		exit(EXIT_FAILURE);

	fclose(fd);

	return EXIT_SUCCESS;
}
