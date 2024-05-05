// 1. Corrija o programa a seguir :

// #include <iostream>
// class Math{
// public:
// static double media_aritmetica(int a, int b){
// return a + b / 2;
// }
// };
// int main(){
// cout << Math::media_aritmetica(2, 1);
// }

#include <iostream>

class Math
{
public:
    static float media_aritmetica(int a, int b)
    {
        return (float(a + b) / 2);
    }
};

int main()
{
    std::cout << Math::media_aritmetica(2, 1);
}

// Resposta: O programa apresenta um erro na função media_aritmetica da classe Math. O erro está na expressão a + b / 2,
// que não calcula a média aritmética dos valores a e b corretamente. Isso ocorre porque a precedência do operador / é
// maior do que a precedência do operador +, o que faz com que a divisão seja realizada antes da soma. Para corrigir esse
// problema, é necessário adicionar parênteses para garantir que a soma seja realizada antes da divisão.
// A expressão correta é (a + b) / 2. Além disso, como o tipo dos parâmetros a e b é int, a divisão entre eles resultará
// em um valor inteiro, mesmo que o resultado seja um número fracionário. Para garantir que o resultado seja um número
// fracionário, é necessário converter pelo menos um dos operandos para float. Nesse caso, a conversão do resultado da
// soma para float é suficiente.

// Na chamada da função cout é necessário adicionar o namespace std::, pois a função cout é parte da biblioteca padrão
// de C++ e está no namespace std.