/* Enunciado
 * Leia uma distância em milhas e apresente-a convertida em quilômetros. A fórmula de
   conversão é: K = 1, 61 ∗ M , sendo K a distância em quilômetros e M em milhas.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float milhas;
	scanf("f", &milhas);

	printf("km/h: %.2f\n", milhas * 1.61);
	return EXIT_SUCCESS;
}
