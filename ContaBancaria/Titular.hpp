#pragma once

#include <string>
#include <iostream>
#include "Titular.hpp"
#include "CPF.hpp"

class Titular {

private:
    CPF cpf;
    std::string nome;


public:
    Titular() = delete; // construtor padrão removido
    Titular(CPF cpf, std::string nome); // construtor customizado
    ~Titular(); // destructor
    CPF obterCpf();
    std::string obterNome();
    
private:
    void verificarTamanhoNomeTitular();


};
