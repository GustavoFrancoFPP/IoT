#include <stdio.h>    
    
    int main() {

    float nota1, nota2, nota3, nota4, media;
    printf("digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("digite a quarta nota: ");
    scanf("%f", &nota4);

    media = (nota1 + nota2 + nota3 + nota4) / 4;

        if (media >= 7.0) {
            printf("Aprovado\n");
        } else if (media >= 5.0) {
            printf("Recuperacao\n");
        } else {
            printf("Reprovado\n");
        }

        return 0;
    }