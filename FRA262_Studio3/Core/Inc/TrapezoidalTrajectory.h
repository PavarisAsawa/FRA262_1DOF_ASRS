/*
 * Trajectory.h
 *
 *  Created on: Apr 29, 2024
 *      Author: emper
 */

#ifndef INC_TRAPEZOIDALTRAJECTORY_H_
#define INC_TRAPEZOIDALTRAJECTORY_H_

#include "main.h"

typedef struct _TrajectoryStructure{
	float InitialPosition;
	float FinalPosition;


	float Velocity;
	float Acceleration;

	float AccTime;
	float AllTime;

	float PositionSetpoint;
	float VelocitySetpoint;
	float AccelerationSetpoint;
	float Time;

	uint8_t FLAG;
	uint16_t CASE;
}TrajectoryTypeDef;

void Trajectory_Init(TrajectoryTypeDef *Traject , float v_max , float a_max , float t_all);
void TrapezoidalTrajectory_Calculator(TrajectoryTypeDef *Traject , float initPos , float finalPos);
void TrapezoidalTrajectory_Generator(TrajectoryTypeDef *Traject);


#endif /* INC_TRAPEZOIDALTRAJECTORY_H_ */
