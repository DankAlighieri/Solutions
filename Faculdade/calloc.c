#include <stdio.h>
#include <stdlib.h>


int main() {
    int tam, comprimento;
    char *str;

    scanf("%d %d", &tam, &comprimento);
                                        // somando 1 ao comprimento para contabilizar o \0
    str = (char *) calloc(tam, (comprimento + 1)*sizeof(char));

    if (!str) {
        printf("Erro na memoria\n");
        exit(1);
    }

    for (int count = 0; count < tam; count++) {
        scanf("%s", str+(count*(comprimento + 1)));
    }

    for (int count = 0; count < tam; count++) {
        printf("%s\n", str+(count*(comprimento + 1)));
    }

    return 0;
}