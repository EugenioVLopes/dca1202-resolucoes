// 4. Um usuário precisa implementar o controle de uma matriz de leds com 8 x 8 elementos. Para
// isso, ele criou um programa em C dotado de uma matriz da forma
// unsigned char m[8][8];
// para armazenar os estados dos leds. Como existem apenas dois estados possíveis para os leds
// (aceso ou apagado), ele assumiu que leds acessos seriam denotados pelo inteiro "1" nessa matriz
// e leds apagados seriam denotados pelo inteiro "0".
// Ocorre que a função que controla os leds exige que a informação que controla a matriz seja
// enviada via porta serial usando uma função que recebe um único inteiro não sinalizado de
// 64 bits, da forma send(unsigned long estado). Nesse inteiro, os bytes mais significativos deverão
// guardar os estados das linhas iniciais da matriz de leds, enquanto os bytes menos significativos
// devem guardar os estados das linhas finais da matriz. Assim, é necessário que cada estado
// previsto na matriz m seja codificado em um bit correspondente na variável enviada pela função.
// Crie um programa em linguagem C para realizar essa codificação e explique na forma de
// comentários como sua codificação da matriz m na variável de 64 bits foi realizada.

#include <stdio.h>
#include <stdlib.h>

// Função que codifica a matriz de leds
unsigned long codificaMatriz(unsigned char matriz[8][8])
{
    unsigned long estado; // Variável que armazenará o estado dos leds
    unsigned long *ponteiro;  // Ponteiro para a variável estado
    int i, j;                 // Variáveis auxiliares

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            estado = (estado << 1) | matriz[i][j];
            // estado << 1: O operador << desloca todos os bits na variável estado uma posição para a esquerda.
            // | matriz[i][j]: Este é um operador OR bit a bit. Ele compara cada bit de (estado << 1) com o bit correspondente
            // em matriz[i][j]. Se pelo menos um dos bits for 1, o bit correspondente no resultado é definido como 1. 
            // Caso contrário, o bit é definido como 0.
        }
    }

    ponteiro = &estado;

    return estado;
}

int main()
{
    unsigned char m[8][8] = {
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1}
    };

    unsigned long estado = codificaMatriz(m); // Codificando a matriz de leds

    printf("Estado: ");

    // Imprimir cada bit individualmente
    for (int i = 63; i >= 0; i--)
    {
        unsigned long bit = (estado >> i) & 1;
        printf("%lu ", bit);
    }

    printf("\n");

    return 0;
}