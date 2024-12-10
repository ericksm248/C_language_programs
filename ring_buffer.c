#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//TIPO DE CONTROL DE MEMORIA  ---- FIFO ------
#define BUFFER_TAM 5
uint8_t buffer_circular[BUFFER_TAM];
uint8_t indice_lectura_buffCircular = 0;
uint8_t indice_escritura_buffCircular = 0;
uint8_t counter_buffer_circular = 0;//verificar si tiene datos el buffer, es necesario? SI

void push_data(uint8_t data)
{
	if(counter_buffer_circular==BUFFER_TAM)
	{
		//printf("buffer lleno\n");
		return;
	}
	buffer_circular[indice_escritura_buffCircular]=data;
	counter_buffer_circular++; //incrementa la cantidad de datos que tiene el buffer
	indice_escritura_buffCircular++; //incrementa el indice de escritura
	if(indice_escritura_buffCircular==BUFFER_TAM)
	{
		indice_escritura_buffCircular = 0;
	}
}

uint8_t get_data(void)
{
	uint8_t aux = 0;
	if(counter_buffer_circular==0)
	{
		//no deberia llegar aqui 
		//antes de extraer datos , primero se debe verificar que el buffer tenga datos
		return 0; 
	}
	counter_buffer_circular--;
	aux = buffer_circular[indice_lectura_buffCircular];
	buffer_circular[indice_lectura_buffCircular] = 0;
	indice_lectura_buffCircular++;
	if(indice_lectura_buffCircular==BUFFER_TAM)
	{
		indice_lectura_buffCircular = 0;
	}
	return aux;
}

bool check_buffer_circular(void)
{
	if (counter_buffer_circular>0)
		return true;
	else
		return false;
}


int main(void)
{
	uint8_t i = 0;
	uint8_t opcion = 0;
	uint8_t valor1 = 0;
	printf("========================== RING BUFFER ===========================\n");
	printf("el buffer circular puede almacenar %d datos, se puede modificar el tamano cambiando el valor de BUFFER_TAM\n",BUFFER_TAM);
	printf("no esta permitido la sobreescritura\n");
	while(1)
	{
		printf("Ingresa una opcion: \n");
		printf("1.ingresar dato \n");
		printf("2.extraer dato\n");
		printf("3 mostrar datos\n");
		printf("4 finalizar\n");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				if(counter_buffer_circular==BUFFER_TAM)
				{
					printf("buffer lleno\n");
					break;
				}
				printf("ingresa un dato: ");
				scanf("%d",&valor1);
				push_data(valor1);				
				break;
			case 2:
				if(check_buffer_circular())
					{
						valor1 = get_data();
						printf("el dato extraido es: %d\n",valor1);
					}
				else
					printf("buffer vacio\n");
				break;
			case 3:
				printf("cantidad buffer: %d / indice actual de escritura: %d / indice actual de lectura: %d\n",counter_buffer_circular,indice_escritura_buffCircular,indice_lectura_buffCircular);
				for(i=0;i<BUFFER_TAM;i++)
				{
					printf("val[%d] = %d\n",i,buffer_circular[i]);
				}
				break;
			case 4:
				printf("programa finalizado\n");
				return 0;
			default:
				printf("opcion incorrecta\n");
					
		}
	}
	return 0;
}
