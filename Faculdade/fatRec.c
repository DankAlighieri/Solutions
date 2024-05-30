/*
    Faça agora uma função recursiva para calcular o fatorial 
    de um número natural e construa um programa que se utilize 
    de forma adequada da função em questão.
*/

int fatRec(int a) {
    if (a == 0) {
      return 1;  
    } 
    a *= fatRec(a - 1);
    return a;
} 