/*
 * config.h
 *
 * Created: 07/06/2026 06:22:13
 *  Author: Anand
 */ 


#ifndef CONFIG_H
#define CONFIG_H

// System Frequency Configuration
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/* Pin definitions */
#define LED_PIN             PB5
#define LED_PORT            PORTB
#define LED_DDR             DDRB
#define BUTTON_PIN          PB7
#define BUTTON_DDR          DDRB
#define BUTTON_PIN_REG      PINB

/* Timer configuration */
#define TIMER_OCR_VALUE     194
#define TIMER_CYCLES        3


#endif /* CONFIG */
