#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>

tADC *adc[3];

void initIRSensor(void) {
    adc[0] = InitializeADC(PIN_D0); //leftIR IR
    adc[1] = InitializeADC(PIN_D1); //centerIR IR
    adc[2] = InitializeADC(PIN_D2); //rightIR IR
}

void IRSensorDemo(void) {
	
	float leftIR = ADCRead(adc[0]);
	float centerIR = ADCRead(adc[1]);
	float rightIR = ADCRead(adc[2]);
	int prev_state = 0;
	if (centerIR == 0.3f)									//if center = far
		//then go straight slow
		motorDemo(0.2,0.2);
	
	else if (centerIR == 0.5f) {						//if center = perfect
		if (prev_state == 0) {							//if previous state = left
			//then turn right fast and change prev_state = right
			motorDemo(0.5, -0.5);
			prev_state = 1;
		}
		else if (prev_state == 1) {					//if previous state = right
		//then turn left fast and prev_state = left
			motorDemo(-0.5, 0.5);
			prev_state = 0;
		}
	}
	else if (rightIR == 0.5f)							//if right = perfect
		//then go straight slow
		motorDemo(0.2, 0.2);
	
	else if (rightIR == 0.4f)							//if right = little far
		//then turn right slow
		motorDemo(0.2, -0.2);
	
	else if (rightIR == 0.7f)							//if right = little close
		//then turn left slow
		motorDemo(-0.2, 0.2);
			
	else if (rightIR == 0.8f)							//if right = too close
		//then turn left fast
		motorDemo(-0.5, 0.5);
		
	else if(centerIR == 0.4f && rightIR == 0.5f) //if center = little far and right = perfect
		//then go straight fast
		motorDemo(0.5, 0.5);
		
	else if (leftIR == 0.5f) 							//if left = perfect
		//then go straight slow
		motorDemo(0.2, 0.2);
		
	else if (leftIR == 0.4f)								//if left = little far
		//then turn left slow
		motorDemo(-0.2, 0.2);
		
	else if (leftIR == 0.7f)								//if left = little close
		//then turn right slow
		motorDemo(0.2, -0.2);
		
	else if (leftIR == 0.8f)								//if left = too close
		//then turn rightIR fast
		motorDemo(0.5, -0.5);
		
	else if (centerIR == 0.4f && leftIR == 0.5f) //if center = little far and left = perfect				
		//then go straight fast
		motorDemo(0.5, 0.5);

	else 
		//then go straight
		motorDemo(0.5, 0.5);
}
