#include "encoder.h"

volatile uint16_t pulse_count;
volatile uint16_t positions;

uint32_t last_press = 0;
uint8_t debounce = 20;
uint8_t button = 0;

extern bool menu_open;
extern double Lamp_Setpoint;
extern bool Lamp_PID_Control_On;

void QE_Initialize() {
	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
}

void QE_CheckPosition() {
	if (!menu_open && pulse_count != TIM1->CNT) {
		int8_t difference = TIM1->CNT - pulse_count;
		pulse_count = TIM1->CNT;
		positions = pulse_count / 4;
		Lamp_Setpoint = Lamp_Setpoint + difference / 4;
		Lamp_PID_Control_On = true;
	} else if (menu_open) {
		pulse_count = TIM1->CNT;
		positions = pulse_count / 4;
		OpenMenu();
	}
}

void SwitchHandler() {
	if (HAL_GetTick() - last_press > debounce) {
		if (!menu_open) {
			OpenMenu();
		} else if (menu_open) {
			if (positions % 2 == 0) {
				Lamp_On_Off();
			} else if (positions % 2 == 1) {
				CloseMenu();
			}
		}
		button++;
		last_press = HAL_GetTick();
	}
}
