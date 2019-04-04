/* Enunciado
 * Leia a altura e o raio de um cilindro circular e imprima o volume do cilindro. O volume
   de um cilindro circular é calculado por meio da seguinte fórmula: V = π ∗ raio 2 ∗ altura,
   onde π = 3.141592.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	float alt, raio;
	printf("Digite a altura e o raio.:");
	scanf("%f %f", &alt, &raio);
	printf("Volume do cilindro: %f\n", M_PI * raio * raio * alt);
	return EXIT_SUCCESS;
}
