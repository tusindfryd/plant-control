/**
 ******************************************************************************
 * @file    messages.h
 * @brief   Helper functions for the communication
 *
 ******************************************************************************
 */

#ifndef INC_MESSAGES_H_
#define INC_MESSAGES_H_

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include <stdio.h>
#include "usart.h"

/* Public function prototypes ------------------------------------------------*/

/**
 * @brief Transmit the data through UART
 * @param[in] reading 1
 * @param[in] reading 2
 * @param[in] setpoint 2
 * @return None
 */
void UART_TransmitData(uint16_t reading1, uint16_t reading2, uint16_t setpoint2);

#endif
