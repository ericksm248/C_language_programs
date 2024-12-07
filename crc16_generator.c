#include <stdio.h>
#include <stdint.h>

uint16_t gen_crc16(uint8_t *data, uint8_t size)
{
    uint16_t out = 0;
    uint16_t bits_read = 0, bit_flag;
    uint16_t j = 0x0001;
    uint16_t crc = 0;
    uint16_t i;
    while(size > 0)
    {
        bit_flag = out >> 15;

        /* Get next bit: */
        out <<= 1;
        out |= (*data >> bits_read) & 1; // item a) work from the least significant bits

        /* Increment bit counter: */
        bits_read++;
        if(bits_read > 7)
        {
            bits_read = 0;
            data++;
            size--;
        }

        /* Cycle check: */
        if(bit_flag)
            out ^= 0x8005;

    }

    // item b) "push out" the last 16 bits

    for (i = 0; i < 16; ++i) {
        bit_flag = out >> 15;
        out <<= 1;
        if(bit_flag)
            out ^= 0x8005;
    }

    // item c) reverse the bits

    i = 0x8000;
    for (; i != 0; i >>=1, j <<= 1) {
        if (i & out) crc |= j;
    }

    return crc;
}

int main(void)
{
    uint8_t data_chain[]="esto es una prueba";
    uint16_t crc = gen_crc16(data_chain,sizeof(data_chain)-1); //no consideramos el caracter nulo al final
    printf("el crc de la cadena es: %x",crc);
    return 0;
}
