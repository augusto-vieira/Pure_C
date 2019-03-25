/* Enunciado
 * Leia um valor de comprimento em centı́metros e apresente-o convertido em polegadas.
   A fórmula de conversão é: P = C / 2,54, sendo C o comprimento em centı́metros e P o
   comprimento em polegadas.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float centimetros;
	scanf("f", &centimetros);

	printf("polegadas: %.2f\n", centimetros / 2.54);
	return EXIT_SUCCESS;
}
