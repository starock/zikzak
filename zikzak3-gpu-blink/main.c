
#define F_CPU 20000000UL  /* 20 MHz CPU clock */

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

#include <string.h>
#include <stdlib.h>

#include "main.h"

// skee board
// PC 01 RR
// PC 23 GG
// PC 45 BB
// PB 0 vsync (pin 1)
// PB 1 hsync (pin 2)

#define LED_OFF      PORTC &= ~(1<<0)
#define LED_ON       PORTC |= (1<<0)
#define LED          (PORTC & (1<<0))

void main ( void ) {
  int i = 0;

  cli();

  DDRC = 0xFF; // C out

  while ( 1 ) {

    if ( LED ) {
      LED_OFF;
    } else {
      LED_ON;
    }
    _delay_ms ( 300 );

  } // while forever

} // main
