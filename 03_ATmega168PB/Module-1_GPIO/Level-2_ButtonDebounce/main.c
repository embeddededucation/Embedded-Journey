/*
 * ButtonPressPolling.cpp
 * This program will poll button press and includes,
 * 1) Set Port C0 as Input Pin with Pull-up register
 * 2) Make Port C1 as Output Pin
 * 3) Write toggleLED as separate function
 * 4) Write buttonPressDetect as separate function (with Debounce)
 * 5) Every time button is pressed (and after release) it will toggle LED state
 * 6) LED will be ON as default
 * Created: 01/05/2026 11:05:25
 * Author : Anand
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

uint8_t buttonPressDetect(void);
void toggleLED(void);


int main(void)
{
    // Set PORTC, P0 as Output Pin
	DDRC |= _BV(DDC0); 
	
	// Set PORTC, P1 as Input Pin
	DDRC &= ~_BV(DDC1);
	
	// Activate Pull-up Register on P1 of PORTC
	PORTC |= _BV(PC1);
		
	// Make LED ON by default
	PORTC |= _BV(PC0);
			
	while (1)
	{
		if (buttonPressDetect())
		{
			toggleLED();
		}
	}
}

uint8_t buttonPressDetect(void)
{

	// Wait till button is pressed
	while(!(PINC & _BV(PC1)))
	{
		_delay_ms(50);
		
		// Now we wait till button is released
		while(!(PINC & _BV(PC1)));
		
		return 1;

	}
	
	return 0;
}

void toggleLED()
{
	PORTC ^= _BV(PC0);
	return;
}

