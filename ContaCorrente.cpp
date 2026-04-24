#include <string>
#include <iostream>
#include <variant>
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

std::variant<ContaCorrente::ResultadoTransferencia, float> ContaCorrente::transferePara(Conta& contaDestino, float valor) {

    if (valor <= 0) {
        return ResultadoTransferencia::VALOR_INVALIDO;
    }

    if (valor > saldo) {
        return ResultadoTransferencia::SALDO_INSUFICIENTE;
    } 

    auto resultado = sacar(valor);
    auto saldo = std::get_if<float>(&resultado); // usando std::get para obter o valor do saque do resultado da função sacar

    if(saldo == nullptr) {
        switch (std::get<ResultadoErroSaque>(resultado)) {
        case ResultadoErroSaque::SALDO_INSUFICIENTE:
            return ResultadoTransferencia::SALDO_INSUFICIENTE;
            break;
        case ResultadoErroSaque::VALOR_INVALIDO:
            return ResultadoTransferencia::VALOR_INVALIDO;
            break;  
        default:
            return ResultadoTransferencia::ERRO_INTERNO;
        }
    }
    
    contaDestino.depositar(valor);
    return this->obterSaldo();
}

void ContaCorrente::operator/=(ContaCorrente& contaOrigem) {

    contaOrigem.transferePara(*this, contaOrigem.obterSaldo() / 2);

}
