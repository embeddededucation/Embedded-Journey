/*
 * gpio.c
 *
 * Created: 05/06/2026 09:28:45
 *  Author: Anand
 */ 

#include "config.h"
#include <avr/io.h>   // ensures PORTB, DDRB, PB5, etc. are known
#include "gpio.h"




void toggleLED()
{
	PORTB ^= _BV(LED_PIN);
}

void setPB5OutPB7Input()
{
	// Pin B5 as o/p (Set to 1), Internal LED
	DDRB |= _BV(LED_PIN);

	// Pin B7 as i/p (Reset Bit),
	// Internal button, already has pull-up on board
	DDRB &= ~_BV(BUTTON_PIN);

	// Set PB5 LED On
	PORTB |= _BV(LED_PIN);
}
