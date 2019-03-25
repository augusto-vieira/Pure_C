/* Enunciado
 * Leia um valor de volume em litros e apresente-o convertido em metros cúbicos m 3 . A
 * fórmula de conversão é: M = L / 1000, sendo L o volume em litros e M o volume em metros
   cúbicos
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float litros;
	scanf("f", &litros);

	printf("volume em m3: %.2f\n", litros / 1000.0);
	return EXIT_SUCCESS;
}
