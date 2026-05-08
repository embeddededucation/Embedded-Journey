# Level 1 — Timer0 Overflow Interrupt

## What this does
Replaces _delay_ms() debounce with Timer0 overflow interrupt.
Button press on PC1 triggers 50ms debounce via timer.
LED on PC0 toggles after confirmed press and release.

## Key registers
- TCCR0A — WGM bits cleared, Normal mode
- TCCR0B — CS02=1, CS01=0, CS00=1 (CLK/1024 prescaler)
- TIMSK0 — TOIE0 set (overflow interrupt enable)
- TIFR0  — TOV0 flag set by hardware on overflow

## Timing calculation
16MHz / 1024 = 15,625 Hz
1 / 15,625   = 64 μs per tick
64μs × 256   = 16.384ms per overflow
50ms / 16.384ms = 3.05 → 3 overflows = 49.152ms (1.72% error)

## What I learned
- Timer must be started AFTER all configuration
- delay_done flag must be reset before starting timer
- Timer must be stopped inside ISR after delay completes
- Continuous timer creates race condition — non-deterministic debounce
- volatile required on variables shared between ISR and main()
