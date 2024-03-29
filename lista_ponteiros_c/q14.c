#include <stdio.h>

// 14. O que é um ponteiro para uma função? Pesquise na Internet referências sobre o assunto e
// escreva um pequeno programa exemplificando o uso deste recurso. Explique seu programa,
// comentando cada uma das linhas de código.

// Um ponteiro para função é um ponteiro que aponta para o endereço de memória de uma função.
// Isso permite que possamos chamar a função através do ponteiro, o que pode ser útil em situações
// onde precisamos passar funções como argumentos para outras funções, ou quando queremos selecionar
// dinamicamente qual função chamar em tempo de execução.

// Declaração de uma função que recebe um inteiro e retorna um inteiro.
float mediaIdades(int a, int b)
{
    return (float)(a + b) / 2;
}

int main()
{
    // Declaração de um ponteiro para função que recebe dois inteiros e retorna um inteiro.
    float (*p)(int, int);
    float (*p2)(int, int);

    // Atribuição do endereço da função 'soma' ao ponteiro 'p'.
    // o ponteiro 'p' agora aponta para a função 'soma'.
    p = mediaIdades;
    p2 = mediaIdades;

    // Recebendo e guardando variaveis
    int idade1, idade2;

    printf("Digite a primeira idade: ");
    scanf("%d", &idade1);
    printf("Digite a segunda idade: ");
    scanf("%d", &idade2);

    // Chamada da função 'soma' através do ponteiro 'p'.
    // Passamos os argumentos 21 e 26 para a função 'soma' através do ponteiro 'p'.
    printf("\nMedia: %.2f\n", p(idade1, idade2));
    printf("Media dos devs dessa lista: %.2f\n", p2(21, 26));

    return 0;
}
