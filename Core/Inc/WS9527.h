/**
 ******************************************************************************
 * @file    WS9527.h
 * @brief   Helper functions for the WS9527 soil moisture sensor
 *
 ******************************************************************************
 */

#ifndef INC_WAVESHARE_9527_H_
#define INC_WAVESHARE_9527_H_

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include <float.h>
#include "adc.h"

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Linear interpolation between two data points
 * @param[in] previous value x(t-1)
 * @param[in] new value x(t)
 * @param[in] sampling time
 * @return linearly interpolated value
 */
float lerp(uint16_t v0, uint32_t v1, float t);

/**
 * @brief Initialize the WS9527 soil moisture sensor
 * @return None
 */
void WS9527_Initialize();

/**
 * @brief Start readings from the WS9527 soil moisture sensor
 * @return None
 */
void WS9527_StartReadings();

/**
 * @brief Get readings from the WS9527 soil moisture sensor
 * @return None
 */
void WS9527_GetReadings(ADC_HandleTypeDef *hadc);

#endif
