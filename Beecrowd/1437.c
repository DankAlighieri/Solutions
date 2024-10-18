#include <stdio.h>
#define tam 1000

int main() {
    int n, i, j;
    char direcoes[] = {'O', 'N', 'L', 'S'}, direcao_atual;

    do {
        scanf("%d", &n);
        if (!n) {
            return 0;
        }
        char entrada[n];
        scanf(" %s", entrada);
        direcao_atual = 'N';
        j = 1;
        for (i = 0; entrada[i]; i++) { 
            //printf("%c\n", direcao_atual);
            //printf("%d\n", j);
            switch (entrada[i]) {
                case 'D':
                    //puts("indo direita");
                    if (j == 3) {
                        //puts("indo esquerda e fazendo ciclo");
                        j = 0;
                        direcao_atual = direcoes[j];
                        break;
                    }    
                    j++;
                    direcao_atual = direcoes[j];
                    break;
                case 'E':
                    //puts("indo esquerda");
                    if (j == 0) {
                        //puts("indo esquerda e fazendo ciclo");
                        j = 3;
                        direcao_atual = direcoes[j];
                        break;
                    }
                    j--;
                    direcao_atual = direcoes[j];
                    break;
                default:
                    break;
                }
            }
            printf("%c\n", direcao_atual);
    } while (n);
    
    return 0;
}