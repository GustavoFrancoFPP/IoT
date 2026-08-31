#include <stdio.h>

int main() {
    printf("Digite a temperatua em Celsius: ");
    float celsius;
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9/5) + 32;
    float kelvin = (celsius + 273.15);

    printf("Temperatura em Fahrenheit: %.2f\n", fahrenheit);
    printf("Temperatura em Kelvin: %.2f\n", kelvin);
}