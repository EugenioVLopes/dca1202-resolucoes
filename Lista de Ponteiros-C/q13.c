// 13. O que é memory leak? Procure 3 exemplos de programas em C que apresentem memory leak e
// explique o que acontece em cada um deles

// Um vazamento de memória ocorre na programação em C quando um programa aloca memória dinamicamente usando funções como
//  malloc, realloc ou calloc, mas falha em liberar (desalocar) essa memória apropriadamente antes do programa terminar.
//  Isso leva a um esgotamento gradual da memória disponível ao longo do tempo, podendo causar problemas de desempenho e
//  até mesmo travamentos do sistema.

// Exemplo 1: (Alocação sem desalocação)
#include <stdio.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int)); // Aloca memória para um inteiro

    // ... (Não libera a memória alocada ao esquecer de chamar free)

    return 0;
}

// No exemplo acima, a memória alocada para o ponteiro ptr não é liberada antes do programa terminar,
// resultando em um vazamento de memória.

// Exemplo 2: (Vazemento em loop)
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        int *ptr = (int *)malloc(sizeof(int)); // Aloca memória
        *ptr = i;                              // Armazena um valor

        // ... (Esquece de chamar free em ptr dentro do loop)
    }
    return 0;
}

// Exemplo 3: (Ponteiro Pendurado)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int)); // Aloca memória para um inteiro

    if (ptr == NULL)
    { // Verifica se a alocação falhou
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    *ptr = 10; // Armazena um valor no bloco alocado

    printf("Valor de ptr depois da atribuicao: %d\n", *ptr);

    free(ptr); // Libera a memória alocada

    // ... (Tenta usar ptr após a memória ser liberada)

    printf("Valor de ptr (apos a liberacao): %d\n", *ptr);

    return 0;
}
