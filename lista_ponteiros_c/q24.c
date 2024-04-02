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
unsigned long codificaMatriz(unsigned char m[8][8])
{
    unsigned long estado = 0; // Variável que armazenará o estado dos leds
    int i, j;                 // Variáveis auxiliares

    // Laço para percorrer a matriz de leds
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            // Verificando se o valor do item da matriz é 1
            if (m[i][j] == 1)
            {
                // Utilizando o operador bitwise '|' para atribuir o estado do led como ativado
                estado |= (1UL << (i * 8 + j));
            }
            else
            {
                // Utilizando o operador bitwise '&' para atribuir o estado do led como desativado
                estado &= ~(1UL << (i * 8 + j));
            }
        }
    }

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
        {0, 1, 0, 1, 0, 1, 0, 1}};

    unsigned long estado = codificaMatriz(m); // Codificando a matriz de leds

    printf("Estado dos leds: %d ", estado);
    
    // Laço para imprimir o estado dos leds
    for (int i = 0; i < 64; i++)
    {
        // Utilizando o operador bitwise '&' para verificar o estado do led
        if (estado & (1UL << i)) // Se o led estiver ativado 
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    
    printf("\n");

    return 0;
}

// O código acima imprime o estado de 64 LEDs em um unsigned long. O estado de cada LED é armazenado
// em uma variável chamada estado, que é um número inteiro de 64 bits. 

// Cada bit na variável estado representa o estado de um LED: se o bit estiver definido (1), o LED correspondente está 
// ligado; se o bit estiver desativado (0), o LED correspondente está desligado.

// O código usa um laço for para percorrer cada bit na variável estado. A variável de controle do laço i começa em 0 e vai 
// até 63, representando as posições dos bits na variável estado.

// Dentro do laço, o código usa um if com um operador bitwise AND (&) para verificar o estado do LED correspondente ao bit
// atual. O código (1UL << i) desloca o número 1 i posições para a esquerda, criando um número que tem todos os bits 
// definidos como 0, exceto o bit na posição i.

// O operador bitwise AND compara esse número com o estado. Se o bit na posição i em estado estiver definido, o resultado
// será diferente de zero e o if será verdadeiro. Nesse caso, o código imprime "1", indicando que o LED correspondente está
// ligado.

// Se o bit na posição i em estado não estiver definido, o resultado será zero e o if será falso. Nesse caso, o código 
// imprime "0", indicando que o LED correspondente está desligado.