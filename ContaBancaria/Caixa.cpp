#include <iostream>
#include "Caixa.hpp"
#include "CPF.hpp"
 

Caixa::Caixa(CPF cpf, std::string nome, float salario) : Funcionario(cpf, nome, salario) {


}


float Caixa::bonificacao() const {

    return obterSalario() * 0.1;

}