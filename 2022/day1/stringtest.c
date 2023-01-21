#define __STDC_WANT_IEC_60559_BFP_EXT__
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    char *string = malloc(sizeof(uint16_t));

    unsigned long long number = 1234567890123456;

    for (int i = 0; i <= sizeof(unsigned long long); i++)
    {
        
    }

    for (int i = 0; i <= sizeof(unsigned long long); i++)
    {
        
        string[i] = 0;
    }
    
    number = atoi(string);

    printf("String: %s\n", string);
    printf("Unsigned long long: %llu\n", number);
}