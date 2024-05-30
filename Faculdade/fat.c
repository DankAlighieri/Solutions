#include <stdio.h>
#include "fatRec.h"

int main() {
    int num;
    scanf("%d", &num);
    printf("%d", fatRec(num));

    return 0;
}