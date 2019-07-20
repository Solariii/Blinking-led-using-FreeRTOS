#include "BlinkingLED_SWC.h"
#include <stdint.h>
#include "interfaces.h"
#include "RTE.h"

void run_blink_led(void){
    static uint8_t state = 0;
    switch(state){
        case 0:
            Rte_Call_RGB_LED_Set(Rte_Read_RGB_LED_Color());
            state = 1;
            break;
        case 1:
            Rte_Call_RGB_LED_Set(dark);
            state = 0;
            break;
    }   
}
