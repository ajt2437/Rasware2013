#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>

tADC *adc[3];

void initIRSensor(void) {
    adc[0] = InitializeADC(PIN_E1); //leftIR IR
    adc[1] = InitializeADC(PIN_E2); //centerIR IR
    adc[2] = InitializeADC(PIN_E3); //rightIR IR
}

void IRSensorCheck(void) {
	
}
void IRSensorFigure8(void) {
	
	float leftIR = ADCRead(adc[0]);
	float centerIR = ADCRead(adc[1]);
	float rightIR = ADCRead(adc[2]);
	int prev_state = 0;
	if (centerIR < 0.2f && centerIR > 0.1f)									//if center = far
		//then go straight slow
		motorSet(0.3,0.3);
/*
	else if (centerIR > 0.4f && centerIR < 0.5f) {						//if center = perfect
		if (prev_state == 0) {							//if previous state = left
			//then turn right fast and change prev_state = right
			motorSet(0.4, -0.4);
		}
		else if (prev_state == 1) {					//if previous state = right
		//then turn left fast and prev_state = left
			motorSet(-0.4, 0.4);
		}
		prev_state = !prev_state;
	}
*/
	else if (rightIR > 0.5f && rightIR < 0.6f)							//if right = perfect
		//then go straight slow
		motorSet(0.1, 0.1);
	
	else if (rightIR < 0.5f && rightIR > 0.4f)							//if right = little far
		//then turn right slow
		motorSet(rightIR, -0.1);
	
	//else if (rightIR > 0.6f && rightIR < 0.8f)							//if right = little close
		//then turn left slow
		//motorSet(-rightIR, 0.1);
			
	//else if (rightIR > 0.9f)																//if right = too close
		//then turn left fast
		//motorSet(-rightIR, 0.3);
	/*
	else if(centerIR < 0.4f && rightIR < 0.5f) //if center = little far and right = perfect
		//then go straight fast
		motorSet(0.5, 0.5);
		
	else if (leftIR < 0.5f) 							//if left = perfect
		//then go straight slow
		motorSet(0.2, 0.2);
		
	else if (leftIR < 0.4f)								//if left = little far
		//then turn left slow
		motorSet(-0.2, 0.2);
		
	else if (leftIR < 0.7f)								//if left = little close
		//then turn right slow
		motorSet(0.2, -0.2);
		
	else if (leftIR < 0.8f)								//if left = too close
		//then turn rightIR fast
		motorSet(0.5, -0.5);
		
	else if (centerIR < 0.4f && leftIR < 0.5f) //if center = little far and left = perfect				
		//then go straight fast
		motorSet(0.5, 0.5);

*/
	else 
		//then go straight
		motorSet(0.2, 0.2);

	Printf(
            "IR values:  %1.3f  %1.3f  %1.3f  %1.3f\r",
            ADCRead(adc[0]),
            ADCRead(adc[1]),
            ADCRead(adc[2])
            );
}
