/* Enunciado
 *Leia um valor em real e a cotação do dólar. Em seguida, imprima o valor correspondente
  em dólares.
 */


#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float real, cotacao_dolar;
	printf("Digita um valor em reais e a cotação do dolar.:");
	scanf("%f %f", &real, &cotacao_dolar);
	printf("Valor em dolares: %.2f\n", real * cotacao_dolar);
	return EXIT_SUCCESS;
}
