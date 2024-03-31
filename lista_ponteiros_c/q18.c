#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 18. Procure na internet mecanismos que possibilitem medir tempos de execução de rotinas
// computacionais. Geralmente, estas medidas são realizadas com o auxílio de funções em C que
// lêem a hora no sistema (sistemas Unix e Windows geralmente usam funções diferentes).
// Utilizando os conhecimentos que você obteve com sua pesquisa, meça os tempos de execução
// das implementações que você criou para os dois problemas de ordenação anteriores,
// considerando apena

// Código da questão 16
int compararElementos(const void *a, const void *b)
{
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

