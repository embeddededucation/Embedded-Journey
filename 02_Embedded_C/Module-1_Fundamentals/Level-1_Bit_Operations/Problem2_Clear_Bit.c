/*
Module-1
Problem-4
Problem Statement: Clearing bit
Details:
This is the program for Clearing up particular bit in the register.
Performing on simulated 8-bit register.
Date: 12th March'26
*/

#include <stdio.h>
#include <stdint.h>

#define BIT_POS 3

int main()
{
    uint8_t reg =0xff;

    printf("\nInitial value of the reg is, 0x%02X", reg);

    // Shifted 1, three positions on the left
    // So it looks like, 00001000
    // And making it invert, 11110111
    // Now ANDing this value to register
    // Will always pass other bits except 3rd bit
    reg &=  ~(1<<BIT_POS);

    printf("\nNew value after clearing 3rd bit is, 0x%02X", reg);

    /*
        if(reg & (1 << BIT_POS))
            printf("Bit %d is SET\n", BIT_POS);
        else
            printf("Bit %d is CLEAR\n", BIT_POS);

    */
    return 0;

}
