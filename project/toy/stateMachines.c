#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"




void led_state_advance(){
  led_update();
}

void switch_state_advance(){
  switch (switch_state){
  case 1:
    cop();
    switch_state = 0;
    break;
  case 2:
    marry_had_a_little_lamb();
    switch_state = 0;
    break;
  case 3:
    twinkle_twinkle_little_star();
    switch_state = 0;
    break;
  case 4:
    buzzer_off();
    break;
  }
  led_update(); //after the state is set it will update the leds accordingly
}
