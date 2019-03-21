/*
 * Ponto.h
 *
 *  Created on: 19 de mar de 2019
 *      Author: solid
 */

#ifndef PONTO_H_
#define PONTO_H_

typedef struct ponto Ponto;

Ponto *ponto_cria(float x, float y);

void ponto_libera(Ponto *p);

void ponto_acessa(Ponto *p, float *x, float *y);

void ponto_atribui(Ponto *p, float x, float y);

float ponto_distancia(Ponto *p1, Ponto *p2);



#endif /* PONTO_H_ */
