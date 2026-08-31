#include <iostream>

using namespace std;

void encontrarMaiorMenor(int vetor[], int tamanho, int *maior, int *menor) {
    *maior = vetor[0];
    *menor = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > *maior) {
            *maior = vetor[i];
        }

        if (vetor[i] < *menor) {
            *menor = vetor[i];
        }
    }
}

int main() {
    const int tamanho = 5;
    int numeros[tamanho];
    int maior;
    int menor;

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o " << i + 1 << "o numero: ";
        cin >> numeros[i];
    }

    encontrarMaiorMenor(numeros, tamanho, &maior, &menor);

    cout << "Maior valor: " << maior << endl;
    cout << "Menor valor: " << menor << endl;

    return 0;
}
