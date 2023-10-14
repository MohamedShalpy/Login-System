#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "STEPPER_interface.h"
#include "STEPPER_config.h"
#include "log_config.h"
#include "log_interface.h"
#include "log_private.h"

u8 key;

void LOG_sysinit(void)
{
	CLCD_voidInit();
	_delay_ms(5);
	Stepper_Init();
   DIO_voidSetPinDir(PORTC_REG,PIN4,PIN_DIR_OUT);
   DIO_voidSetPinDir(PORTC_REG,PIN5,PIN_DIR_OUT);
   CLCD_voidSendString("Login System");
   _delay_ms(1000);
   CLCD_voidInit();
   CLCD_voidSendString("1- DC Motor");
   CLCD_voidSendPosition(1,0);
   CLCD_voidSendString("2- Stepper");



}
void LOG_Sys(void)
{

	key=KPD_u8GetPressedKey();
	if(key==1 || key==2)
	{
		switch(key)
		{
		case DC:
			CLCD_voidInit();
			CLCD_voidSendString("3- Cw");
			_delay_ms(10);
			CLCD_voidSendPosition(1,0);
			CLCD_voidSendString("4- Ccw");
			_delay_ms(10);
			break;
		case Stepper:
			CLCD_voidInit();
			CLCD_voidSendString("5- Cw");
			CLCD_voidSendPosition(1,0);
			CLCD_voidSendString("6- Ccw");
          break;
		}
	}
	if(key==3 || key==4)
	{
		switch(key)
		{
		case 3:
			CLCD_voidInit();
	      _delay_ms(10);
	      CLCD_voidSendString("DC Rotatecw");
	      while(key==3)
	      {
	    	  DIO_voidSetPinVal(PORTC_REG,PIN4,PIN_VAL_LOW);
	    	  DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_HIGH);

	      }
	      break;
		case 4:
			CLCD_voidInit();
			_delay_ms(10);
			CLCD_voidSendString("DCRotateCcw");
			while(key==4)
			{
				DIO_voidSetPinVal(PORTC_REG,PIN4,PIN_VAL_HIGH);
				DIO_voidSetPinVal(PORTC_REG,PIN5,PIN_VAL_LOW);
			}
			break;
		}

	}
  if(key==5 || key==6)
  {
	  switch(key)
	  {
	  case 5:
		  CLCD_voidInit();
		  _delay_ms(10);
		  CLCD_voidSendString("StepperRotateCW ");
		  while(key==5)
		  {
			Stepper_ON(CW,FAST);

		  }
		  break;
	  case 6:
		  CLCD_voidInit();
		  _delay_ms(10);
		  CLCD_voidSendString("StepperRotateCcw");
		  while(key==6)
		  {
			  Stepper_ON(ACW,FAST);
		  }
		  break;
	  }
  }
 if(key==13)
 {
	 LOG_sysinit();
	 key=0;
 }



}



