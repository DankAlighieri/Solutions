#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 2
#define tam 40

typedef struct {
	char NOME[tam];
	int IDADE, MATRICULA;
	float NOTA_FINAL;
} ALUNO;

// inicializar
void inicializarAluno(ALUNO *aluno){
	int i;
	for (i = 0; i < n; i++){
		printf("Digite o nome do(a) %d aluno(a): ", i+1);
		setbuf(stdin, NULL);
		fgets(aluno[i].NOME, tam, stdin);
		aluno[i].NOME[strcspn(aluno[i].NOME, "\n")] = '\0';
		
		printf("Digite a idade do(a) %d aluno(a): ", i+1);
		scanf("%d", &aluno[i].IDADE);
		
		printf("Digite o numero de matricula do(a) %d aluno(a): ", i+1);
		scanf("%d", &aluno[i].MATRICULA);
		
		printf("Digite a nota final do(a) %d aluno(a): ", i+1);
		scanf("%f", &aluno[i].NOTA_FINAL);
	}
}

// a média das notas
float mediaAlunos(ALUNO *a) {
	int i;
	float soma = 0.0;
	for (i = 0; i < n; i++) {
		soma += a[i].NOTA_FINAL;
	}
	return soma/n;
}

int indiceDaMenorNota(ALUNO *a) {
	float menorNota = a[0].NOTA_FINAL;
	int i, j = 0;
	for(i = 1; i < n; i++) {
		if(menorNota > a[i].NOTA_FINAL) {
			j = i;
			menorNota = a[i].NOTA_FINAL;
		}
	}
	return j;
}

int indiceDaMaiorNota(ALUNO *a) {
	float maiorNota = a[0].NOTA_FINAL;
	int i, j = 0;
	for(i = 1; i < n; i++) {
		if(a[i].NOTA_FINAL > maiorNota) {
			j = i;
			maiorNota = a[i].NOTA_FINAL;
		}
	}
	return j;
}

int main() {
	ALUNO *aluno = NULL;
	int count, indiceMenor, indiceMaior;
	float media;
	count = n;
	
	aluno = (ALUNO *) realloc(aluno, n*sizeof(ALUNO));
	if(!aluno) {
		puts("Erro de memoria!");
		exit(1);
	}
	
	inicializarAluno(aluno);

	printf("A media eh igual a = %.1f\n", mediaAlunos(aluno));
	
	indiceMenor = indiceDaMenorNota(aluno);
	printf("Aluno com menor nota: %s\n", aluno[indiceMenor].NOME);
	
	indiceMaior = indiceDaMaiorNota(aluno);
	printf("Aluno com menor nota: %s\n", aluno[indiceMaior].NOME);
	
	return 0;
}