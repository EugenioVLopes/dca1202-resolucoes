// 21. (ENADE, 2023) Memory leak, ou vazamento de memória, é um problema que ocorre em
// sistemas computacionais quando uma parte da memória, alocada para uma determinada
// operação, não é liberada quando se torna desnecessária. Na linguagem C, esse tipo de problema
// é quase sempre relacionado ao uso incorreto das funções malloc( ) e free( ). Esse erro de
// programação pode levar a falhas no sistema se a memória for completamente consumida. Um
// dos trechos abaixo apresenta um vazamento de memória. Identifique-o e justifique sua
// resposta.
// A void f( ){
//   void *s;
//   s = malloc(50);
//   free(s);
// }
// B int f( ){
//   float *a;
//   return 0;
// }
// C int f(char *data){
//   void *s;
//   s = malloc(50);
//   int size = strlen(data);
//   if (size > 50)
//   return(-1);
//   free(s);
//   return 0;
// }
// D int *f(int n){
//   int *num = malloc(sizeof(int)*n);
//   return num;
// }
// 7
// int main(void){
//   int *num;
//   num = f(10);
//   free(num);
//   return 0;
// }
// E void f(int n){
//   char *m = malloc(10);
//   char *n = malloc(10);
//   free(m);
//   m = n;
//   free(m);
//   free(n);
// }

// Resposta: Alternativa C. O trecho de código da alternativa C apresenta um vazamento de memória. 
// Isso ocorre porque a memória alocada para o ponteiro s não é liberada caso o tamanho da string 
// passada como argumento seja maior que 50. Nesse caso, a função retorna -1 sem liberar a memória 
// alocada, resultando em um vazamento de memória. Para corrigir esse problema, é necessário liberar 
// a memória alocada para o ponteiro s antes de retornar -1.
