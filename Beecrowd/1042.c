#include <stdio.h>
#include <stdlib.h>


int main() {
    int values[3], ind_menor = 0, aux;
    scanf("%d%d%d", &values[0], &values[1], &values[2]);

    for (int i = 1; i < sizeof(values) - 1; i++) {
        if (values[i] < values[ind_menor]) ind_menor = i;
    }

    aux = values[0];
    values[0] = values[ind_menor];
    values[ind_menor] = aux;
    return 0;
}