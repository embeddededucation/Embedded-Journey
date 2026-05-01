Update main.c
In this example, got multiple learnings,
1. PORTC, PIN0, is used as o/p and PIN1 as i/p
2. Pull-up register is activated by writing "1" to PIN1 (which is i/p)
3. De-bounce operation is activated with 50msec delay
4. Most important, after debounce delay, we need to wait for key to get released
5. And once key is released then only "Key press" is activated
6. If don't wait till key release, LED toggles with 50 msec delay, as program keeps running continuously
