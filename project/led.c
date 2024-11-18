#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"


unsigned char redOn = 0, greenOn = 0;
unsigned char led_diff = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init(){
  P1DIR |= LEDS;
  led_diff = 1;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if(switch_state_changed){
    char ledFlags = 0;

    if(led_diff && switch_state == 1){
      P1OUT &= (0xff - LEDS) | ledFlags; //clear bits
      P1OUT |= ledFlags; // set bits for led
    }

    if(led_diff && switch_state == 2){
      P1OUT &= (0xff - LEDS) | ledFlags;
      P1OUT |= ledFlags;
    }
    
    if(led_diff && switch_state == 3){
      P1OUT &= (0xff - LEDS) | ledFlags;
      P1OUT |= ledFlags;
    }

    if(led_diff && switch_state == 4){
      ledFlags |= LED_RED;
      P1OUT &= (0xff - LEDS) | ledFlags;
      P1OUT |= ledFlags;
    }
    switch_state_changed =0;
  }
}

void greenC(int on){
  if(on){
    P1OUT |= LED_GREEN;
  }
  else{
    P1OUT &= ~LED_GREEN;
  }
}
void redC(int on){
  if(on){
    P1OUT |= LED_RED;
  }
  else{
    P1OUT &= ~LED_RED;
  }
}
