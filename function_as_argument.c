#include <stdio.h>
#include <stdint.h>

uint8_t mul(uint8_t a,uint8_t b)
{
	return a*b;
}

uint8_t sum(uint8_t a,uint8_t b)
{
	return a+b;
}

int main()
{
	uint8_t data = 0;
	data = mul(sum(5,4),10);
	printf("el resultado es: %d",data);
	return 0;
}
