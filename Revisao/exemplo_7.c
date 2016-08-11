#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *append_to, char *text_to_append);
char *concat(char *str1, char *str2);

int main(){

	//Aqui eu faço a alocação dinâmica dos meus vetores de caracteres
	//Faço isso porque, para conseguir fazer realozação de memória, o ponteiro
	//deve ter recebido alocação dinâmica
	char *texto_original = malloc(31 * sizeof(char));
	char *texto_acrescentado = malloc(31 * sizeof(char));
	
	printf("\nDigite a primeira string (máximo de 30 caracteres): \n");

	//esta função substitui o scanf. Com scanf, se você ultrapassa o tamanho especificado,
	//ocorem problemas na aplicação. O fgets "corta" a entrada na quantidade de caracteres
	//especificada. Os parâmetros são: ponteiro de destino, tamanho, dispositivo de entrada
	fgets(texto_original, 31, stdin);
	
	//O fgets considera a entrada da quebra de linha (enter) Então, caso identifique uma
	//quebra de linha (caracter \n) na string, eu a substituo pelo terminador de string (\0) 
	char *pos;
	if((pos=strchr(texto_original, '\n')) != NULL)
		*pos = '\0';
	
	printf("\nDigite a segunda string (máximo de 30 caracteres): \n");
	fgets(texto_acrescentado, 31, stdin);
	
	if((pos=strchr(texto_acrescentado, '\n')) != NULL)
		*pos = '\0';
		
	char *resultado = concat(texto_original, texto_acrescentado);
	printf("\nTexto por concatenação: %s\n", resultado);

	append(texto_original, texto_acrescentado);

	printf("\nTexto por append: %s\n", texto_original);
}

void append(char *append_to, char *text_to_append){
	int tamanho_original;
	int tamanho_acrescentar;
	
	//Descubro o tamanho de append_to
	for(tamanho_original=0; append_to[tamanho_original] != '\0'; tamanho_original++){}
	//Descubro o tamanho de text_to_append
	for(tamanho_acrescentar=0; text_to_append[tamanho_acrescentar] != '\0'; tamanho_acrescentar++){}

	//Calculo o tamanho que vou precisar, com a junção
	int tamanho_total = (tamanho_original - 1) + tamanho_acrescentar;

	//"Aumento" o tamanho em memória disponível para append_to
	append_to = realloc(append_to, tamanho_total * sizeof(char));

	int indice_acrescentar;
	int indice_original = tamanho_original;

	//Preciso apenas acrescentar a informação. No que já existe na string, não mexo.
	//Ou seja, começo a acrescentar o conteúdo de text_to_append apenas depois da última
	//posição ocupada em append_to
	for(indice_acrescentar = 0; indice_acrescentar <= tamanho_acrescentar; indice_acrescentar++){
		append_to[indice_original] = text_to_append[indice_acrescentar];
		indice_original++;
	}
}

char *concat(char *str1, char *str2){
	int tamanho_original;
	int tamanho_acrescentar;

	char *resultado;
	
	//Descubro o tamanho de str1
	for(tamanho_original=0; str1[tamanho_original] != '\0'; tamanho_original++){}
	//Descubro o tamanho de str2
	for(tamanho_acrescentar=0; str2[tamanho_acrescentar] != '\0'; tamanho_acrescentar++){}

	//Calculo qual será o tamanho da junção. Note que desconto um caracter, uma vez que o tamanho
	//conta também o caractere \0
	int tamanho_total = (tamanho_original - 1) + tamanho_acrescentar;

	//Aloco memória usando o tamanho total calculado
	resultado = malloc(tamanho_total * sizeof(char));

	int i_resultado = 0;
	int i_str1;
	int i_str2;

	//Copio o conteúdo de str1 para resultado
	for(i_str1 = 0; i_str1 < tamanho_original; i_str1++){
		resultado[i_resultado] = str1[i_str1];
		i_resultado++;
	}

	//Copio o conteúdo de str2 para resultado, a partir do ponto onde parei na cópia de str1
	for(i_str2 = 0; i_str2 <= tamanho_acrescentar; i_str2++){
		resultado[i_resultado] = str2[i_str2];
		i_resultado++;
	}

	return resultado;
}
