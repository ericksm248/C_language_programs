#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef  struct{
	uint8_t value;
	char data;
}data_t;

uint8_t global_register[3] = {0,0,0};

//copy data to another register and check index data
uint8_t copy_and_check_register(uint8_t * data,uint8_t *register_d,uint8_t size_data)
{
	uint8_t i = 0;
	for(i=0;i<size_data;i++)
	{
		register_d[i] = data[i];
	}
	if(global_register[1]==5)
		return 1;
	else
		return 0;
}

int main(void)	
{
	char *array_data = "data output";
	data_t mi_data = {10,'a'};
	data_t * ptr = &mi_data;
	uint8_t a= 5;
	uint8_t b= 10;
	uint8_t c= 2;
	uint8_t val_array[5]={0,5,0,0,0};

	// take advantage of short-circuit evaluation to optimize program behavior
	// first, check the flag, then evaluate more complex conditions
	if(a==3 && strcmp(array_data,"data input")==0)
		printf("condition passed for short-circuit, second condition was executed\n");
	else
		printf("was the second condition executed? if the first condition  was true, the second condition was executed\n");
	
	// safe acces to variable, avoid accessing a null pointer
	if (ptr != NULL && ptr->value == 10) 
	{
		printf("valid access\n");
	}
	// warning! due to short-circuit, in this case the second condition will not execute and values won't be copied to the register
	if (b==4 && copy_and_check_register(val_array,global_register,3))
	{
		printf("no problem, data saved into register\n");
	}
	printf("if the value is different from 0, the second condition was executed. Value: %d\n", global_register[1]);
	return 0;
}
