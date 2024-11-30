#include <stdio.h>
#include <stdint.h>
#include <string.h>
uint8_t comparar_cadenas(const uint8_t data1[],const uint8_t data2[],uint8_t cantidad);

uint8_t comparar_cadenas(const uint8_t data1[],const uint8_t data2[],uint8_t cantidad)
{
	uint8_t size_arr,i = 0;
	size_arr = cantidad;
	uint8_t aux1 = strlen(data1);
	uint8_t aux2 = strlen(data2);
	printf("tam: 1 (%d) 2 (%d)\n",aux1,aux2);
	//las cadenas deben ser igual o de mayor tamano de la cantidad de bytes a comparar
	if(cantidad==0 || cantidad>aux1 || cantidad>aux2) return 0;
	for(i=0;i<size_arr;i++)
	{
		if(data1[i]!=data2[i])
		{
			return 0;
		}
//		if(data1[i]==0||data2[i]==0)//se acaba el arreglo de uno de ellos
//		{
//			return 0;
//		}
		printf("comparacion %d\n",i+1);
	}
	return 1;
}

int main(void)
{
	uint8_t arreglo[20]="hola22";
	if(comparar_cadenas(arreglo,"hola22asdasdasd",4)==1)
	{
		printf("paso el if");
	}
	else 
	{
		printf("no paso el if");
	}
	return 0;
}
