#include <stdio.h>
#include <string.h>
#define tam 300

typedef struct {
    char id;
    int minutos;
    char veredito[10];
} problemas;

void inicializa_struct(problemas p) {
    scanf("%c %d, %s", &p.id, &p.minutos, p.veredito);
}

int verifica_correto(problemas p){
    if (!strcmp(p.veredito,"correct")) {
        return p.minutos;
    }
    return 0;
}

int main() {
    problemas p[tam];
    int i, n;

    do {
        scanf("%d", &n);
        if (n > 0) {
            for (i = 0; i < tam; i++) {
                inicializa_struct(p[i]);
                verifica_correto(p[i]);
            }
        } else {
            break;
        }
    } while (n);

    return 0;
}