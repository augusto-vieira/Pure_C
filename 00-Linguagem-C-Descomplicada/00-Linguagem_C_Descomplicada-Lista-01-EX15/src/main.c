/* Enunciado
 * Leia um ângulo em radianos e apresente-o convertido em graus. A fórmula de conversão
   é: G = R ∗ 180/π, sendo G o ângulo em graus e R em radianos e π = 3.14.
 */


#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(void) {
	float radianos;
	scanf("f", &radianos);

	printf("radianos: %.2f\n", radianos  *  180.0 /PI);
	return EXIT_SUCCESS;
}
