#pragma once

#include <string>
#include "Pessoa.hpp"
#include "CPF.hpp"


class Funcionario: public Pessoa {

public:
    Funcionario(CPF cpf, std::string nome, float salario);
    float obterSalario() const;
    virtual float bonificacao() const = 0;

private:
    float salario;


};