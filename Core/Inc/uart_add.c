/*
 * uart_add.c
 *
 *  Created on: 10.08.2021
 *      Author: oxford
 */

#include "uart_add.h"

void line_append(uint8_t value)
{
	if (value == '\r' || value == '\n') {
		// end of line detected
		if (line_length > 0) {
			// if buffer is not empty
			line_buffer[line_length] = '\0';
			// przetwarzamy dane
			HAL_UART_Transmit_DMA(huart, pData, Size)
			// zaczynamy zbieranie danych od nowa
			line_length = 0;
		}
	}
	else {
		if (line_length >= LINE_MAX_LENGTH) {
			// za du¿o danych, usuwamy wszystko co odebraliœmy dotychczas
			line_length = 0;
		}
		// dopisujemy wartoœæ do bufora
		line_buffer[line_length++] = value;
	}
}

