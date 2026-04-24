#pragma once
#include <string>
#include <utility>
#include <variant>
#include "Titular.hpp"

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

    enum ResultadoErroSaque { SALDO_INSUFICIENTE, VALOR_INVALIDO };

    Conta(std::string numero, Titular titular); // construtor customizado
    Conta() = delete; // construtor padrão removido
    virtual ~Conta(); // destructor
    
    std::string obterNumero();
    float obterSaldo() const;
    
    std::variant<ResultadoErroSaque, float> sacar(float valor);
    void depositar(float valor);
    void operator+=(float valor); // operator overloaded para o operador += que ira depositar um valor na conta
    std::variant<ResultadoErroSaque, float> operator-=(float valor); // operator overloaded para o operador -= que ira sacar um valor da conta
    bool operator<(const Conta& outra);
    
    virtual float taxaDeSaque() const = 0; // método puramente virtual - isso obriga que todas as classes que herdem de Conta tenha que implementar esse método
    
    friend std::ostream& operator<<(std::ostream& cout, Conta& conta); // friend function + operator overloaded para o operador << que ira exibir as informações da conta

};
