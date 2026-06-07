/*
 * timer.c
 *
 * Created: 05/06/2026 21:05:07
 *  Author: Anand
 */ 
#include "config.h"   
#include <avr/io.h>
#include "timer.h"
#include <avr/interrupt.h>


static volatile uint8_t cycleMultiplier =0;

void delay50msec()
{

	// Now load 194 to OCR0A
	OCR0A = TIMER_OCR_VALUE;

	// Set Pre-scaler to 1024, this will start Timer
	TCCR0B |= _BV(CS00);
	TCCR0B &= ~_BV(CS01);
	TCCR0B |= _BV(CS02);


	while(cycleMultiplier < TIMER_CYCLES)
	{
		// Wait till three cycles are complete
	}

	// Switch off timer
	TCCR0B &= ~_BV(CS00);
	TCCR0B &= ~_BV(CS01);
	TCCR0B &= ~_BV(CS02);

	cycleMultiplier =0;

}

void timerCTCsetup()
{
	// Set OCIE0A bit of TIMSK0, this enables Interrupt
	// To be set only once
	TIMSK0 |= _BV(OCIE0A);

	// Now setting of Timer registers
	// 1: Set CTC Mode
	// TCCR0A: WGM00->0, WGM01->1,
	// TCCR0B: WGM02->0
	// 2: TIMSK0 – Timer/Counter Interrupt Mask Register
	// Set bit, OCIE0A to High to enable Interrupt
	// 3: Set compare value
	// OCR0A: Output Compare Register A
	// Need to set value 195 here
	// 4: Setting Pre-Scaler to 1024 and start timer
	// TCCR0B: CS00->1; CS01->0; CS02->1

	// Setting CTC Timer Mode
	TCCR0A &= ~_BV(WGM00);	// WGM00->0
	TCCR0A |= _BV(WGM01);	// WGM01->1
	TCCR0B &= ~_BV(WGM02);	// WGM02->0
}

ISR(TIMER0_COMPA_vect)
{
	cycleMultiplier++;
}
