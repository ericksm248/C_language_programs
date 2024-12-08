#include <stdio.h>
#include <stdint.h>

//se crea el puntero a funcion
void (*my_puntero_a_funcion)(void);

void suma()
{
	printf("funcion suma");
}

void resta()
{
	printf("funcion resta");
}

//funcion que indica a donde apuntar a mi puntero a funcion
void escojer_funcion(void (*my_funcion)(void))
{
	my_puntero_a_funcion = my_funcion;
}

int main()
{
	uint8_t a = 0;
	escojer_funcion(suma);
	my_puntero_a_funcion();
	return 0;
}
