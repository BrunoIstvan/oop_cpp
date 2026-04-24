#include <iostream>
#include "Caixa.hpp"
#include "Funcionario.hpp"
#include "Pessoa.hpp"
#include "DiaDaSemana.hpp"
#include "CPF.hpp"
 

Caixa::Caixa(CPF cpf, std::string nome, float salario, DiaDaSemana diaDePagamento) : Funcionario(cpf, nome, salario, diaDePagamento) {


}


float Caixa::bonificacao() const {

    return obterSalario() * 0.1;

}