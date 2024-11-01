/*
 * QuinticTrajectory.c
 *
 *  Created on: May 2, 2024
 *      Author: emper
 */

#include "QuinticTrajectory.h"


enum
{
	READY,CALCULATE,WORKING,FINISH
}state;

float period = 0.001;

void QuinticTrajectory_Init(QuinticTypeDef *q)
{
	q->STATE = READY;
	q->Pi = 0;
	q->Pf = 0;
	q->t = 0;
	q->tf = 0;
	q->Position = 0;
	q->Velocity = 0;
	q->Acceleration = 0;

}

void QuinticTrajectory_Generator(QuinticTypeDef *q, float pi ,float pf , float tf)
{
	switch(q->STATE)
	{
	case READY:
//		if(q->Pi != q->Pf) q->STATE = CALCULATE;
		q->STATE = CALCULATE;
		break;
	case CALCULATE:
		q->t = 0;

		q->Pi = pi;
		q->Pf = pf;
		q->tf = tf;

		float s = pf - pi;
		/*Coefficient Calculated*/
		q->c[0] = q->Pi;
		q->c[1] = 0;
		q->c[2] = 0;
		q->c[3] = 10.0*s/powf(q->tf,3);
		q->c[4] = -15.0*s/powf(q->tf,4);
		q->c[5] = 6.0*s/powf(q->tf,5);

		q->STATE = WORKING;
		break;

	case WORKING:
		q->Position = q->c[0] +
						q->c[1]*q->t + q->c[2]*powf(q->t,2) +
						q->c[3]*powf(q->t,3) +
						q->c[4]*powf(q->t,4) +
						q->c[5]*powf(q->t,5);

		q->Velocity = q->c[1] + (float)2*q->c[2]*q->t + (float)3*q->c[3]*powf(q->t,2) + (float)4*q->c[4]*powf(q->t,3) + (float)5*q->c[5]*powf(q->t,4);
		q->Acceleration = 2*q->c[2] + 6*q->c[3]*q->t + 12*q->c[4]*powf(q->t,2) + 20*q->c[5]*powf(q->t,3);
		q->t += period;
		if(q->t >= tf)
		{
			q->Position = q->Pf;
//			q->Velocity = 0;
//			q->Acceleration =0;
			q->STATE = FINISH;
		}
		break;

	case FINISH:
		q->Velocity = 0;
		q->Acceleration = 0;
		q->Pi = q->Pf;
		break;
	}
}

void QuinticTrajectory_SetReady(QuinticTypeDef *q)
{
	q->STATE = READY;
}
