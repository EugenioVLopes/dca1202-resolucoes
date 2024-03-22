#include <stdio.h>

int main() {
    // Variavéis declaradas advindas da questão:

    // Variável inteira chamada valor.
    int valor;
    // Ponteiro para inteiro chamado p1.
    int *p1;
    // Variável de ponto flutuante chamada temp.
    float temp;
    // Ponteiro para ponto flutuante chamado p2.
    float *p2;
    // Variável de caractere chamada aux.
    char aux;
    // Ponteiro para caractere chamado nome e inicializa-o com o endereço da string "Ponteiros".
    char *nome = "Ponteiros";
    // Ponteiro para caractere chamado p3.
    char *p3;
    // Variável inteira chamada idade.
    int idade;
    // Ponteiro para inteiro chamado p4.
    int vetor[3];
    // Ponteiro para inteiro chamado p5.
    int *p4;
    // Ponteiro para inteiro chamado p5.
    int *p5;

    // CÓDIGO EXPLICADO

    // TRECHO a)
    printf("\nTRECHO a) \n");
    // A variavel 'valor' recebe valor igual a 10:
    valor = 10;
    // Em seguida, o ponteiro definido para inteiro p1 recebe o endereço (&) da memoria de 'valor':
    p1 = &valor;
    // Agora, o valor que era guardado no endereço de p1 é alterado pra 20:
    *p1 = 20;
    // Por fim, o valor que existe no endereço de 'valor' é mostrado, que agora é igual a 20:
    printf("Valor de 'valor': %d \n", valor);

    // TRECHO b)
    printf("\nTRECHO b) \n");
    // Variavel 'temp' recebe valor com ponto flutuante igual a 26.5:
    temp = 26.5;
    // Endereço (&) de temp é recebido por p2:
    p2 = &temp;
    // Agora, o valor que era guardado no endereço de p1 é alterado pra 29.0:  
    *p2 = 29.0;
    // Por fim, o valor que existe no endereço de 'temp' é mostrado com aproximação de uma casa decimal:
    printf("Valor de 'temp: '%.1f \n", temp);

    // TRECHO c)
    printf("\nTRECHO c) \n");
    // O ponteiro *p3 recebe o endereço (&) do primeiro elemento da string 'nome':
    p3 = &nome[0];
    // Variavel 'aux' recebe o valor contido na variavel p3, que é a primeira letra do nome 'Ponteiros'
    aux = *p3;
    // Por fim, o valor que existe no endereço de 'aux' é mostrado (P):
    printf("Valor de 'aux': %c \n", aux);

    // TRECHO d)
    printf("\nTRECHO d) \n");
    // Assim como no trecho c, o ponteiro *p3 recebe agora, sobrescrevendo o valro guardado antes, o endereço (&) do quinto elemento da string 'nome':
    p3 = &nome[4];
    // Variavel 'aux' recebe o valor contido na variavel p3, que é a quinta letra do nome 'Ponteiros'
    aux = *p3;
    // Por fim, o valor que existe no endereço de 'aux' é mostrado (e):
    printf("Valor de aux: %c \n", aux);

    // TRECHO e)
    printf("\nTRECHO e) \n");
    // O ponteiro *p3 recebe agora:
    // A variável nome é inicializada com o endereço da primeira posição da string "Ponteiros"
    // Em C, uma string é representada como um array de caracteres terminado por um caractere nulo '\0'
    // Portanto, quando atribuimos "Ponteiros" a nome, na verdade está atribuindo o endereço do primeiro caractere da string
    p3 = nome;
    // Sendo assim, agora a letra P será mostrada:
    printf("Valor de *p3 : %c \n", *p3);

    // TRECHO f)
    printf("\nTRECHO f) \n");
    // Assim como no trecho e, agora atribuimos a p3 o valor do endereço da string "Ponteiros" "pulando" 4 posições
    // Agora será visulizado o que está no endereço nesta respectiva posição
    p3 = p3 + 4;
    //Será mostrado agora o valor que está no endereço de p3, que é a letra e:
    printf("Valor de *p3: %c \n", *p3);

    // TRECHO g)
    printf("\nTRECHO g) \n");
    // Agora pegamos a posição que estavamos e subtraimos uma "casa" dela, ou seja, agora estamos na posição 3 da string "Ponteiros"
    p3--;
    //Será mostrado agora o valor que está no endereço de p3, que é a letra t:
    printf("Valor de p3: %c \n", *p3);

    // TRECHO h)
    printf("\nTRECHO h) \n");
    // Aqui são atribuidas as 3 primeiras posições do vetor para os 3 primeiros elementos do vetor:
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    // O ponteiro p4 recebe o endereço do vetor:
    p4 = vetor;
    // A variavel idade recebe então o valor que está no endereço de p4, que é, conforme explicado no trecho e, o primeiro elemento do vetor:
    idade = *p4;
    // Será mostrado o valor que está no endereço de idade (primeira posição), que é 31:
    printf("Valor de idade: %d \n", idade);
    
    // TRECHO i)
    printf("\nTRECHO i) \n");
    // O ponteiro p5 recebe o endereço que está em p4, que é o do vetor, somado a 1, ou seja, será guardao 45
    p5 = p4 + 1;
    // A variavel idade recebe então o valor que está no endereço de p5, que é, conforme explicado no trecho e, o segundo elemento do vetor:
    idade = *p5;
    // Será mostrado o valor que está no endereço de idade (segunda posição), que é 45:
    printf("Valor de idade: %d \n", idade);

    // Trecho j)
    printf("\nTRECHO j) \n");
    // O trecho segue a mesma lógica dos trechos anteriores...
    // O ponteiro p4 recebe o endereço que está em p5, que é o do vetor, somado a 1, ou seja, será guardao 27
    p4 = p5 + 1;
    // A variavel idade recebe então o valor que está no endereço de p4, que é, conforme explicado no trecho e, o terceiro elemento do vetor:
    idade = *p4;
    // Será mostrado o valor que está no endereço de idade (terceira posição), que é 27:
    printf("Valor de idade%d \n", idade);

    // Trecho l)
    printf("\nTRECHO l) \n");
    // O ponteiro p4 recebe o endereço que está em p4, que é o do vetor, subtraido de 2, ou seja, será guardao o mesmo que no trecho h), 31
    p4 = p4 - 2;
    // A variavel idade recebe então o valor que está no endereço de p4
    idade = *p4;
    // Será mostrado o valor que está no endereço de idade (primeira posição), que é 31:
    printf("Valor de idade: %d \n", idade);

    // Trecho m)
    printf("\nTRECHO m) \n");
    // O ponteiro p5 recebe o endereço que está na posição 2 do vetor "vetor", subtraido de 1, ou seja, será guardao o mesmo que no trecho i), 45
    p5 = &vetor[2] - 1;
    // O valor do endereço que está em p5 é mostrado, que é 45:
    printf("Valor de *p5: %d \n", *p5);

    // Trecho n)
    printf("\nTRECHO n) \n");
    // O ponteiro p5 pula uma posição do vetor, ou seja, agora está no endereço do terceiro elemento do vetor, é o próprio endereço somado a 1
    p5++;
    // O valor do endereço que está em p5 é mostrado, que é 27:
    printf("Valor de *p5: %d \n", *p5);
}