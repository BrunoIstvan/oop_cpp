#pragma once
#include <iostream>
#include "Funcionario.hpp"
#include "DiaDaSemana.hpp"


class Caixa final: public Funcionario {

public:

    Caixa(CPF cpf, std::string nome, float salario, DiaDaSemana diaDePagamento);
    float bonificacao() const;

};