/* Enunciado
 * Leia o salário de um funcionário. Calcule e imprima o valor do novo salário, sabendo que
   ele recebeu um aumento de 25%.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	const float premio = 780000.0;
	float ganha46 = premio * 0.46;
	float ganha32 = premio * 0.32;
	float ganha_resto = premio - (ganha46 + ganha32);

	printf("Ganhador_1: %0.2f\nGanhador_2: %0.2f\nGanhador_3: %0.2f\n", ganha46, ganha32, ganha_resto);
	printf("Total = %0.2f\n", ganha46 + ganha32 + ganha_resto);
	return EXIT_SUCCESS;
}
