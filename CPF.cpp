#include <iostream>
#include <string>
#include "CPF.hpp"



CPF::CPF(std::string numero): numero(numero) {

    // AQUI VAI CHAMAR A VALIDAÇÃO COMPLEXA DO NÚMERO DO CPF

}

CPF::CPF(char* numero): numero(numero) {

    // AQUI VAI CHAMAR A VALIDAÇÃO COMPLEXA DO NÚMERO DO CPF

}



std::string CPF::obterNumero() { 
    return this->numero;
}
