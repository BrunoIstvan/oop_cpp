#pragma once

#include <string>
#include <iostream>
#include "Pessoa.hpp"
#include "CPF.hpp"

class Pessoa {

protected:
    CPF cpf;
    std::string nome;


public:
    Pessoa() = delete; // construtor padrão removido
    Pessoa(CPF cpf, std::string nome); // construtor customizado
    ~Pessoa(); // destructor
    CPF obterCpf();
    std::string obterNome();
    
private:
    void verificarTamanhoNome();


};
