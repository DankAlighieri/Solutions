#include <stdio.h>

int main() {
    int hI, mI, hF, mF, ans;
    scanf("%d %d %d %d", &hI, &mI, &hF, &mF);

    ans = (hF-hI)*60 + (mF-mI);
    if (ans <= 0) 
        ans += 60*24;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", ans/60, ans%60);

    return 0;
}
