#include "RASDemo.h"

#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>

tBoolean led_on;

void blink(void) {
    SetPin(PIN_F1, led_on);

    led_on = !led_on;
}

int main(void) {  
    
    InitializeMCU();
    CallEvery(blink, 0, 0.25f);

    while(1) {
        
 
    }
}
