#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

/* Switch on P2 (S2) */

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;               /* clear pending sw interrupts */
  switch_interrupt_handler();	/* single handler for all switches */
}
  
}//
 static int  secondCount = 0;
 static char step = 0;
 
/* WDT*/
void
__interrupt_vec(WDT_VECTOR) WDT(){
  secondCount++;
  
  if(secondCount >= 75){
    step++;
    stateAdvance(step);
    secondCount = 0 ;
  }
  if(step >=16){
    step = 0;
  }
}
