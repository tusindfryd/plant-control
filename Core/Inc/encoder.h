/**
 ******************************************************************************
 * @file    encoder.h
 * @brief   Helper functions for the rotary encoder
 *
 ******************************************************************************
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

/* Includes ------------------------------------------------------------------*/

#include <stdbool.h>
#include <stdint.h>
#include "tim.h"
#include "gpio.h"
#include "display.h"
#include "lamp.h"

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Initialize the rotary encoder
 * @return None
 */
void QE_Initialize();

/**
 * @brief Check the position of the rotary encoder knob
 * @return None
 */
void QE_CheckPosition();

/**
 * @brief Handle rotary encoder switch press
 * @return None
 */
void SwitchHandler();

#endif
