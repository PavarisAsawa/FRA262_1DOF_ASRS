/*
 * Trajectory.h
 *
 *  Created on: Apr 29, 2024
 *      Author: emper
 */

#ifndef INC_TRAJECTORY_H_
#define INC_TRAJECTORY_H_

#include "main.h"

typedef struct _TrajectoryStructure{
	float InitialPosition;
	float FinalPosition;
	float MaximumVelocity;
	float MaximumAcceleration;

	float PositionSetpoint;
	float VelocitySetpoint;
}TrajectoryTypeDef;

void QuinticTrajectory_Init(TrajectoryTypeDef *Traject , float v_max);
void QuinticTrajectory_Calculator(TrajectoryTypeDef *Traject ,float initPos , float finalPos);

#endif /* INC_TRAJECTORY_H_ */