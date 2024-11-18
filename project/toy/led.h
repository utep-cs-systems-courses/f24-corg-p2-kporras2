#ifndef led_included
#define led_included

#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

extern unsigned char redOn,greenOn;
extern unsigned char led_diff;

void led_init();
void led_update();
void greenC(int on);
void redC(int on);
#endif
