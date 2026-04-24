#pragma once
#include <iostream>
#include <string>
#include "Funcionario.hpp"
#include "Autenticavel.hpp"
#include "DiaDaSemana.hpp"
#include "CPF.hpp"


class Gerente final: public Funcionario, public Autenticavel {

public:

    Gerente(CPF cpf, std::string nome, float salario, std::string senha, DiaDaSemana diaDePagamento);
    float bonificacao() const override;

};