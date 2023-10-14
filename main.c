#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "STEPPER_interface.h"
#include "log_config.h"
#include "log_interface.h"
#include "log_private.h"


void main(void)
{
	DIO_voidSetPortDir(PORTD_REG,0b00001111);
	DIO_voidSetPortVal(PORTD_REG,PORT_VAL_HIGH);
	DIO_voidSetPortDir(PORTA_REG,PORT_DIR_OUT);
	DIO_voidSetPortDir(PORTB_REG,PORT_DIR_OUT);

	LOG_sysinit();
	while(1)
	{
		LOG_Sys();
	}
}

