// Mostre o que será impresso por programa supondo que a variável i ocupa o endereço 4094 na
// memória e que nessa arquitetura os inteiros possuem 2 bytes de tamanho.
#include <stdio.h>

int main()
{
  int i = 5, *p; // Declaração da variável i e do ponteiro p.
  p = &i;        // Atribuição do endereço de i ao ponteiro p.
  printf("%p %p %d %d %d %d\n", p, p + 1, *p + 2, **&p, 3 * *p, **&p + 4);
  // Saída: p   : Endereço de memória que a variávl i esta armazenada em hexadecimal. (4094)

  //        p+1 : Adiciono o valor de um int (2 bytes) ao endereço de memória armazenado em p. (4096)

  //        *p+2: Recupera o conteudo do endereço armazenado no ponteiro (i=5) e faz a operação de +2, resultando em 7. (7)

  //        **&p: (*(*(&p) Aponta para o endereço de p; aponta para o conteudo do endereço p (Memória que a variável i
  //                       está armazenada ); aponta para o conteudo do endereço armazenado no ponteiro (i=5). (5)

  //        3**p: 3*(*p)) Multiplica o conteudo do endereço armazenado no ponteiro por 3 (i=5*3=15). (15)

  //        **&p+4: (*(*(&p)) Aponta para o endereço de p; aponta para o conteudo do endereço p (Memória que a variável i está
  //                          armazenada ); aponta para o conteudo do endereço armazenado no ponteiro (i=5) e soma 4, resultando
  //                          em 9. (9)

  // RESPOSTA:       4094 4096 7 5 15 9
}