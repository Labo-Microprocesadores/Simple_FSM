#include "ledVerde.h"

void prenderVerde(void){
    gpioWrite(PIN_LED_BLUE, LED_OFF);
    gpioWrite(PIN_LED_GREEN, LED_ON);
    gpioWrite(PIN_LED_RED, LED_OFF);
}