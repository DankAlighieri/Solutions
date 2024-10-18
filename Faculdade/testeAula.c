#include <stdio.h>
#include <string.h>

int main (void) {
    char digits[4];

    while (digits) {
        setbuf(stdin, NULL);
        scanf("%s", digits);
        if (strlen(digits) == 1 && digits[0] == '0'){
                break;
            }
        else {
            for (int i = strlen(digits) - 1 ; i >=0 ; i--){
                printf("%c", digits[i]);
            }
            printf("\n");
        }
    }
}