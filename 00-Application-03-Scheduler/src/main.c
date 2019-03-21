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
#include "scheduler.h"

void hello_world(void)
{
	printf("Hello World 1\n");
}

void bye(void)
{
	printf("bye\n");
}

int main(void) {

	register_task(hello_world, 0);
	register_task(bye, 0);

	scheduler_run();

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

