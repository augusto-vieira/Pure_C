/* Enunciado
 * Peça ao usuário para digitar três valores inteiros e imprima a soma deles.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int val1, val2, val3;
	printf("Entre com 3 valores inteiros.:");
	scanf("%d %d %d", &val1, &val2, &val3);

	printf("Soma = %d\n", val1 + val2 + val3);
	return EXIT_SUCCESS;
}
