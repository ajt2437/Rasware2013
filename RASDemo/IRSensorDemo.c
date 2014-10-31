#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>

tADC *adc[2];

void initIRSensor(void) {
    adc[0] = InitializeADC(PIN_D0);
    adc[1] = InitializeADC(PIN_D1);
}

void IRSensorDemo(void) {
    
}
