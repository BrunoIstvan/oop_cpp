#include <string>
#include <iostream>
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


void Conta::sacar(float valor) {

    if (valor <= 0) {
        std::cout << "Valor de saque inválido!" << std::endl;
        return;
    }

    float taxa = this->taxaDeSaque();
    float tarifaDoSaque = valor * taxa;
    float valorDoSaque = valor + tarifaDoSaque;

    if (valorDoSaque > saldo) {
        std::cout << "Saldo insuficiente!" << std::endl;
        return;
    } 
    
    saldo -= valorDoSaque;
    std::cout << "Saque de " << valorDoSaque << " e taxa de " << taxa * 100 << "% realizado com sucesso!" << std::endl;
    
}

void Conta::depositar(float valor) {

    if (valor <= 0) {
        std::cout << "Valor de depósito inválido!" << std::endl;
        return;
    }

    saldo += valor;
    std::cout << "Depósito de "<< valor << " realizado com sucesso!" << std::endl;
}

float Conta::obterSaldo() const { 
    return saldo; 
}

std::string Conta::obterNumero() {

    return this->numero;

}