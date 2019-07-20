#include "RTE.h"
#include <stdint.h>
#include "interfaces.h"
#include "HwAb.h"

RGB_LED_Color Rte_RGB_LED_Color = red;

void Rte_Send_RGB_LED_Color(RGB_LED_Color color){
    Rte_RGB_LED_Color = color;
}

RGB_LED_Color Rte_Read_RGB_LED_Color(void){
    return Rte_RGB_LED_Color;
}

void Rte_Call_RGB_LED_Set(RGB_LED_Color color){
    RGB_LED_Set(color);
}

uint8_t Rte_Call_PushButton_Read(void){
    return PushButton_Read();
}
