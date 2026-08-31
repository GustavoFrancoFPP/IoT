#include <stdio.h>

int main() {
    int num1;
    long long fatorial = 1;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &num1);

    if (num1 < 0) {
    printf("Erro : Forneça um numero positivo\n");
    } else {
        for (int i = 1;  i <= num1; i++){
            fatorial *= i;
        }
        printf("O fatorial de %d é: %lld\n", num1, fatorial);
    }
    return 0;
}