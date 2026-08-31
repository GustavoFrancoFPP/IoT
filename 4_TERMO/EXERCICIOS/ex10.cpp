#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void converterParaMaiusculas(string &texto) {
    for (char &caractere : texto) {
        caractere = static_cast<char>(toupper(static_cast<unsigned char>(caractere)));
    }
}

int main() {
    string texto;

    cout << "Digite uma frase: ";
    getline(cin, texto);

    converterParaMaiusculas(texto);

    cout << "Texto em maiusculas: " << texto << endl;

    return 0;
}
