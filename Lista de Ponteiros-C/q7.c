// 7. Considerando a declaração
// int mat[4], *p, x;
// quais das seguintes expressões são válidas? Justifique.
// p = mat + 1;
// p = mat;
// p = mat;
// x = (*mat);

#include <stdio.h>

int main(){
    int mat[4], *p, x; // Declaração do vetor mat de 4 posições, do ponteiro p e da variável x.
    
    p = mat + 1; // Válida.
    // O ponteiro p recebe o endereço do segundo elemento do vetor mat.
    // mat + 1 é equivalente a &mat[1].
    printf("p1 = %p\n", p);
    
    p = mat; // Válida.
    // O ponteiro p recebe o endereço do primeiro elemento do vetor mat.
    // mat é equivalente a &mat[0].
    printf("p2 = %p\n", p);
    
    p = mat; // Válida.
    // O ponteiro p recebe o endereço do primeiro elemento do vetor mat.
    // mat é equivalente a &mat[0].
    printf("p3 = %p\n", p);
    
    x = (*mat); // Válida.
    // A variável x recebe o valor do primeiro elemento do vetor mat.
    // *mat é equivalente a mat[0].
    // O valor de x sera um valor "lixo", pois mat não foi inicializado.
    printf("x = %d\n", x);

    return 0;
}

// Perguntar a Agostinho pq quando eu coloco apenas mat de um vetor retorna o endereço do primeiro elemento do vetor.