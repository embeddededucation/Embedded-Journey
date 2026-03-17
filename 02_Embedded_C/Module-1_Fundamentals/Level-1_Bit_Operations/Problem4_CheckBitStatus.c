/*
Module-1
Problem-4
Problem Statement: Check bit status
Details:
This is the program for checking status of particular bit in the register.
Performing on simulated 8-bit register.
Date: 12th March'26
*/

#include <stdio.h>
#include <stdint.h>

#define BIT_POS3 3
#define BIT_POS4 4

int main()
{
    uint8_t reg = 0x18;
    uint8_t check =0;

    // 1st will check bit 3 of reg
    check = reg &(1<<BIT_POS3);
    printf("\ncheck = 0x%02X", check);

    // Next will check bit 4 of reg
    check = reg &(1<<BIT_POS4);
    printf("\ncheck = 0x%02X", check);

    return 0;

}
