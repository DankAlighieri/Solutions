#include <stdio.h>
#include <string.h>
#define tam 300

typedef struct {
    char id;
    int minutos;
    char veredito[20];
} PROBLEMAS;

int main() {
    PROBLEMAS problemas[tam];
    int i, n, correct, minutos, j, 
        somatorio, quant = 0, count, 
        erros[26], primeiro_acerto[26];
    char id;
    do {
        correct = 0;
        somatorio = 0;
        memset(erros, 0, sizeof(erros));
        memset(primeiro_acerto, -1, sizeof(primeiro_acerto));

        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        for (i = 0; i < n; i++) {
            scanf(" %c %d %s", &problemas[i].id, &problemas[i].minutos, problemas[i].veredito);
        }
        
        for (i = 0 ; i < n; i++) {
            id = problemas[i].id - 'A';
            if (!strcmp(problemas[i].veredito, "correct")) {
                if (primeiro_acerto[id] == -1) {
                    correct++;
                    primeiro_acerto[id] = problemas[i].minutos;
                    somatorio += problemas[i].minutos + erros[id] * 20;
                }
            } else {
                erros[id]++;
            }
        }
        printf("%d %d\n", correct, somatorio);
    } while (n);

    return 0;
}