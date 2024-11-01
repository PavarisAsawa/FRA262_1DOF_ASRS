/*
 * Controller.c
 *
 *  Created on: Apr 22, 2024
 *      Author: emper
 */

#include "Encoder.h"
#include "Controller.h"
#include "QuinticTrajectory.h"
#include "main.h"

uint32_t Saturation = 1000;
extern TIM_HandleTypeDef htim4;
float tolerance = 0.005;

void PIDController_Init(PIDStructureTypeDef* PID,float FWKp ,float FWKi , float FWKd, float BWKp ,float BWKi , float BWKd)	// Initialize PID Variable
{
	PID->FWKp = FWKp;
	PID->FWKi = FWKi;
	PID->FWKd = FWKd;

	PID->BWKp = BWKp;
	PID->BWKi = BWKi;
	PID->BWKd = BWKd;


	PID->Error[0] = 0;
	PID->Error[1] = 0;
	PID->Error[2] = 0;
	PID->Command = 0;
	PID->Command_1 = 0;
}

void Motor_Control(int32_t cmd)
{
	if(cmd > 0) HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, SET);
	else if (cmd < 0)  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, RESET);

	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,fabs(cmd));
}


void PIDControllerPosition_Command(PIDStructureTypeDef* PID,QEIStructureTypeDef* Feedback,float setpoint)
{
	PID->Error[0] = setpoint - Feedback->LinearPosition;
	/* y[n] = y[n-1] + A0 * x[n] + A1 * x[n-1] + A2 * x[n-2]*/

	if (fabs(PID->Error[0]) > tolerance)
	{
		if (PID->Error[0] >= 0)
		 {
			PID->Command = PID->Command_1 +
					((PID->FWKp + PID->FWKi + PID->FWKd)*PID->Error[0])
					- ((PID->FWKp+(2*PID->FWKd))*PID->Error[1])
					+ (PID->FWKd*PID->Error[2]);
		 }
		else if (PID->Error[0] < 0)
		{
			PID->Command = PID->Command_1 +
					((PID->BWKp + PID->BWKi + PID->BWKd)*PID->Error[0])
					- ((PID->BWKp+(2*PID->BWKd))*PID->Error[1])
					+ (PID->BWKd*PID->Error[2]);
		}
	}
	else PID->Command = 0;

	if(PID->Command >= 550) PID->Command = 550;
	else if (PID->Command <= -550) PID->Command = -550;
	// Implement PID Velocity Form Algorithm

	/* Update Variable */
	PID->Command_1 = PID->Command;
	PID->Error[2] = PID->Error[1];
	PID->Error[1] = PID->Error[0];
}

void PIDControllerVelocity_Command(PIDStructureTypeDef* PID,QEIStructureTypeDef* Feedback,float setpoint)
{
	PID->Error[0] = setpoint - Feedback->LinearVelocity;
	/* y[n] = y[n-1] + A0 * x[n] + A1 * x[n-1] + A2 * x[n-2] */

//    if (!((controller->u >= controller->u_max && ek > 0) || (controller->u <= -controller->u_max && ek < 0)))


		if (PID->Error[0] >= 0)
		 {
			PID->Command = PID->Command_1 +
					((PID->FWKp + PID->FWKi + PID->FWKd)*PID->Error[0])
					- ((PID->FWKp+(2*PID->FWKd))*PID->Error[1])
					+ (PID->FWKd*PID->Error[2]);
		 }
		else if (PID->Error[0] < 0)
		{
			PID->Command = PID->Command_1 +
					((PID->BWKp + PID->BWKi + PID->BWKd)*PID->Error[0])
					- ((PID->BWKp+(2*PID->BWKd))*PID->Error[1])
					+ (PID->BWKd*PID->Error[2]);
		}


	// Implement PID Velocity Form Algorithm

	if(PID->Command >= 1000) PID->Command = 1000;
	else if (PID->Command <= -1000) PID->Command = -1000;

	/* Update Variable */
	PID->Command_1 = PID->Command;
	PID->Error[2] = PID->Error[1];
	PID->Error[1] = PID->Error[0];
}

void PIDControllerCascade_Command(PIDStructureTypeDef *PIDposition , PIDStructureTypeDef *PIDvelocity ,QEIStructureTypeDef *QEI , float setpoint)
{
	PIDControllerPosition_Command(PIDposition, QEI, setpoint);
	PIDControllerVelocity_Command(PIDvelocity, QEI, PIDposition->Command);
}

void PIDControllerCascade_Command2(PIDStructureTypeDef *PIDposition , PIDStructureTypeDef *PIDvelocity ,QEIStructureTypeDef *QEI , float pf , float vf)
{
	PIDControllerPosition_Command(PIDposition, QEI, pf);
	PIDControllerVelocity_Command(PIDvelocity, QEI, PIDposition->Command + vf);
}

//void PIDControllerCascade_Trajectory(PIDStructureTypeDef *PIDposition , PIDStructureTypeDef *PIDvelocity ,QEIStructureTypeDef *QEI , QuinticTypeDef *Traject , float pf)
//{
//	QuinticTrajectory_Generator(Traject, Traject->Pi,pf,2);
//	PIDControllerPosition_Command(PIDposition, QEI, Traject->Position);
//	PIDControllerVelocity_Command(PIDvelocity, QEI, PIDposition->Command+Traject->Velocity);
//}
