#include <stdio.h>
//1. A partir de n = 13, o resultado retornado é incorreto. Por que?
//(deveria ser 6.227.020.800
//2. O cálculo do fatorial foi feito de forma recursiva
int fatorial(int n){
	return n > 1 ? n  * fatorial(n - 1) : 1;
}


int main(){
	int n = 0, resultado = 0;
	
	while(n <= 0){
		printf("\nDigite o número de termos: ");
		scanf("%d", &n);

		if(n <= 0)
			printf("\nO número de termos deve ser positivo e maior que zero.");
	}

	printf("\nO valor do fatorial de %d é: %d\n", n, fatorial(n));	
}
