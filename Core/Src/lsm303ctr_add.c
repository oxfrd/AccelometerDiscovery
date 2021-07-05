/*
 * lsm303ctr_add.c
 *
 *  Created on: 13.03.2021
 *      Author: oxford
 */

#include "lsm303ctr_add.h"

void error_shouter(int32_t* error_check, char text[40])
{
	if (error_check == 0)	return;

	waiterForEOFTx();

	uint16_t size;
	size = sprintf((char*) tx_buffer, "!!!  %s error.  !!! \r\n", text);
	transfer_data(tx_buffer, size);
	error_check = 0;
}


void lsm303ctr_init(void)
{
	HAL_Delay(2000);
	int32_t error_check;

	dev_ctx_xl.write_reg = lsm303ctr_write_a;
	dev_ctx_xl.read_reg = lsm303ctr_read_a;
	dev_ctx_xl.handle = (void *) &SENSOR_BUS;

	dev_ctx_mg.write_reg = lsm303ctr_write_m;
	dev_ctx_mg.read_reg = lsm303ctr_read_m;
	dev_ctx_mg.handle = (void *) &SENSOR_BUS;

	whoamI_a = 0;
	error_check = lsm303ctr_xl_device_id_get(&dev_ctx_xl, &whoamI_a);
	error_shouter(&error_check, "Accelerometer not found.");

	/*whoamI_m = 0;
	error_check = lsm303ctr_mag_device_id_get(&dev_ctx_mg, &whoamI_m);
	error_shouter(&error_check, "Magnetometer not found");
*/
	lsm303ctr_mag_reset_set(&dev_ctx_mg, PROPERTY_ENABLE);
	do {
	    lsm303ctr_mag_reset_get(&dev_ctx_mg, &rst);
	  } while (rst);

	  /* Enable Block Data Update */
	  error_check = lsm303ctr_xl_block_data_update_set(&dev_ctx_xl, PROPERTY_ENABLE);
	 // error_check = lsm303ctr_mag_block_data_update_set(&dev_ctx_mg, PROPERTY_ENABLE);
	  error_shouter(&error_check, "BDU setting");
	  /* Set Output Data Rate */
	  error_check = lsm303ctr_xl_data_rate_set(&dev_ctx_xl, LSM303CTR_XL_ODR_50Hz);
	//  error_check = lsm303ctr_mag_data_rate_set(&dev_ctx_mg, LSM303CTR_MG_ODR_10Hz);
	  error_shouter(&error_check, "Data rate setting");
	  /* Set accelerometer full scale */
	  error_check = lsm303ctr_xl_full_scale_set(&dev_ctx_xl, LSM303CTR_2g);
	  error_shouter(&error_check, "Full scale setting");
	  /* Set / Reset magnetic sensor mode */
	  //  error_check = lsm303ctr_mag_set_rst_mode_set(&dev_ctx_mg,LSM303CTR_SENS_OFF_CANC_EVERY_ODR);
	  //  error_shouter(&error_check, "set reset mode setting");
	  /* Enable temperature compensation on mag sensor */
	  //	  error_check = lsm303ctr_mag_offset_temp_comp_set(&dev_ctx_mg, PROPERTY_ENABLE);
	  //	  error_shouter(&error_check, "offset temp comp setting");
	  /* Enable temperature sensor */
	  error_check = lsm303ctr_temperature_meas_set(&dev_ctx_mg, LSM303CTR_TEMP_ENABLE);
	  error_shouter(&error_check, "Set measurement setting");
	  /* Set device in continuous mode */
	  // lsm303ctr_xl_operating_mode_set(&dev_ctx_xl, LSM303CTR_HR_12bit);
	  /* Set magnetometer in continuous mode */
	//  error_check =  lsm303ctr_mag_operating_mode_set(&dev_ctx_mg,
	//                                   LSM303CTR_CONTINUOUS_MODE);
	  error_shouter(&error_check, "Magnetometer operating mode setting");

	  HAL_Delay(200);
}


int32_t lsm303ctr_write_a(void *handle, uint8_t reg, uint8_t *bufp,
		uint16_t length) {

	HAL_GPIO_WritePin(XL_CS_GPIO_Port, XL_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&SENSOR_BUS, &reg, 1, 1000);
	HAL_SPI_Transmit(&SENSOR_BUS, bufp, length, 1000);
	HAL_GPIO_WritePin(XL_CS_GPIO_Port, XL_CS_PIN, GPIO_PIN_SET);
	return 0;
}

