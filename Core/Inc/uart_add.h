/*
 * uart_add.h
 *
 *  Created on: 10.08.2021
 *      Author: oxford
 */

#ifndef INC_UART_ADD_H_
#define INC_UART_ADD_H_

#define LINE_MAX_LENGTH	41
//with 1 byte for "/0"

static char line_buffer[LINE_MAX_LENGTH];
static uint32_t line_length;
static

void line_append(uint8_t value);




#endif /* INC_UART_ADD_H_ */
