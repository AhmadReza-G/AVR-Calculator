/*******************************************************
Project : AVR-Calculator
Version : 1.1
Date    : 12/3/2023
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
#include <delay.h>
#include <stdint.h>

#define C0 PIND.4
#define C1 PIND.5
#define C2 PIND.6
#define C3 PIND.7

flash uint8_t shift[4] = { 0xFE, 0xFD, 0xFB, 0xF7 };
flash unsigned char layout[16] = { '7', '8', '9', '/',
                                   '4', '5', '6', '*',
                                   '1', '2', '3', '-',
                                   'C', '0', '=', '+' };
unsigned char keypad(void);

void main(void)
{
    unsigned char pressed_button;
    DDRD = 0x0F;
    PORTD = 0xF0;

    lcd_init(16);

    while (1)
          {
            pressed_button = keypad();
            if (pressed_button == 'C')
                lcd_clear();
            else
                lcd_putchar(pressed_button);
          }
}
unsigned char keypad(void)
{
    int row = 0, column = -1, position = 0;
    while (1)
    {
        for (row = 0; row < 4; ++row)
        {
            PORTD = shift[row];
            if (C0 == 0)
                column = 0;
            if (C1 == 0)
                column = 1;
            if (C2 == 0)
                column = 2;
            if (C3 == 0)
                column = 3;
            if (column != -1)
            {
                position = (row * 4) + column;
                lcd_putchar(layout[position]);
                column = -1;

                while (C0 == 0);
                while (C1 == 0);
                while (C2 == 0);
                while (C3 == 0);

                return layout[position];
            }
            delay_ms(50);
        }
    }
}