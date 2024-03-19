// Mostre o que será impresso por programa supondo que a variável i ocupa o endereço 4094 na
// memória e que nessa arquitetura os inteiros possuem 2 bytes de tamanho.
#include <stdio.h>

int main(){
  int i=5, *p;
  p = &i;
  printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);
    // Saída: 0x7ffedc3d3f7c 0x7ffedc3d3f80 7 5 15 9
}