/*
 * global.c
 *
 *  Created on: Dec 1, 2025
 *      Author: cthanh
 */

#include "global.h"

int status_parser = HEAD;
int status_uart = CHECK_RST;

int index_command = 0;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];

uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t command_flag = 0;
uint8_t command_data[MAX_BUFFER_SIZE];
uint32_t ADC_value = 0;


void DisplayMessage(UART_HandleTypeDef *huart,  uint8_t *message)
{

    uint16_t length = strlen((const char *)message);

    HAL_UART_Transmit(huart, message, length, HAL_MAX_DELAY);
}

void DisplayChar(UART_HandleTypeDef *huart, uint8_t character) {
    HAL_UART_Transmit(huart, &character, 1, HAL_MAX_DELAY);
}

void clear_command()
{
	for (int i = 0; i < MAX_BUFFER_SIZE; i++) command_data[i] = '\0';
	index_command = 0;
}
