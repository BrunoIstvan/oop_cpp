#pragma once
#include "Titular.hpp"
#include "Conta.hpp"
#include <string>

class ContaPoupanca final : public Conta {

public:
    ContaPoupanca(std::string numero, Titular titular); // construtor customizado
    ContaPoupanca() = delete; // construtor padrão removido
    ~ContaPoupanca(); // destrutor
    
    float taxaDeSaque() const override;
    
};
