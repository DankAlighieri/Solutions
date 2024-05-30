#include <stdio.h>

int main() {
    int a,b, aux;
    scanf("%d%d", &a, &b);


    // Verificiando se b maior que a
    if (b > a) {
        // invertendo os valores
        aux = a;
        a = b;
        b = aux;
        // atribuindo a divisao de a/b p aux
        aux = a/b;
        // verficando se o produto entre aux e b eh diferente de a
        if ((aux*b) != a) {
            // se for, ent n sao multiplos
            printf("Nao sao Multiplos\n");
            return 0;
        }

        printf("Sao Multiplos\n");
        return 0;
    }

    aux = a/b;
    if ((aux*b) != a) {
        printf("Nao sao Multiplos\n");
        return 0;
    }

    printf("Sao Multiplos\n");

    return 0;
}