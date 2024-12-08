#include <stdio.h>
#include <string.h>

/* TYPEDEF */
typedef int (*funcion_callback)(char*, int);

int llamada(char *cadena, int numero)
{
  return (strlen(cadena)+numero);
}

/* DECLARACIÓN DE LLAMADORA */
void llamadora(funcion_callback func)
{
  int num;
  printf("Voy a llamar a una funcion con el texto HOLA y el numero 20\n");
  num=func("hola", 20);
  printf("La he llamado y me ha devuelto: %d\n", num);
}

int main()
{
  llamadora(llamada);
}
