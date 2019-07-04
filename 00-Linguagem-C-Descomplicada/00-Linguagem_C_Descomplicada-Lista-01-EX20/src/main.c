/* Enunciado
 * Leia um valor de massa em quilogramas e apresente-o convertido em libras. A fórmula
   de conversão é: L = K /0,45, sendo K a massa em quilogramas e L a massa em libras.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float quilogramas;
	scanf("f", &quilogramas);

	printf("Libras: %.2f\n", quilogramas / 0.45);
	return EXIT_SUCCESS;
}
