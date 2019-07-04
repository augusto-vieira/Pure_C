/* Enunciado
 * Leia uma velocidade em km/h (quilômetros por hora) e apresente-a convertida em m/s
   (metros por segundo). A fórmula de conversão é: M = K/3.6, sendo K a velocidade em
   km/h e M em m/s.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float velocidade;
	scanf("f", &velocidade);

	printf("m/s: %.2f\n", velocidade/3.6);
	return EXIT_SUCCESS;
}
