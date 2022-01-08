#include "encoder.h"

volatile uint16_t pulse_count;
volatile uint16_t positions;

uint32_t lastPress = 0;
uint8_t debounce = 20;
uint8_t button = 0;

void QE_Initialize() {
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
}

void QE_CheckPosition() {
	pulse_count = TIM1->CNT;
	positions = pulse_count / 4;
}

void switchHandler() {
	if (HAL_GetTick() - lastPress > debounce) {
		button++;
		lastPress = HAL_GetTick();
	}
}
