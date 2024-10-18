#include <stdio.h>
#include <string.h>
#define tam 1

typedef struct {
	char nome[100];
	char nascimento[14];
	unsigned long int n_mat;
	char cpf[13];
	float CRE;
} registroAluno;

void inicializarVetor(registroAluno *v) {
	int i;
	for(i = 0; i < tam; i++) {
		printf("\nEntre com as informacoes do %d registro", i+1);
		printf("\nNome: ");
		setbuf(stdin, NULL);
		scanf("%99[^\n]", v[i].nome);
		printf("\nData de nascimento: ");
		setbuf(stdin, NULL);
		scanf("%13[^\n]", v[i].nascimento);
		printf("\nNumero de matricula: ");
		scanf("%ld", &v[i].n_mat);
		printf("\nCpf: ");
		setbuf(stdin, NULL);
		scanf("%12[^\n]", v[i].cpf);
		printf("\nCRE: ");
		scanf("%f", &v[i].CRE);
	}
}

void imprimirRegistroCPF(registroAluno *v, char *cpf) {
	unsigned int i;
	for (i = 0; i < tam; i++) {
		if(!strcmp(v[i].cpf, cpf)){
			printf("\nRegistro com cpf n° %s\n", cpf);
			printf("%s\n", v[i].nome);
			printf("%s\n", v[i].nascimento);
			printf("%s\n", v[i].cpf);
			printf("%.2f\n", v[i].CRE);
		}
	}
}

void imprimirRegistroInd(registroAluno *v, unsigned int i) {

	printf("\nRegistro do indice n° %d\n", i);

	printf("%s\n", v[i-1].nome);
	printf("%s\n", v[i-1].nascimento);
	printf("%s\n", v[i-1].cpf);
	printf("%.2f\n", v[i-1].CRE);
}

int main() {
	registroAluno vetor[tam];
	int i;
	char cpf[13];

	inicializarVetor(vetor);
	
	printf("\nInsira o cpf sem pontos ou hifen\n");
	scanf("%s", cpf);
	imprimirRegistroCPF(vetor, cpf);

	printf("\nInsira o indice\n");
	scanf("%d", &i);
	imprimirRegistroInd(vetor, i);
	
	return 0;
}