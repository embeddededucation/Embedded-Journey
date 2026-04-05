/*
 * main.c
 * Created: 05/04/2026
 * Author : Anand
 * Board  : ATmega168PB Xplained Mini
 * Program: LED on PB5 blinks 3 times fast (100ms),
 *          then stays OFF for 1 second, then repeats.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1 << DDB5);        /* PB5 as output */

    while (1)
    {
        for (uint8_t i = 0; i < 3; i++)
        {
            PORTB |=  (1 << PORTB5);  /* LED on  */
            _delay_ms(100);
            PORTB &= ~(1 << PORTB5);  /* LED off */
            _delay_ms(100);
        }
        _delay_ms(1000);              /* pause 1 second */
    }
}
