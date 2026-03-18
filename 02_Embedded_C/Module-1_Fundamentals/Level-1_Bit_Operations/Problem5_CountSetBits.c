/*
Module-1
Problem-5
Problem Statement: Count Set Bits
Details:
This is the program for counting set bits particular in the register.
Performing on simulated 8-bit register.
Date: 12th March'26
*/

#include <stdio.h>
#include <stdint.h>

#define FIRST_BIT 1

int main()
{
    uint8_t reg = 0xF5;
    uint8_t bitNum =1, bitCount =0;

    for (uint8_t Count =0; Count <8; Count++)
    {
         if(reg & bitNum)
        {
            bitCount++;
        }
       //  printf("\nbitNum = %d", bitNum);
        bitNum = bitNum<<1;
    }

    printf("\nCount of Ones in this Number are, %d", bitCount);
    return 0;
}
