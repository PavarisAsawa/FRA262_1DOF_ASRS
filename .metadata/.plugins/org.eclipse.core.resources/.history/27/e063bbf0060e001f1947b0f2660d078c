/*
 * Encoder.h
 *
 *  Created on: Apr 10, 2024
 *      Author: emper
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_
#include "main.h"

typedef struct _QEIStructure
{
	uint64_t Position[2];
	uint64_t TimeStamp[2];
	float AngularVelocity;		// RPM
	float LinearAcceleration;	// [mm/s^2]
	float LinearVelocity;		// mm/s
	float LinearPosition;		// mm
	TIM_HandleTypeDef* EncoderTIM;	// Define Encoder Timer
}QEIStructureTypeDef;

void QEIEncoder_Init(QEIStructureTypeDef* QEIStructure ,TIM_HandleTypeDef* Encoder_tim);
void QEIEncoder_Update(QEIStructureTypeDef* QEIStructure ,TIM_HandleTypeDef* EncoderTIM ,uint64_t current_time);
void QEIEncoder_SetHome(QEIStructureTypeDef* QEIStructure);

#endif /* INC_ENCODER_H_ */
