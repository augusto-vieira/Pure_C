/* Enunciado
 * Leia o tamanho do lado de um quadrado e imprima como resultado a sua área.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float num;
	printf("Digita o lado do quadrado.:");
	scanf("%f", &num);
	printf("Area: %f\n", num * num);
	return EXIT_SUCCESS;
}
