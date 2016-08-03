#include <stdio.h>
#include <math.h>

void gerar_quadrados(int quadrados[], int termos){
	int i;
	
	for(i = 0; i < termos; i++){
		quadrados[i] = pow((i + 1), 2); 
	}
}

int main(){

	int n = 0;
	
	do{
		printf("\nDigite o número de termos: ");
		scanf("%d", &n);

		if(n < 0)
			printf("\nO número de termos deve ser positivo.");
	} while(n < 0);

	int quadrados[n];

	gerar_quadrados(quadrados, n);

	int i;
	for(i = 0; i < n; i++){
		printf("\nO quadrado de %d é: %d\n", (i + 1), quadrados[i]);	
	}	
}
