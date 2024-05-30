#include <stdio.h>

int main(){
    int cd, qt; 
    float c[6]={0, 4, 4.5, 5, 2, 1.5};
    scanf("%d%d", &cd, &qt);
    printf("Total: R$ %.2f\n", qt *c[cd]);

    return 0;
}