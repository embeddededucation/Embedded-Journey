/*
 * 05_CTC_Mode.c
 *
 * Created: 17/05/2026 10:12:27
 * Author : Anand
 This project basically focuses on CTC Timer mode
 Further operations are same such as,
 1) PortB: Bit7 i/p: User Button provided on the board
 2) PortB: Bit5 o/p: User LED provided on board
 3) Button press & release triggers interrupt
 4) and 50msec delay is implemented by CTC timer mode
 5) All have to be implemented by dedicated libraries
 */

#include "config.h"
#include "gpio.h"
#include <avr/interrupt.h>
#include "timer.h"


int main(void)
{
	// Set PB5 as Output Pin and PB7 as input Pin
	setPB5OutPB7Input();
	
	// Initial setup of CTC Timer 
	timerCTCsetup();
	
	// Set I-Bit of SREG Register to 1
	// This is Global Timer Enable Register
	sei();
	
    while (1)
    {
		// If PINB07 is high stay waiting
		while(!(PINB & _BV(BUTTON_PIN)))
		{
			// When we enter in the loop, indicates Button is pressed
			delay50msec();

			while(!(PINB & _BV(BUTTON_PIN)))
			{
				// Here we are waiting till button is released
				// This loop will be executed till button is released
			}

			// Now button is released & to toggle LED
			toggleLED();

		}

    }
}
