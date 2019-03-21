/* Enunciado
 * Leia um número real e imprima o resultado do quadrado desse número.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float val;

	scanf("%f", &val);

	printf("Square = %f\n", val + val);
	return EXIT_SUCCESS;
}
