#include <stdio.h>
#include <string.h> // Inclusão da biblioteca string.h para utilizar a função strcpy.

struct teste // Declaração da estrutura teste.
{
    int x;         // Declaração da variável x.
    char nome[10]; // Declaração do vetor de caracteres nome.
};

int main()
{
    struct teste *s; // Declaração do ponteiro s como do tipo struct teste.

    struct teste t; // Declaração de uma variável do tipo struct teste.

    t.x = 3; // Atribuição de valor para a variável x da estrutura t.

    strcpy(t.nome, "jose"); // Atribuição de valor para o vetor de caracteres nome da estrutura t.

    s = &t; // Atribuição do endereço de memória da estrutura t para o ponteiro s.

    printf("x = %d", s->x); // Imprime o valor da variável x da estrutura apontada por s.

    printf("\nnome = %s", s->nome); // Imprime o valor do vetor de caracteres nome da estrutura apontada por s.

    return 0;
}