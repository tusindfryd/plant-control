#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_
#endif

#include "i2c.h"
#include "ssd1306.h"
#include <stdio.h>

void splash();
void display_measurements(uint16_t moisture);
