/* Enunciado
 * Leia uma distância em quilômetros e apresente-a convertida em milhas. A fórmula de
   conversão é: M = k/1,61, sendo K a distância em quilômetros e M em milhas.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float quilometros;
	scanf("f", &quilometros);

	printf("milhas: %.2f\n", quilometros / 1.61);
	return EXIT_SUCCESS;
}
