/*
Module-1
Problem-1
Problem Statement: Setting up bit
Details:
This is the program for setting up particular bit in the register.
Though it is simulated 8-bit register, but we are
Date: 9th March'26
*/

#include <stdio.h>
#include <stdint.h>

#define BIT_POS 3

int main()
{
    // Initial value of reg is zero
    uint8_t reg =0, reg1= 1;

    reg1 = reg1<<5;
    printf("\nreg1 = %d", reg1);

    // Shifting "1" three times and making OR with reg
    reg |= (1 << BIT_POS);
    // This prints Hex value
    // 0x -> Printed as it is
    // % -> Formatted value will be printed
    // 0 -> added as pad
    // X -> Hex value displayed
    printf("\nReg value is, 0x%02X\n", reg);

    // For Binary
    for (int i=7; i>=0; i--)
    {
        printf("%d", (reg>>i)&1);
    }

    return 0;

}
