#include <stdio.h>
#include <string.h>

int main() {
    char cor1[10] = "vermelho", cor2[20]  = "branco";
    
    printf("%d", strcmp(cor1, cor2));

    return 0;
}