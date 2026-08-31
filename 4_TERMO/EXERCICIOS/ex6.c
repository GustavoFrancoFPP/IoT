#include <stdio.h>

int main() {
    int n;
    long long t1 = 0, t2 = 1, proximoTermo;

    printf("Digite a quantidade de termos da sequencia de Fibonacci: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, digite um numero maior que zero.\n");
    } else {
        printf("Os primeiros %d termos sao:\n", n);

        for (int i = 1; i <= n; i++) {
            printf("%lld ", t1);
            
            proximoTermo = t1 + t2;
            t1 = t2;
            t2 = proximoTermo;
        }
        printf("\n");
    }

    return 0;
}