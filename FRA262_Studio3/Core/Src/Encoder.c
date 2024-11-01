/*
 * Encoder.c
 *
 *  Created on: Apr 10, 2024
 *      Author: emper
 */

#include "Encoder.h"
#include "main.h"

extern uint64_t micros;				// Find time from main.c
uint16_t resolution = 8192; 		// pulse / revolution
uint8_t lead = 16;					// Lead of Ball screw = 16 mm

void QEIEncoder_Init(QEIStructureTypeDef* QEIdata,TIM_HandleTypeDef* Encoder_tim)
{
	QEIdata->EncoderTIM = Encoder_tim;
	HAL_TIM_Encoder_Start(QEIdata->EncoderTIM, TIM_CHANNEL_ALL);		// Initialize Encoder Timer
	QEIdata->HomePosition = 64.85;
}

void QEIEncoder_Update(QEIStructureTypeDef* QEIdata,TIM_HandleTypeDef* EncoderTIM ,uint64_t current_time)
{
	static float tempVel[2] = {0};			// For Estimate Acceleration

	QEIdata->TimeStamp[0] = current_time; 						// index[0] = new time
	QEIdata->Position[0] = __HAL_TIM_GET_COUNTER(EncoderTIM);	// index[0] = new Position

	int64_t diffPosition = QEIdata->Position[0] - QEIdata->Position[1];			// position [pulse]
	float diffTime = (QEIdata->TimeStamp[0]-QEIdata->TimeStamp[1]) * 0.000001; 	// time [seconds]

	if(diffPosition > 2147483648)  diffPosition -= 4294967296;		// For unwrap
	if(diffPosition < -2147483648) diffPosition +=  4294967296;

	QEIdata->AngularVelocity	=	(diffPosition*60)/(diffTime*resolution);	//	Angular Velocity [RPM]
	QEIdata->LinearPosition		+=	(diffPosition*16.0)/resolution;				//	Linear	Position [mm]
	QEIdata->LinearVelocity		=	(QEIdata->AngularVelocity * 16)/60.0;		//	Linear	Velocity [mm/s]
	tempVel[0]					=	QEIdata->LinearVelocity;
	QEIdata->LinearAcceleration	=	(tempVel[0] - tempVel[1])/diffTime;			// Linear	Acceleration [mm/s^2]

	//Updata NEW[0] to OLD[1] Value
	QEIdata->TimeStamp[1]	=	QEIdata->TimeStamp[0];
	QEIdata->Position[1]	=	QEIdata->Position[0];
	tempVel[1]				=	tempVel[0];
}

void QEIEncoder_SetHome(QEIStructureTypeDef* QEI)
{
	QEI->LinearPosition = QEI->HomePosition;//	Set Zero Position
}
