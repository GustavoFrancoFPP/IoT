#include <iostream>

using namespace std;

class Veiculo {
public:
    virtual void exibirInfo() const {
        cout << "Informacoes do veiculo." << endl;
    }

    virtual ~Veiculo() = default;
};

class Carro : public Veiculo {
private:
    int portas;

public:
    Carro(int quantidadePortas) {
        portas = quantidadePortas;
    }

    void exibirInfo() const override {
        cout << "Carro com " << portas << " portas." << endl;
    }
};

class Moto : public Veiculo {
private:
    int cilindradas;

public:
    Moto(int quantidadeCilindradas) {
        cilindradas = quantidadeCilindradas;
    }

    void exibirInfo() const override {
        cout << "Moto com " << cilindradas << " cilindradas." << endl;
    }
};

int main() {
    Carro carro(4);
    Moto moto(160);

    Veiculo *veiculo;

    veiculo = &carro;
    veiculo->exibirInfo();

    veiculo = &moto;
    veiculo->exibirInfo();

    return 0;
}
