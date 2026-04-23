#include <iostream>
#include <string>
#include "Autenticavel.hpp"
#include "Gerente.hpp"
#include "CPF.hpp"
 

Gerente::Gerente(CPF cpf, std::string nome, float salario, std::string senha) : Funcionario(cpf, nome, salario), Autenticavel(senha) {


}


float Gerente::bonificacao() const {

    return obterSalario() * 0.5;

}