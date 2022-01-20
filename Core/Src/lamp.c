/* the lamp PWM channel hardcoded as timer 3, channel 3 for simplicity */

#include "lamp.h"
#include "bh1750_config.h"

uint16_t BH1750_Reading;
double Lamp_Setpoint = 1000;

double Kp = 1.2;
double Ki = 0.0001;
double Kd = 0.05;

double previous_error = 0;
double integral = 0;
double derivative = 0;
double dt = 0.2;
double output = 0;
void Lamp_Initialize() {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
}

void Lamp_SetBrightness(uint8_t brightness_percent) {
	if (brightness_percent <= 100) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, brightness_percent * 10);
	}
}

void Lamp_On_Off() {
	__HAL_TIM_GET_COMPARE(&htim3, TIM_CHANNEL_3) == 0 ?
			Lamp_SetBrightness(100) : Lamp_SetBrightness(0);
}

void Lamp_PID_Control(double setpoint) {
	double error = setpoint - BH1750_Reading;
	double proportional = error;
	integral = integral - previous_error;
	derivative = (error - previous_error) / dt;
	output = Kp * proportional + Ki * integral + Kd * derivative;
	uint16_t current_CRR = __HAL_TIM_GET_COMPARE(&htim3, TIM_CHANNEL_3);
	uint16_t next_CRR = current_CRR + output;
	if (next_CRR < 0) {
		next_CRR = 0;
	}
	if (next_CRR > 1000) {
		next_CRR = 1000;
	}
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, next_CRR);
	previous_error = error;
}
