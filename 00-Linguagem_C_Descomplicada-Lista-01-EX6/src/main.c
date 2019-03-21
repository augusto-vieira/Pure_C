/* Enunciado
 * Leia uma temperatura em graus Celsius e apresente-a convertida em graus Fahrenheit.
   A fórmula de conversão é: F = C ∗(9.0/5.0)+32.0, sendo F a temperatura em Fahrenheit
   e C a temperatura em Celsius.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float celsius;

	scanf("%f", &celsius);

	printf("Fahrenheit = %f\n", (celsius * (9.0/5.0)) + 32.0);
	return EXIT_SUCCESS;
}
