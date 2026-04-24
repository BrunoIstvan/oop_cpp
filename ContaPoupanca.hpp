#pragma once
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"

class ContaPoupanca final : public Conta {

public:
    ContaPoupanca(std::string numero, Titular titular); // construtor customizado
    ContaPoupanca() = delete; // construtor padrão removido
    ~ContaPoupanca(); // destrutor
    
    float taxaDeSaque() const override;
    
};
