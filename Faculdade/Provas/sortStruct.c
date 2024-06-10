#include <stdio.h>

#define tam 30

typedef struct {
    char ID;
    char NOME[tam];
    int IDADE;
} jogador;

int main() {
    jogador temp;
    int i, j;

    jogador jogadores[] = {
        {'C', "Guilherme", 22},
        {'A', "Luis", 30},
        {'B', "Pedro", 10}
    };

    puts("--- VETOR NAO ORGANIZADO ---");
    for (i = 0; i < 3; i++) {
        printf("--- %d JOGADOR ---\n", i+1);
        printf("ID: %c; Nome: %s; Idade: %d\n", jogadores[i].ID, jogadores[i].NOME, jogadores[i].IDADE);
    }

    for (i = 0; i < 3 - 1; i++) {
        if (jogadores[i].ID > jogadores[i+1].ID) {
            temp = jogadores[i];
            jogadores[i] = jogadores[i+1];
            jogadores[i+1] = temp;
        }
    }

    puts("--- VETOR ORGANIZADO ---");
    for (i = 0; i < 3; i++) {
        printf("--- %d JOGADOR ---\n", i+1);
        printf("ID: %c; Nome: %s; Idade: %d\n", jogadores[i].ID, jogadores[i].NOME, jogadores[i].IDADE);
    }

    return 0;
}