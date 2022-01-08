#include "encoder.h"

volatile uint16_t pulse_count;
volatile uint16_t positions;

uint32_t last_press = 0;
uint8_t debounce = 20;
uint8_t button = 0;

extern bool menu_open;

void QE_Initialize() {
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
}

void QE_CheckPosition() {
	pulse_count = TIM1->CNT;
	positions = pulse_count / 4;
	if (menu_open) {
		OpenMenu();
	}
}

void SwitchHandler() {
	if (HAL_GetTick() - last_press > debounce) {
		if (!menu_open) {
			OpenMenu();
		} else if (menu_open) {
			if (positions % 3 == 0) {
//				SetSoilMoistureScreen();
			} else if (positions % 3 == 1) {
//				RunPump();
			} else if (positions % 3 == 2) {
				CloseMenu();
			}
		}
		button++;
		last_press = HAL_GetTick();
	}
}
