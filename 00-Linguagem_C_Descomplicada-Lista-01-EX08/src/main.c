/* Enunciado
 * Leia uma temperatura em graus Kelvin e apresente-a convertida em graus Celsius. A
   fórmula de conversão é: C = K − 273.15, sendo C a temperatura em Celsius e K a
   temperatura em Kelvin.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float kelvin;
	scanf("f", &kelvin);

	printf("Celsius: %f\n", kelvin - 273.15);
	return EXIT_SUCCESS;
}
