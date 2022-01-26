/**
 ******************************************************************************
 * @file    lamp.h
 * @brief   Helper functions for the lamp control
 *
 ******************************************************************************
 */

#ifndef INC_LAMP_H_
#define INC_LAMP_H_

/* Includes ------------------------------------------------------------------*/

#include "tim.h"
#include <stdint.h>

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Initialize the lamp
 * @return None
 */
void Lamp_Initialize();

/**
 * @brief Set lamp brightness
 * @return None
 */
void Lamp_SetBrightness(uint8_t brightness_percent);

/**
 * @brief Turn lamp on or off
 * @return None
 */
void Lamp_On_Off();

/**
 * @brief Adjust lamp to the given setpoint with PID control
 * @param[in] setpoint : setpoint (in lux)
 * @return None
 */
void Lamp_PID_Control(double setpoint);

#endif