int32_t lsm303ctr_read_a(void *handle, uint8_t reg, uint8_t *bufp,
		uint16_t length) {

	reg |= 0x80;
	HAL_GPIO_WritePin(XL_CS_PORT, XL_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(handle, &reg, 1, 1000);
	HAL_SPI_Receive(handle, bufp, length, 1000);
	HAL_GPIO_WritePin(XL_CS_PORT, XL_CS_PIN, GPIO_PIN_SET);

	return 0;
}

int32_t lsm303ctr_write_m(void *handle, uint8_t reg, uint8_t *bufp,
		uint16_t length) {

	HAL_GPIO_WritePin(MAG_CS_GPIO_Port, MAG_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(handle, &reg, 1, 1000);
	HAL_SPI_Transmit(handle, bufp, length, 1000);
	HAL_GPIO_WritePin(MAG_CS_GPIO_Port, MAG_CS_PIN, GPIO_PIN_SET);
	return 0;
}

int32_t lsm303ctr_read_m(void *handle, uint8_t reg, uint8_t *bufp,
		uint16_t length) {

	reg |= 0x80;
	HAL_GPIO_WritePin(MAG_CS_GPIO_Port, MAG_CS_PIN, GPIO_PIN_RESET);
	HAL_SPI_Transmit(handle, &reg, 1, 1000);
	HAL_SPI_Receive(handle, bufp, length, 1000);
	HAL_GPIO_WritePin(MAG_CS_GPIO_Port, MAG_CS_PIN, GPIO_PIN_SET);
	return 0;
}

int32_t lsm303ctr_AccelerationRead(void) {

	lsm303ctr_reg_t reg;
	lsm303ctr_xl_status_get(&dev_ctx_xl, &reg.status_reg_a);

	if (reg.status_reg_a.zyxda) {
		/* Read accelerometer data */
		memset(data_raw_acceleration, 0x00, 3 * sizeof(int16_t));
		lsm303ctr_acceleration_raw_get(&dev_ctx_xl, data_raw_acceleration);
		acceleration_mg[0] = (float) 2
				* lsm303ctr_from_fs_2g_hr_to_mg(data_raw_acceleration[0]);
		acceleration_mg[1] = (float) 2
				* lsm303ctr_from_fs_2g_hr_to_mg(data_raw_acceleration[1]);
		acceleration_mg[2] = (float) 2
				* lsm303ctr_from_fs_2g_hr_to_mg(data_raw_acceleration[2]);

		waiterForEOFTx();

		sprintf((char *) tx_buffer, "Acceleration [mg]:%4.2f \t%4.2f\t%4.2f \r\n",
				acceleration_mg[0], acceleration_mg[1], acceleration_mg[2]);
		transfer_data(tx_buffer, strlen((char const *) tx_buffer));
	}
	return 0;
}

int32_t lsm303ctr_MagneticRead(void) {

	lsm303ctr_mag_status_get(&dev_ctx_mg, &reg.status_reg_m);

	if (reg.status_reg_m.zyxda) {
		/* Read magnetic field data */
		memset(data_raw_magnetic, 0x00, 3 * sizeof(int16_t));
		lsm303ctr_magnetic_raw_get(&dev_ctx_mg, data_raw_magnetic);
		magnetic_mG[0] = lsm303ctr_from_lsb_to_mgauss(data_raw_magnetic[0]);
		magnetic_mG[1] = lsm303ctr_from_lsb_to_mgauss(data_raw_magnetic[1]);
		magnetic_mG[2] = lsm303ctr_from_lsb_to_mgauss(data_raw_magnetic[2]);

		waiterForEOFTx();

		sprintf((char *) tx_buffer,
				"Magnetic field [mG]:%4.2f\t%4.2f\t%4.2f \r\n", magnetic_mG[0],
				magnetic_mG[1], magnetic_mG[2]);
		transfer_data(tx_buffer, strlen((char const *) tx_buffer));
	}
	return 0;
}


int32_t lsm303ctr_TemperatureRead(void) {

	lsm303ctr_temp_data_ready_get(&dev_ctx_xl, &reg.byte);

	if (reg.byte) {
		/* Read temperature data */
		memset(&data_raw_temperature, 0x00, sizeof(int16_t));
		lsm303ctr_temperature_raw_get(&dev_ctx_xl, &data_raw_temperature);
		temperature_degC = lsm303ctr_from_lsb_hr_to_celsius(
				data_raw_temperature);

		waiterForEOFTx();

		sprintf((char *) tx_buffer, "Temperature [degC]:%6.2f\r\n",
				temperature_degC);
		transfer_data(tx_buffer, strlen((char const *) tx_buffer));
	}
	return 0;
}

/*
 * @brief  Write generic device register (platform dependent)
 *
 * @param  tx_buffer     buffer to transmit
 * @param  length        number of byte to send
 *
 */

void transfer_data(uint8_t *tx_buffer, uint16_t length) {

	HAL_UART_Transmit_DMA(&UART_BUS, tx_buffer, length);
}
