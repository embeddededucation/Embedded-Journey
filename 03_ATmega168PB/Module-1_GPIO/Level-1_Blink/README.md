# Level 1 — GPIO Blink

## What this does
Blinks onboard LED on PB5 every 500ms using direct register writes.
No Arduino library. No HAL. Pure register-level C.

## Hardware
- Board: ATmega168PB Xplained Mini
- LED: PB5 (onboard)

## Key registers
- DDRB  — set PB5 as output
- PORTB — drive PB5 high/low

## Status
[x] Complete
