/**
 ******************************************************************************
 * @file    display.h
 * @brief   Helper functions for the SSD1306 display.
 *
 ******************************************************************************
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

/* Includes ------------------------------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
#include "i2c.h"
#include "ssd1306.h"
#include "WS9527.h"
#include "lamp.h"

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Splash screen
 * @return None
 */
void Splash();

/**
 * @brief Measurements screen view
 * @return None
 */
void DisplayMeasurements();

/**
 * @brief Open menu screen view
 * @return None
 */
void OpenMenu();

/**
 * @brief Close menu screen view
 * @return None
 */
void CloseMenu();

/**
 * @brief Draw background rectangle
 * @return None
 */
void BackgroundRectangle();

#endif
