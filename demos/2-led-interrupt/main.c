//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

static int secondCount = 0;

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();       /* enable periodic interrupt */
 
  or_sr(0x18);		/* CPU off, GIE on */
}
//global state var for time 

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  secondCount++;
  if(secondCount %5 == 0){
    P1OUT ^= LED_GREEN;
  }
  if(secondCount %50 == 0){
    P1OUT ^= LED_RED;
   }
  if(secondCount == 500)
    secondCount = 0;
} 

