
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <util/delay.h>
#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8Key=0xff;

	u8 arr[ROW_NUM][COL_NUM]= KPD_ARR;


	for(u8 col=0 ; col<COL_NUM ; col++)
	{
		DIO_voidSetPinVal(KPD_PORT , col , PIN_VAL_LOW);

		for(u8 row=0 ; row<ROW_NUM ; row++)
		{
			if ((DIO_u8GetPinVal(KPD_PORT , row+4)) == PIN_VAL_LOW)
			{
				Local_u8Key=arr[row][col];
				_delay_ms(2);
				while((DIO_u8GetPinVal(KPD_PORT , row+4))==PIN_VAL_LOW)
				{

				}
			}

		}

		DIO_voidSetPinVal(KPD_PORT , col , PIN_VAL_HIGH);

	}

	return Local_u8Key;

}

