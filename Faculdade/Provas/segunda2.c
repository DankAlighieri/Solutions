/*
	Escreva uma função recursiva para inverter uma string. 
	Escreva um programa que chama esta função e imprima os citados valores.
*/
#include<stdio.h>
#include<string.h>

#define N 10

char V[] = "12345678910";

void inverter(char *V) {
	if(*V) {
		inverter(V + 1);
		printf("%c", *V);
	}

}

int main(){
	inverter(V);
	
	return 0;
}