/* Enunciado
 * Leia o salário de um funcionário. Calcule e imprima o valor do novo salário, sabendo que
   ele recebeu um aumento de 25%.
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
	float salario;
	printf("Digite o salario do funcionario.:");
	scanf("%f", &salario);
	printf("Slario com aumento: %f\n", salario - (salario * 0,25));
	return EXIT_SUCCESS;
}
