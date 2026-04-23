#include <string>
#include <iostream>
#include "Pessoa.hpp"
#include "CPF.hpp"


// destructor
Pessoa::~Pessoa() {
    
}

// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Pessoa::Pessoa(CPF cpf, std::string nome): 
    cpf(cpf), 
    nome(nome) {

    std::cout << "O construtor de Pessoa foi executado" << std::endl;

    verificarTamanhoNome();
}

CPF Pessoa::obterCpf(){
    return cpf;
}

std::string Pessoa::obterNome(){
    return nome;
}

void Pessoa::verificarTamanhoNome() {

    std::cout << "Nome da pessoa: " << this->nome << " - Tamanho do campo: " << this->nome.size() << std::endl;

    if (this->nome.size() < 5) {
        std::cout << "Nome muito curto!" << std::endl;
        exit(1);
    }
}