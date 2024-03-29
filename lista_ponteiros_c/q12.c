#include <stdio.h>

// 12. Suponha que as seguintes declarações tenham sido realizadas:
//     float aloha[10], coisas[10][5], *pf, value = 2.2;
//     int i=3;
//   - Identifique quais dos seguintes comandos é válido ou inválido:
//     aloha[2] = value;
//     scanf("%f", &aloha);
//     aloha = "value";
//     printf("%f", aloha);
//     coisas[4][4] = aloha[3];
//     coisas[5] = aloha;
//     pf = value;
//     pf = aloha;

void main(){
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;

    aloha[2] = value;
    printf("aloha[2]: %f \n", aloha[2]);
    // O comando acima é válido, pois estamos atribuindo um valor float a um elemento do vetor 'aloha'.	
    
    scanf("%f", &aloha);
    // O comando acima é incorreto, pois estamos tentando atribuir um valor float a um vetor de floats.
    // Pelo testado, apesar de ser inválido, o programa não apresenta erro de compilação. 
    // O que acontece é que não especificamos qual elemento do vetor 'aloha' queremos atribuir o valor lido.
    // Dessa forma, o valor lido será atribuído ao primeiro elemento do vetor 'aloha'.
    printf("aloha[0]: %f \n", aloha[0]);
    // Mas isso não é uma boa prática, pois estamos acessando um endereço de memória que não foi inicializado.
    // O comando no caso é válido, mas não é recomendado.
    
    // aloha = "value";
    // O comando acima é inválido, pois estamos tentando atribuir uma string a um vetor de floats.

    printf("%f", aloha);
    // Como não foi especificado qual elemento do vetor 'aloha' queremos imprimir (sem indice), o programa vai interpretar o vetor 'aloha' como um ponteiro para o endereço de memória do início do vetor
    // Mas o que acontece nesse caso é que estamos tentando imprimir um endereço de memória como se fosse um float (%f), o que não é possível.
    // O comando acima é inválido.

    coisas[4][4] = aloha[3];
    printf("\ncoisas[4][4]: %f \n", coisas[4][4]);
    // O comando acima é válido, pois estamos atribuindo um valor float a um elemento da matriz 'coisas'.
    // Como esse elemento não foi inicializado, o valor atribuído será 0.0.

    // coisas[5] = aloha;
    // O comando acima é inválido, pois estamos tentando atribuir um vetor de floats a uma linha da matriz 'coisas'.

    // pf = value;
    // Como o próprio compilador avisa, o comando acima é inválido, pois estamos tentando atribuir um valor float a um ponteiro para float.

    pf = aloha;
    // Nessa caso, estamos tentando declarar um ponteiro para float e atribuir a ele o endereço do vetor 'aloha'.
    // aloha é um vetor de floats, então seu nome é um ponteiro para o primeiro elemento do vetor.
    // Dessa forma, o comando acima é válido.
    printf("pf: %f \n", *pf);
}