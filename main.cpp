#include <iostream>
#include <variant>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Autenticavel.hpp"
#include "Titular.hpp"
#include "CPF.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"
#include "DiaDaSemana.hpp"
using namespace std;

template<typename T> // template function para comparar dois valores de qualquer tipo e retornar o menor valor
T Menor(T a, T b) {
    return a < b ? a : b;
}


void ExibeSaldo(Conta& conta) {

    // exemplo criado apenas para demonstrar o funcionamento do destructor
    // Conta conta12("12345-6", Titular("123.456.789-00", "João Candeia"));

    cout << "Saldo da conta número: " << conta.obterNumero() << " é de R$ " << conta.obterSaldo() << endl << endl;
    
}

void RealizaSaque(Conta& conta, float valor) {

    auto resultado = conta.sacar(valor);
    auto saqueResult = std::get_if<float>(&resultado); // usando std::get para obter o valor do saque do resultado da função sacar
    // resultado.first - resultado do saque (SUCESSO, SALDO_INSUFICIENTE ou VALOR_INVALIDO)
    // resultado.second - valor do saque (valor do saque + taxa) ou 0 caso o saque tenha sido recusado   
    
    if(saqueResult != nullptr) {
        cout << "Saque de " << valor << " e taxa de " << conta.taxaDeSaque() * 100 << "% realizado com sucesso!" << endl;
    } else if (std::get<Conta::ResultadoErroSaque>(resultado) == Conta::ResultadoErroSaque::SALDO_INSUFICIENTE) {
        cout << "Saldo insuficiente para realizar o saque!" << endl;
    } else if (std::get<Conta::ResultadoErroSaque>(resultado) == Conta::ResultadoErroSaque::VALOR_INVALIDO) {
        cout << "Valor de saque inválido!" << endl;
    }
    
}

void RealizaTransferencia(ContaCorrente& contaOrigem, Conta& contaDestino, float valor) {
    
    cout << endl << "Realizando transferência de conta corrente para uma outra conta" << endl;
    
    auto resultado = contaOrigem.transferePara(contaDestino, valor);
    auto saldoContaOrigem = std::get_if<float>(&resultado); // usando std::get para obter o saldo da conta de origem do resultado da função transferePara

    // resultado.first - resultado da transferência (SUCESSO, SALDO_INSUFICIENTE ou VALOR_INVALIDO)
    // resultado.second - saldo da conta de origem após a transferência ou saldo da conta de origem caso a transferência tenha sido recusada
    
    if(saldoContaOrigem != nullptr) {
        cout << "Transferência de " << valor << " realizada com sucesso da conta " << contaOrigem.obterNumero() << " para a conta " << contaDestino.obterNumero() << endl << endl;
    } else if (std::get<ContaCorrente::ResultadoTransferencia>(resultado) == ContaCorrente::ResultadoTransferencia::SALDO_INSUFICIENTE) {
        cout << "Saldo insuficiente para realizar a transferência!" << endl;
    } else if (std::get<ContaCorrente::ResultadoTransferencia>(resultado) == ContaCorrente::ResultadoTransferencia::VALOR_INVALIDO) {
        cout << "Valor de transferência inválido!" << endl;
    }

}

void FazLogin(Autenticavel& autenticavel, string senha) {

    if (autenticavel.autentica(senha)) {
        cout << "Login realizado com sucesso!" << endl << endl;
    } else {
        cout << "Falha no login! Senha incorreta." << endl << endl;
    }

}


ostream& operator<<(ostream& cout, Conta& conta) { // operator overloaded para o operador << que ira exibir as informações da conta

    Pessoa titular = conta.titular; // acessando a propriedade titular da classe Conta que é do tipo Titular e atribuindo a uma variável do tipo Pessoa para acessar os métodos da classe Pessoa
    cout << ">>> Informações da conta <<< " << endl;
    cout << "Número da conta: " << conta.obterNumero() << endl;
    cout << "Titular da conta: " << titular.obterNome() << endl;
    cout << "CPF do titular: " << titular.obterDocumento().obterNumero() << endl;
    cout << "Saldo da conta: " << conta.obterSaldo() << endl;
    cout << "Taxa de saque: " << conta.taxaDeSaque() * 100 << "%" << endl;
    cout << ">>>>>>>>>>>>><<<<<<<<<<<<<<" << endl;
    return cout;
}

