#include <stdio.h>

// 10. Qual será a saída do seguinte programa?

// void main(){
//     // Aqui aparentemente temos 2 situações incorretas
//     // Primeiramente, a varivael constante x é um ponteiro e está recendo um valor inteiro e não um endereço de memória.
//     int const *x = 3;
//     // Segundamente, a função printf está tentando incrementar o valor de x, porém x é uma variável constante e não pode ser alterada.
//     printf("%d", ++(*x));
//     // A saída será um erro de compilação. Quando abro o executavel da q10.c nada é mostrado!
// }

void main(){
    // Uma alternativa para esse código acima é essa:
    int teste = 3;
    int *x = &teste;

    printf("%d", ++(*x));
}