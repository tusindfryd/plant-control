#ifndef INC_LAMP_H_
#define INC_LAMP_H_
#endif

#include "tim.h"
#include <stdint.h>

void Lamp_Initialize();
void Lamp_SetBrightness(uint8_t brightness_percent);
void Lamp_On_Off();
void Lamp_PID_Control(double setpoint);
