#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
#endif

#include <stdio.h>
#include <stdbool.h>
#include "i2c.h"
#include "ssd1306.h"
#include "WS9527.h"

void Splash();
void DisplayMeasurements();
void OpenMenu();
void CloseMenu();
