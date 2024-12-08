#include <stdio.h>
#include <stdlib.h>

int main()
{
	char caracter;
	FILE *flujo = fopen("datos.xlsx","rb");
	while(feof(flujo)==0)
	{
		caracter = fgetc(flujo);
		printf("%c",caracter);
	}
	fclose(flujo);
	printf("\nSe ha leido el archivo correctamente\r");
	return 0;
}
