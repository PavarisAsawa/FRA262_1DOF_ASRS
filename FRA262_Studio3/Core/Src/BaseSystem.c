/*
 * BaseSytem.c
 *
 *  Created on: May 1, 2024
 *      Author: ponpon
 */
#include <BaseSystem.h>

extern State status;
extern ShelvePosition shelve;
extern GetValue Value;
extern STATE;
extern QEIStructureTypeDef QEI;
extern float KFoutput[3];

float safePush = 6.5;

void Heartbeat(){
	static uint64_t timestamp = 0;
	  if(HAL_GetTick() >= timestamp)
	  {
		  timestamp += 200;
		  registerFrame[0x00].U16 = 22881;
	  }
}

void Routine(QEIStructureTypeDef *QEI , JoystickStructureTypeDef *joy){
	static uint64_t timestamp2 = 0;
	if(HAL_GetTick() >= timestamp2 && registerFrame[0x00].U16 == 18537) //ส่งค่าพวกนี้หลังจาก BaseSytem อ่าน Heartbeat ทุกๆ 200 ms
	{
	timestamp2 += 200;

	//Check Lead
	if(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)) registerFrame[0x04].U16 = 0b0010;
	else if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)) registerFrame[0x04].U16 = 0b0001;
	else registerFrame[0x04].U16 = 0b0000;

	registerFrame[0x10].U16 = status.Z_Status; //Z-axis Moving Status
	registerFrame[0x11].U16 = (int16_t)((QEI->LinearPosition - (int16_t)(QEI->HomePosition))  * 10); //Z-axis Actual Position = 19 ค่าจริง*10
	registerFrame[0x12].U16 = (uint16_t)(fabs(KFoutput[1] * 10)); //Z-axis Actual Speed = 20
	registerFrame[0x13].U16 = (uint16_t)(fabs(KFoutput[2] * 10)); //Z-axis Acceleration = 21
	registerFrame[0x40].U16 = (int16_t)((joy->Xpos)*10); //X-axis Actual Position = 2

		if(registerFrame[0x02].U16 == 0b0000)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, RESET);
			status.VacuumState = 0; //Off
		}
		else if(registerFrame[0x02].U16 == 0b0001)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, SET);
			status.VacuumState = 1;
		}

		if(registerFrame[0x03].U16 == 0b0000)
		{
			SolenoidPull();
			status.GripperState = 0; //Backward
		}
		else if(registerFrame[0x03].U16 == 0b0001)
		{
			SolenoidPush();
			status.GripperState = 1; //Forward
		}
	}
}
void VacuumOn_Off(){ // อ่านค่า Vacuum จากการกดปุ่มที่ BaseSytem
	if(registerFrame[0x02].U16 == 0b0000){
		status.VacuumState = 0; //Off
	}
	if(registerFrame[0x02].U16 == 0b0001){
		status.VacuumState = 1; //On
		}
}

void Gripper_Movement(){ // อ่านค่า Gripper จากการกดปุ่มที่ BaseSytem
	if(registerFrame[0x03].U16 == 0b0000){
		status.GripperState = 0; //Backward
		}
	if(registerFrame[0x03].U16 == 0b0001){
		status.GripperState = 1; //Forward
			}
}

void Set_Shelves(){ //Setting Shelve Position
		status.Z_Status = 1;
		registerFrame[0x10].U16 = status.Z_Status; // z-axis update z-xis moving status to "set shelves"

		//Joggig for set shelve

		registerFrame[0x23].U16 = shelve.ShelvePosition_1; // ค่า Shelve ที่ต้องส่งให้ BaseSytem
		registerFrame[0x24].U16 = shelve.ShelvePosition_2;
		registerFrame[0x25].U16 = shelve.ShelvePosition_3;
		registerFrame[0x26].U16 = shelve.ShelvePosition_4;
		registerFrame[0x27].U16 = shelve.ShelvePosition_5;
		status.Z_Status = 0;
		// reset z-axis moving state after finish Jogging
		//if (Finish Jogging)
		if (status.reset == 1){ //if reset state == 1 จะทำการรีเซ็ตระบบให้กดทุกอย่างได้เหมือนเดิม
		status.reset = 0; //ไว้เช็คว่าเข้า condition มั้ย
		registerFrame[0x01].U16 = 0;

		status.Z_Status = 0; // z-axis reset BaseSystem status
		registerFrame[0x10].U16 = status.Z_Status;
		}

}
void GetGoalPoint(){
	//if(registerFrame[0x01].U16 == 8){ // if run point mode
		Value.GoalPoint = (registerFrame[0x30].U16)/10 ; //Get Goal point from BaseSytem(Point Mode) that we pick/write After pressing Run Button
		 //ค่าที่ได้จาก BaseSytem จะได้ค่าที่เรากรอก*10 ดังนั้นต้องหาร10 ถึงจะได้ค่าจริงที่เรากรอก
}

void RunPointMode(){
	//if(registerFrame[0x01].U16 == 8){ //if run point mode
		status.Z_Status = 16;
		registerFrame[0x10].U16 = status.Z_Status; //update Z Status "Go Point"

		//going to point (use Goal point(0x30) for target z-axis position)
		//if (Gripper at GoalPoint){
		if (status.reset == 1){ //if reset state == 1 จะทำการรีเซ็ตระบบให้กดทุกอย่างได้เหมือนเดิม
		status.reset = 0;
		registerFrame[0x01].U16 = 0; //Reset BaseSystem Status
		status.Z_Status = 0;
		registerFrame[0x10].U16 = status.Z_Status; // reset z-axis moving state after finish jogging

		//Z.position = registerFrame[0x21].U16;
		}
		}

