#include <stdio.h>

// 22. (ENADE, 2023) Na programação de sistemas embarcados, algumas posições de memória servem
// para diferentes propósitos, não apenas para armazenar valores. Em algumas dessas memórias,
// cada um os bits possui um significado diferente, sendo necessário manipulá-los
// individualmente ou em pequenos grupos. Por isso, o conhecimento da álgebra booliana, bem
// como dos operadores tilizados para realizar operações binárias nas linguagens de programação,
// é essencial para o desenvolvimento desse tipo de sistema. A partir dessas informações, observe
// o código apresentado a seguir, escrito na linguagem C, que faz uso de operações binárias sobre
// variáveis inteiras.

// (código após o enuciado da questão)

// Após a chamada desse programa, caso o usuário entre com os valores 10 e 1, nessa ordem, qual
// será, exatamente, o valor da saída do programa?

int main(){
    // Declaração das variáveis
    int a, b;
    int x, y, z;
    
    // Leitura dos valores de a e b
    scanf("%d %d", &a, &b);
    // Atribuindo dos valores de a e b às variáveis x e y
    x = a; y = b; z = a + b;
    
    // Laço de repetição
    // Enquanto a for diferente de 0
    while (a) {
        // x recebe o valor de x ou b
        // Aqui o que ocorre é uma operação de OR bit a bit
        // OR é uma operação que retorna 1 se pelo menos um dos bits for 1
        x = x | b;
        // y recebe o valor de y ou a
        // Já nesse caso a operação é de XOR bit a bit
        // XOR é uma operação que retorna 1 se os bits forem diferentes e 0 se forem iguais
        y = y ^ a;
        // z recebe o valor de z e (a + b)
        // Aqui a operação é de AND bit a bit
        // AND é uma operação que retorna 1 se ambos os bits forem 1, e 0 caso contrário
        z = z & (a+b);
        // a recebe o valor de a deslocado uma posição para a direita
        a = a >> 1;
        // b recebe o valor de b deslocado uma posição para a esquerda
        b = b << 1;
    }
    
    printf ("%d %d %d\n", x, y, z);
    return 0;
}

// Quando exercutamos o código e entramos com os valores 10 e 1, respectivamente, o que vai acontecer no primeiro laço é o seguinte:
// - x será inicializado com a (10), y com b (1) e z com a + b (11).
// - No loop, a operação OR bit a bit será realizada entre x e b, resultando em x = 10 | 1 = 11.
// - A operação XOR bit a bit será realizada entre y e a, resultando em y = 1 ^ 10 = 11.
// - A operação AND bit a bit será realizada entre z e a + b, resultando em z = 11 & 11 = 11.
// - a será deslocado uma posição para a direita, resultando em a = 10 >> 1 = 5.
// - b será deslocado uma posição para a esquerda, resultando em b = 1 << 1 = 2.
// - O loop será repetido com os novos valores de a e b, e as operações serão realizadas novamente.
// O loop será repetido até que a seja igual a 0.
// Executando o código na minha máquina, o resultado obtido foi 15 13 0