#pragma once

#include <string>


class CPF {

public:
    // CASO EU QUEIRA FORÇAR O USO DESSE CONSTRUTOR PADRÃO, EVITANDO A CONVERSÃO IMPLÍCITA, EU PRECISO UTILIZAR A PALAVRA explicit
    // explicit CPF(std::string numero);
    CPF(std::string numero);
    CPF(char* numero);

    void validarCPF();
    std::string obterNumero();

private:
    std::string numero;

};