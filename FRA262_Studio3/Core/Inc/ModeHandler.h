/*
 * ModeHandler.h
 *
 *  Created on: Apr 27, 2024
 *      Author: emper
 */

#ifndef INC_MODEHANDLER_H_
#define INC_MODEHANDLER_H_

#include "Joystick.h"
#include "Encoder.h"
#include "Controller.h"
#include "main.h"

void Jog_mode(JoystickStructureTypeDef *joystick, QEIStructureTypeDef *QEI);
void Point_mode(PIDStructureTypeDef *PID , QEIStructureTypeDef *QEI,float setpoint);
void Motor_Control(int32_t cmd);




#endif /* INC_MODEHANDLER_H_ */