/* Enunciado
 *Leia um valor de área em acres e apresente-o convertido em metros quadrados m 2 . A
  fórmula de conversão é: M = A ∗ 4048, 58, sendo M a área em metros quadrados e A a
  área em acres.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float acres;
	scanf("f", &acres);
	printf("Metros Quadrado: %.2f\n", acres *  4048.58);
	return EXIT_SUCCESS;
}
