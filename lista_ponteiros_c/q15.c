// 15. Implemente em linguagem C uma função em um programa de computador que leia n valores do
// tipo float e os apresente em ordem crescente. Utilize alocação dinâmica de memória para
// realizar a tarefa

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; // Variável que receberá o tamanho do vetor

    float *vetor; // Ponteiro para o vetor

    printf("Digite o tamanho do vetor: ");

    scanf("%d", &n); // Lendo o tamanho do vetor por meio do número dado pelo usuário

    vetor = (float *)malloc(n * sizeof(float)); // Alocando memória para o vetor

    // Verificando se a memória foi alocada corretamente
    if (vetor == NULL)
    {
        printf("Memória insuficiente\n");
        return 1;
    }

    // Lendo os valores do vetor
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    // Ordenando o vetor
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[i] > vetor[j])
            {
                float aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", vetor[i]);
    }

    free(vetor); // Liberando a memória alocada para o vetor

    vetor = NULL; // Atribuindo NULL ao ponteiro vetor

    return 0;
}