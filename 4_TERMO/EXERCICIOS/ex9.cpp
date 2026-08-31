#include <iostream>

using namespace std;

void trocarPorPonteiros(int *a, int *b) {
    int temporario = *a;
    *a = *b;
    *b = temporario;
}

void trocarPorReferencias(int &a, int &b) {
    int temporario = a;
    a = b;
    b = temporario;
}

int main() {
    int valor1;
    int valor2;

    cout << "Digite dois valores inteiros: ";
    cin >> valor1 >> valor2;

    cout << "Antes da troca por ponteiros: " << valor1 << " e " << valor2 << endl;
    trocarPorPonteiros(&valor1, &valor2);
    cout << "Depois da troca por ponteiros: " << valor1 << " e " << valor2 << endl;

    cout << "Antes da troca por referencias: " << valor1 << " e " << valor2 << endl;
    trocarPorReferencias(valor1, valor2);
    cout << "Depois da troca por referencias: " << valor1 << " e " << valor2 << endl;

    return 0;
}
