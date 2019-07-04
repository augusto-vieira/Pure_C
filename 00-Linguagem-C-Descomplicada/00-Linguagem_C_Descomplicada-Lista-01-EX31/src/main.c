/* Enunciado
 * Leia um número inteiro e imprima o seu antecessor e o seu sucessor.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int num;
	printf("Digita um valor inteiro.:");
	scanf("%d", &num);
	printf("Antecessor: %d, Sucessor: %d\n", num - 1, num + 1);
	return EXIT_SUCCESS;
}
