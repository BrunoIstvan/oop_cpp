#pragma once
#include "Titular.hpp"
#include <string>

class Conta {

private:
    std::string numero;
    Titular titular;

protected:
    float saldo;

private:
    static int numeroDeContas;

public:
    static int obterNumeroDeContas();

public:

    Conta(std::string numero, Titular titular); // construtor customizado
    Conta() = delete; // construtor padrão removido
    virtual ~Conta(); // destructor
    
    std::string obterNumero();
    float obterSaldo() const;
    
    void sacar(float valor);
    void depositar(float valor);
    virtual float taxaDeSaque() const = 0; // método puramente virtual - isso obriga que todas as classes que herdem de Conta tenha que implementar esse método
    
};
