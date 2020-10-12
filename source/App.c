/***************************************************************************//**
  @file     App.c
  @brief    Application functions
  @author   charlie y mati
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "board.h"
#include "gpio.h"
#include "button.h"
#include "SysTick.h"
#include "fsm.h"
#include "fsmtable.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define LED PORTNUM2PIN(PB,23) //PTA0
#define SW PORTNUM2PIN(PC,0)
#define DELAY 8
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/


void callback_systick(void);
void callback_switch(void);
Events_t getEvent(void);

/*******************************************************************************
 * GLOBAL VARIABLES
 ******************************************************************************/
STATE *currentState;

/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/* Función que se llama 1 vez, al comienzo del programa */
void App_Init (void)
{
	//Configuro la salida
	gpioMode(PIN_LED_RED, OUTPUT);
	gpioMode(PIN_LED_GREEN, OUTPUT);
	gpioMode(PIN_LED_BLUE, OUTPUT);
	//Apago todo
	gpioWrite(PIN_LED_RED, LED_OFF);
	gpioWrite(PIN_LED_GREEN, LED_OFF);
	gpioWrite(PIN_LED_BLUE, LED_ON);
	//Defino entrada
	gpioMode(PIN_SW3, INPUT);
	//Inicializo
	SysTick_Init();
	buttonsInit();
	buttonConfiguration(PIN_SW3, LKP , 50);

}

/* Función que se llama constantemente en un ciclo infinito */

void App_Run (void)
{
	Events_t event;
	currentState = FSM_GetInitState();// Inicializo la FSM con el estado inicial

	while(1)
	{
		event = getEvent();
		if(event)			
			currentState=fsm(currentState,event);
	}
	

}

Events_t getEvent(void)
{
	if(wasTap(PIN_SW3))
		return PRESS_EV;
	else if(wasLkp(PIN_SW3))
		return LKP_EV;
	return NONE;
	
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/*******************************************************************************
 ******************************************************************************/

