// 11. Seja x um vetor de 4 elementos, declarado da forma TIPO x[4]. Suponha que depois da
// declaração, x esteja armazenado no endereço de memória 4092 (ou seja, o endereço de x[0]).
// Suponha também que na máquina seja usada uma variável do tipo char ocupa 1 byte, do tipo
// int ocupa 2 bytes, do tipo float ocupa 4 bytes e do tipo double ocupa 8 bytes. Quais serão os
// valores de x+1, x+2 e x+3 se:
// ◦ x for declarado como char?
// ◦ x for declarado como int?
// ◦ x for declarado como float?
// ◦ x for declarado como double?
// Implemente um programa de computador para testar estas suposições e compare as respostas
// oferecidas pelo programa com as respostas que você idealizou


#include <stdio.h>

int main()
{
    char x_chart[4] = {'A', 'B', 'C', 'D'};        // Declaração do vetor x de 4 elementos do tipo char.
    int x_int[4] = {1, 2, 3, 4};                   // Declaração do vetor x de 4 elementos do tipo int.
    float x_float[4] = {1.1, 2.2, 3.3, 4.4};       // Declaração do vetor x de 4 elementos do tipo float.
    double x_double[4] = {1.11, 2.22, 3.33, 4.44}; // Declaração do vetor x de 4 elementos do tipo double.

    // Imprime o valor do elemento do vetor x na posição i e o endereço de memória do elemento do vetor x na posição i.

    printf("char:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("char[%d] = %c, Endereco na memoria = %p\n", i, x_chart[i], &x_chart[i]);
    }

    printf("\nint:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("int[%d] = %d, Endereco na memoria = %p\n", i, x_int[i], &x_int[i]);
    }

    printf("\nfloat:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("float[%d] = %.2f, Endereco na memoria = %p\n", i, x_float[i], &x_float[i]);
    }

    printf("\ndouble:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("double[%d] = %.2f, Endereco na memoria = %p\n", i, x_double[i], &x_double[i]);
    }

    return 0;
}


// Dado que x é um vetor: TIPO x[4]; sua posição x[0] tem o endereço 4092.
// Tomando por referência que: char ocupa 1 byte, int ocupa 2 bytes, float ocupa 4 bytes e double ocupa 8 bytes.

// ◦ x for declarado como char?
// Se x for declarado como char, cada elemento do vetor x ocupará 1 byte. 
// Portanto, x+1 ocupará 4093, x+2 ocupará 4094 e x+3 ocupará 4095.

// ◦ x for declarado como int?
// Se x for declarado como int, cada elemento do vetor x ocupará 2 bytes.
// Portanto, x+1 ocupará 4094, x+2 ocupará 4096 e x+3 ocupará 4098.

// ◦ x for declarado como float?
// Se x for declarado como float, cada elemento do vetor x ocupará 4 bytes.
// Portanto, x+1 ocupará 4096, x+2 ocupará 4100 e x+3 ocupará 4104.

// ◦ x for declarado como double?
// Se x for declarado como double, cada elemento do vetor x ocupará 8 bytes.
// Portanto, x+1 ocupará 4100, x+2 ocupará 4108 e x+3 ocupará 4116.




// PERGUNTAR A AGOSTINHO SOBRE O PORQUE DA INICIALIZAÇÃO DE CHAR NÃO FUNCIONAR QUANDO EU USO "", 
// MAS QUANDO EU USO '' DA CERTO.