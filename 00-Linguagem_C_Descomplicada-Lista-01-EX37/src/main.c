/* Enunciado
 * Faça um programa que leia o valor de um produto e imprima o valor com desconto, tendo
   em vista que o desconto foi de 12%
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	float preco;
	printf("Digite o preco do produto.:");
	scanf("%f", &preco);
	printf("Disconto: %f\n", preco - (preco * 0,12));
	return EXIT_SUCCESS;
}
