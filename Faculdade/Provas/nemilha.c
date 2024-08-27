#include <stdio.h>
#define tam 40

typedef struct {
    char Cnum[tam];
    char email[tam];
    char nome[tam];
    char cpf[tam];
    char nascimento[tam];
    char lim[tam];
    char venc[tam];
} reg1;

typedef struct {
    char cartao[tam];
    char codEst[tam];
    char nomEst[tam];
    char valor[tam];
    char dataComp[tam];
} reg2;

typedef struct {
    char cartao[tam];
    char codBol[tam];
    char valor[tam];
    char venc[tam];
    char pago;
} reg3;

void cadastro(reg1 *r1  ) {

    
}