#include <stdio.h>
#include <stdint.h>

void cambiar_variables(int *x , int *y);

int main(void)
{
	int x =10, y;
	//scanf("%d",&x);
	printf("Ingresa x: ");
	scanf("%d",&x);
	printf("Ingresa y: ");
	scanf("%d",&y);
	cambiar_variables(&x,&y);
	printf("x = %d \n\ry = %d",x,y);
	return 0;
}

void cambiar_variables(int *x , int *y)
{
	int aux = 0;
	aux = *x;
	*x = *y;
	*y = aux;
}
