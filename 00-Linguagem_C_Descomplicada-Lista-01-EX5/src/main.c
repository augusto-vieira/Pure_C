/* Enunciado
 * Leia um número real e imprima a quinta parte deste número.
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float val;

	scanf("%f", &val);

	printf("Fifth part = %f\n", val/5.0);
	return EXIT_SUCCESS;
}
