#include <msp430.h>
#include "stateMachines.h"
static char count = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++count == 250) {
    state_advance();
    blink_count = 0;
  }
}
