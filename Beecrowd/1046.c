#include <stdio.h>

int main() {
    int horaInicial, horaFinal;
    scanf("%d %d", &horaInicial, &horaFinal);

    if (horaInicial == horaFinal) {
        printf("O JOGO DUROU 24 HORA(S)\n");
        return 0;
    }

    if (horaFinal < horaInicial) {
        horaFinal += 24;
        printf("O JOGO DUROU %d HORA(S)\n", (horaFinal-horaInicial));
    } else {
        printf("O JOGO DUROU %d HORA(S)\n", (horaFinal-horaInicial));
    }

    return 0;
}