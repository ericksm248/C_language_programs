#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define CANTIDAD 10


void imprimir_arreglo(uint8_t *p,uint8_t cantidad)
{
	int i = 0;
	for(i=0;i<cantidad;i++)
	{
		printf("%d, ",p[i]);
	}
}

int main(void)
{
	uint8_t *mi_p,*var_p; 
	uint8_t *aux;
	uint8_t data_aux = 20;
	mi_p = malloc(CANTIDAD);
	assert(data_aux>0);
	mi_p[2]= 10;
	printf("\n\rmalloc arreglo:  ");
	imprimir_arreglo(mi_p,CANTIDAD);
	var_p = calloc(CANTIDAD,1);
	var_p[4]=255;
	printf("\n\rcalloc arreglo:  ");
	imprimir_arreglo(var_p,CANTIDAD);
	aux = realloc(var_p,CANTIDAD-4);
	printf("\n\rrealloc arreglo: ");
	imprimir_arreglo(aux,CANTIDAD-4);

	free(var_p);
	free(mi_p);
	//free(aux);
	return 0;
}
