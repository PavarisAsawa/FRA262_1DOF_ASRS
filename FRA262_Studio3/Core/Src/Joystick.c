/*
 * Joystick.c
 *
 *  Created on: Apr 27, 2024
 *      Author: emper
 */

#include "main.h"
#include "Joystick.h"
#include "Controller.h"
#include "stm32g4xx_hal.h"

/*		PIN - LIST		*/
/*
	A	:	PB10
	B	:	PB4
	C	:	PB5
	D	:	PA10
*/
uint8_t DEBOUNCE_INTERVAL = 200;
extern u16u8_t registerFrame[200];

void Joystick_UpdateValue(JoystickStructureTypeDef* joystick,QEIStructureTypeDef* QEI)
{

	/*			Push Button			*/
	static uint16_t tempSTATE[4] = {1,1,1,1};
	static uint64_t lastTIME[4] = {0,0,0,0};
	static uint64_t SUMX;
	static uint64_t SUMY;
	SUMX = 0;
	SUMY = 0;

	static uint64_t currentTIME;
	currentTIME = HAL_GetTick();
	/* Update STATE Value */

//
    if (!tempSTATE[A] && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) && (currentTIME - lastTIME[A] > DEBOUNCE_INTERVAL))
    {
        joystick->PIN[A] = 1;
        lastTIME[A] = currentTIME;
    }
    else joystick->PIN[A] = 0;
    tempSTATE[A] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);

    // Check button B
    if (!tempSTATE[B] && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4) && (currentTIME - lastTIME[B] > DEBOUNCE_INTERVAL))
    {
        joystick->PIN[B] = 1;
        lastTIME[B] = currentTIME;
    }
    else joystick->PIN[B] = 0;
    tempSTATE[B] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4);

    // Check button C
    if (!tempSTATE[C] && HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5) && (currentTIME - lastTIME[C] > DEBOUNCE_INTERVAL))
    {
        joystick->PIN[C] = 1;
        lastTIME[C] = currentTIME;
    }
    else joystick->PIN[C] = 0;
    tempSTATE[C] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5);

    // Check button D
    if (!tempSTATE[D] && HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10) && (currentTIME - lastTIME[D] > DEBOUNCE_INTERVAL))
    {
        joystick->PIN[D] = 1;
        lastTIME[D] = currentTIME;
    }
    else joystick->PIN[D] = 0;
    tempSTATE[D] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10);



	/*			Joy			*/
	for(uint8_t i = 0 ; i < 100 ; i ++)
	{
		SUMX += joystick->XYBuffer[2*i];
		SUMY += joystick->XYBuffer[(2*i)+1];
	}

	joystick->X = SUMX/100;
	joystick->Y = SUMY/100;


}
