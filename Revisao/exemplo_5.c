#include <stdio.h>

void swap(int *x, int *y);

int main(){

	int x = 10;
	int y = 30;

	printf("\nX é: %i", x);
	printf("\nY é: %i", y);
	
	swap(&x, &y);

	printf("\nX agora é: %i", x);
	printf("\nY agora é: %i", y);
	printf("\n");

}

void swap(int *x, int *y){
	int temp = *x;

	*x = *y;
	*y = temp;
}
