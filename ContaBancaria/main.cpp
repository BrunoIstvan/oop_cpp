#include <iostream>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Autenticavel.hpp"
#include "Titular.hpp"
#include "CPF.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"
using namespace std;

void ExibeSaldo(Conta& conta) {

    // exemplo criado apenas para demonstrar o funcionamento do destructor
    // Conta conta12("12345-6", Titular("123.456.789-00", "João Candeia"));

    cout << "Saldo da conta número: " << conta.obterNumero() << " é de R$ " << conta.obterSaldo() << endl << endl;
    
}

void RealizaSaque(Conta& conta, float valor) {

    conta.sacar(valor);

}

void FazLogin(Autenticavel& autenticavel, std::string senha) {

    if (autenticavel.autentica(senha)) {
        cout << "Login realizado com sucesso!" << endl << endl;
    } else {
        cout << "Falha no login! Senha incorreta." << endl << endl;
    }

}


int main() {

    // repare que o primeiro parametro da classe Titular está sendo um valor do tipo string quando seria esperado um tipo CPF
    // O que está acontecendo aqui é uma conversão implícita que o C++ faz. Isso só está funcionando de fato porque a classe CPF tem um construtor recebendo somente string
    Titular titular(string("123.456.789-00"), "Claudiomir Santos", "cla123");
    ContaCorrente conta1("12345-6", titular);
    conta1.depositar(200.0);
    RealizaSaque(conta1, 100.00);
    ExibeSaldo(conta1);
    FazLogin(titular, "cla123");
    
    // Aqui o primeiro parametro do Titular é um CPF de fato
    Titular titular2(CPF("987.654.321-00"), "Maria Souza", "mar123");
    ContaCorrente conta2("98765-4", titular2    );
    conta2.depositar(500.0);
    RealizaSaque(conta2, 100.00);
    ExibeSaldo(conta2);
    FazLogin(titular2, "mar123");

    // repare que o primeiro parametro da classe Titular está sendo um valor do tipo VETOR DE CARACTERES quando seria esperado um tipo CPF
    // O que está acontecendo aqui é uma conversão implícita que o C++ faz. Isso só está funcionando de fato porque a classe CPF tem um construtor recebendo um VETOR DE CARACTERES
    std::string cpf = "567.443.223-55";
    Titular titular3(cpf, "Joana Clara", "joa123");
    ContaPoupanca conta3("4444-4", titular3);
    conta3.depositar(1500.0);
    RealizaSaque(conta3, 200.00);
    ExibeSaldo(conta3);
    FazLogin(titular3, "joa123");

    cout << "Número de contas: " << Conta::obterNumeroDeContas() << endl << endl;
    

    std::cout << endl << "Realizando transferência de conta corrente para uma outra conta" << std::endl;
    conta1.transferePara(conta3, 50);


    Gerente gerente(CPF("444.555.666-33"), "Claudio Ramos", 2000.00, "ger123");
    std::cout << "Nome do gerente: " << gerente.obterNome() << " - Salário: " << gerente.obterSalario() << std::endl << endl;

    Caixa caixa(CPF("111.555.666-33"), "Claudecir Pereira Rocha", 1000.00);
    std::cout << "Nome do caixa: " << caixa.obterNome() << " - Salário: " << caixa.obterSalario() << std::endl << endl;

    return 0;

}