/*
 * Trajectory.c
 *
 *  Created on: Apr 29, 2024
 *      Author: emper
 */

#include "main.h"
#include "TrapezoidalTrajectory.h"

float tol = 0.005;
float t_acc = 0.275; // USE 1375 [mm/s^2]
uint8_t CASE;

enum
{
	TRIANGLE,TRAPEZOID,NONE
};

enum
{
	READY,WORKING
};

//void Trajectory_Init(TrajectoryTypeDef *Traject , float v_max , float a_max , float t_all)
//{
//	Traject->Velocity = v_max;
//	Traject->Acceleration = a_max;
//	Traject->AccTime = Traject->Velocity/Traject->Acceleration;
//	Traject->AllTime = t_all;
//
//	//	Traject->AccelerationTime = t_acc;
//	//	Traject->MaximumAcceleration = Traject->MaximumVelocity/ Traject->AccelerationTime;
//}
//
//void TrapezoidalTrajectory_Calculator(TrajectoryTypeDef *Traject , float initPos , float finalPos)
//{
//	if(Traject->FLAG == READY){
//		Traject->AllTime = ((fabs(finalPos - initPos)-Traject->MaximumVelocity*Traject->AccelerationTime)/Traject->MaximumVelocity) + Traject->AccelerationTime;
//		if (2*Traject->AccelerationTime >= Traject->AllTime)
//		{
//			Traject->CASE = TRIANGLE;
//			Traject->Time = 0;
//			Traject->AllTime = 2*Traject->AccelerationTime;
//		}
//		else
//		{
//			Traject->CASE = TRAPEZOID;
//			Traject->InitialPosition = initPos;
//			Traject->FinalPosition = finalPos;
//			Traject->Time = 0;
//		}
//		Traject->FLAG = WORKING;
//	}
//}
//
//void TrapezoidalTrajectory_Generator(TrajectoryTypeDef *Traject)
//{
//	if(Traject->FLAG != WORKING) return 0;
//
//	float s = Traject->FinalPosition - Traject->InitialPosition;		// Init Distance
//	uint8_t dir = 1;
//	if(s < 0)	dir = -1;
//
//	if(Traject->CASE == TRAPEZOID)
//	{
//		if(Traject->Time <= Traject->AccTime)
//		{
//			Traject->AccelerationSetpoint = dir * Traject->Acceleration;
//			Traject->VelocitySetpoint = dir * Traject->Acceleration * Traject->Time;
//			Traject->PositionSetpoint = Traject->InitialPosition + ( dir * (0.5 * Traject->Acceleration* powf(Traject->Time,2)) );
//		}
//		else if(Traject->AccTime < Traject->Time && Traject->Time < (Traject->AllTime - Traject->AccTime))
//		{
//			Traject->AccelerationSetpoint = 0;
//			Traject->VelocitySetpoint = dir * Traject->Acceleration*Traject->AccTime;
//			Traject->PositionSetpoint = Traject->InitialPosition +  (dir * (0.5 * Traject->Acceleration * powf(Traject->AccTime,2)) + Traject->Acceleration * Traject->AccTime*(Traject->Time - Traject->AccTime));
//		}
//		else if (((Traject->AllTime - Traject->AccTime) <= Traject->Time) && (Traject->Time <= Traject->AllTime))
//		{
//			Traject->AccelerationSetpoint = -dir * Traject->Acceleration;
//			Traject->VelocitySetpoint = dir * Traject->Acceleration*(Traject->AllTime - Traject->Time);
//			Traject->PositionSetpoint = Traject->InitialPosition + dir * (Traject->Acceleration * Traject->AllTime + Traject->Acceleration*Traject->AccTime*Traject->AllTime - Traject->Acceleration * powf(Traject->Acceleration,2)-0.5*Traject->Acceleration*powf(Traject->Time,2)+powf(Traject->AllTime,2));
//		}
//	}
//
//	Traject->Time +=0.001;
//}



