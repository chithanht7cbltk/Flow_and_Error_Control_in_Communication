/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 1, 2025
 *      Author: cthanh
 */

#include "command_parser_fsm.h"


void command_parser_fsm() {
	switch (status_parser) {
		case HEAD:
			if (temp == '!') {
				clear_command();
				status_parser = INFO;
				if (command_flag)
					status_uart = CHECK_OK;
//				else
//					status_uart = CHECK_RST;
			}
			break;
		case INFO:
			if (temp == '#') status_parser = TAIL;
			else command_data[index_command++] = temp;
			break;
		case TAIL:
			command_flag = 1;
			status_parser = HEAD;
			break;
		default:
			break;
	}
}
