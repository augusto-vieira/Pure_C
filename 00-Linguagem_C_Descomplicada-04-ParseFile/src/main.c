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

struct data{
	int field1;
	int field2;
	int field3;
	int field4;
};

void parse(char *data, struct data dt);

int main(void) {

	FILE *f;
	char line[80];

	f = fopen("parse.txt", "r");
	if(f == NULL)
	{
		printf("Unable to open parse.txt file.\n");
		exit(1);
	}

	fgets(line, sizeof(line), f);

	printf("%s\n", line);

	fclose(f);

	return EXIT_SUCCESS;
}

void parse(char *data, struct data *dt)
{
	int *p = NULL;

	if(data == NULL || dt == NULL)
		return;

	p = dt;

}
