/* Enunciado
 *Faça a leitura de três valores e apresente como resultado a soma dos quadrados dos
  três valores lidos.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int val1, val2, val3;
	scanf("%d %d %d", &val1, &val2, &val3);
	printf("Soma dos quadrados: %d\n", val1 * val1 + val2 * val2 + val3 * val3);
	return EXIT_SUCCESS;
}
