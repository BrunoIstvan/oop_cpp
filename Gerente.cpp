#include <iostream>
#include <string>
#include "Autenticavel.hpp"
#include "Gerente.hpp"
#include "CPF.hpp"
#include "Funcionario.hpp"
#include "DiaDaSemana.hpp"
 

Gerente::Gerente(CPF cpf, std::string nome, float salario, std::string senha, DiaDaSemana diaDePagamento) : Funcionario(cpf, nome, salario, diaDePagamento), Autenticavel(senha) {


}


float Gerente::bonificacao() const {

    return obterSalario() * 0.5;

}