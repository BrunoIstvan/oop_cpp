#pragma once
#include <string>
#include <variant>
#include "Titular.hpp"
#include "Conta.hpp"

class ContaCorrente final : public Conta {

public:

    enum ResultadoTransferencia { ERRO_INTERNO, SALDO_INSUFICIENTE, VALOR_INVALIDO };

    ContaCorrente(std::string numero, Titular titular); // construtor customizado
    ContaCorrente() = delete; // construtor padrão removido
    ~ContaCorrente(); // destrutor
    
    float taxaDeSaque() const override;

    std::variant<ResultadoTransferencia, float> transferePara(Conta& contaDestino, float valor);
    void operator/=(ContaCorrente& contaOrigem); // operator overloaded para o operador /= que ira transferir metade do valor de uma conta para outra como exemplo de uso do operator overloaded
    
};
