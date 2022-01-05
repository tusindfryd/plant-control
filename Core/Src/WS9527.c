/* WS9527 is hardcoded as ADC1 for simplicity */

#include "WS9527.h"

uint16_t WS9527_Reading;

void WS9527_Initialize() {
	HAL_ADC_Start_IT(&hadc1);
}

void WS9527_StartReadings() {
	HAL_ADC_Start_IT(&hadc1);
}

void WS9527_GetReadings(ADC_HandleTypeDef* hadc) {
	/* let's say that 100% is the reading of 2000 which *
	 * then would mean that 1% is reading divided by 20 *
	 *                                     (...roughly) */
	if(hadc->Instance == ADC1) {
		WS9527_Reading = HAL_ADC_GetValue(&hadc1) / 20;
	    }
}


