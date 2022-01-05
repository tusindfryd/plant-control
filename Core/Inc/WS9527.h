#ifndef INC_WAVESHARE_9527_H_
#define INC_WAVESHARE_9527_H_
#endif

#include <stdint.h>
#include "adc.h"

void WS9527_Initialize();
void WS9527_StartReadings();
void WS9527_GetReadings(ADC_HandleTypeDef* hadc);