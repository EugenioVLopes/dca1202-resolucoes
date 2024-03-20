// QUESTÃO 1
// Seja o seguinte trecho de programa:
// int i=3,j=5;
// int *p, *q;
// p = &i;
// q = &j;
// Determine o valor das seguintes expressões, justificando o porquê de cada resultado:
// ◦ p == &i;
// ◦ *p - *q;
// ◦ **&p;
// ◦ 3 - *p/(*q) + 7

#include <stdio.h>

int main(void)
{
    int i = 3, j = 5; // Declaração das variáveis i e j como do tipo int e atribuição de seus valores respectivamente.
    int *p, *q;       // Declaração dos ponteiros p e q como do tipo int.
    p = &i;           // Atribuição do endereço de i ao ponteiro p
    q = &j;           // Atribuição do endereço de j ao ponteiro q.

    // Determinação do valor das expressões da questão.

    p == &i;
    // Expressão boolena que verifica se o ponteiro p é igual ao endereço de i.
    // RESPOSTA: A expressão p == &i é verdadeira, pois o ponteiro p aponta para o endereço de i.
    printf("p == &i: %d\n", p == &i);
    printf("p == &i: %s\n", p == &i ? "true" : "false"); // Saída: true
                                                         //          ^       ^      ^^^^^^^^^^^^^^^^^^^^^^^
                                                         //          |       |      |
                                                         //          |       |      Expressão ternária. Retorna "true" se p for igual ao endereço de i, caso contrário
                                                         //                            retorna "false".
                                                         //          |       Especificador de formato para string.
                                                         //          String literal que será impressa.}

    *p - *q;
    // Expressão que subtrai o valor apontado por p (conteúdo do endereço de memória de p => Valor da variável i = 3)
    // do valor apontado por q (conteúdo do endereço de memória de q => Valor da variável j = 5 ).
    // RESPOSTA: A expressão *p - *q é igual a -2, pois o valor apontado por p é 3 e o valor apontado por q é 5.
    printf("*p - *q: %d\n", *p - *q);

    **&p;
    // Expressão que retorna o valor apontado pelo endereço de memória de p.
    // RESPOSTA: A expressão **&p é igual a 3, pois o valor apontado pelo endereço de memória de p é 3.
    printf("**&p: %d\n", **&p);

    3 - *p / (*q) + 7;
    // Expressão que subtrai 3 do valor apontado por p (conteúdo do endereço de memória de p => Valor da variável i = 3)
    // e divide o resultado pelo valor apontado por q (conteúdo do endereço de memória de q => Valor da variável j = 5).
    // Em seguida, soma 7 ao resultado.
    // RESPOSTA: A expressão 3 - *p/(*q) + 7 é igual a 10, pois 3 - 3/5 + 7 = 3 - 0 + 7 = 10.
    printf("3 - *p/(*q) + 7: %d\n", 3 - *p / (*q) + 7);
}