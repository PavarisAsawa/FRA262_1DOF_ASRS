/*
 * Controller.h
 *
 *  Created on: Apr 22, 2024
 *      Author: emper
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "main.h"
#include "Encoder.h"

typedef struct _PIDStructure
{
	/*	Forward UP		*/
	float FWKp;			//	Kp
	float FWKi;			//	Ki
	float FWKd;			//	Kd

	/*	Backward DOWN	*/
	float BWKp;			//	Kp
	float BWKi;			//	Ki
	float BWKd;			//	Kd

	float Error[3];
	/*	[ 0 ] : Current Error
	 *	[ 1 ] : First Previous Error
	 *	[ 2 ] : Second Previous Error
	 */
	float Command;			//	Current Output
	float Command_1;		//	Previous Output

}PIDStructureTypeDef;

void PIDController_Init(PIDStructureTypeDef* PID,float FWKp ,float Ki , float FWKd, float BWKp ,float BWKi , float BWKd);
void PIDControllerPosition_Command(PIDStructureTypeDef* PID,QEIStructureTypeDef* Feedback , float setpoint);
void PIDControllerVelocity_Command(PIDStructureTypeDef* PID,QEIStructureTypeDef* Feedback , float setpoint);
void PIDControllerCascade_Command(PIDStructureTypeDef *PIDposition , PIDStructureTypeDef *PIDvelocity ,QEIStructureTypeDef *QEI , float setpoint);
void PIDControllerCascade_Command2(PIDStructureTypeDef *PIDposition , PIDStructureTypeDef *PIDvelocity ,QEIStructureTypeDef *QEI , float pf , float vf);

//void PIDControllerCascade_Trajectory(PIDStructureTypeDef *PIDposition , PIDStructureTypeDef *PIDvelocity ,QEIStructureTypeDef *QEI , TrajectoryTypeDef *Traject);


#endif /* INC_CONTROLLER_H_ */
