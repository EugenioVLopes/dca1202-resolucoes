/* 
    Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões referenciam o
    valor do terceiro elemento do vetor?
    ◦ *(pulo + 2);
    ◦ *(pulo + 4);
    ◦ pulo + 4;
    ◦ pulo + 2;
*/

#include <stdio.h>

int main() {
    int pulo[] = {1, 2, 3, 4, 5};

    // pulo + 4 referencia o endereço do quinto elemento do vetor
    printf("pulo + 4: %d\n", pulo + 4);
    // pulo + 2 referencia o terceiro elemento, porém o que será mostrado aqui é seu endereço e não seu valor
    printf("pulo + 2: %d\n", pulo + 2);
    // *(pulo + 4) referencia, agora sim, o valor (*) do elemento, porém da posição 5
    printf("*(pulo + 4): %d\n", *(pulo + 4));
    // *(pulo + 2) referencia o valor (*) do terceiro elemento do vetor, e é a opção correta
    printf("*(pulo + 2): %d\n", *(pulo + 2));

    return 0;
}
