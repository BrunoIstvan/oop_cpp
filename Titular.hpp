#pragma once

#include <string>
#include <iostream>
#include "Titular.hpp"
#include "Pessoa.hpp"
#include "CPF.hpp"
#include "Autenticavel.hpp"


class Titular : public Pessoa<CPF>, public Autenticavel {

public:
    Titular() = delete; // construtor padrão removido
    Titular(CPF cpf, std::string nome, std::string senha); // construtor customizado
    ~Titular(); // destructor

};
