#include <iostream>
#include <string>

using namespace std;

struct Aluno {
    string nome;
    int matricula;
    double nota;
};

int main() {
    const int quantidade = 3;
    Aluno alunos[quantidade];
    int indiceMaiorNota = 0;

    for (int i = 0; i < quantidade; i++) {
        cout << "Aluno " << i + 1 << endl;

        cout << "Nome: ";
        getline(cin >> ws, alunos[i].nome);

        cout << "Matricula: ";
        cin >> alunos[i].matricula;

        cout << "Nota: ";
        cin >> alunos[i].nota;

        if (alunos[i].nota > alunos[indiceMaiorNota].nota) {
            indiceMaiorNota = i;
        }

        cout << endl;
    }

    cout << "Aluno com a maior nota:" << endl;
    cout << "Nome: " << alunos[indiceMaiorNota].nome << endl;
    cout << "Matricula: " << alunos[indiceMaiorNota].matricula << endl;
    cout << "Nota: " << alunos[indiceMaiorNota].nota << endl;

    return 0;
}
