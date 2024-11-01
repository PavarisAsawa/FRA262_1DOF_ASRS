/*
 * KalmanFilter.h
 *
 *  Created on: May 27, 2024
 *      Author: emper
 */

#ifndef INC_KALMANFILTER_H_
#define INC_KALMANFILTER_H_

#include "arm_math.h"
#define DT 0.001f

// Model Matrix
extern float Ak[3][3];
extern float Bk[3][1];
extern float Ck[1][3];
extern float G[3][1];
extern float R;
extern float Q;

// Initial state and covariance
extern float x_est[3];
extern float P_est[3][3];

// Function prototypes
void kalman_predict(float x_est[3], float P_est[3][3], float A[3][3], float G[3][1], float Q);
void kalman_update(float x_est[3], float P_est[3][3], float C[1][3], float R, float z);



#endif /* INC_KALMANFILTER_H_ */
