#include <stdio.h>
#include <math.h>

#define IMC_MIN_NORMAL 18.5
#define IMC_MIN_ACIMA 24.5

float calcula_imc(float peso, float altura){
	return peso / pow(altura, 2);
}

int main(){
	
	float peso, altura, imc;
	printf("\nQual o seu peso e altura?\n");
	scanf("%f %f", &peso, &altura);

	imc = calcula_imc(peso, altura);

	printf("\nSeu I.M.C é %.1f", imc);

	if(imc < IMC_MIN_NORMAL)
		printf("\nVocê está abaixo do peso.\n");
	else if(imc >= IMC_MIN_NORMAL && imc < IMC_MIN_ACIMA)
		printf("\nSeu peso é normal.\n");
	else
		printf("\nVocê está acima do peso.\n");

	getchar();
}
