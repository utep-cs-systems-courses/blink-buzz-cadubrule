#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static char stateR1=0;
static char stateR2=0;
static char stateR3=0;
static char stateR4=0;

char toggle_red()
{
  static char state_red = 0;

  switch(state_red){
  case 0:
    red_on = 1;
    state_red = 1;
    led_update();
    break;
  case 1:
    red_on = 0;
    state_red = 0;
    led_update();
    break;
  }
  return 1;
}

char toggle_green()
{
  static char state_green = 0;

  switch(state_green){
  case 0:
    green_on = 1;
    state_green = 1;
    led_update();
    break;
  case 1:
    green_on = 0;
    state_green = 0;
    led_update();
    break;
  }
  return 1;
}
void stateAdvance(char step){
  if(stateR1>0){
    route1(step);
  }
    if(stateR2>0){
      route2(step);
  }
    if(stateR3>0){
      route3(step);
  }
    if(stateR4>0){
      route4(step);
  }

}
void state_ofButton(){
 
  if(sw1_down){
    stateR1 ^= 1;   
    stateR2 = 0;
    stateR3 = 0;
    stateR4 = 0;
  }
  if(sw2_down){
    stateR2 ^= 1;
    stateR1 = 0;
    stateR3 = 0;
    stateR4 = 0;
   
  }
  if(sw3_down){
    stateR3 ^= 1;
    stateR1 = 0;
    stateR2 = 0;
    stateR4 = 0;
   
  }
  if(sw4_down){
    stateR4 ^= 1;
    stateR1 = 0;
    stateR2 = 0;
    stateR3 = 0;
    
   
  }

}

void route1(char step){
    if(step == 1){
      toggle_green();
      buzzer_set_period(1000);
    }
    if(step == 2){
      toggle_red();
      buzzer_set_period(2000);
    }
    if(step == 3){
      toggle_green();
      buzzer_set_period(3000);
    }
    if(step == 4){
      toggle_red();
      buzzer_set_period(4000);
    }
    if(step == 5){
      toggle_green();
       buzzer_set_period(5000);
    }
    if(step == 9){
      toggle_green();
      buzzer_set_period(1000);
    }
    if(step == 10){
      toggle_green();
      buzzer_set_period(2000);
    }
    if(step == 11){
      toggle_green();
      buzzer_set_period(3000);
    }
    if(step == 12){
      toggle_red();
      buzzer_set_period(4000);
    }
    if(step == 13){
      toggle_green();
       buzzer_set_period(1000);
    }
    if(step == 14){
      toggle_red();
    }
    if(step == 15){
      toggle_red();
    }
    if(step == 16){
      toggle_red();
      buzzer_set_period(0);
    }
  
}

void route2(char step){
  buzzer_set_period(0);
      if(step == 1){
      toggle_green();
      buzzer_set_period(5000);
    }
    if(step == 3){
      toggle_green();
      toggle_red();
      buzzer_set_period(6000);
    }
    if(step == 4){
      toggle_red();
    }
    if(step == 5){
      toggle_green();
      toggle_red();
       buzzer_set_period(7000);
    }
    if(step == 7){
      toggle_green();
    }
    if(step == 9){
      toggle_green();
      buzzer_set_period(7000);
    }
    if(step == 10){
      toggle_red();
    }
    if(step == 11){
      toggle_green();
      buzzer_set_period(5000);
    }
    if(step == 12){
      toggle_red();
    }
    if(step == 13){
      toggle_green();
       buzzer_set_period(5000);
    }
    if(step == 14){
      toggle_red();
      toggle_green();
    }
    if(step == 15){
      toggle_green();
    }
    if(step == 16){
      toggle_red();
       buzzer_set_period(0);
    }
}
void route4(char step){
  buzzer_set_period(0);
}
