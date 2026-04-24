#include <string>
#include <iostream>
#include <variant>
#include "Conta.hpp"


// // destructor
Conta::~Conta() {
    numeroDeContas--;
    std::cout << "Destrutor da conta" << std::endl;
}


// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Conta::Conta(std::string numero, Titular titular): 
    numero(numero), 
    titular(titular), 
    saldo(0) {

    std::cout << "Conta criada com sucesso" << std::endl;
    numeroDeContas++;
}

// usando construtor na forma mais comum
// Conta::Conta(std::string numero, Titular titular) {
//     this->numero = numero;
//     this->titular = titular;
//     this->saldo = 0;
// }

int Conta::numeroDeContas = 0;

int Conta::obterNumeroDeContas() {
    return numeroDeContas;
}


std::variant<Conta::ResultadoErroSaque, float> Conta::sacar(float valor) {

    if (valor <= 0) {
        return VALOR_INVALIDO;
    }

    float taxa = this->taxaDeSaque();
    float tarifaDoSaque = valor * taxa;
    float valorDoSaque = valor + tarifaDoSaque;

    if (valorDoSaque > saldo) {
        return SALDO_INSUFICIENTE;
    } 
    
    saldo -= valorDoSaque;
    return valorDoSaque;

}

void Conta::depositar(float valor) {

    if (valor <= 0) {
        std::cout << "Valor de depósito inválido!" << std::endl;
        return;
    }

    saldo += valor;
    std::cout << "Depósito de "<< valor << " realizado com sucesso!" << std::endl;
}

void Conta::operator+=(float valor) {
    this->depositar(valor);
}

std::variant<Conta::ResultadoErroSaque, float> Conta::operator-=(float valor) {
    return this->sacar(valor);
}

float Conta::obterSaldo() const { 
    return saldo; 
}

std::string Conta::obterNumero() {
    return this->numero;
}

bool Conta::operator<(const Conta& outra) {

    return this->saldo < outra.saldo;

}