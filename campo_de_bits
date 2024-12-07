#include <stdio.h>
#include <stdint.h>

#define led1

typedef union {
    struct {
       uint8_t a:2;//LSB
       uint8_t b:1;
       uint8_t c:3;
       uint8_t d:1;
       uint8_t e:1;//MSB
    };
    uint8_t data;
} union_bit; 

int main()
{
	union_bit my_port,prueba ;
	my_port.data = 0;
	my_port.c = 2;
	my_port.e = 1;
	prueba.data = 0;
	printf("tamano puerto creado: %ld \n",sizeof(my_port));
	printf("dato: %x\n",my_port.data);
	prueba.e = 1;
	printf("dato de la nueva variable %x",prueba.data);
	return 0;
}
