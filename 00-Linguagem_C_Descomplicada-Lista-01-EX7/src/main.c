/* Enunciado
 * Leia uma temperatura em graus Fahrenheit e apresente-a convertida em graus Celsius.
   A fórmula de conversão é: C = 5.0 ∗ (F − 32.0)/9.0, sendo C a temperatura em Celsius
   e F a temperatura em Fahrenheit.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float fahrenheit;
	scanf("%f", &fahrenheit);

	printf("Celsius = %f\n", 5.0 * (fahrenheit - 32.0)/9.0);
	return EXIT_SUCCESS;
}