#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/linesensor.h>

tLineSensor *gls;

void initGPIOLineSensor(void) {
    gls = InitializeGPIOLineSensor(PIN_B5, PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_E0, PIN_C6, PIN_C7);
}

void gpioLineSensorDemo(void) {
   
}
