#include <iostream>

using namespace std;

int main() {
    int numeros[5];

    for (int i = 0; i < 5; i++) {
        cout << "Digite o " << i + 1 << "o elemento: ";
        cin >> numeros[i];
    }

    cout << "Array na ordem inversa: ";
    for (int i = 4; i >= 0; i--) {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}
