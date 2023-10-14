/****************Layer:HAL********************/
/****************Author:Mohamed Shalpy******************/
/****************Date:6/10/2023****************/
/****************Component:STEPPER*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "STEPPER_config.h"
#include "STEPPER_interface.h"
#include "STEPPER_private.h"


//Initialize the Stepper port to output direction
void Stepper_Init(void)
{
	_delay_ms(20);
	DIO_voidSetPortDir(STEPPER_PORT, PORT_DIR_OUT);
}

//For Clock wise rotation
void Rotate_CW(u8 Copy_u8Speed)
{

	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_HIGH);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_LOW);
	_delay_ms(Copy_u8Speed);

	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_HIGH);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_LOW);
	_delay_ms(Copy_u8Speed);

	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_HIGH);
	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_LOW);
	_delay_ms(Copy_u8Speed);

	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_HIGH);
	_delay_ms(Copy_u8Speed);
}

//For Anti-Clock wise rotation
void Rotate_ACW(u8 Copy_u8Speed)
{
	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_HIGH);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_LOW);
	_delay_ms(Copy_u8Speed);

	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_HIGH);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_LOW);
	_delay_ms(Copy_u8Speed);

	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_HIGH);
	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_LOW);
	_delay_ms(Copy_u8Speed);

	DIO_voidSetPinVal(STEPPER_PORT, ORANGE_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, YELLOW_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, PINK_WIRE, PIN_VAL_LOW);
	DIO_voidSetPinVal(STEPPER_PORT, BLUE_WIRE, PIN_VAL_HIGH);
	_delay_ms(Copy_u8Speed);
}

/*functions the takes the direction and the speed the user wants
 * and rotates the stepper accordingly
 * if the user entered the wrong speed or direction
 * the function won't do anything*/
void Stepper_ON(u8 Copy_u8Direction,u8 Copy_u8Speed)
{
	if(Copy_u8Direction==CW)
	{
		switch(Copy_u8Speed)
		{
		case FAST:
			Rotate_CW(FAST);
			break;
		case MID:
			Rotate_CW(MID);
			break;
		case SLOW:
			Rotate_CW(SLOW);
			break;
		default:
			break;
		}
	}
	else if(Copy_u8Direction==ACW)
	{
		switch(Copy_u8Speed)
		{
		case FAST:
			Rotate_ACW(FAST);
			break;
		case MID:
			Rotate_ACW(MID);
			break;
		case SLOW:
			Rotate_ACW(SLOW);
			break;
		default:
			break;
		}
	}
	else
	{

	}
}
