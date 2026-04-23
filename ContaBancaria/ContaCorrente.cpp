#include <string>
#include <iostream>
#include "Conta.hpp"
#include "ContaCorrente.hpp"


// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
ContaCorrente::ContaCorrente(std::string numero, Titular titular): Conta(numero, titular) {

    std::cout << "ContaCorrente criada com sucesso - Número: " << this->obterNumero() << std::endl;

}

// destructor
ContaCorrente::~ContaCorrente() {
    std::cout << "Destrutor da conta corrente" << std::endl;
}

float ContaCorrente::taxaDeSaque() const {
    return 0.05;
}

void ContaCorrente::transferePara(Conta& contaDestino, float valor) {

    if (valor <= 0) {
        std::cout << "Valor de transferência inválido!" << std::endl;
        return;
    }

    if (valor > saldo) {
        std::cout << "Saldo insuficiente!" << std::endl;
        return;
    } 

    sacar(valor);
    contaDestino.depositar(valor);

    std::cout << "Transferência no valor " << valor << " realizada com sucesso para a conta " << contaDestino.obterNumero() << std::endl << std::endl;

}

