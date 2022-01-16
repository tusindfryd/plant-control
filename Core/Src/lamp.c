/* the lamp PWM channel hardcoded as timer 3, channel 3 for simplicity */

#include "lamp.h"

void Lamp_Initialize() {
	HAL_TIM_PWM_Start (&htim3, TIM_CHANNEL_3);
}

void Lamp_SetBrightness(uint8_t brightness_percent) {
	if (brightness_percent <= 100) {
	 __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, brightness_percent * 10);
	}
}

void Lamp_On_Off() {
	__HAL_TIM_GET_COMPARE(&htim3, TIM_CHANNEL_3) == 0 ? Lamp_SetBrightness(100) : Lamp_SetBrightness(0);
}
