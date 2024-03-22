// 8. O que fazem os seguintes programas em C?

#include <stdio.h>

int main(){
    // Criando um vetor de inteiros
    int vet[] = {4, 9, 13};
    // Criando for pra percorrer o vetor
    int i;
    for(i=0;i<3;i++){
        // pra cada iteração do for, o endereço inicial do vetor é somado com o valor de i
        // ou seja, usando o * antes do (vet+i) é possível acessar o valor do vetor na posição vet (inicial) + i
        printf("%d ", *(vet+i));
    }
    
    // Nesse novo código, a situação é bem parecida com a anterior
    int vet_2[] = {4, 9, 13};
    int j;
    // Mas agora, a diferença é que agora o endereço de memória é impresso no lugar do valor
    for(j=0;j<3;j++){
        // o %X é usado para imprimir o endereço de memória em hexadecimal
        printf("%X ", vet_2+j);
    }
}