void SetHome(){
	if(registerFrame[0x01].U16 == 2){ //BaseSystem Status "Home"
		status.Z_Status = 2;
		registerFrame[0x10].U16 = status.Z_Status; // update Z-axis moving status "Home"

		//Homing
		//if (Gripper at HomePoint){
		if (status.reset == 1){ //if reset state == 1 จะทำการรีเซ็ตระบบให้กดทุกอย่างได้เหมือนเดิม
		status.reset = 0;
		registerFrame[0x01].U16 = 0; //reset Base System Status

		status.Z_Status = 0;
		registerFrame[0x10].U16 = status.Z_Status; // reset z-axis moving state after finish homing
		}
	}
}

void GetPick_PlaceOrder(JoystickStructureTypeDef *joy){
	if(registerFrame[0x01].U16 == 4){ // after pressing run button on Jogmode (before running)
		Value.PickOrder = registerFrame[0x21].U16 ; // ค่าชั้นที่ต้อง Pick from BaseSystem
		Value.PlaceOrder = registerFrame[0x22].U16 ;// ค่าชั้นที่ต้อง Place from BaseSystem

		Value.Pick[0] = Value.PickOrder / 10000;                     // Most significant digit (ten-thousands place)
		Value.Pick[1] = (Value.PickOrder % 10000) / 1000;            // Thousands place
		Value.Pick[2] = (Value.PickOrder % 1000) / 100;              // Hundreds place
		Value.Pick[3] = (Value.PickOrder % 100) / 10;                // Tens place
		Value.Pick[4] = Value.PickOrder % 10;

		Value.Place[0] = Value.PlaceOrder / 10000;                     // Most significant digit (ten-thousands place)
		Value.Place[1] = (Value.PlaceOrder % 10000) / 1000;            // Thousands place
		Value.Place[2] = (Value.PlaceOrder % 1000) / 100;              // Hundreds place
		Value.Place[3] = (Value.PlaceOrder % 100) / 10;                // Tens place
		Value.Place[4] = Value.PlaceOrder % 10;

		Value.PointPosition[0] = joy->PointPosition[0];
		Value.PointPosition[1] = joy->PointPosition[1];
		Value.PointPosition[2] = joy->PointPosition[2];
		Value.PointPosition[3] = joy->PointPosition[3];
		Value.PointPosition[4] = joy->PointPosition[4];

		Value.TargetPoint[0]	=	Value.Pick[0];
		Value.TargetPoint[1]	=	Value.Place[0];
		Value.TargetPoint[2]	=	Value.Pick[1];
		Value.TargetPoint[3]	=	Value.Place[1];
		Value.TargetPoint[4]	=	Value.Pick[2];
		Value.TargetPoint[5]	=	Value.Place[2];
		Value.TargetPoint[6]	=	Value.Pick[3];
		Value.TargetPoint[7]	=	Value.Place[3];
		Value.TargetPoint[8]	=	Value.Pick[4];
		Value.TargetPoint[9]	=	Value.Place[4];

		for(int i = 0; i < 10; i++)
		{
			if(Value.TargetPoint[i] == 1) Value.TargetPosition[i] = Value.PointPosition[0];
			else if(Value.TargetPoint[i] == 2) Value.TargetPosition[i] = Value.PointPosition[1];
			else if(Value.TargetPoint[i] == 3) Value.TargetPosition[i] = Value.PointPosition[2];
			else if(Value.TargetPoint[i] == 4) Value.TargetPosition[i] = Value.PointPosition[3];
			else if(Value.TargetPoint[i] == 5) Value.TargetPosition[i] = Value.PointPosition[4];
		}
		for(int i = 0; i < 10; i++)
		{
			static float tempPos = 0;
			if(i%2 == 1)
			{
				tempPos = Value.TargetPosition[i];
				Value.TargetPosition[i] = tempPos+safePush;
			}
		}
	}
		//ค่าที่ได้จะเรียงติดกัน ex.ถ้าเซ็ตค่าในUIชั้นแรกที่ต้อง Pick คือ ชั้น1-5 ตามลำดับ ค่าชั้นที่ต้องPick จะได้ 12345
}

void RunJogMode(){
	//if(registerFrame[0x01].U16 == 4){ //after pressing run button on Jogmode

		//Loop{
		//Pick
		status.Z_Status = 4;
		registerFrame[0x10].U16 = status.Z_Status; // go pick state

		//Going to Pick from Shelve 5 round(Use PickOder to do task)
		//When finish Pick from round(i) shelve --> Go Place

		//Place
		if (status.Place == 1){
			status.Z_Status = 8;
			registerFrame[0x10].U16 = status.Z_Status; // go place state

		}

		//Going to Place from Shelve 5 round(Use PlaceOder to do task)
		//When finish Place from round(i) shelve --> Return Pick
		//When Finish Place round 5 --> Out of Loop
		//}

		//if(All Pick&Place == Finish){
		if (status.reset == 1){ //if reset state == 1 จะทำการรีเซ็ตระบบให้กดทุกอย่างได้เหมือนเดิม
		status.reset = 0;
		registerFrame[0x01].U16 = 0;

		status.Z_Status = 0;
		registerFrame[0x10].U16 = status.Z_Status; // after finish jogging

		}
}



