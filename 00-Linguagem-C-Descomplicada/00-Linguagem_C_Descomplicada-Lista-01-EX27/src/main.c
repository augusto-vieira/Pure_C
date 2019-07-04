/* Enunciado
 *Leia um valor de área em hectares e apresente-o convertido em metros quadrados m 2 .
  A fórmula de conversão é: M = H ∗ 10000, sendo M a área em metros quadrados e H
  a área em hectares.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float hectar;
	scanf("f", &hectar);
	printf("Metros Quadrado: %.2f\n", hectar * 10000);
	return EXIT_SUCCESS;
}
