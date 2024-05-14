#include <stdio.h>

int main() {
    int a, b, MMC;

    if (a<b) {
        MMC = a;
        a = b;
        b = MMC;
    }

    for (MMC = a; MMC%b; MMC+=a);


    return 0;
}