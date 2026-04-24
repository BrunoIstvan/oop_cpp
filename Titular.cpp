#include <string>
#include <iostream>
#include "Titular.hpp"
#include "CPF.hpp"


// destructor
Titular::~Titular() {
    
}

// usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
Titular::Titular(CPF cpf, std::string nome, std::string senha): Pessoa(cpf, nome), Autenticavel(senha) {

}
