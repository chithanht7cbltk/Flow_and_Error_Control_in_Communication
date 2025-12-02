/*
 * global.h
 *
 *  Created on: Dec 1, 2025
 *      Author: cthanh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include "main.h"
#include <stdio.h>
#include <string.h>
#include "software_timer.h"
#include "command_parser_fsm.h"
#include "uart_communication_fsm.h"


extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;



#define MAX_BUFFER_SIZE 30

#define HEAD 0
#define INFO 1
#define TAIL 2

#define CHECK_RST 10
#define CHECK_OK 11
#define GET_ADC 12
#define SENDING 13
#define EXIT 14

extern int status_parser;
extern int status_uart;

extern int index_command;
extern uint8_t buffer[MAX_BUFFER_SIZE];


extern uint8_t temp, index_buffer, buffer_flag;
extern uint8_t command_flag, command_data[MAX_BUFFER_SIZE];
extern uint32_t ADC_value;

void DisplayMessage(UART_HandleTypeDef *huart,  uint8_t *message);
void DisplayChar(UART_HandleTypeDef *huart, uint8_t character);

void clear_command();


#endif /* INC_GLOBAL_H_ */
