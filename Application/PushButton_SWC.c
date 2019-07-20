#include "PushButton_SWC.h"
#include <stdint.h>
#include "interfaces.h"
#include "RTE.h"

RGB_LED_Color colors[6] = {red, blue, pink, green, yellow, sky};

void run_poll_pushbutton(void){
    static uint8_t color_index = 1;
    uint8_t PB_state = Rte_Call_PushButton_Read();
    if(PB_state == 0){
        Rte_Send_RGB_LED_Color(colors[color_index]);
        color_index = (color_index + 1) % 6;
    }
}
