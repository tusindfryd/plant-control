#ifndef INC_WAVESHARE_9527_H_
#define INC_WAVESHARE_9527_H_
#endif

#include <stdint.h>
#include <float.h>
#include "adc.h"

float lerp(uint16_t v0, uint32_t v1, float t);
void WS9527_Initialize();
void WS9527_StartReadings();
void WS9527_GetReadings(ADC_HandleTypeDef *hadc);
