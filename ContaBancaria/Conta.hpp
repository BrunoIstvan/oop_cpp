#pragma once
#include "Titular.hpp"
#include <string>

class Conta {

private:
    std::string numero;
    Titular titular;
    float saldo;

private:
    static int numeroDeContas;

public:
    static int obterNumeroDeContas();

public:

    Conta() = delete; // construtor padrão removido
    ~Conta(); // destructor
    Conta(std::string numero, Titular titular); // construtor customizado

    std::string obterNumero();

    void sacar(float valor);
    void depositar(float valor);
    
    float obterSaldo() const;

};
