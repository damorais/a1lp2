#include <stdio.h>
#include <stdlib.h>

char *strcopy(char *str);

int main(){

	char *original = "Isto é um teste";

	char *copia = strcopy(original);

	printf("\nString original: %s", original);
	printf("\nEndereço de memória da string original: %p", original);
	printf("\nString copiada: %s", copia);
	printf("\nEndereço de memória da string copiada: %p", copia);
	printf("\n");
}

char *strcopy(char *str){
	int n, i;

	char *novastr;

	for(n=0; str[n] != '\0'; n++){}

	novastr = malloc(n * sizeof(char));

	for(i = 0; i <= n; i++)
		novastr[i] = str[i];

	return novastr;
}
