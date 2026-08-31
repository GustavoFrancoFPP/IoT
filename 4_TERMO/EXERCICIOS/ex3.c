#include <stdio.h>

int main() { 
    int numero;
    printf("Insira um numero: ");
    scanf("%d", &numero);

    printf("O numero e %s.\n", (numero % 2 == 0) ? "Par" : "Impar");

    return 0;
}