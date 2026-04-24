
#pragma once

#include <string>
#include <iostream>
#include "Pessoa.hpp"

template<typename Documento> // template function para comparar dois valores de qualquer tipo e retornar
class Pessoa { 
    
protected:
    Documento documento;
    std::string nome;

public:
    Pessoa() = delete; // construtor padrão removido
    
    std::string obterNome(){
        return nome;
    }

    // destructor
    ~Pessoa() {
        
    }

    // usando initialization list - isso evita um processo de inicialização das propriedades não primitivas
    Pessoa(Documento documento, std::string nome): 
        documento(documento), 
        nome(nome) {
        std::cout << "O construtor de Pessoa foi executado" << std::endl;
        verificarTamanhoNome();
    }

    Documento obterDocumento(){
        return documento;
    }

private:
    
    void verificarTamanhoNome() {

        std::cout << "Nome da pessoa: " << this->nome << " - Tamanho do campo: " << this->nome.size() << std::endl;

        if (this->nome.size() < 5) {
            std::cout << "Nome muito curto!" << std::endl;
            exit(1);
        }
    }

};

