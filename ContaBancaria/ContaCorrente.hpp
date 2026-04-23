#pragma once
#include "Titular.hpp"
#include "Conta.hpp"
#include <string>

class ContaCorrente final : public Conta {

public:
    ContaCorrente(std::string numero, Titular titular); // construtor customizado
    ContaCorrente() = delete; // construtor padrão removido
    ~ContaCorrente(); // destrutor
    
    float taxaDeSaque() const override;

    void transferePara(Conta& contaDestino, float valor);
    
};
