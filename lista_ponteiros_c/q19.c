// 19. Escreva uma função em linguagem C que escreva em um vetor a soma dos elementos
// correspondentes de outros dois vetores (os tamanhos dos vetores devem ser fornecidos pelo
// usuário). 
// Por exemplo, se o primeiro vetor contiver os elementos 1, 3, 0 e -2, e o segundo vetor
// contiver os elementos 3, 5, -3 e 1, o vetor de soma terá valores resultantes iguais a 4, 8, -3 e -1. A
// função deve receber 4 argumentos: os nomes dos três vetores e o número de elementos
// presentes em cada vetor. 
// Exemplo: soma_vetores(vet1, vet2, resultado, 4);

#include <stdio.h>
#include <stdlib.h>

void soma_vetores(int *vet1, int *vet2, int *resultado, int n)
{
    for (int i = 0; i < n; i++)
    {
        resultado[i] = vet1[i] + vet2[i];
    }
}

int main()
{
    int n; // Variável que receberá o tamanho dos vetores

    int *vet1; // Ponteiro para o primeiro vetor
    int *vet2; // Ponteiro para o segundo vetor
    int *resultado; // Ponteiro para o vetor de soma

    printf("Digite o tamanho dos vetores: ");

    scanf("%d", &n); // Lendo o tamanho dos vetores por meio do número dado pelo usuário

    vet1 = (int *)malloc(n * sizeof(int)); // Alocando memória para o primeiro vetor
    vet2 = (int *)malloc(n * sizeof(int)); // Alocando memória para o segundo vetor
    resultado = (int *)malloc(n * sizeof(int)); // Alocando memória para o vetor de soma

    // Verificando se a memória foi alocada corretamente
    if (vet1 == NULL || vet2 == NULL || resultado == NULL)
    {
        printf("Memória insuficiente\n");
        return 1;
    }

    // Lendo os valores do primeiro vetor
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do primeiro vetor: ", i + 1);
        scanf("%d", &vet1[i]);
    }

    // Lendo os valores do segundo vetor
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do segundo vetor: ", i + 1);
        scanf("%d", &vet2[i]);
    }

    // Chamando a função soma_vetores para calcular a soma dos vetores
    soma_vetores(vet1, vet2, resultado, n);

    // Exibindo o vetor de soma
    printf("Vetor de soma: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", resultado[i]);
    }

    free(vet1); // Liberando a memória alocada para o primeiro vetor
    free(vet2); // Liberando a memória alocada para o segundo vetor
    free(resultado); // Liberando a memória alocada para o vetor de soma

    vet1 = NULL; // Atribuindo NULL ao ponteiro vet1
    vet2 = NULL; // Atribuindo NULL ao ponteiro vet2
    resultado = NULL; // Atribuindo NULL ao ponteiro resultado

    return 0;
}
