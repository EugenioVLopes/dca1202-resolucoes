#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 18. Procure na internet mecanismos que possibilitem medir tempos de execução de rotinas
// computacionais. Geralmente, estas medidas são realizadas com o auxílio de funções em C que
// lêem a hora no sistema (sistemas Unix e Windows geralmente usam funções diferentes).

// Utilizando os conhecimentos que você obteve com sua pesquisa, meça os tempos de execução
// das implementações que você criou para os dois problemas de ordenação anteriores,
// considerando apenas arrays de elementos tipo int e compare os resultados obtidos. O que se
// conclui nesse caso?

// Função da questão 16
int compararElementos(const void *a, const void *b){
    float *x = (float *) a;
    float *y = (float *) b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    else
        return 0;
}

// Funções da questão 17
int comparaCrescente(const void *a, const void *b){
    return (*(int *)a - *(int *)b); 
}

int comparaDecrescente(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}

void ordena(int *vetor, int n, int (*compara)(const void *, const void *)){
    qsort(vetor, n, sizeof(int), compara);
}

int main()
{
    clock_t inicioQs16, fimQs16, inicioQs17, fimQs17; // Variáveis para medir o tempo de execução
    double tempoGastoQs16, tempoGastoQs17; // Variáveis para armazenar o tempo gasto

    int nQ16; // Variável que receberá o tamanho do vetor
    float *vetorQ16; // Ponteiro para o vetor

    int nQ17; // Variável que receberá o tamanho do vetor
    int *vetorQ17; // Ponteiro para o vetor

    printf("Digite o tamanho do vetor da Qs16: ");
    scanf("%d", &nQ16);

    printf("Digite o tamanho do vetor da Qs17: ");
    scanf("%d", &nQ17);

    vetorQ16 = (float *)malloc(nQ16 * sizeof(float)); // Alocando memória para o vetor
    vetorQ17 = (int *)malloc(nQ17 * sizeof(int)); // Alocando memória para o vetor
    
    if (vetorQ16 == NULL || vetorQ17 == NULL){
        printf("Memória insuficiente\n");
        return 1;
    }

    for (int i = 0; i < nQ16; i++){
        printf("Digite o valor %d (Qs16): ", i + 1);
        scanf("%f", &vetorQ16[i]);
    }

    for (int i = 0; i < nQ17; i++) {
        printf("Digite o valor %d (Qs17): ", i + 1);
        scanf("%d", &vetorQ17[i]);
    }

    // Utilizando ordenação da questão 16
    inicioQs16 = clock();

    // Vou usar o "for" pra conseguir calcular uma diferença de tempo
    for (int i = 0; i < 10000000; i++){
        qsort(vetorQ16, nQ16, sizeof(float), compararElementos);
    }

    fimQs16 = clock();

    // Utilizando ordenação da questão 17
    inicioQs17 = clock();

    for (int i = 0; i < 10000000; i++){
        ordena(vetorQ17, nQ17, comparaCrescente);
    }

    fimQs17 = clock();

    printf("Vetor ordenado - Qs16 (float): ");
    for (int i = 0; i < nQ16; i++){
        printf("%.2f ", vetorQ16[i]);
    }

    printf("\n");
    
    printf("Vetor ordenado - Qs17 (int): ");
    for (int i = 0; i < nQ17; i++){
        printf("%d ", vetorQ17[i]);
    }

    free(vetorQ16);
    vetorQ16 = NULL;

    free(vetorQ17);
    vetorQ17 = NULL;

    tempoGastoQs16 = ((double)(fimQs16 - inicioQs16));
    tempoGastoQs17 = ((double)(fimQs17 - inicioQs17));

    printf("\nTempo gasto para ordenar o vetor da Qs16: %lf\n", tempoGastoQs16);
    printf("Tempo gasto para ordenar o vetor da Qs17: %lf\n", tempoGastoQs17);

    return 0;
}

// Utilizando o método de cálculo tempo acima, pode se perceber que o tempo gasto para ordenar
// um vetor do tipo float é maior que o do tipo int.

// Tal diferença de tempo se dá pelo fato de que o tipo float é um número de ponto flutuante
// e o tipo int é um número inteiro. O tipo float é mais complexo que o tipo int, pois ele
// possui uma parte fracionária, o que faz com que o processamento seja mais lento.

// Sendo assim, em um contexto de uso desses dois tipos de dados, é importante levar em conta
// o tempo de execução de cada um deles, para que se possa escolher o tipo de dado mais adequado.