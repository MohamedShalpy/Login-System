/****************Layer:HAL********************/
/****************Author:Mohamed Shalpy******************/
/****************Date:6/10/2023****************/
/****************Component:STEPPER*****************/

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

void Stepper_Init(void);								//sets the stepper port to output
void Rotate_CW(u8 Copy_u8Speed);						//takes the speed the user wants and rotates the stepper clockwise
void Rotate_ACW(u8 Copy_u8Speed);						//takes the speed the user wants and rotates the stepper anti clockwise
void Stepper_ON(u8 Copy_u8Direction,u8 Copy_u8Speed);	//takes direction and speed of stepper and turns it on

#define CW 0											//clock wise 0
#define ACW 1											//anti clock wise 1

#endif
