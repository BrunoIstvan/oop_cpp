#include <iostream>
#include "Conta.hpp"
#include "Titular.hpp"
#include "CPF.hpp"
using namespace std;

void ExibeSaldo(Conta& conta) {

    // exemplo criado apenas para demonstrar o funcionamento do destructor
    // Conta conta12("12345-6", Titular("123.456.789-00", "João Candeia"));

    cout << "Saldo da conta: " << conta.obterSaldo() << endl;
    
}


int main() {

    // repare que o primeiro parametro da classe Titular está sendo um valor do tipo string quando seria esperado um tipo CPF
    // O que está acontecendo aqui é uma conversão implícita que o C++ faz. Isso só está funcionando de fato porque a classe CPF tem um construtor recebendo somente string
    Titular titular(string("123.456.789-00"), "Claudiomir Santos");
    Conta conta1("12345-6", titular);
    conta1.depositar(200.0);
    conta1.sacar(100.0);
    cout << "Saldo da conta 1: R$ " << conta1.obterSaldo() << endl;

    ExibeSaldo(conta1);
    
    // Aqui o primeiro parametro do Titular é um CPF de fato
    Conta conta2("98765-4", Titular(CPF("987.654.321-00"), "Maria Souza"));
    conta2.depositar(500.0);
    conta2.sacar(100.0);
    cout << "Saldo da conta 2: R$ " << conta2.obterSaldo() << endl;

    ExibeSaldo(conta2);

    // repare que o primeiro parametro da classe Titular está sendo um valor do tipo VETOR DE CARACTERES quando seria esperado um tipo CPF
    // O que está acontecendo aqui é uma conversão implícita que o C++ faz. Isso só está funcionando de fato porque a classe CPF tem um construtor recebendo um VETOR DE CARACTERES
    std::string cpf = "567.443.223-55";
    Conta conta3("4444-4", Titular(cpf, "Joana Clara"));
    conta3.depositar(1500.0);
    conta3.sacar(200.0);
    cout << "Saldo da conta 3: R$ " << conta3.obterSaldo() << endl;

    ExibeSaldo(conta3);

    cout << "Número de contas: " << Conta::obterNumeroDeContas() << endl;
    

}