/* Enunciado
 * Leia um ângulo em graus e apresente-o convertido em radianos. A fórmula de conversão
   é: R = G ∗ π/180, sendo G o ângulo em graus e R em radianos e π = 3.14.
 */


#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

int main(void) {
	float angulo;
	scanf("f", &angulo);

	printf("radianos: %.2f\n", angulo  * PI/ 180.0);
	return EXIT_SUCCESS;
}
