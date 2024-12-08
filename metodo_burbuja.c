#include <stdio.h>
#define tamano 10 

int main (void) 
{ 
  int vNumeros[tamano]; 
  int j, i, temp; 

  

  printf ("Introduce los %d números a ordenar:\n", tamano); 
  
  /* Obtenemos los 10 números y los guardamos en vNumeros */
  for (i = 0; i < tamano; i++) 
  { 
    printf ("%d: ", i + 1); 
    scanf ("%d", &vNumeros[i]); 
    printf ("\n"); 
  } 
  
  /* Ordenamos los números del vector vNumeros por el método de burbuja */
  for (i = 0; i < (tamano - 1); i++) 
  { 
    for (j = i + 1; j < tamano; j++) 
    { 
      if (vNumeros[j] < vNumeros[i]) 
      { 
        temp = vNumeros[j]; 
        vNumeros[j] = vNumeros[i]; 
        vNumeros[i] = temp; 
      } 
    } 
  } 
  
  /* Mostramos los números ordenados */
  printf ("Los números ordenados son:\n"); 
  for (i = 0; i < tamano; i++) 
  { 
    printf("%d, ", vNumeros[i]); 
  } 
  printf("\n\n\n");  
  return 0;
}
