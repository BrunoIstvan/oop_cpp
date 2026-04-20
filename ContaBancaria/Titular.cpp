#include <string>
#include <iostream>
#include "Titular.hpp"
#include "CPF.hpp"


// destructor
Titular::~Titular() {
    
}

// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Titular::Titular(CPF cpf, std::string nome): 
    cpf(cpf), 
    nome(nome) {

    verificarTamanhoNomeTitular();
}

CPF Titular::obterCpf(){
    return cpf;
}

std::string Titular::obterNome(){
    return nome;
}

void Titular::verificarTamanhoNomeTitular() {

    std::cout << "Nome do titular: " << this->nome << " - Tamanho do campo: " << this->nome.size() << std::endl;

    if (this->nome.size() < 5) {
        std::cout << "Nome muito curto!" << std::endl;
        exit(1);
    }
}