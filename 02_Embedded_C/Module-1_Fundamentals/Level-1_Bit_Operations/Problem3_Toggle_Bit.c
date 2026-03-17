/*
Module-1
Problem-3
Problem Statement: Toggle bit
Details:
This is the program for toggle up particular bit in the register.
Performing on simulated 8-bit register.
Date: 12th March'26
*/

#include <stdio.h>
#include <stdint.h>

// Considering LSB is zero
// BIT_POS, 3 is 4th bit
#define BIT_POS 3

int main()
{
    uint8_t reg =0;

    printf("\nOriginal value of the register is, 0x%02X", reg);

    reg ^=  (1<< BIT_POS);
    printf("\nNew value of the register is, 0x%02X", reg);

    printf("\nWe will perform again toggle");

    reg ^=  (1<< BIT_POS);
    printf("\nNew value of the register is, 0x%02X\n", reg);

    return 0;
}
