#include <stdio.h>
#include <stdint.h>
int main(){

    uint8_t *d;
	const uint8_t data=8;
	uint8_t aux = 30;
	//d=&data;//si el puntero apunta a una variable, no se puede apuntar a una constante
	aux= 50;
	//*d = 3; //si el puntero apunta a un valor constante, no se puede modificar este valor
	d=&aux; 
	//data=30;
	printf("valor = %d\n",*d);
	//if para cualquier valor diferente de cero es verdadero
	if(545)
	printf("paso el if");
	
	
	const int * pp=NULL; // asi se define un puntero de solo lectura
	int dato2 = 10;
	int dato3 = 2;
	const int dato4 = 8;
	pp = &dato2;
	dato2 = 80;
	//*pp = 400;  //puntero constante, de solo lectura, no puede modificar el valor apuntado
	printf("\npuntero solo lectura dato2: %d",*pp);
	pp= &dato3;
	dato3 = 1200;
	printf("\npuntero solo lectura dato3: %d",*pp);
	pp = &dato4;  //se puede apuntar a una variable de tipo constante
	//dato4 = 40; //la variable no se puede modificar
	printf("\npuntero solo lectura dato4 variable de tipo constante: %d",*pp);
	return 0;
}



	//dato PUNTERO DE SOLO LECTURA
	/*
	Tambi�n puede haber punteros de solo lectura que hacen referencia a variables modificables.

int x = 7;
const int *p = &x;

printf("%d\n", *p); // V�lido

int y = -1;

p = &y; // V�lido

printf("%d\n", *p);

*p = 2; // Inv�lido
*/
