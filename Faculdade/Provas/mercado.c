#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define tam 30

typedef struct{
    char NOME[tam];
    float VALOR;
    char MEDIDA[tam];
    char TIPO[tam];
} PRODUTO;

typedef struct {
    char NOME[tam];
    int QUANT;
} PRODUTO_CARRINHO;

void cadastro(PRODUTO **p, int *count);
void consulta(PRODUTO *p, int count);
void carrinho(PRODUTO *p, int count);

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int menu() {
    int op2;
    do {
        printf("Qual operacao deseja realizar?\n");
        printf("\t1 - Cadastro;\n");
        printf("\t2 - Consulta;\n");
        printf("\t3 - Carrinho;\n");
        printf("\t4 - Sair;\n");
        scanf("%d", &op2);
        clearInputBuffer();
    } while (op2 > 4 || op2 < 1);

    return op2;
}

int main () {
    PRODUTO *produto=NULL;
    int op1, op2, count = 0;
    do {
        printf("\nBem vindo ao mercado KU!\n"); 
        puts("Deseja realizar alguma operacao?");
        printf("Digite 1 para sim, 2 para nao: ");
        scanf("%d", &op1);
        clearInputBuffer();
        if (op1 == 1) {

            op2 = menu();

            switch (op2) {
                case 1:
                    cadastro(&produto, &count);
                    break;
                case 2:
                    if (!produto) {
                        puts("Mercado vazio!");
                        break;
                    }
                    consulta(produto, count);
                    break;
                case 3:
                    carrinho(produto, count);
                    break;
                case 4:
                    return 0;
            }
        } else return 0;

    } while (op1);

    free(produto);

    return 0;
}

// FUNCAO DE CADASTRO
void cadastro(PRODUTO **p, int *count) {
    int op3;
    while (1) {

        *count+=1;

        (*p) = (PRODUTO *) realloc(*p, (*count)*sizeof(PRODUTO));

        if (!(*p)) {
            puts("--- ERRO DE MEMORIA ---");
            exit(1);
        }

        printf("\nDigite o nome do produto: ");       
        fgets((*p)[*count-1].NOME, tam, stdin);
        (*p)[*count-1].NOME[strcspn((*p)[*count-1].NOME, "\n")] = '\0';
        
        printf("Digite o valor do produto (Apenas numeros): ");
        scanf("%f", &(*p)[*count-1].VALOR);
        clearInputBuffer();
        
        printf("Digite a medida do produto (Kg ou L): ");
        fgets((*p)[*count-1].MEDIDA, tam, stdin);
        (*p)[*count-1].MEDIDA[strcspn((*p)[*count-1].MEDIDA, "\n")] = '\0';
        
        printf("Digite o tipo do produto (Comida/Bebida): ");
        fgets((*p)[*count-1].TIPO, tam, stdin);
        (*p)[*count-1].TIPO[strcspn((*p)[*count-1].TIPO, "\n")] = '\0';

        puts("Deseja cadastrar outro produto?\n");
        printf("\t 1 - Sim\n");
        printf("\t 2 - Nao\n");
        scanf("%d", &op3);
        clearInputBuffer();

        if (op3 != 1) break;
    }
    
}

// FUNCAO CONSULTA
void consulta(PRODUTO *p, int count) {
    while (1) {
        int i, encontrado = 0;
        char categoria[tam], nomeProd[tam], op4;
        printf("--- LISTA DE PRODUTOS DO MERCADO ---\n");
        for (i = 0; i < count; i++) {
            printf("%d - Nome do produto: %s\n", i+1 ,strupr(p[i].NOME));
        }

        printf("\nDigite a categoria do produto (Bebida, comida): ");
        fgets(categoria, tam, stdin);
        categoria[strcspn(categoria, "\n")] = '\0';
        printf("Digite o nome do produto: ");
        fgets(nomeProd, tam, stdin);
        nomeProd[strcspn(nomeProd, "\n")] = '\0';


        for (i = 0; i < count; i++) {
            if (!strcmp(strlwr(nomeProd), strlwr(p[i].NOME))) {
                printf("%s: R$%.2f por 1%s\n", strupr(nomeProd), p[i].VALOR, strupr(p[i].MEDIDA));
                encontrado++;
            }
        }
        if (!encontrado) {
            puts("Produto nao encontrado!");
        }

        puts("Deseja consultar novamente? (s/n)");
        //clearInputBuffer();
        scanf("%c", &op4);

        if (op4 != 's' && op4 != 'S') break;
        clearInputBuffer();
    }
}

void carrinho(PRODUTO *p, int count) {
    PRODUTO_CARRINHO *prod_carr = NULL;
    int quant, count1 = 0, i, desconto, j;
    float soma = 0.0, valorDesconto;
    char entrada[tam], quantC[tam], *nome, c = ' ';
    
    printf("O MERCADAO KU esta com uma promocao imperdivel!\nNa compra de 3 bebidas voce recebe 10%% de desconto em toda a sua compra.\n");

    printf("Digite um produto e a quantidade que deseja comprar (Caso deseje sair insira \"0\"): \n");
    puts("(x produto)");

    do {
        fgets(entrada, tam, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        if (strcmp(entrada, "0")) {

            count1++;
            prod_carr = (PRODUTO_CARRINHO *) realloc(prod_carr, count1*sizeof(PRODUTO_CARRINHO));

            if (!prod_carr) {
                puts("--- ERRO DE MEMORIA! ---");
                exit(1);
            }
            
            // encontrando a quantidade
            for (i = 0; entrada[i]; i++) {
                if (entrada[i]> 47 && entrada[i] < 58) {
                    strcpy(&quantC[i], &entrada[i]);
                }
            }

            quant = atoi(quantC);

            // encontrando o nome do produto
            nome = strchr(entrada, c);
            if (!nome) {
                puts("Erro de conversao!");
                exit(1);
            } else nome++;

            // atribuindo ao vetor de produtos no carrinho
            prod_carr[count1 - 1].QUANT = quant;
            strcpy(prod_carr[count1 - 1].NOME, nome);
        } else break;
    } while (1);

    for (i = 0; i < count; i++) {
        for (j = 0; j < count1; j++) {
            // verificando se os produtos existem no estoque e somando seus valores, caso existam
            if (!strcmp(strlwr(prod_carr[j].NOME), strlwr(p[i].NOME))) {
                printf("%s encontrado!\n", prod_carr[i].NOME);
                soma += (p[i].VALOR * prod_carr[i].QUANT);
                printf("Valor parcial = %.2f\n", soma);
                if (!strcmp("L", strupr(p[i].TIPO)) 
                    && prod_carr[i].QUANT > 3) {
                    desconto++;
                }
            }
        }
    }

    puts("--- VALOR DA COMPRA ---");
    printf("Total = R$%.2f\n", soma);
    if (desconto) {
        valorDesconto = soma/10.0;
        puts("--- DESCONTO APLICADO ---");
        printf("Total apos desconto = R$%.2f\n", soma-valorDesconto);
    }

    free(prod_carr);
}