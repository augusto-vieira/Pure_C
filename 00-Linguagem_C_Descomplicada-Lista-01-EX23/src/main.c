/* Enunciado
 *Leia um valor de comprimento em metros e apresente-o convertido em jardas. A fórmula
  de conversão é: J = M/ 0,91, sendo J o comprimento em jardas e M o comprimento em metros
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float metros;
	scanf("f", &metros);

	printf("Jardas: %.2f\n", metros / 0.91);
	return EXIT_SUCCESS;
}
