#include <stdio.h>

int main() {
    int testei;
    char testec[10];
    scanf("%d %9[^\n]", &testei, testec);

    printf("%d %s", testei, testec);
    return 0;
}