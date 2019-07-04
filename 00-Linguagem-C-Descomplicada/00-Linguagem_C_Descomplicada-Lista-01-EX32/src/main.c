/* Enunciado
 * Leia um número inteiro e imprima a soma do sucessor de seu triplo com o antecessor de
   seu dobro.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int num;
	printf("Digita um valor inteiro.:");
	scanf("%d", &num);
	printf("Soma: %d\n", ((num - 1) * 2) + ((num + 1) * 3));
	return EXIT_SUCCESS;
}
