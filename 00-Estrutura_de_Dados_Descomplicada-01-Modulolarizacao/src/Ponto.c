/*
 * Ponto.c
 *
 *  Created on: 19 de mar de 2019
 *      Author: solid
 */

#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

struct ponto{
	float x;
	float y;
};


Ponto *ponto_cria(float x, float y)
{
	Ponto *p = (Ponto *)malloc(sizeof(Ponto));
	if(p == NULL)
		return NULL;
	p->x = x;
	p->y = y;

	return p;
}

void ponto_libera(Ponto *p)
{
	if(p)
		free(p);
}

void ponto_acessa(Ponto *p, float *x, float *y)
{
	if(p && x && y )
	{
		*x = p->x;
		*y = p->y;
	}
}

void ponto_atribui(Ponto *p, float x, float y)
{
	if(p)
	{
		p->x = x;
		p->y = y;
	}
}

float ponto_distancia(Ponto *p1, Ponto *p2)
{
	if(p1 && p2)
	{
		float dx = p1->x - p2->x;
		float dy = p1->y - p2->y;
		return sqrt(pow(dx, 2.0) + pow(dy, 2.0));
	}
	return 0.0;
}
