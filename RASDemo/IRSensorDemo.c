#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>

tADC *adc[2];

void initIRSensor(void) {
    adc[0] = InitializeADC(PIN_E1);
    adc[1] = InitializeADC(PIN_E2);
}

void IRSensorDemo(void) {
		float leftIR = ADCRead(adc[0]);
		float rightIR = ADCRead(adc[1]);
        
    Printf("leftIR values: %d\t", (int)(1000 * leftIR));
		Printf("rightIR value: %d\t", (int)(1000 * rightIR));
    
  
    Printf("\n");
}
