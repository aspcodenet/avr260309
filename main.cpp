#include <avr/io.h>
#include <util/delay.h>


// https://wokwi.com/projects/365047092561218561

// PORTB B (digital pin 8 to 13)
// C (analog input pins)
// PORTD D (digital pins 0 to 7)

#define LED_PIN 2

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))




int main() {
    
    // Set LED_PIN as output
    BIT_SET(DDRB,LED_PIN); //OUTPUT MODE

    while(1){
        // on PORTB set pin 2 to HIGH   // PIN AND  BIT ARE THE SAME
        //                                 PORT AND BYTE ARE THE SAME
        BIT_SET(PORTB,LED_PIN);         // PORTB contains 8 bits (ints an char/byte) - and is wired to the digital pins 8 to 13. So PORTB0 is pin 8, PORTB1 is pin 9, PORTB2 is pin 10, etc.
        // SLEEP 500ms
        _delay_ms(500);
        // on PORTB set pin 2 to LOW
        BIT_CLEAR(PORTB,LED_PIN);
        // SLEEP 500ms
        _delay_ms(500);
    }


    return 0;
}