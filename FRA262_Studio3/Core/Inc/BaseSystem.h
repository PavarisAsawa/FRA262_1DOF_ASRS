/*
 * BaseSystem.h
 *
 *  Created on: Apr 28, 2024
 *      Author: ponpon
 */

#ifndef INC_BASESYSTEM_H_
#define INC_BASESYSTEM_H_


#include <ModBusRTU.h>
#include "Encoder.h"
#include "Joystick.h"
#include "Controller.h"
#include "main.h"
#include "ModeHandler.h"

extern ModbusHandleTypedef hmodbus;
extern u16u8_t registerFrame[200];

typedef struct {
	uint16_t speed;
	uint16_t position;
	uint16_t acce;
}Z_Value;


typedef struct {
	uint16_t GoalPoint;
	uint16_t PickOrder;
	uint16_t PlaceOrder;
	uint16_t Pick[5];
	uint16_t Place[5];
	float PointPosition[5];
	float TargetPoint[10];
	float TargetPosition[10];

}GetValue;

typedef struct {
	uint16_t HeartFlag;
	uint16_t VacuumState;
	uint16_t GripperState;
	int Z_Status;
	int reset;
	int StateFrame;
	int Place;
}State;

typedef struct {
	uint16_t ShelvePosition_1;
	uint16_t ShelvePosition_2;
	uint16_t ShelvePosition_3;
	uint16_t ShelvePosition_4;
	uint16_t ShelvePosition_5;
}ShelvePosition;

void Heartbeat();
void Routine(QEIStructureTypeDef *qei,JoystickStructureTypeDef *joy);
void VacuumOn_Off();
void Gripper_Movement();
void Set_Shelves();
void GetGoalPoint();
void RunPointMode();
void SetHome();
void GetPick_PlaceOrder(JoystickStructureTypeDef *joy);
void RunJogMode();

#endif /* INC_BASESYSTEM_H_ */
