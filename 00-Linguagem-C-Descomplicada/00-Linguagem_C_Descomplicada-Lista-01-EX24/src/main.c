/* Enunciado
 *Leia um valor de área em metros quadrados m 2 e apresente-o convertido em acres. A
  fórmula de conversão é: A = M ∗ 0, 000247, sendo M a área em metros quadrados e A
  a área em acres.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float area;
	scanf("f", &area);
	printf("Acres: %.2f\n", area  *  0.000247);
	return EXIT_SUCCESS;
}
