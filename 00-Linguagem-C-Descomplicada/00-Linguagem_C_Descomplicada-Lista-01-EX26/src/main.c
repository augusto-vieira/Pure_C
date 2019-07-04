/* Enunciado
 *Leia um valor de área em metros quadrados m 2 e apresente-o convertido em hectares.
  A fórmula de conversão é: H = M ∗ 0, 0001, sendo M a área em metros quadrados e H
  a área em hectares.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float area;
	scanf("f", &area);
	printf("Hectares: %.2f\n", area *  0.0001);
	return EXIT_SUCCESS;
}
