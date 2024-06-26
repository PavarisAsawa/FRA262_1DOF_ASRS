/*
 * QuinticTrajectory.h
 *
 *  Created on: May 2, 2024
 *      Author: emper
 */

#ifndef INC_QUINTICTRAJECTORY_H_
#define INC_QUINTICTRAJECTORY_H_

#include "main.h"

typedef struct Quintic
{
	// define setpoint
	float Position;
	float Velocity;
	float Acceleration;

	// define constrain
//	float v;	// max v
//	float a;	// max a

	float t;	// time to calculate
	float tf;	// Final Time

	float Pi;	//init position
	float Pf;	//final position

	float c[6];	// Coefficient

	uint8_t FLAG;
	uint8_t STATE;

}QuinticTypeDef;

void QuinticTrajectory_Init(QuinticTypeDef *q);
void QuinticTrajectory_Generator(QuinticTypeDef *q, float pi ,float pf , float tf);
void QuinticTrajectory_SetReady(QuinticTypeDef *q);



#endif /* INC_QUINTICTRAJECTORY_H_ */
