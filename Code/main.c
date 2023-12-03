/*******************************************************
Project : AVR-Calculator
Version : 1.0
Date    : 12/1/2023
Author  : AhmadReza G
Comments: This is a small calculator using (4x4) Keypad and LCD interfacing with AVR (ATmega16) Microcontroller.


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>
#include <alcd.h>

void main(void)
{
    DDRD = 0x0F;
    PORTD = 0xF0;

    lcd_init(16);

    while (1)
          {
            // Place your code here
          }
}
