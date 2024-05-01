/*
 * Trajectory.c
 *
 *  Created on: Apr 29, 2024
 *      Author: emper
 */

#include "main.h"
#include "Trajectory.h"

float tolerance = 0.005;
void QuinticTrajectory_Init(TrajectoryTypeDef *Traject , float v_max)
{
	Traject->MaximumVelocity = v_max;
}

void QuinticTrajectory_Calculator(TrajectoryTypeDef *Traject ,float initPos , float finalPos,float)
{
	if(fabs(initPos - finalPos) > tolerance)
	{
		float distance = finalPos - initPos;
		float a[6];
		a[0] = initPos;
		a[1] = 0;
		a[2] = 0;
		a[3] = 10.0*distance/powf(totalTime,3);
	}
}

void QuinticTrajectory_Generation(TrajectoryTypeDef *Trajectory , float initial_pos , float final_pos)
{
	if(initial_pos != final_pos)
	{
		float distance = final_pos - initial_pos;
//		static float a0 =
	}
}

//void
