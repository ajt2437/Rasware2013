#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/motor.h>

tMotor *motors[2];

void initMotors(void) {
    motors[0] = InitializeServoMotor(PIN_B0, false); //left motor
    motors[1] = InitializeServoMotor(PIN_B1, false); //right motor
	
    SetMotor(motors[0], 0);
    SetMotor(motors[1], 0);
}

void motorDemo(float leftSpeed, float rightSpeed) {
		SetMotor(motors[0], leftSpeed); //left motor
		SetMotor(motors[1], rightSpeed); //right motor
}
