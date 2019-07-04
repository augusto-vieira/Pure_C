/* Enunciado
 * Leia o valor do raio de um cı́rculo e calcule e imprima a área do cı́rculo correspondente.
   A área do cı́rculo é π ∗ raio 2 , considere π = 3.141592.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	float radius;
	printf("Digite o raio do circulo.:");
	scanf("%f", &radius);
	printf("Area: %f\n", radius * radius * M_PI);
	return EXIT_SUCCESS;
}
