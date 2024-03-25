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
int ***alocaMatriz(int altura, int largura, int profundidade)
{
    int ***matriz = (int ***)malloc(altura * sizeof(int **)); // Alocando a primeira dimensão da matriz
    for (int i = 0; i < altura; i++)
    {
        matriz[i] = (int **)malloc(largura * sizeof(int *)); // Alocando a segunda dimensão da matriz
        for (int j = 0; j < largura; j++)
        {
            matriz[i][j] = (int *)malloc(profundidade * sizeof(int)); // Alocando a terceira dimensão da matriz
        }
    }
    return matriz;
}
// Função que libera a matriz tridimensional
void liberaMatriz(int ***matriz, int altura, int largura)
{
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            free(matriz[i][j]); // Liberando a terceira dimensão da matriz
        }
        free(matriz[i]); // Liberando a segunda dimensão da matriz
    }
    free(matriz); // Liberando a primeira dimensão da matriz
}
// Função que imprime um plano da matriz tridimensional
void imprimePlano(int ***matriz, int altura, int largura, int profundidade, int plano)
{
    printf("Plano %d:\n", plano);
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            printf("%d ", matriz[i][j][plano]);
        }
        printf("\n");
    }
}
// Função que modifica o estado de um elemento da matriz tridimensional
void modificaElemento(int ***matriz, int altura, int largura, int profundidade, int i, int j, int k, int valor)
{
    matriz[i][j][k] = valor;
}
int main()
{
    int altura, largura, profundidade, planoImpresso;
    
    printf("Digite a altura da matriz: ");
    scanf("%d", &altura);
    
    printf("Digite a largura da matriz: ");
    scanf("%d", &largura);
    
    printf("Digite a profundidade da matriz: ");
    scanf("%d", &profundidade);
    
    int ***matriz = alocaMatriz(altura, largura, profundidade);
    // Inicializando a matriz com valores aleatórios
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
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
    imprimePlano(matriz, altura, largura, profundidade, planoImpresso);

    // Modificando o estado de um elemento da matriz
    modificaElemento(matriz, altura, largura, profundidade, 0, 0, 0, 1);

    // Imprimindo o plano modificado
    imprimePlano(matriz, altura, largura, profundidade, 0);
    
    // Liberando a memória alocada para a matriz
    liberaMatriz(matriz, altura, largura);
    return 0;
}
