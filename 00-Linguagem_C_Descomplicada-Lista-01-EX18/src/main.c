/* Enunciado
 * Leia um valor de volume em metros cúbicos m 3 e apresente-o convertido em litros. A
   fórmula de conversão é: L = 1000 ∗ M , sendo L o volume em litros e M o volume em
   metros cúbicos.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float volume_m3;
	scanf("f", &volume_m3);

	printf("litros: %.2f\n", volume_m3 * 1000.0);
	return EXIT_SUCCESS;
}
