#include <stdio.h>
#include <string.h>
#define tam 1000

int main() {
    int lineQuant, i, j, *k, size, asciiCode[tam], metade, aux;
    char text[tam], outuput[size], *p;

    scanf("%d", &lineQuant);

    while(lineQuant) {
        scanf(" %999[^\n]", text);
        size = strlen(text);

        for (i = 0; text[i]; i++) {
            asciiCode[i] = text[i];
            //printf("%c = %d\n", text[i], asciiCode[i]);
        }

    // Passo 1
        for (i = 0; i < size; i++) {
            if ((asciiCode[i] > 64 && asciiCode[i] < 91) || (asciiCode[i] > 96 && asciiCode[i] < 123))
                asciiCode[i] += 3;
        }

        // TODO: Find wrong answer 5% bug

    // Passo 2
        for (j = 0; j < size / 2; j++) {
            aux = asciiCode[j];
            asciiCode[j] = asciiCode[size - j - 1];
            asciiCode[size - j - 1] = aux;
        }

    // Passo 3
        for (metade = (size/2) - 1; metade < size; metade++)
            asciiCode[metade]--;

        for (i = 0, k = asciiCode; i < size; k++, i++) {
            printf("%c", *k);
        }
        printf("\n");


        lineQuant--;
    }

    return 0;
}
