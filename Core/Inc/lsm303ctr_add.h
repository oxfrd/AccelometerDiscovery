/*
 * lsm303ctr_add.h
 *
 *  Created on: 13.03.2021
 *      Author: oxford
 */

#ifndef INC_LSM303CTR_ADD_H_
#define INC_LSM303CTR_ADD_H_

/*****************************************************************************************/
/* 									INCLUDES											 */
/*****************************************************************************************/
#include <string.h>
#include <stdio.h>

#include "lsm303ctr_reg.h"
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/*****************************************************************************************/
/* 									DEFINES												 */
/*****************************************************************************************/

#define SENSOR_BUS hspi2
#define UART_BUS huart2
#define TX_BUF_DIM 300

#define XL_CS_PORT XL_CS_GPIO_Port
#define XL_CS_PIN XL_CS_Pin
#define MAG_CS_PORT MAG_CS_GPIO_Port
#define MAG_CS_PIN MAG_CS_Pin

#define ACCEL_ALL 1100
#define ACCEL_X 1101
#define ACCEL_Y 1102
#define ACCEL_Z 1103

/*****************************************************************************************/
/* 									Variables                                            */
/*****************************************************************************************/

int16_t data_raw_acceleration[3];
int16_t data_raw_magnetic[3];
int16_t data_raw_temperature;
float acceleration_mg[3];
float magnetic_mG[3];
float temperature_degC;
uint8_t whoamI_a, whoamI_m, rst;
uint8_t tx_buffer[TX_BUF_DIM];

stmdev_ctx_t dev_ctx_xl;
stmdev_ctx_t dev_ctx_mg;
lsm303ctr_reg_t reg;

/*****************************************************************************************/
/* 								Functions predefines         		                     */
/*****************************************************************************************/

void lsm303ctr_init(void);
void error_shouter(int32_t* error_check, char text[40]);
int32_t lsm303ctr_write_a(void *handle, uint8_t reg, uint8_t *bufp, uint16_t length);
int32_t lsm303ctr_read_a(void *handle, uint8_t reg, uint8_t *bufp, uint16_t length);
int32_t lsm303ctr_write_m(void *handle, uint8_t reg, uint8_t *bufp, uint16_t length);
int32_t lsm303ctr_read_m(void *handle, uint8_t reg, uint8_t *bufp, uint16_t length);
void transfer_data(uint8_t *tx_buffer, uint16_t length);

int32_t lsm303ctr_AccelerationRead(void);
int32_t lsm303ctr_MagneticRead(void);
int32_t lsm303ctr_TemperatureRead(void);
int32_t lsm303ctr_sendAccel(uint32_t instruction, float *acceleration);

#endif /* INC_LSM303CTR_ADD_H_ */
