#include <stdio.h>
#include <string.h>

typedef struct {
    char NOME [1000];
    char COR[10];
    char TAMANHO;
} camiseta;

void imrpime(camiseta *c, int n);

void inicializa(camiseta *c, int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf(" %999[^\n]", c[i].NOME);
        scanf(" %s %c", c[i].COR, &c[i].TAMANHO);
    }
}

void swap(camiseta *c, camiseta *ca) {
    camiseta temp = *c;
    *c = *ca;
    *ca = temp;

    return;
}

void sortCor(camiseta *c, int n) {
    int i, j;
    camiseta temp;
    for(i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(c[j].COR, c[j+1].COR) > 0) {
                swap(&c[j], &c[j+1]);
            }
        }
    }
}

void sortTam(camiseta *c, int n) {
    int i, j;
    camiseta temp;
    for(i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (c[j].TAMANHO < c[j+1].TAMANHO) {
                swap(&c[j], &c[j+1]);
            }
        }
    }
}

void sortNome(camiseta *c, int n) {
    int i, j;
    camiseta temp;
    for(i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(c[j].NOME, c[j+1].NOME) > 0) {
                swap(&c[j], &c[j+1]);
            }
        }
    }
}

int main() {
    int n, i, first = 1;
    camiseta camisetas[61];
    do {
        scanf("%d", &n);
        if (n == 0) break;

        if (!first) {
            printf("\n");
        }
        first = 0;

        inicializa(camisetas, n);

        sortNome(camisetas, n);
        sortTam(camisetas, n);
        sortCor(camisetas, n);
        
        imrpime(camisetas, n);

    } while(1);

    return 0;
}

void imrpime(camiseta *c, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s %c %s\n", c[i].COR, c[i].TAMANHO, c[i].NOME);
    }
}