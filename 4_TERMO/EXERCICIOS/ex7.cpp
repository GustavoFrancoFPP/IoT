#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros(10);
    int busca;
    int indiceEncontrado = -1;

    for (int i = 0; i < 10; i++) {
        cout << "Digite o " << i + 1 << "o numero: ";
        cin >> numeros[i];
    }

    cout << "Digite o valor que deseja buscar: ";
    cin >> busca;

    for (int i = 0; i < 10; i++) {
        if (numeros[i] == busca) {
            indiceEncontrado = i;
            break;
        }
    }

    if (indiceEncontrado != -1) {
        cout << "Valor encontrado no indice " << indiceEncontrado << "." << endl;
    } else {
        cout << "Valor nao encontrado no vetor." << endl;
    }

    return 0;
}
