/* Enunciado
 * Leia uma temperatura em graus Celsius e apresente-a convertida em graus Kelvin. A
   fórmula de conversão é: K = C + 273.15, sendo C a temperatura em Celsius e K a
   temperatura em Kelvin.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float celsius;
	scanf("f", &celsius);

	printf("Kelvin: %f\n", celsius + 273.15);
	return EXIT_SUCCESS;
}
