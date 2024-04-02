// 25. Um programador precisa desenvolver uma aplicação em linguagem C para manipular matrizes
// capazes de armazenar representações de modelos tridimensionais.
// Entende-se que o tamanho da matriz é definido pelo usuário e esta deve ser alocada
// dinamicamente usando malloc() em tempo de execução. O processo de criar um modelo na
// matriz consiste em atribuir aos seus elementos os valores inteiros “1” ou “0” para simbolizar
// que há ou não parte do modelo naquela posição. Uma analogia para o modelo seria que a
// criação funciona como no jogo "Minecraft", onde "0" representaria a ausência de objeto e "1"
// representaria a presença de objetos.
// Nesta aplicação, as matrizes devem ser definidas como tipos de dados int. Isto posto, pede-se
// que o programador prepare os algoritmos de alocação dinâmica (usando malloc()/free()) para
// guardar os dados da matriz tridimensional e crie um programa de testes para verificar se a sua
// implementação foi realizada corretamente de modo a garantir as seguintes condições:
// a. O usuário do programa de testes deverá poder fornecer o tamanho da matriz tridimensional
// que deseja manipular, inserindo as dimensões da altura, largura e profundidade desta.
// b. O usuário do programa de testes poderá solicitar a impressão de um dos planos da matriz
// tridimensional.
// c. O usuário do programa de testes poderá modificar o estado de um dos elementos da matriz.
// Insira no seu código comentários para indicar como as posições da matriz poderão ser
// acessadas

// Resposta:
#include <stdio.h>
#include <stdlib.h>
//
// Função que aloca a matriz tridimensional
int ***alocaMatriz(int coluna, int linha, int profundidade)
{
    int ***matriz; // Declaração da matriz tridimensional
    int i, j;      // Variáveis auxiliares

    // Alocando a primeira dimensao
    matriz = (int ***)malloc(profundidade * sizeof(int **));

    // Alocando a segunda dimensao
    matriz[0] = (int **)malloc(profundidade * linha * sizeof(int *));

    // Alocando a terceira dimensao
    matriz[0][0] = (int *)malloc(profundidade * linha * coluna * sizeof(int));

    // Laço para ajustar os ponteiros da segunda dimensão apontar para a terceira dimensão
    for (i = 0; i < linha; i++) {
        matriz[i] = matriz[0] + i * profundidade;
        for (j = 0; j < profundidade; j++) {
            matriz[i][j] = matriz[0][0] + (i * profundidade + j) * coluna;
        }
    }

    return matriz;
}
// Função que libera a matriz tridimensional
void liberaMatriz(int ***matriz, int coluna, int linha)
{
    free(matriz[0][0]); // Liberando a terceira dimensão da matriz
    free(matriz[0]);    // Liberando a segunda dimensão da matriz
    free(matriz);       // Liberando a primeira dimensão da matriz
}
// Função que imprime um plano da matriz tridimensional
void imprimePlano(int ***matriz, int coluna, int linha, int profundidade, int plano)
{
    printf("Plano %d:\n", plano);
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            printf("%d ", matriz[i][j][plano]);
        }
        printf("\n");
    }
}
// Função que modifica o estado de um elemento da matriz tridimensional
void modificaElemento(int ***matriz, int i, int j, int k, int valor)
{
    matriz[i][j][k] = valor;
}
int main()
{
    int coluna, linha, profundidade, planoImpresso;
    int iModificado, jModificado, kModificado, valorModificado;

    printf("Digite a coluna da matriz: ");
    scanf("%d", &coluna);

    printf("Digite a linha da matriz: ");
    scanf("%d", &linha);

    printf("Digite a profundidade da matriz: ");
    scanf("%d", &profundidade);

    int ***matriz = alocaMatriz(coluna, linha, profundidade);
    // Inicializando a matriz com valores aleatórios
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            for (int k = 0; k < profundidade; k++)
            {
                matriz[i][j][k] = rand() % 2; // Atribuindo valores aleatórios 0 ou 1
            }
        }
    }

    printf("Digite o plano que deseja imprimir da matriz: ");
    scanf("%d", &planoImpresso);

    // Imprimindo um plano da matriz tridimensional
    imprimePlano(matriz, coluna, linha, profundidade, planoImpresso);

    // Modificando o estado de um elemento da matriz
    printf("Digite o valor de i: ");
    scanf("%d", &iModificado);

    printf("Digite o valor de j: ");
    scanf("%d", &jModificado);

    printf("Digite o valor de k: ");
    scanf("%d", &kModificado);

    printf("Digite o novo valor do elemento: ");
    scanf("%d", &valorModificado);

    modificaElemento(matriz, iModificado, jModificado, kModificado, valorModificado);

    // Imprimindo o plano modificado
    imprimePlano(matriz, coluna, linha, profundidade, planoImpresso);

    // Liberando a memória alocada para a matriz
    liberaMatriz(matriz, coluna, linha);
    return 0;
}

// Comentários para estudo:

// - Preciso liberar a memória alocada 3 vezes?
//     Sim, é preciso fazer esses três free. Quando é alocada memória dinamicamente em C usando malloc, calloc ou realloc,
//     é sua responsabilidade liberar essa memória quando você terminar de usá-la. Se não for feito isso, o programa
//     terá um vazamento de memória, o que pode levar a problemas de desempenho ou até mesmo fazer com que seu programa
//     trave se ele ficar sem memória.

// No caso desse código, foi alocada memória para uma matriz tridimensional em três etapas separadas. Portanto, é
// preciso liberar essa memória em três etapas separadas também.

// - Qual é a diferença entre malloc e calloc na alocação de memória em C?
//     malloc e calloc são funções em C que são usadas para alocar memória dinamicamente. A diferença entre malloc e calloc
//     é que malloc não inicializa a memória alocada, enquanto calloc inicializa a memória alocada com zero.
//     Portanto, se não for desejado que a memória alocada seja inicializada com zero, deve-se usar calloc. Caso o conteudo
//     inicial não seja importante, pode-se usar malloc.