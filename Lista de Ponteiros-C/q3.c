// 3. Se i e j são variáveis inteiras e p e q ponteiros para int, quais das seguintes expressões de
// atribuição são ilegais? Justifique.
// p = &i;
// *q = &j;
// p = &*&i;
// i = (*&)j;
// i = *&j;
// i = *&*&j;
// q = *p;
// i = (*p)++ + *q;~

#include <stdio.h>

int main(){
    int i, j;
    int *p, *q;
    p = &i; // Legal.
    // É atribuido o endereço de i ao ponteiro p e é válido porque &i retorna o endereço de memória de i 
    // e p é um ponteiro para int.

    //*q = &j; // Ilegal. 
    // É tentado atribuir o endereço de j ao valor (conteúdo) de p.
    // Isso é inválido dado que "&" retorna um endereço, que já não é compatível com o tipo de dado que 
    // q aponta (int).
    // Além disso, o ponteiro "q" precisa ser inicializado.
    
    
    p = &*&i; // Legal. 
    // Atribuição do endereço de i ao ponteiro p.
    // &(*(&i)): Primeiro, o operador & retorna o endereço de i. Depois, o operador * retorna o valor apontado
    // pelo endereço de memória de i, que é o valor de i. Por fim, o operador & retorna o endereço de memória
    // do valor de i.

    // i = (*&)j; // Ilegal. 
    // O operador & retorna o endereço de memória de uma variável, mas não pode ser aplicado a uma expressão.

    i = *&j; // Legal. 
    // Atribuição do valor apontado por j à variável i.
    // *(&j): Primeiro, o operador & retorna o endereço de memória de j. Depois, o operador * retorna o valor
    // apontado pelo endereço de memória de j (O valor apontado por j é o valor da variável j).

    i = *&*&j; // Legal. 
    //Atribuição do valor apontado por j à variável i.
    // *(&(*(&j))): Primeiro, o operador & retorna o endereço de memória de j. Depois, o operador * retorna o valor
    // apontado pelo endereço de memória de j (O valor apontado por j é o valor da variável j). Depois, o operador
    // & retorna o endereço de memória do valor de j. Por fim, o operador * retorna o valor apontado pelo endereço
    // de memória do valor de j.
    
    
    q = *p; // Legal. 
    // Atribuição do valor apontado por p à variável q.

    i = (*p)++ + *q; // Legal. 
    //Atribuição da soma do valor apontado por p incrementado e do valor apontado por q à variável i.
    // (*p)++: Primeiro, o operador * retorna o valor apontado por p. Depois, o operador ++ incrementa o valor
    // apontado por p. Por fim, o operador + soma o valor apontado por p incrementado ao valor apontado por q.
    
}