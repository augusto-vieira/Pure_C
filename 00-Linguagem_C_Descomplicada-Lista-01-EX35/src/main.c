/* Enunciado
 * Sejam a e b os
   catetos de um triângulo, onde a hipotenusa é obtida pela equação:
   hipotenusa = √a 2 + b 2 . Faça um programa que receba os valores de a e b e calcule
   o valor da hipotenusa através da equação. Imprima o resultado dessa operação.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	float cat_a, cat_b;
	printf("Digite o cateto adjacente e cateto oposto.:");
	scanf("%f %f", &cat_a, &cat_b);
	printf("Hipotenusa: %f\n", sqrtf((powf(cat_a, 2.0) + powf(cat_b, 2.0))));
	return EXIT_SUCCESS;
}
