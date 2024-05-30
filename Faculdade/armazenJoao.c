#include <stdio.h>
#define tam 5

int main(){
    int vetor[tam][tam],armazem,produto,quantidade=0,maior,auxiliar=0;

    for(armazem=0; armazem<tam; armazem++){
        quantidade=0;//zero o acumulador para pegar a proxima quantidade
        for(produto=0;produto<tam;produto++){
            scanf("%d", &vetor[armazem][produto]);//populando a matriz
            quantidade+=vetor[armazem][produto];//acumulando a quantidade na linha
        }
        printf("armazem[%d] = %d\n",armazem+1, quantidade);//apresentando a quantidade da linha
    }

    for(maior=vetor[0][1], armazem = 0;armazem<tam;armazem++){
        if(vetor[armazem+1][1]>maior){
            maior=vetor[armazem][1];
            auxiliar=armazem; 
        }
    }
        printf("armazem[%d] tem mais do produto 2 = %d\n",auxiliar+1, maior);
        quantidade=0;
}