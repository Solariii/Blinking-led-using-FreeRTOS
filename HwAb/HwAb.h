#ifndef __HWAB_H__
#define __HWAB_H__

#include <stdint.h>
#include "interfaces.h"

void Clk_Init(void);
void PushButton_Init(void);
uint8_t PushButton_Read(void);
void RGB_LED_Init(void);
void RGB_LED_Set(RGB_LED_Color color);

#endif // __HWAB_H__
