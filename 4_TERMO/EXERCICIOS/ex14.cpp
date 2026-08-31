#include <iostream>
#include <string>

using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;

public:
    ContaBancaria(string titularConta, double saldoInicial) {
        titular = titularConta;
        saldo = saldoInicial;
    }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Deposito realizado com sucesso." << endl;
        } else {
            cout << "Valor de deposito invalido." << endl;
        }
    }

    void sacar(double valor) {
        if (valor <= 0) {
            cout << "Valor de saque invalido." << endl;
        } else if (valor > saldo) {
            cout << "Saque bloqueado. Saldo insuficiente." << endl;
        } else {
            saldo -= valor;
            cout << "Saque realizado com sucesso." << endl;
        }
    }

    void exibirSaldo() const {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: R$ " << saldo << endl;
    }
};

int main() {
    string titular;
    double saldoInicial;
    double valor;

    cout << "Digite o nome do titular: ";
    getline(cin, titular);

    cout << "Digite o saldo inicial: ";
    cin >> saldoInicial;

    ContaBancaria conta(titular, saldoInicial);

    cout << "Digite o valor para deposito: ";
    cin >> valor;
    conta.depositar(valor);

    cout << "Digite o valor para saque: ";
    cin >> valor;
    conta.sacar(valor);

    conta.exibirSaldo();

    return 0;
}
