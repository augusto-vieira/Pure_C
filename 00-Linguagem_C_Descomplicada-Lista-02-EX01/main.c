#include <stdlib.h>
#include <stdio.h>

//Faça um programa que receba dois números e mostre qual deles é o maior.

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;
  int n1 , n2;

  printf("Entre com o valor 1: ");
  scanf("%d", &n1);
  printf("Entre com o valor 2: ");
  scanf("%d", &n2);
  if(n1 > n2)
    printf("Maior valor: %d\n", n1);
  else
    printf("Maior valor: %d\n", n2);


  return EXIT_SUCCESS;
}
