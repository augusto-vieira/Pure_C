/* Enunciado
 *Leia quatro notas, calcule a média aritmética e imprima o resultado.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float n1, n2, n3, n4;
	scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
	printf("Media Aritimetica: %.2f\n", (n1 + n2 + n3 + n4)/ 4.0);
	return EXIT_SUCCESS;
}
