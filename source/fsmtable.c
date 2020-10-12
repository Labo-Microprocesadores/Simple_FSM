#include <stdio.h>
#include "fsm.h"
#include "fsmtable.h"
#include "Estados/ledRojo.h"
#include "Estados/ledAzul.h"
#include "Estados/ledVerde.h"

/*Foward Declarations*/

extern STATE ledAzul[];
extern STATE ledRojo[];
extern STATE ledVerde[];



// prototipos

static void do_nothing(void);


/*** tablas de estado ***/

/*** ledAzul ***/

 STATE ledAzul[]=
{
  	{PRESS_EV,ledRojo,prenderRojo},
  	{LKP_EV,ledVerde,prenderVerde},
  	{FIN_TABLA,ledAzul,do_nothing}
};


/*** ledRojo ***/

STATE ledRojo[]=
{
	{PRESS_EV,ledVerde,prenderVerde},
	{LKP_EV,ledAzul,prenderAzul},
	{FIN_TABLA,ledAzul,do_nothing}
};

/*** ledVerde ***/

STATE ledVerde[] =
{
	{PRESS_EV,ledAzul,prenderAzul},
	{LKP_EV,ledRojo,prenderRojo},
	{FIN_TABLA,ledAzul,do_nothing}
};



//========interfaz=================


STATE *FSM_GetInitState(void)
{
 	return (ledAzul);
}



///=========Rutinas de accion===============



/*Dummy function*/
static void do_nothing(void)
{

}



