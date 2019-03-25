/* Enunciado
 * Leia uma velocidade em m/s (metros por segundo) e apresente-a convertida em km/h
  (quilômetros por hora). A fórmula de conversão é: K = M ∗ 3.6, sendo K a velocidade
   em km/h e M em m/s.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float velocidade;
	scanf("f", &velocidade);

	printf("km/h: %.2f\n", velocidade * 3.6);
	return EXIT_SUCCESS;
}
