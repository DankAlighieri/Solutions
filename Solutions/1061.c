#include <stdio.h>

int main() {
    int wI, xI, yI, zI, wF, xF, yF, zF, totalSegundos, totalDias, horas, minutos;
    scanf(" Dia %d", &wI);
    scanf(" %d : %d : %d", &xI, &yI, &zI);
    scanf(" Dia %d", &wF);
    scanf(" %d : %d : %d", &xF, &yF, &zF);

    totalDias = wF - wI;
    totalSegundos = (((xF-xI)*3600) + ((yF-yI)*60) + zF-zI);

    if(totalSegundos < 0) {
        totalDias--;
        totalSegundos += 86400;
    }
    horas = totalSegundos/3600;
    minutos = totalSegundos%3600/60;
    totalSegundos = (totalSegundos%3600%60);

    printf ("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", totalDias, horas, minutos, totalSegundos);

    return 0;
}