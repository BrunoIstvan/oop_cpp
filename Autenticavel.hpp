#pragma once
#include <string>

class Autenticavel {

protected:
    std::string senha;

public:
    Autenticavel(std::string senha);
    virtual bool autentica(std::string senha) const;
};