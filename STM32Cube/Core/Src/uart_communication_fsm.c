/*
 * uart_communication_fsm.c
 *
 *  Created on: Dec 1, 2025
 *      Author: cthanh
 */

#include "uart_communication_fsm.h"


void uart_communication_fsm() {
	switch (status_uart) {
		case CHECK_RST:
			if (command_flag && !strcmp((char *)command_data, "RST"))
			{
				ADC_value = HAL_ADC_GetValue(&hadc1);
				status_parser = HEAD;
				status_uart = SENDING;
				timer_flag[1] = 1;
			}
			else
				command_flag = 0;
			break;

		case SENDING:
			if (timer_flag[1] == 1) {
				HAL_UART_Transmit(&huart2, buffer, sprintf((char *)buffer, "!ADC=%ld#\r\n", ADC_value), 500);
				setTimer(1, 3000);
			}
			break;

		case CHECK_OK:
			if (command_flag && !strcmp((char *)command_data, "OK"))
			{
				command_flag = 0;
				status_parser = HEAD;
				status_uart = CHECK_RST;
			}
			break;
		default:
			break;
	}
}


