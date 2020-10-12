#include "ledAzul.h"

void prenderAzul(void){
    gpioWrite(PIN_LED_BLUE, LED_ON);
    gpioWrite(PIN_LED_GREEN, LED_OFF);
    gpioWrite(PIN_LED_RED, LED_OFF);
}
