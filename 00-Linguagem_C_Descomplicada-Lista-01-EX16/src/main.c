/* Enunciado
 * Leia um valor de comprimento em polegadas e apresente-o convertido em centı́metros.
   A fórmula de conversão é: C = P ∗ 2, 54, sendo C o comprimento em centı́metros e P o
   comprimento em polegadas
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float polegadas;
	scanf("f", &polegadas);

	printf("centimetros: %.2f\n", polegadas * 2.54);
	return EXIT_SUCCESS;
}
