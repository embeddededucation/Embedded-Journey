/*
Module-1
Problem-7
Problem Statement: Pointers Basics
Details:
1) Declare variable x = 5
2) Create pointer to x
3) Modify x using pointer
4) Print both x and *ptr
Date: 28th March'26
*/

#include <stdio.h>
#include <stdint.h>

int main()
{
    uint8_t x=5;
    uint8_t *ptr = &x;

    *ptr = *ptr +1;

    printf("\nValue of x= %d", x);
    printf("\nValue of *ptr= %d", *ptr);
    printf("\nValue of ptr is 0x%p", ptr);

    return 0;

}
