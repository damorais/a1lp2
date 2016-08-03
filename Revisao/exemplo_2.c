#include <stdio.h>
#include <math.h>
#include <limits.h>

//Utilizando unsigned int porque a soma do quadrado dos termos nunca será positiva
//Considerando que estamos apenas utilizando números positivos
unsigned int soma_quadrados(unsigned int n){

	unsigned int soma = 0, i = 0;

	for(i = 0; i < n; i++){
		soma += pow(i + 1, 2);
	}
	
	return soma;
}


int main(){
	int n = 0, resultado = 0;
	
	do{
		printf("\nDigite o número de termos: ");
		scanf("%d", &n);

		if(n < 0)
			printf("\nO número de termos deve ser positivo.");
	} while(n < 0);

	printf("\nA soma dos quadrados dos %d termos é: %d\n", n, soma_quadrados(n));	
}

