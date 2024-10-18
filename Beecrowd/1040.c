#include <stdio.h>

int main() {
    double n1,n2,n3,n4,f1, m;
    setbuf(stdin,NULL);
    scanf("%lf%lf%lf%lf", &n1,&n2,&n3,&n4);

    m = ((n1*2)+(n2*3)+(n3*4)+(n4*1))/(2+3+4+1);

    printf("Media: %.1lf\n", m);
    if (m >= 7.0 ) printf("Aluno aprovado.\n");
    else if ( m < 5.0) printf("Aluno reprovado.\n");
    else {
        printf("Aluno em exame.\n");
        setbuf(stdin,NULL);
        scanf("%lf", &f1);
        m  = (m + f1)/2;
        printf("Nota do exame: %.1lf\n", f1);
        if (m > 5.0) {
            printf("Aluno aprovado.\nMedia final: %.1lf\n", m);
            return 0;
        }
        printf("Aluno reprovado.\n");
    }
    return 0;
}