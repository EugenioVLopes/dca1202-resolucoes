// 2. Desenvolva uma classe em C++ para simular operações de depósito, saque, atualização de rendimentos e
// apresentação de saldos em uma poupança. Sua classe deverá funcionar com o programa-exemplo mostrado a
// seguir:

// int main(void){
// ContaCorrente c; // inicializa a conta corrente
// c.deposita(300); // deposita 300 dinheiros
// c.rendimento(); // reajusta o valor do deposito em mais 5% do valor atual
// c.saca(200); // realiza um saque de 200 dinheiros
// c.saldo(); // imprime o saldo da poupança na tela
// }

#include <iostream>
#include <string>

class ContaCorrente
{
private:
    float saldo;

public:
    ContaCorrente()
    {
        saldo = 0;
    }
    void deposita(float valor)
    {
        saldo += valor;
    }
    void rendimento()
    {
        saldo *= 1.05;
    }
    void saca(float valor)
    {
        saldo -= valor;
    }
    void imprimeSaldo()
    {
        std::cout << "Saldo: " << saldo << std::endl;
    }
};
int main(void)
{
    ContaCorrente c;  // inicializa a conta corrente
    c.deposita(300);  // deposita 300 dinheiros
    c.rendimento();   // reajusta o valor do deposito em mais 5% do valor atual
    c.saca(200);      // realiza um saque de 200 dinheiros
    c.imprimeSaldo(); // imprime o saldo da poupança na tela
}