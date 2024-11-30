#include <stdint.h>
#include <stdio.h>
#include <math.h>

void obtiene_significativos(int data);

int main()
{
	int d = 0;
	printf("ingrese un numero: ");
	scanf("%d",&d);
	obtiene_significativos(d);
	return 0;
}

void obtiene_significativos(int data)
{
	int aux = data;
	int new_data = 0;
	do
	{
		new_data = aux%10;
		aux = aux/10;
		if(new_data>0)
			printf("%d",new_data);
	}
	while(aux>0);
}
