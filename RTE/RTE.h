#ifndef __RTE_H__
#define __RTE_H__

#include <stdint.h>
#include "interfaces.h"

void Rte_Send_RGB_LED_Color(RGB_LED_Color color);
RGB_LED_Color Rte_Read_RGB_LED_Color(void);
void Rte_Call_RGB_LED_Set(RGB_LED_Color color);
uint8_t Rte_Call_PushButton_Read(void);

#endif // __RTE_H__
