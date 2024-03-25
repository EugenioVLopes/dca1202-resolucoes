// 17. Utilize a ideia do ponteiro para função pela função qsort() para implementar sua própria
// função de ordenação, mas que seja capaz de ordenar apenas inteiros do tipo int. Para isso, sua
// função deverá receber, entre outros argumentos, um ponteiro para a função de comparação
// que determinará como os elementos do array serão ordenados

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenação crescente
int comparaCrescente(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b); 
    // Comparando os valores de a e b
    // Se o valor de a for menor que o valor de b, a função retorna um valor negativo
    // Se o valor de a for igual ao valor de b, a função retorna 0
    // Se o valor de a for maior que o valor de b, a função retorna um valor positivo
}

// Função de comparação para ordenação decrescente
int comparaDecrescente(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
    // Comparando os valores de a e b
}

// Função de ordenação
void ordena(int *vetor, int n, int (*compara)(const void *, const void *))
{
    // Ordenando o vetor
    qsort(vetor, n, sizeof(int), compara);
    // A função qsort ordena o vetor de acordo com a função de comparação fornecida
    // O vetor a ser ordenado é vetor e seu tamanho é n (número de elementos) e o tamanho de cada elemento é sizeof(int)
    // A função de comparação é compara (comparaCrescente ou comparaDecrescente) 
    // que determinará como os elementos do vetor serão ordenados 
}

int main()
{
    int n; // Variável que receberá o tamanho do vetor

    int *vetor; // Ponteiro para o vetor

    printf("Digite o tamanho do vetor: ");

    scanf("%d", &n); // Lendo o tamanho do vetor por meio do número dado pelo usuário

    vetor = (int *)malloc(n * sizeof(int)); // Alocando memória para o vetor

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
        scanf("%d", &vetor[i]);
    }

    // Ordenando o vetor de forma crescente
    ordena(vetor, n, comparaCrescente);

    printf("Vetor ordenado de forma crescente: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Ordenando o vetor de forma decrescente
    ordena(vetor, n, comparaDecrescente);

    printf("Vetor ordenado de forma decrescente: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); // Liberando a memória alocada para o vetor

    vetor = NULL; // Atribuindo NULL ao ponteiro vetor

    return 0;
}