
#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"


// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Funcionario::Funcionario(CPF cpf, std::string nome, float salario): Pessoa(cpf, nome), salario(salario) {

};

float Funcionario::obterSalario() const {

    return this->salario;

}

