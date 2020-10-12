#include "ledRojo.h"

void prenderRojo(void){
    gpioWrite(PIN_LED_BLUE, LED_OFF);
    gpioWrite(PIN_LED_GREEN, LED_OFF);
    gpioWrite(PIN_LED_RED, LED_ON);
}
