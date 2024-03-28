// 23. (ENADE, 2021) Observe o código abaixo escrito na linguagem C.

#include <stdio.h>

#define TAM 10 // Definindo o tamanho do vetor

// Função que realiza a busca linear

int funcao1(int vetor[], int v)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (vetor[i] == v)
            return i;
    }
    return -1;
}

// Função que realiza a busca binária de forma recursiva e que recebe o vetor, o valor a ser buscado,
// o índice inicial e o índice final do vetor
int funcao2(int vetor[], int v, int i, int f)
{
    int m = (i + f) / 2; // Calculando o meio do vetor
    if (v == vetor[m])   // Verificando se o valor foi encontrado
        return m;
    if (i >= f) // Verificando se o valor não foi encontrado
        return -1;
    if (v > vetor[m]) // Verificando se o valor está na parte direita do vetor
        return funcao2(vetor, v, m + 1, f);
    // Chamando a função recursivamente para a parte direita do vetor (do meio até o final)
    else // Verificando se o valor está na parte esquerda do vetor
        return funcao2(vetor, v, i, m - 1);
    // Chamando a função recursivamente para a parte esquerda do vetor (do início até o meio)
}

// Essa função só funciona para vetores ordenados?

int main()
{
    int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM - 1));
    return 0;
}
// A respeito das funções implementadas, avalie as afirmações a seguir.
// I. O resultado da impressão na linha 24 é: 7 - 7. // 7 é o índice do vetor onde está o valor 15 (vetor[7] = 15)
// II. A função funcao1, no pior caso, é uma estratégia mais rápida do que a funcao2.
// A função funcao1 é uma busca linear, enquanto a função funcao2 é uma busca binária,
// que é mais rápida que a busca linear.
// III. A função funcao2 implementa uma estratégia iterativa na concepção do algoritmo.
// A função funcao2 implementa uma estratégia recursiva, não iterativa.
// É correto o que se afirma em:
// IV. I, apenas.
// V. III, apenas.
// VI. I e II, apenas.
// VII. II e III, apenas.
// VIII. I, II e III.
// Justifique sua resposta

// Resposta: IV. I, apenas. // A afirmação I está correta, pois o resultado da impressão na linha 24 é 7 - 7.
// A afirmação II está incorreta, pois a função funcao1 é uma busca linear, que é uma estratégia mais lenta do que a busca
// binária, implementada pela função funcao2.
// A afirmação III está incorreta, pois a função funcao2 implementa uma estratégia recursiva, não iterativa.
// Na busca binária iterativa, um loop seria utilizado para dividir o vetor e realizar as comparações.

// A busca linear (funcao1) sempre percorre todo o vetor, enquanto a busca binária (funcao2) divide o vetor a cada iteração.
// No pior caso, a busca linear fará n comparações, enquanto a busca binária fará log2(n) comparações. Para grandes valores
// de n, a busca binária será significativamente mais rápida.