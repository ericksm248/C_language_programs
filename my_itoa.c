#include <stdio.h>
#include <stdint.h>

uint8_t my_itoa(int16_t n, uint8_t s[])
{
   uint8_t i,c,j,tamano,ind;
   i = 0;
   ind = 0;
   if(n<0)
   {
   		n*=-1;
   		s[i++] = '-';
   		ind = 1;
   }

   do
   {
     s[i++] = n % 10 + '0';
   }
   while ((n /= 10) >= 1);

   tamano = i;
   //s[i] = '\0';

    for (i = ind, j = tamano-1; i < j; i++ , j--)
   {
     c = s[i];
     s[i] = s[j];
     s[j] = c;
   }
   s[tamano]=0; //final de cadena para evitar fallas con el dato volada
   return tamano;
}

int main(void)
{
    uint8_t my_data[10];
    my_itoa(-145,my_data);
    printf("mi cadena es: %s",my_data);//funcion con numeros positivos y negativos
    return 0;
}
