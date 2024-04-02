#include <stdio.h>
#include <stdlib.h>

// 16. Reimplemente o programa da questão anterior utilizando a função qsort() do C. 
// Comente o seu código, explicando o que faz cada uma das linhas.

// Função de comparação para qsort
int compararElementos(const void *a, const void *b){
    // Convertendo os ponteiros para float
    float *x = (float *) a;
    float *y = (float *) b;

    // Comparando os valores
    // Retornando 1 se x > y 
    if (*x > *y)
        return 1;
    // Retornando -1 se x < y
    else if (*x < *y)
        return -1;
    // Retornando 0 se x == y
    else
        return 0;
}

int main(){
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
    for (int i = 0; i < n; i++){
        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    // INICIO DA MUDANÇA DA Qs16

    // Ordenando o vetoe utilizando a função qsort
    qsort(vetor, n, sizeof(float), compararElementos); // Utilizando a função qsort para ordenar o vetor

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", vetor[i]);
    }

    free(vetor);
    vetor = NULL;

    return 0;
}
