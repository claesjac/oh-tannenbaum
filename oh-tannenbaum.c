/*
    Oh Tannenbaum! (c) Claes Jakobsson <claes@surfar.nu> 2013
    
    See LICENSE
*/

#include <avr/io.h>
#include <util/delay.h>

/* 
    2-bit MSB controls the delay length (0 - 250ms, 1 - 500ms, 2 - 1000ms, 3 - 2000ms)
    6-bit LSB controls each LED strip 0 - 5
*/
const uint8_t animation[] = {
    0b00000000,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
    
    0b01000000,
    0b01010101,
    0b01101010,
    0b01010101,
    0b01101010,
    0b01010101,
    0b01101010,
    0b01010101,
    0b01101010,
    
    0b00000000,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
    
    0b01000000,
    0b01111111,
    0b01000000,
    0b01111111,
    0b01000000,
    0b01111111,
    0b01000000,
    0b01111111,
    
    0b00000000,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,

    0b10000000,
    0b10000001,
    0b10000011,
    0b10000111,
    0b10001111,
    0b10011111,
    0b10111111,
    0b10111110,
    0b10111100,
    0b10111000,
    0b10110000,
    0b10100000,
};

int main(void) {
    uint8_t i;
    uint8_t delay;
    uint16_t len;
    
    PORTA = 0b00000000;
    DDRA = 0b11111111;
    
    len = sizeof(animation) / sizeof(animation[0]);
    
    while (1) {
        for(i = 0; i < len; i++) {
            delay = (animation[i] & 0b11000000) >> 6;
            PORTA = animation[i] & 0b00111111;

            switch (delay) {
                case 0:
                    _delay_ms(250);
                break;
                
                case 1:
                    _delay_ms(500);
                break;
                
                case 2:
                    _delay_ms(1000);
                break;
                
                case 3:
                default:
                    _delay_ms(2000);
                break;
            }
        }
    }
}