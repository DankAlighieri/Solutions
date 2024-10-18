#include <stdio.h>
#include <string.h>

int main() {
    int n, tot;
    char skills[1001];

    scanf("%d", &n);
    tot = n;
    while (n) {
        scanf(" %s", skills);
        if (strstr(skills, "CD")) 
            tot--;
        
        n--;
    }

    printf("%d\n", tot);

    return 0;
}