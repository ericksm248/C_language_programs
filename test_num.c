#include <stdio.h>
#include <stdint.h>
   
int main()
{
   uint16_t numero = 1640;
   uint8_t millares = 0;//numero/100;
   uint8_t centenas = 0;
   uint8_t decenas = 0;
   uint8_t unidades = 0;
   if(numero>999)
   {
      millares = (uint8_t)(numero/1000);
   }

   if(numero>99)
   {
      centenas = (uint8_t)((numero-(millares*1000))/100);

   }

   if(numero>9)
   {
      decenas = (uint8_t)((numero- (millares*1000 + centenas*100))/10);

   }

    unidades=(uint8_t)(numero-(millares*1000 + centenas*100 + decenas*10 ));
   
    printf("millares = %d, centenas = %d, decenas = %d, unidades = %d",millares,centenas,decenas,unidades);
}