int main() {

    // repare que o primeiro parametro da classe Titular está sendo um valor do tipo string quando seria esperado um tipo CPF
    // O que está acontecendo aqui é uma conversão implícita que o C++ faz. Isso só está funcionando de fato porque a classe CPF tem um construtor recebendo somente string
    Titular titular(string("123.456.789-00"), "Claudiomir Santos", "cla123");
    ContaCorrente conta1("12345-6", titular);
    conta1.depositar(200.0);
    RealizaSaque(conta1, 100.00);
    ExibeSaldo(conta1);
    conta1 += 50.0; // usando operator overloaded para o operador +=
    ExibeSaldo(conta1);
    conta1 -= 25.0; // usando operator overloaded para o operador -=
    ExibeSaldo(conta1);
    FazLogin(titular, "cla123");
    
    // Aqui o primeiro parametro do Titular é um CPF de fato
    Titular titular2(CPF("987.654.321-00"), "Maria Souza", "mar123");
    ContaCorrente conta2("98765-4", titular2    );
    conta2.depositar(500.0);
    RealizaSaque(conta2, 100.00);
    ExibeSaldo(conta2);
    conta2 += 150.0; // usando operator overloaded para o operador +=
    ExibeSaldo(conta2);
    conta2 -= 50.0; // usando operator overloaded para o operador -=
    ExibeSaldo(conta2);
    FazLogin(titular2, "mar123");

    // repare que o primeiro parametro da classe Titular está sendo um valor do tipo VETOR DE CARACTERES quando seria esperado um tipo CPF
    // O que está acontecendo aqui é uma conversão implícita que o C++ faz. Isso só está funcionando de fato porque a classe CPF tem um construtor recebendo um VETOR DE CARACTERES
    string cpf = "567.443.223-55";
    Titular titular3(cpf, "Joana Clara", "joa123");
    ContaPoupanca conta3("4444-4", titular3);
    conta3.depositar(1500.0);
    RealizaSaque(conta3, 200.00);
    ExibeSaldo(conta3);
    conta3 += 300.0; // usando operator overloaded para o operador +=
    ExibeSaldo(conta3);
    conta3 -= 100.0; // usando operator overloaded para o operador -=
    ExibeSaldo(conta3);
    FazLogin(titular3, "joa123");

    conta2 /= conta1; // usando operator overloaded para o operador /= que ira transferir metade do valor de conta1 para conta2

    ExibeSaldo(conta1);
    ExibeSaldo(conta2);

    cout << "Número de contas: " << Conta::obterNumeroDeContas() << endl << endl;
    
    cout << conta1 << endl; // usando operator overloaded para o operador << que ira exibir as informações da conta
    cout << conta2 << endl; // usando operator overloaded para o operador << que ira exibir as informações da conta
    cout << conta3 << endl; // usando operator overloaded para o

    cout << "Comparando o saldo da conta1 e conta2 para verificar qual tem o menor saldo: " << endl;
    cout << "Menor saldo: " << Menor<Conta&>(conta1, conta2) << endl; // usando a função template para comparar o saldo de duas contas e retornar a conta com menor saldo
    

    RealizaTransferencia(conta1, conta3, 50.0); // transferindo R$ 50 da conta1 para a conta3

    Gerente gerente(CPF("444.555.666-33"), "Claudio Ramos", 2000.00, "ger123", DiaDaSemana::Segunda);
    cout << "Nome do gerente: " << gerente.obterNome() << " - Salário: " << gerente.obterSalario() << endl << endl;

    Caixa caixa(CPF("111.555.666-33"), "Claudecir Pereira Rocha", 1000.00, DiaDaSemana::Sexta);
    cout << "Nome do caixa: " << caixa.obterNome() << " - Salário: " << caixa.obterSalario() << endl << endl;

    
    return 0;

}