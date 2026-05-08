/*
 * GPIO-Timer.c
 *
 * Created: 07/05/2026 11:33:29
 * Author : anand
 * This is the replica of the old Push Button polling program by using Timer module with interrupt.
 In main.c, timer is initialized (Normal mode and enabling all timer routines) and interrupt as well. 
 But timer is not started. After confirmation of push button (press and release), it will trigger timer operation.
 Global variables are used as volatile to extract real time values.
 Sequence of Operation,
 1) Set all Port Pins
	PORTC, PC0- o/p, PC1- i/p
 2) Set Prescaler to 1024
	TCCR0B- CS02=1, CS01=0 & CS00=1, For Prescaler 1024
 3) Activate Normal mode
	TCCR0A- Reset Bits,  WGM00 &  WGM01
	TCCR0B- Reset Bit, WGM02
 5) TIMSK0- Write 1 (TOIE0 bit)
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t overflow_count;
volatile uint8_t delay_done;
void toggleLED();


void fityMsecDelay();

int main(void)
{
	// Make PC0 as output bit and PC1 as input bit
	DDRC |= _BV(DDC0);
	DDRC &= ~_BV(DDC1);
	
	// Activate pull-up
	PORTC |= _BV(PC1);
	
	// Switch On LED
	PORTC |= _BV(PC0);
	
	// Set Timer0 in Normal Mode, all set to '0'
	TCCR0A &= ~_BV(WGM00);
	TCCR0A &= ~_BV(WGM01);
	TCCR0B &= ~_BV(WGM02);
	
	// Set Interrupt Mask Register
	TIMSK0 |= _BV(TOIE0);
	
	overflow_count =0;
	delay_done=0;
	
	// Initiate interrupt
	sei();
	
	while(1)
	{
		while(!(PINC & _BV(PC1)))
		{
			fityMsecDelay();
			// Wait till it is released
			while(!(PINC & _BV(PC1)));
			
			toggleLED();
		}		
	}

}


// 50 msec delay function
void fityMsecDelay()
{
	delay_done = 0;
	
	// Start Timer
	TCCR0B |= _BV(CS02);
	TCCR0B &= ~_BV(CS01);
	TCCR0B |= _BV(CS00);
	
	while(!delay_done);

}

ISR(TIMER0_OVF_vect)
{
	overflow_count++;
	if (overflow_count ==3)
	{
		overflow_count = 0;		
		delay_done =1;
		TCCR0B &= ~(_BV(CS02) | _BV(CS01) | _BV(CS00));  /* stop timer */
	}
}

void toggleLED()
{
	PORTC ^= _BV(PC0); 
}
