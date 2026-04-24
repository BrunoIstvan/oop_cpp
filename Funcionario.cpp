
#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "CPF.hpp"
#include "DiaDaSemana.hpp" 


// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Funcionario::Funcionario(CPF cpf, std::string nome, float salario, DiaDaSemana diaDePagamento): Pessoa(cpf, nome), salario(salario), diaDePagamento(diaDePagamento) {

};

float Funcionario::obterSalario() const {

    return this->salario;

}

