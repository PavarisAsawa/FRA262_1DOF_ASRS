/*
 * Controller.c
 *
 *  Created on: Apr 22, 2024
 *      Author: emper
 */

#include "Encoder.h"
#include "Controller.h"
#include "main.h"

uint32_t Saturation = 1000;

void PIDPositionController_Init(PIDStructureTypeDef* PID,float Kp ,float Ki , float Kd)	// Initialize PID Variable
{
	PID->Kp = Kp;
	PID->Ki = Ki;
	PID->Kd = Kd;
	PID->Error[0] = 0;
	PID->Error[1] = 0;
	PID->Error[2] = 0;
	PID->Command = 0;
	PID->Command_1 = 0;
}

void PIDController_Command(PIDStructureTypeDef* PID,QEIStructureTypeDef* Feedback,float setpoint)
{
	PID->Error = setpoint - Feedback->LinearPosition;
	/* y[n] = y[n-1] + A0 * x[n] + A1 * x[n-1] + A2 * x[n-2]
	A0 = Kp + Ki + Kd;
	A1 = -Kp - (2 * Kd);
	A2 = Kd; */

	PID->Command = PID->Command_1 +
			((PID->Kp + PID->Ki + PID->Kd)*PID->Error[0])
			- ((PID->Kp+(2*PID->Kd))*PID->Error[1])
			+ (PID->Kd*PID->Error[2]);
	// Implement PID Velocity Form Algorithm





	/* Update Variable */
	PID->Command_1 = PID->Command;
	PID->Error[2] = PID->Error[1];
	PID->Error[1] = PID->Error[0];
}