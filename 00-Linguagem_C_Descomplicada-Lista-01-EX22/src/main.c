/* Enunciado
 * Leia um valor de comprimento em jardas e apresente-o convertido em metros. A fórmula
   de conversão é: M = 0, 91 ∗ J, sendo J o comprimento em jardas e M o comprimento
   em metros.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float jardas;
	scanf("f", &jardas);

	printf("Metros: %.2f\n", jardas * 0.91);
	return EXIT_SUCCESS;
}
