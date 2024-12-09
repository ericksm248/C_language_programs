#include <stdio.h>
#include <stdint.h>

typedef struct 
{
	uint8_t data1;
	uint8_t data2;
	char *put;
}data_struc;

char info[11]="es otro sms";

int main(void)
{
	data_struc mi_struc ={4,8,"hola mundo"};
	data_struc struc_2 = {1,100,"sms nuevo"};
	printf("struct %d\n",mi_struc.data2);
	printf("struct puntero: %s\n",mi_struc.put);
	mi_struc.put = info;
	printf("struct puntero cambiado: %s\n",mi_struc.put);
	printf("otro struct puntero: %s\n",struc_2.put);
	return 0;
}
