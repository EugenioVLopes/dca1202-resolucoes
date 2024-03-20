// 9. Qual será a saída do seguinte programa
// #include <stdio.h>
// struct teste{
//   int x = 3;
//   char nome[] = "jose";
// };
// main(){
//   struct teste *s;
//   printf("%d", s->x);
//   printf("%s", s->name);
// }

#include <stdio.h>

struct teste // Declaração da estrutura teste.
{
    int x = 3;            // Declaração e inicialização da variável x.
    char nome[] = "jose"; // Declaração e inicialização da variável nome como um vetor de caracteres.
};

// O erro está aqui, a inicialização de variáveis dentro de uma estrutura não é permitida.

int main()
{
    struct teste *s;       

    printf("%d", s->x);    
    
    printf("%s", s->nome); 
    
    return 0;
}

// O programa acima não compila, pois a estrutura teste está com erro de sintaxe.
