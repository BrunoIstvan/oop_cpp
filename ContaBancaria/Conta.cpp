#include <string>
#include <iostream>
#include "Conta.hpp"


// destructor
Conta::~Conta() {
    numeroDeContas--;
}


// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Conta::Conta(std::string numero, Titular titular): 
    numero(numero), 
    titular(titular), 
    saldo(0) {

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

void Conta::sacar(float valor) {

    if (valor <= 0) {
        std::cout << "Valor de saque inválido!" << std::endl;
        return;
    } else if (valor > saldo) {
        std::cout << "Saldo insuficiente!" << std::endl;
        return;
    } 
    
    saldo -= valor;
    std::cout << "Saque realizado com sucesso!" << std::endl;
    
}

void Conta::depositar(float valor) {

    if (valor <= 0) {
        std::cout << "Valor de depósito inválido!" << std::endl;
        return;
    }

    saldo += valor;
    std::cout << "Depósito realizado com sucesso!" << std::endl;
}

float Conta::obterSaldo() const { 
    return saldo; 
}

std::string Conta::obterNumero() {

    return this->numero;

}