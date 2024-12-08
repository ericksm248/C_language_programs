#include <stdio.h>
#include <stdlib.h>
// Definicion del numero de elementos maximos del vector
#define MAX 10
int main(void)
{
    // Variables a utilizar por el programa
    int numeros[MAX];
    int contador=0;
    int auxiliar[MAX];
    int posicion=0;
    int numero=0;
    int contador2=0;
    int mayor=0;
    int posicionmayor=0;
    int bandera=0;
    float suma=0;
    // Solicitar los numeros para rellenar el vector
    for(contador=0;contador<MAX;contador++) {
        printf("No. %d : ",contador+1);
        scanf(" %d",&numeros[contador]);
    }
    // Visualizar los elementos introducidos en el vector
    printf("\nElementos del vector : ");
    for(contador=0;contador<MAX;contador++) {
        printf(" %d",numeros[contador]);
    }
    // Calcular la moda
    // Rellenamos el vector auxiliar inicializandolo a valores 0
    for(contador=0;contador<MAX;contador++) {
        auxiliar[contador]=0;
    }
    // Recorrer el vector comprobando las repeticiones de cada numero
    // y almacenando las mismas en el vector auxiliar segun la posicion
    // del numero
    for(contador=0;contador<MAX;contador++) {
        numero = numeros[contador];
        posicion = contador;
        for(contador2=contador;contador2<MAX;contador2++) {
            if(numeros[contador2]==numero) auxiliar[posicion]++;
        }
    }
    // Una vez establecidas las repeticiones de cada numero se ha de establcer
    // cual es la posicion del vector que tiene un numero de repeticiones mayor
    // ya que esta es la posicion que se corresponde con el numero que se repite
    // mas veces el vector ( MODA )
    // se establece en primer lugar el mayor como el primer elemento del vector
    mayor=auxiliar[0];
    posicionmayor = 0;
    for(contador=0;contador<MAX;contador++) {
        if(auxiliar[contador]>mayor) {
            posicionmayor=contador;
            mayor=auxiliar[contador];
        }
    }
    // Visualizar el elemento con mas frecuencia de aparicion
    printf("\nMODA : %d",numeros[posicionmayor]);
     return 0;
}
