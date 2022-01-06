/* the UART port is hardcoded as UART3 for simplicity */

#include "messages.h"

void UART_TransmitData(uint16_t reading) {
	char json_data[23];
    sprintf(json_data, "{ \"moisture\" : %03d }\r\n", reading);

	HAL_UART_Transmit(&huart3, (uint8_t*)json_data, sizeof(json_data) - 1, 100);
}
