#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define tam 30

typedef struct {
    char PRIMEIO_NOME[tam];
    char NOME_MEIO[tam];
    char ULTIMO_NOME[tam];
    char ENDERECO[tam];
    char TEL_CONV[tam];
    char TEL_CEL[tam];
    char TEL_COM[tam];
    char DATA_ANIVERSARIO[tam];
    char EMAIL[tam];

} agenda;


void inicializarAgenda(agenda **a, int *count) {
    char entrada[tam];

    *count = 0;

    while (1) {
        puts("Digite o primeiro nome: ");
        setbuf(stdin, NULL);
        fgets(entrada, tam, stdin);
        if (entrada[0] == '\n') {
            return;
        }

        entrada[strcspn(entrada, "\n")] = '\0';

        *count += 1;
        *a = (agenda *) realloc(*a, (*count)*sizeof(agenda));
        if (!(*a)) {
            puts("Erro de memoria!");
            exit(1);
        }
        strcpy((*a)[*count-1].PRIMEIO_NOME, entrada);

        puts("Digite o segundo nome: ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].NOME_MEIO, tam, stdin);
        (*a)[*count-1].NOME_MEIO[strcspn((*a)[*count-1].NOME_MEIO, "\n")] = '\0';

        puts("Digite o ultimo nome: ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].ULTIMO_NOME, tam, stdin);
        (*a)[*count-1].ULTIMO_NOME[strcspn((*a)[*count-1].ULTIMO_NOME, "\n")] = '\0';

        puts("Digite o endereco: ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].ENDERECO, tam, stdin);
        (*a)[*count-1].ENDERECO[strcspn((*a)[*count-1].ENDERECO, "\n")] = '\0';

        puts("Digite o telefone convencional: ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].TEL_CONV, tam, stdin);
        (*a)[*count-1].TEL_CONV[strcspn((*a)[*count-1].TEL_CONV, "\n")] = '\0';

        puts("Digite o telefone celular: ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].TEL_CEL, tam, stdin);
        (*a)[*count-1].TEL_CEL[strcspn((*a)[*count-1].TEL_CEL, "\n")] = '\0';

        puts("Digite o telefone comercial: ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].TEL_COM, tam, stdin);
        (*a)[*count-1].TEL_COM[strcspn((*a)[*count-1].TEL_COM, "\n")] = '\0';

        puts("Digite a data de aniversario (xx/xx/xx): ");
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].DATA_ANIVERSARIO, tam, stdin);
        (*a)[*count-1].DATA_ANIVERSARIO[strcspn((*a)[*count-1].DATA_ANIVERSARIO, "\n")] = '\0';

        puts("Digite o email: ");  
        setbuf(stdin, NULL);
        fgets((*a)[*count-1].EMAIL, tam, stdin);
        (*a)[*count-1].EMAIL[strcspn((*a)[*count-1].EMAIL, "\n")] = '\0';
    }
}

void imprimirAgendaAna(agenda *a, int count){
    for (int i = 0; i < count; i++) {
        if (strcmp(a[i].PRIMEIO_NOME, "Ana")) {
            printf("\nContato %d:\n", i + 1);
            printf("  Primeiro Nome: %s\n", a[i].PRIMEIO_NOME);
            printf("  Nome do Meio: %s\n", a[i].NOME_MEIO);
            printf("  Ultimo Nome: %s\n", a[i].ULTIMO_NOME);
            printf("  Endereco: %s\n", a[i].ENDERECO);
            printf("  Telefone Convencional: %s\n", a[i].TEL_CONV);
            printf("  Telefone Celular: %s\n", a[i].TEL_CEL);
            printf("  Telefone Comercial: %s\n", a[i].TEL_COM);
            printf("  Data de Aniversario: %s\n", a[i].DATA_ANIVERSARIO);
            printf("  Email: %s\n", a[i].EMAIL);
        } else {
            puts("Nenhum contato com o nome Ana.");
            return;
        }
    }
}

int main() {
    agenda *a = NULL;
    int count = 0;

    inicializarAgenda(&a, &count);

    if (count > 0) {
        imprimirAgendaAna(a, count);
    } else {
        puts("Nenhum contato adicionado!");
    }

    free(a);

    return 0;
}