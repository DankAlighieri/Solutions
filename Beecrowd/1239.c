#include <stdio.h>
#include <string.h>
#define tam 51
#define tam2 300

int main() {
    char texto[tam], textoFinal[tam2];
    int i, j, contadorI, contadorB, size;
    
    
    while(scanf(" %[^\n]", texto)!=EOF) {

        memset(textoFinal, 0, sizeof(textoFinal));

        contadorI = 0;
        contadorB = 0;

        for (i = 0, j = 0; texto[i]; i++) {
            if (texto[i] == '_') {
                contadorI++;
                if (contadorI % 2 == 1) {
                    textoFinal[j++] = '<';
                    textoFinal[j++] = 'i';
                    textoFinal[j++] = '>';
                } else {
                    textoFinal[j++] = '<';
                    textoFinal[j++] = '/';
                    textoFinal[j++] = 'i';
                    textoFinal[j++] = '>';
                }
            } else if (texto[i] == '*') {
                contadorB++;
                if (contadorB % 2 == 1) {
                    textoFinal[j++] = '<';
                    textoFinal[j++] = 'b';
                    textoFinal[j++] = '>';
                } else {
                    textoFinal[j++] = '<';
                    textoFinal[j++] = '/';
                    textoFinal[j++] = 'b';
                    textoFinal[j++] = '>';
                }
            } else {
                textoFinal[j++] = texto[i];
            }
        }

        size = strlen(textoFinal);

        printf("%s\n", textoFinal);
    }

    return 0;
}

