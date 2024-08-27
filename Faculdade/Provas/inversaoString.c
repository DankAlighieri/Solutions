#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void inverter(char *string, int i, int f) {
    if (i < f) {
        swap(string + i, string + f); 
        inverter(string, i + 1, f -1);
    }
}

int main() {
    char string[] = "carro";
    printf("%s\n",string);
    inverter(string, 0, strlen(string) - 1);
    printf("%s\n",string);

    return 0;
}