/* Enunciado
 * Leia um valor de massa em libras e apresente-o convertido em quilogramas. A fórmula
   de conversão é: K = L ∗ 0, 45, sendo K a massa em quilogramas e L a massa em libras.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float libras;
	scanf("f", &libras);

	printf("Quilogramas: %.2f\n", libras * 0.45);
	return EXIT_SUCCESS;
}
