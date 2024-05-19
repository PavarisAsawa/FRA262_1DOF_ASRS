/*
 * ModeHandler.h
 *
 *  Created on: Apr 27, 2024
 *      Author: emper
 */

#ifndef INC_MODEHANDLER_H_
#define INC_MODEHANDLER_H_

#include "Encoder.h"
#include "Controller.h"
#include "main.h"
#include "QuinticTrajectory.h"
#include "BaseSystem.h"
#include "Joystick.h"


typedef struct FLAG{

	uint8_t setHome;
	uint8_t setShelve;
	uint8_t Point;
	uint8_t Jog;
	uint8_t TrejectoryGen;
	uint8_t jogTIME;
}FlagTypeDef;

void SetShelve_mode(FlagTypeDef *flag,JoystickStructureTypeDef *joystick, QEIStructureTypeDef *QEI);
void Point_mode(FlagTypeDef *flag,PIDStructureTypeDef *PIDp , PIDStructureTypeDef *PIDv , QEIStructureTypeDef *QEI,QuinticTypeDef *quintic , float goal);
void SetHome_mode(FlagTypeDef *flag ,QEIStructureTypeDef *QEI);
void Jog_mode(FlagTypeDef *flag,PIDStructureTypeDef *PIDp , PIDStructureTypeDef *PIDv , QEIStructureTypeDef *QEI,QuinticTypeDef *quintic);

void SolenoidPush();
void SolenoidPull();
void SolenoidSuck(uint8_t trig);
//void





#endif /* INC_MODEHANDLER_H_ */
