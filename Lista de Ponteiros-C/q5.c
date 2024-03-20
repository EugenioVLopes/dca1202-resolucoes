// Determine o que será mostrado pelo seguinte programa (compile-o, execute-o e explique se
// foram obtidas as respostas esperadas).
#include <stdio.h>

int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5}; // Declaração do vetor vet de 5 posições e atribuição de valores.
  
  float *f; // Declaração do ponteiro f como do tipo float.
  
  int i; // Declaração da variável i como do tipo int.
  
  f = vet; // Atribuição do endereço do primeiro elemento do vetor vet ao ponteiro f.
           // f agora aponta para o local de memória onde o valor 1.1 está armazenado, nesse caso.
  
  printf("contador/valor/valor/endereco/endereco\n");
  
  // Laço "for" que percorre o vetor vet e imprime o valor de i, o valor do elemento do vetor vet na posição i, 
  // o valor do elemento do vetor vet na posição i, o endereço de memória do elemento do vetor vet na posição i
  // e o endereço de memória do elemento do vetor vet na posição i.
  
  for(i = 0 ; i <= 4 ; i++){
  printf("i = %d",i); // Imprime o valor de i.
  
  printf(" vet[%d] = %.1f",i, vet[i]); // Imprime o valor do elemento do vetor vet na posição i.
  
  printf(" *(f + %d) = %.1f",i, *(f+i)); // Imprime o valor do elemento do vetor vet na posição i.
  // *(f + i) é equivalente a vet[i], dado que f aponta para o endereço de memória do primeiro elemento do vetor vet.

  printf(" &vet[%d] = %X",i, &vet[i]); // Imprime o endereço de memória do elemento do vetor vet na posição i.
  // &vet[i] é equivalente a f+i, dado que &(vet[i]) retorna o endereço de memória do elemento do vetor vet na posição i.
  
  printf(" (f + %d) = %X",i, f+i); // Imprime o endereço de memória do elemento do vetor vet na posição i.
  // f+i é equivalente a &vet[i], dado que f aponta para o endereço de memória do primeiro elemento do vetor vet.
  
  printf("\n");
  }
  return 0;
}