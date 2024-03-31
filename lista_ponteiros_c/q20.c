// 20. Crie uma função capaz de realizar multiplicação matricial da forma C = AxB. A função deve
// receber 6 argumentos: os ponteiros para as matrizes A, B e C, o número de linhas e colunas de A
// e o número de colunas de B (assuma que o número de coluna de A é igual ao número de linhas
// de B). O resultado da multiplicação deve ficar armazenado em C. Crie um programa para testar
// sua implementação, capaz de utilizar a função de multiplicação e imprimir as três matrizes. A
// função criada para multiplicação não deve realizar nenhum tipo de saída de dados no terminal.
// Exemplo: para multiplicar duas matrizes (A e B) de dimensões 2x3 e 3x4, respectivamente (o
// resultado deve ficar armazenado em C).

#include <stdio.h>
#include <stdlib.h>

// Função de multiplicação de matrizes
void multiplicacaoMatricial(int *A, int *B, int *C, int linhasA, int colunasA, int colunasB)
{
    // Multiplicando as matrizes

    // Percorrendo as linhas da matriz A
    for (int i = 0; i < linhasA; i++){
        // Percorrendo as colunas da matriz B
        for (int j = 0; j < colunasB; j++){
            // Inicializando o valor da matriz C
            // Cada elemento da matriz C é inicializado com 0
            // O valor de C[i][j] é a soma do produto dos elementos da linha i da matriz A pelos elementos da coluna j da matriz B
            C[i * colunasB + j] = 0;
            
            // Percorrendo as colunas da matriz A
            for (int k = 0; k < colunasA; k++){
                // Multiplicando os elementos da linha i da matriz A pelos elementos da coluna j da matriz B
                C[i * colunasB + j] += A[i * colunasA + k] * B[k * colunasB + j];
            }
        }
    }
}

int main()
{
    int linhasA, colunasA, colunasB; // Variáveis que receberão o número de linhas e colunas das matrizes

    int *A, *B, *C; // Ponteiros para as matrizes

    printf("Digite o número de linhas da matriz A: ");
    scanf("%d", &linhasA); // Lendo o número de linhas da matriz A

    printf("Digite o número de colunas da matriz A: ");
    scanf("%d", &colunasA); // Lendo o número de colunas da matriz A

    printf("Digite o número de colunas da matriz B: ");
    scanf("%d", &colunasB); // Lendo o número de colunas da matriz B

    // Alocando memória para as matrizes
    A = (int *)malloc(linhasA * colunasA * sizeof(int));
    B = (int *)malloc(colunasA * colunasB * sizeof(int));
    C = (int *)malloc(linhasA * colunasB * sizeof(int));

    // Verificando se a memória foi alocada corretamente
    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memória insuficiente\n");
        return 1;
    }

    // Lendo os valores da matriz A
    for (int i = 0; i < linhasA; i++)
    {
        for (int j = 0; j < colunasA; j++)
        {
            printf("Digite o valor da matriz A[%d][%d]: ", i, j);
            scanf("%d", &A[i * colunasA + j]);
        }
    }

    // Lendo os valores da matriz B
    // Pra cada linha da matriz A, temos que preencher todas as colunas da matriz B
    for (int i = 0; i < colunasA; i++)
    {
        for (int j = 0; j < colunasB; j++)
        {
            printf("Digite o valor da matriz B[%d][%d]: ", i, j);
            scanf("%d", &B[i * colunasB + j]);
        }
    }

    // Multiplicando as matrizes
    multiplicacaoMatricial(A, B, C, linhasA, colunasA, colunasB);

    // Imprimindo as matrizes
    printf("Matriz A:\n");
    for (int i = 0; i < linhasA; i++)
    {
        for (int j = 0; j < colunasA; j++)
        {
            printf("%d ", A[i * colunasA + j]);
        }
        printf("\n");
    }

    printf("Matriz B:\n");
    for (int i = 0; i < colunasA; i++)
    {
        for (int j = 0; j < colunasB; j++)
        {
            printf("%d ", B[i * colunasB + j]);
        }
        printf("\n");
    }

    printf("Matriz C:\n");
    for (int i = 0; i < linhasA; i++)
    {
        for (int j = 0; j < colunasB; j++)
        {
            printf("%d ", C[i * colunasB + j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    free(A);
    free(B);
    free(C);

    return 0;
}