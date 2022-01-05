/* WS9527 is hardcoded as ADC1 for simplicity */

#include "WS9527.h"

uint16_t WS9527_Reading_ADC;
uint16_t WS9527_Reading;

void WS9527_Initialize() {
	HAL_ADC_Start_IT(&hadc1);
}

void WS9527_StartReadings() {
	HAL_ADC_Start_IT(&hadc1);
}

void WS9527_GetReadings(ADC_HandleTypeDef* hadc) {
	/* first we lerp everything out and then scale the result by 18  *
	 * that's because maximally moist soil gives the reading of 1800 *
	 * so 1% is the reading divided by 18                            */
	if (hadc->Instance == ADC1) {
		WS9527_Reading_ADC = (int)((1 - 0.001) * WS9527_Reading_ADC + 0.001 * HAL_ADC_GetValue(&hadc1));
		WS9527_Reading = WS9527_Reading_ADC / 18;
	}
}


