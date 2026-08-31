#include <iostream>

using namespace std;

int main() {
    int tamanho;
    int soma = 0;

    cout << "Digite o tamanho do array: ";
    cin >> tamanho;

    if (tamanho <= 0) {
        cout << "O tamanho deve ser maior que zero." << endl;
        return 1;
    }

    int *numeros = new int[tamanho];

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o " << i + 1 << "o valor: ";
        cin >> numeros[i];
        soma += numeros[i];
    }

    cout << "Soma dos elementos: " << soma << endl;

    delete[] numeros;

    return 0;
}
