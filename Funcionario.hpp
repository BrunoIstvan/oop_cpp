#pragma once

#include <string>
#include "Pessoa.hpp"
#include "CPF.hpp"
#include "DiaDaSemana.hpp"


class Funcionario: public Pessoa<CPF> {

public:
    Funcionario(CPF cpf, std::string nome, float salario, DiaDaSemana diaDePagamento);
    float obterSalario() const;
    virtual float bonificacao() const = 0;

private:
    float salario;
    DiaDaSemana diaDePagamento;


};