/* the UART port is hardcoded as UART3 for simplicity */

#include "messages.h"

void UART_TransmitData(uint16_t reading1, uint16_t reading2, uint16_t setpoint2) {
	char json_data[80];
	sprintf(json_data,
			"{ \"moisture\" : \"%03d\", \"brightness\" : \"%04d\", \"brightness_setpoint\" : \"%04d\" }\r\n",
			reading1, reading2, (int) setpoint2);

	HAL_UART_Transmit(&huart3, (uint8_t*) json_data, sizeof(json_data) - 1,
			100);
}
