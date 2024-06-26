/*
 * Joystick.h
 *
 *  Created on: Apr 27, 2024
 *      Author: emper
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "main.h"
#include "Encoder.h"
#include "ModbusRTU.h"

/*		PIN - LIST		*/
/*
	A	:	PB10
	B	:	PB4
	C	:	PB5
	D	:	PA10
*/

enum
{
	A,B,C,D
};

typedef struct _JoystickStructure
{
	uint16_t XYBuffer[200];			// Even Number is X [0,2,4,...] , Odd is Y [1,3,5,...]
	uint16_t X;
	uint16_t Y;
	uint16_t PIN[4];				//A B C D
	float PointPosition[5];
	float Xpos;
}JoystickStructureTypeDef;

void Joystick_UpdateValue(JoystickStructureTypeDef *joystick , QEIStructureTypeDef *QEI);

#endif /* INC_JOYSTICK_H_ */
