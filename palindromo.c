#include <stdint.h>
#include <string.h>
#include <stdio.h>

void ingreso(char *ptr, int* cant)
{
	printf("ingrese la palabra: ");
	scanf("%s",ptr);getchar();
	*cant=strlen(ptr);
	return;
}
void palindromo(char*ptr,int* cant)
{
	int pal=0,i;
	int test = *cant/2;
	for(i=0;i<test;i++)
	{
		if(ptr[i]==ptr[*cant-1-i])
		{
			pal++;
		}
	}
	if(pal!=test)
	{
		printf("No es palindromo");	
	}
	else printf("Si es palindromo");
	return;
}

int main(void)
{
	char palabra[30];
	int cant=0;
	ingreso(palabra,&cant);
	palindromo(palabra,&cant);
	return 0;
}
