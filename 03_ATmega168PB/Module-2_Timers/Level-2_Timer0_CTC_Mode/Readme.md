# Level 2 — Timer0 CTC Mode with Multi-File Driver Architecture

## Experiment Objective
Implement a 50ms button debounce using Timer0 in CTC mode, while
introducing a professional multi-file firmware architecture.
The same button toggle behavior from previous experiments is retained —
what changes completely is how the code is organized.

## Hardware
- Board  : ATmega168PB Xplained Mini
- Button : PB7 (onboard, active-low, external 10k pull-up)
- LED    : PB5 (onboard, active-high)

## CTC Mode — Key Difference from Normal Mode
In Normal mode the timer counts 0→255 and overflows.
In CTC mode the timer counts 0→OCR0A, fires an interrupt,
then resets to 0 automatically. This gives precise, controllable
intervals without accumulating overflow count error.

Timer calculation:
- Prescaler   : CLK/1024 → 15,625 Hz → 64μs per tick
- OCR0A       : 194 → (194+1) × 64μs = 12.48ms per interrupt
- Iterations  : 3 × 12.48ms = 49.92ms (0.16% error)
- ISR vector  : TIMER0_COMPA_vect

## Library Structure Overview
This experiment introduces a multi-file driver architecture.
main.c contains zero register names — all hardware access is
delegated to dedicated driver files.

| File      | Responsibility                                      |
|-----------|-----------------------------------------------------|
| config.h  | F_CPU, pin definitions, timer constants             |
| gpio.h/c  | GPIO driver — pin setup, LED toggle, button read    |
| timer.h/c | Timer driver — CTC setup, delay function, ISR       |
| main.c    | Application logic only — calls driver functions     |

### Key C concepts introduced
- Header guards         — prevent duplicate declarations
- static variables      — file-scoped, enforces encapsulation
- volatile variables    — prevents compiler optimizing ISR-shared data
- Self-contained headers — each .h includes its own dependencies
- Include syntax        — <> for system headers, "" for project files
- config.h pattern      — single source of truth for all constants

## Portability
Because main.c has no register names, porting to a different
microcontroller requires changing only the driver files.
main.c application logic stays identical.
