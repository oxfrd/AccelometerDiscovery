/*
 ******************************************************************************
 * @file    lsm303ctr_reg.h
 * @author  Sensors Software Solution Team
 * @brief   This file contains all the functions prototypes for the
 *          lsm303ctr_reg.c driver.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LSM303CTR_REGS_H
#define LSM303CTR_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <math.h>

/** @addtogroup LSM303CTR
  * @{
  *
  */

/** @defgroup Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/**
  * @}
  *
  */

/** @defgroup STMicroelectronics sensors common types
  * @{
  *
  */

#ifndef MEMS_SHARED_TYPES
#define MEMS_SHARED_TYPES

typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0       : 1;
  uint8_t bit1       : 1;
  uint8_t bit2       : 1;
  uint8_t bit3       : 1;
  uint8_t bit4       : 1;
  uint8_t bit5       : 1;
  uint8_t bit6       : 1;
  uint8_t bit7       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7       : 1;
  uint8_t bit6       : 1;
  uint8_t bit5       : 1;
  uint8_t bit4       : 1;
  uint8_t bit3       : 1;
  uint8_t bit2       : 1;
  uint8_t bit1       : 1;
  uint8_t bit0       : 1;
#endif /* DRV_BYTE_ORDER */
} bitwise_t;

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, uint8_t *,
                                    uint16_t);
typedef int32_t (*stmdev_read_ptr) (void *, uint8_t, uint8_t *,
                                    uint16_t);

typedef struct {
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Customizable optional pointer **/
  void *handle;
} stmdev_ctx_t;

/**
  * @}
  *
  */

#endif /* MEMS_SHARED_TYPES */

#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** @defgroup    Generic address-data structure definition
  * @brief       This structure is useful to load a predefined configuration
  *              of a sensor.
  *              You can create a sensor configuration by your own or using
  *              Unico / Unicleo tools available on STMicroelectronics
  *              web site.
  *
  * @{
  *
  */

typedef struct {
  uint8_t address;
  uint8_t data;
} ucf_line_t;

/**
  * @}
  *
  */

#endif /* MEMS_UCF_SHARED_TYPES */

/**
  * @}
  *
  */

/** @defgroup lsm303ctr_Infos
  * @{
  *
  */

/** I2C Device Address 8 bit format !!! DIDNT changed  !!!! **/
#define LSM303CTR_I2C_ADD_XL       0x33U
#define LSM303CTR_I2C_ADD_MG       0x3DU

/** Device Identification (Who am I) **/
#define LSM303CTR_ID_XL            0x41U
#define LSM303CTR_ID_MG            0x3DU

/**
  * @}
  *
  */

#define LSM303CTR_STATUS_REG_AUX_A           0x07U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01            : 2;
  uint8_t tda                    : 1;
  uint8_t not_used_02            : 3;
  uint8_t tor                    : 1;
  uint8_t not_used_03            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_03            : 1;
  uint8_t tor                    : 1;
  uint8_t not_used_02            : 3;
  uint8_t tda                    : 1;
  uint8_t not_used_01            : 2;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_status_reg_aux_a_t;

#define LSM303CTR_WHO_AM_I_A                 0x0FU
#define LSM303CTR_ACT_THS_A            		 0x1EU
#define LSM303CTR_ACT_DUR_A            		 0x1FU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used_01            : 6;
  uint8_t temp_en                : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t temp_en                : 2;
  uint8_t not_used_01            : 6;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_temp_cfg_reg_a_t;

#define LSM303CTR_CTRL_REG1_A                0x20U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xen                    : 1;
  uint8_t yen                    : 1;
  uint8_t zen                    : 1;
  uint8_t bdu                    : 1;
  uint8_t odr                    : 3;
  uint8_t hr					 : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t hr					 : 1;
  uint8_t odr                    : 3;
  uint8_t bdu                    : 1;
  uint8_t zen                    : 1;
  uint8_t yen                    : 1;
  uint8_t xen                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg1_a_t;

#define LSM303CTR_CTRL_REG2_A                0x21U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t hpis                   : 2;
  uint8_t fds                    : 1;
  uint8_t hpm                    : 2;
  uint8_t dfc                    : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t dfc                    : 2;
  uint8_t hpm                    : 2;
  uint8_t fds                    : 1;
  uint8_t hpis                   : 2;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg2_a_t;

#define LSM303CTR_CTRL_REG3_A                0x22U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int_xl_drdy            : 1;
  uint8_t int_xl_inact           : 1;
  uint8_t int_xl_ovr             : 1;
  uint8_t int_xl_ig1             : 1;
  uint8_t int_xl_ig2             : 1;
  uint8_t int_xl_inact1           : 1;
  uint8_t stop_fth               : 1;
  uint8_t fifo_en                : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_en                : 1;
  uint8_t stop_fth               : 1;
  uint8_t int_xl_inact           : 1;
  uint8_t int_xl_ig2             : 1;
  uint8_t int_xl_ig1             : 1;
  uint8_t int_xl_ovr             : 1;
  uint8_t int_xl_inact           : 1;
  uint8_t int_xl_drdy            : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg3_a_t;

#define LSM303CTR_CTRL_REG4_A                0x23U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t spi_mode_select        : 1;
  uint8_t i2c_disable            : 1;
  uint8_t if_add_inc             : 1;
  uint8_t bw_scale_odr           : 1;
  uint8_t fs                     : 2;
  uint8_t bw                     : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bw                     : 2;
  uint8_t fs                     : 2;
  uint8_t bw_scale_odr           : 1;
  uint8_t if_add_inc             : 1;
  uint8_t i2c_disable            : 1;
  uint8_t spi_mode_select        : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg4_a_t;

#define LSM303CTR_CTRL_REG5_A                0x24U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t debug	                 : 1;
  uint8_t soft_reset             : 1;
  uint8_t dec		             : 2;
  uint8_t st		             : 2;
  uint8_t h_lactive              : 1;
  uint8_t pp_od                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t pp_od                  : 1;
  uint8_t h_lactive              : 1;
  uint8_t st		             : 2;
  uint8_t dec		             : 2;
  uint8_t soft_reset             : 1;
  uint8_t debug	                 : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg5_a_t;

#define LSM303CTR_CTRL_REG6_A               0x25U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used           	 : 7;
  uint8_t boot					 : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t boot					 : 1;
  uint8_t not_used           	 : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg6_a_t;

#define LSM303CTR_CTRL_REG7_A               0x26U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t d4_ig            		 : 2;
  uint8_t lir	                 : 2;
  uint8_t dcrm		             : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t dcrm		             : 2;
  uint8_t lir	                 : 2;
  uint8_t d4_ig            		 : 2;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg7_a_t;



#define LSM303CTR_STATUS_REG_A              0x27U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xda                    : 1;
  uint8_t yda                    : 1;
  uint8_t zda                    : 1;
  uint8_t zyxda                  : 1;
  uint8_t _xor                    : 1;
  uint8_t yor                    : 1;
  uint8_t zor                    : 1;
  uint8_t zyxor                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t zyxor                  : 1;
  uint8_t zor                    : 1;
  uint8_t yor                    : 1;
  uint8_t _xor                   : 1;
  uint8_t zyxda                  : 1;
  uint8_t zda                    : 1;
  uint8_t yda                    : 1;
  uint8_t xda                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_status_reg_a_t;

#define LSM303CTR_OUT_X_L_A                 0x28U
#define LSM303CTR_OUT_X_H_A                 0x29U
#define LSM303CTR_OUT_Y_L_A                 0x2AU
#define LSM303CTR_OUT_Y_H_A                 0x2BU
#define LSM303CTR_OUT_Z_L_A                 0x2CU
#define LSM303CTR_OUT_Z_H_A                 0x2DU
#define LSM303CTR_FIFO_CTRL_REG_A           0x2EU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fth                    : 5;
  uint8_t fmode                  : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fmode                  : 3;
  uint8_t fth                    : 5;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_fifo_ctrl_reg_a_t;

#define LSM303CTR_FIFO_SRC_REG_A            0x2FU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fss                    : 5;
  uint8_t empty                  : 1;
  uint8_t ovrn_fifo              : 1;
  uint8_t fth                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fth                    : 1;
  uint8_t ovrn_fifo              : 1;
  uint8_t empty                  : 1;
  uint8_t fss                    : 5;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_fifo_src_reg_a_t;

#define LSM303CTR_INT1_CFG_A                0x30U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xlie                   : 1; /* or XDOWNE */
  uint8_t xhie                   : 1; /* or XUPE */
  uint8_t ylie                   : 1; /* or YDOWNE */
  uint8_t yhie                   : 1; /* or YUPE */
  uint8_t zlie                   : 1; /* or ZDOWNE */
  uint8_t zhie                   : 1; /* or ZUPE */
  uint8_t _6d                    : 1;
  uint8_t aoi                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t aoi                    : 1;
  uint8_t _6d                    : 1;
  uint8_t zhie                   : 1; /* or ZUPE */
  uint8_t zlie                   : 1; /* or ZDOWNE */
  uint8_t yhie                   : 1; /* or YUPE */
  uint8_t ylie                   : 1; /* or YDOWNE */
  uint8_t xhie                   : 1; /* or XUPE */
  uint8_t xlie                   : 1; /* or XDOWNE */
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int1_cfg_a_t;

#define LSM303CTR_INT1_SRC_A                0x31U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl                     : 1;
  uint8_t xh                     : 1;
  uint8_t yl                     : 1;
  uint8_t yh                     : 1;
  uint8_t zl                     : 1;
  uint8_t zh                     : 1;
  uint8_t ia                     : 1;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t ia                     : 1;
  uint8_t zh                     : 1;
  uint8_t zl                     : 1;
  uint8_t yh                     : 1;
  uint8_t yl                     : 1;
  uint8_t xh                     : 1;
  uint8_t xl                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int1_src_a_t;

#define LSM303CTR_INT1_THS_A                0x32U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths                    : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t ths                    : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int1_ths_a_t;

#define LSM303CTR_INT1_DURATION_A           0x33U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t d                      : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t d                      : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int1_duration_a_t;

#define LSM303CTR_INT2_CFG_A                0x34U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xlie                   : 1;
  uint8_t xhie                   : 1;
  uint8_t ylie                   : 1;
  uint8_t yhie                   : 1;
  uint8_t zlie                   : 1;
  uint8_t zhie                   : 1;
  uint8_t _6d                    : 1;
  uint8_t aoi                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t aoi                    : 1;
  uint8_t _6d                    : 1;
  uint8_t zhie                   : 1;
  uint8_t zlie                   : 1;
  uint8_t yhie                   : 1;
  uint8_t ylie                   : 1;
  uint8_t xhie                   : 1;
  uint8_t xlie                   : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int2_cfg_a_t;

#define LSM303CTR_INT2_SRC_A                0x35U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl                     : 1;
  uint8_t xh                     : 1;
  uint8_t yl                     : 1;
  uint8_t yh                     : 1;
  uint8_t zl                     : 1;
  uint8_t zh                     : 1;
  uint8_t ia                     : 1;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t ia                     : 1;
  uint8_t zh                     : 1;
  uint8_t zl                     : 1;
  uint8_t yh                     : 1;
  uint8_t yl                     : 1;
  uint8_t xh                     : 1;
  uint8_t xl                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int2_src_a_t;

#define LSM303CTR_INT2_THS_A                0x36U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths                    : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t ths                    : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int2_ths_a_t;

#define LSM303CTR_INT2_DURATION_A           0x37U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t d                      : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t d                      : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_int2_duration_a_t;

#define LSM303CTR_CLICK_CFG_A               0x38U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xs                     : 1;
  uint8_t xd                     : 1;
  uint8_t ys                     : 1;
  uint8_t yd                     : 1;
  uint8_t zs                     : 1;
  uint8_t zd                     : 1;
  uint8_t not_used_01            : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 2;
  uint8_t zd                     : 1;
  uint8_t zs                     : 1;
  uint8_t yd                     : 1;
  uint8_t ys                     : 1;
  uint8_t xd                     : 1;
  uint8_t xs                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_click_cfg_a_t;

#define LSM303CTR_CLICK_SRC_A               0x39U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t x                      : 1;
  uint8_t y                      : 1;
  uint8_t z                      : 1;
  uint8_t sign                   : 1;
  uint8_t sclick                 : 1;
  uint8_t dclick                 : 1;
  uint8_t ia                     : 1;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t ia                     : 1;
  uint8_t dclick                 : 1;
  uint8_t sclick                 : 1;
  uint8_t sign                   : 1;
  uint8_t z                      : 1;
  uint8_t y                      : 1;
  uint8_t x                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_click_src_a_t;

#define LSM303CTR_CLICK_THS_A               0x3AU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ths                    : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t ths                    : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_click_ths_a_t;

#define LSM303CTR_TIME_LIMIT_A              0x3BU
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t tli                    : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t tli                    : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_time_limit_a_t;

#define LSM303CTR_TIME_LATENCY_A            0x3CU
typedef struct {
  uint8_t tla                    : 8;
} lsm303ctr_time_latency_a_t;

#define LSM303CTR_TIME_WINDOW_A             0x3DU
typedef struct {
  uint8_t tw                     : 8;
} lsm303ctr_time_window_a_t;


typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t acth                   : 7;
  uint8_t not_used_01            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01            : 1;
  uint8_t acth                   : 7;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_act_ths_a_t;


typedef struct {
  uint8_t actd                   : 8;
} lsm303ctr_act_dur_a_t;

#define LSM303CTR_WHO_AM_I_M                0x3DU
#define LSM303CTR_CTRL_REG1_M               0x20U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t st                     : 1;
  uint8_t mustBeZeroBit          : 1;
  uint8_t doutrate               : 3;	//by defaut is 10Hz
  uint8_t outmode                : 2;
  uint8_t temp_en                : 1;
 #elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t temp_en                : 1;
  uint8_t outmode                : 2;
  uint8_t doutrate               : 3;	//by defaut is 10Hz
  uint8_t mustBeZeroBit          : 1;
  uint8_t st                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg1_m_t;

#define LSM303CTR_CTRL_REG2_M               0x21U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mustBeZeroBit          : 2;
  uint8_t soft_rst               : 1;
  uint8_t reboot		         : 1;
  uint8_t mustBeZeroBit1         : 1;
  uint8_t fs				     : 2; // +- 16 gausses if set to 3
  uint8_t mustBeZeroBit2         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mustBeZeroBit          : 1;
  uint8_t fs				     : 2; // +- 16 gausses if set to 3
  uint8_t mustBeZeroBit          : 1;
  uint8_t reboot		         : 1;
  uint8_t soft_rst               : 1;
  uint8_t mustBeZeroBit          : 2;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg2_m_t;

#define LSM303CTR_CTRL_REG3_M               0x22U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t md	                 : 2; // by default '11'
  uint8_t sim               	 : 1;
  uint8_t mustBeZeroBit1         : 2;
  uint8_t lp                     : 1;
  uint8_t mustBeZeroBit          : 1;
  uint8_t i2c_disable            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t i2c_disable            : 1;
  uint8_t mustBeZeroBit          : 1;
  uint8_t lp                     : 1;
  uint8_t mustBeZeroBit          : 2;
  uint8_t sim               	 : 1;
  uint8_t md	                 : 2;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg3_m_t;

#define LSM303CTR_CTRL_REG4_M            0x23U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mustBeZeroBit          : 1;
  uint8_t ble                    : 1;
  uint8_t omz                    : 2;
  uint8_t mustBeZeroBit1         : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mustBeZeroBit          : 4;
  uint8_t omz                    : 2;
  uint8_t ble                    : 1;
  uint8_t mustBeZeroBit          : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg4_m_t;

#define LSM303CTR_CTRL_REG5_M          0x24U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mustBeZeroBit          : 6;
  uint8_t bdu                    : 1;
  uint8_t mustBeZeroBit1         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mustBeZeroBit          : 1;
  uint8_t bdu                    : 1;
  uint8_t mustBeZeroBit          : 6;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_ctrl_reg5_m_t;

#define LSM303CTR_STATUS_REG_M              0x27U
typedef struct {
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xda                    : 1;
  uint8_t yda                    : 1;
  uint8_t zda                    : 1;
  uint8_t zyxda                  : 1;
  uint8_t _xor                   : 1;
  uint8_t yor                    : 1;
  uint8_t zor                    : 1;
  uint8_t zyxor                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t zyxor                  : 1;
  uint8_t zor                    : 1;
  uint8_t yor                    : 1;
  uint8_t _xor                   : 1;
  uint8_t zyxda                  : 1;
  uint8_t zda                    : 1;
  uint8_t yda                    : 1;
  uint8_t xda                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm303ctr_status_reg_m_t;

#define LSM303CTR_OUTX_L_REG_M              0x28U
#define LSM303CTR_OUTX_H_REG_M              0x29U
#define LSM303CTR_OUTY_L_REG_M              0x2AU
#define LSM303CTR_OUTY_H_REG_M              0x2BU
#define LSM303CTR_OUTZ_L_REG_M              0x2CU
#define LSM303CTR_OUTZ_H_REG_M              0x2DU
#define LSM303CTR_TEMP_L_REG_M              0x2EU
#define LSM303CTR_TEMP_H_REG_M              0x2FU
#define LSM303CTR_INT_CFG_M        	        0x30U	//interrupts weren't developed

/**
  * @defgroup LSM303CTR_Register_Union
  * @brief    This union group all the registers that has a bit-field
  *           description.
  *           This union is useful but not need by the driver.
  *
  *           REMOVING this union you are compliant with:
  *           MISRA-C 2012 [Rule 19.2] -> " Union are not allowed "
  *
  * @{
  *
  */
typedef union {
  lsm303ctr_status_reg_aux_a_t       status_reg_aux_a;
  lsm303ctr_temp_cfg_reg_a_t         temp_cfg_reg_a;
  lsm303ctr_ctrl_reg1_a_t            ctrl_reg1_a;
  lsm303ctr_ctrl_reg2_a_t            ctrl_reg2_a;
  lsm303ctr_ctrl_reg3_a_t            ctrl_reg3_a;
  lsm303ctr_ctrl_reg4_a_t            ctrl_reg4_a;
  lsm303ctr_ctrl_reg5_a_t            ctrl_reg5_a;
  lsm303ctr_ctrl_reg6_a_t            ctrl_reg6_a;
  lsm303ctr_ctrl_reg7_a_t            ctrl_reg7_a;
  lsm303ctr_status_reg_a_t           status_reg_a;
  lsm303ctr_fifo_ctrl_reg_a_t        fifo_ctrl_reg_a;
  lsm303ctr_fifo_src_reg_a_t         fifo_src_reg_a;
  lsm303ctr_int1_cfg_a_t             int1_cfg_a;
  lsm303ctr_int1_src_a_t             int1_src_a;
  lsm303ctr_int1_ths_a_t             int1_ths_a;
  lsm303ctr_int1_duration_a_t        int1_duration_a;
  lsm303ctr_int2_cfg_a_t             int2_cfg_a;
  lsm303ctr_int2_src_a_t             int2_src_a;
  lsm303ctr_int2_ths_a_t             int2_ths_a;
  lsm303ctr_int2_duration_a_t        int2_duration_a;
  lsm303ctr_click_cfg_a_t            click_cfg_a;
  lsm303ctr_click_src_a_t            click_src_a;
  lsm303ctr_click_ths_a_t            click_ths_a;
  lsm303ctr_time_limit_a_t           time_limit_a;
  lsm303ctr_time_latency_a_t         time_latency_a;
  lsm303ctr_time_window_a_t          time_window_a;
  lsm303ctr_act_ths_a_t              act_ths_a;
  lsm303ctr_act_dur_a_t              act_dur_a;
  lsm303ctr_ctrl_reg1_m_t            ctrl_reg1_m;
  lsm303ctr_ctrl_reg2_m_t            ctrl_reg2_m;
  lsm303ctr_ctrl_reg3_m_t            ctrl_reg3_m;
  lsm303ctr_ctrl_reg4_m_t        	 crtl_reg4_m;
  lsm303ctr_ctrl_reg5_m_t       	 ctrl_reg5_m;
  lsm303ctr_status_reg_m_t           status_reg_m;
  bitwise_t                          bitwise;
  uint8_t                            byte;
} lsm303ctr_reg_t;

/**
  * @}
  *
  */

int32_t lsm303ctr_read_reg(stmdev_ctx_t *ctx, uint8_t reg,
                           uint8_t *data,
                           uint16_t len);
int32_t lsm303ctr_write_reg(stmdev_ctx_t *ctx, uint8_t reg,
                            uint8_t *data,
                            uint16_t len);

float_t lsm303ctr_from_fs_2g_hr_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_4g_hr_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_8g_hr_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_16g_hr_to_mg(int16_t lsb);
float_t lsm303ctr_from_lsb_hr_to_celsius(int16_t lsb);

float_t lsm303ctr_from_fs_2g_nm_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_4g_nm_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_8g_nm_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_16g_nm_to_mg(int16_t lsb);
float_t lsm303ctr_from_lsb_nm_to_celsius(int16_t lsb);

float_t lsm303ctr_from_fs_2g_lp_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_4g_lp_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_8g_lp_to_mg(int16_t lsb);
float_t lsm303ctr_from_fs_16g_lp_to_mg(int16_t lsb);
float_t lsm303ctr_from_lsb_lp_to_celsius(int16_t lsb);

float_t lsm303ctr_from_lsb_to_mgauss(int16_t lsb);

int32_t lsm303ctr_temp_status_reg_get(stmdev_ctx_t *ctx,
                                      uint8_t *buff);

int32_t lsm303ctr_temp_data_ready_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lsm303ctr_temp_data_ovr_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_temperature_raw_get(stmdev_ctx_t *ctx,
                                      int16_t *val);

typedef enum {
  LSM303CTR_TEMP_DISABLE  = 0,
  LSM303CTR_TEMP_ENABLE   = 1,
} lsm303ctr_temp_en_a_t;
int32_t lsm303ctr_temperature_meas_set(stmdev_ctx_t *ctx,
                                       lsm303ctr_temp_en_a_t val);
int32_t lsm303ctr_temperature_meas_get(stmdev_ctx_t *ctx,
                                       lsm303ctr_temp_en_a_t *val);

typedef enum {
  LSM303CTR_HR_12bit   = 0,
  LSM303CTR_NM_10bit   = 1,
  LSM303CTR_LP_8bit    = 2,
} lsm303ctr_op_md_a_t;
int32_t lsm303ctr_xl_operating_mode_set(stmdev_ctx_t *ctx,
                                        lsm303ctr_op_md_a_t val);
int32_t lsm303ctr_xl_operating_mode_get(stmdev_ctx_t *ctx,
                                        lsm303ctr_op_md_a_t *val);

typedef enum {
  LSM303CTR_XL_POWER_DOWN                      = 0,
  LSM303CTR_XL_ODR_10Hz                        = 1,
  LSM303CTR_XL_ODR_50Hz                        = 2,
  LSM303CTR_XL_ODR_100Hz                       = 3,
  LSM303CTR_XL_ODR_200Hz                       = 4,
  LSM303CTR_XL_ODR_400Hz                       = 5,
  LSM303CTR_XL_ODR_800Hz	                   = 6,
  LSM303CTR_XL_ODR_NA					       = 7,
} lsm303ctr_odr_a_t;
int32_t lsm303ctr_xl_data_rate_set(stmdev_ctx_t *ctx,
                                   lsm303ctr_odr_a_t val);
int32_t lsm303ctr_xl_data_rate_get(stmdev_ctx_t *ctx,
                                   lsm303ctr_odr_a_t *val);

int32_t lsm303ctr_xl_high_pass_on_outputs_set(stmdev_ctx_t *ctx,
                                              uint8_t val);
int32_t lsm303ctr_xl_high_pass_on_outputs_get(stmdev_ctx_t *ctx,
                                              uint8_t *val);

typedef enum {
  LSM303CTR_AGGRESSIVE  = 0,
  LSM303CTR_STRONG      = 1,
  LSM303CTR_MEDIUM      = 2,
  LSM303CTR_LIGHT       = 3,
} lsm303ctr_hpcf_a_t;
int32_t lsm303ctr_xl_high_pass_bandwidth_set(stmdev_ctx_t *ctx,
                                             lsm303ctr_hpcf_a_t val);
int32_t lsm303ctr_xl_high_pass_bandwidth_get(stmdev_ctx_t *ctx,
                                             lsm303ctr_hpcf_a_t *val);

typedef enum {
  LSM303CTR_NORMAL 			 = 0,
  LSM303CTR_REFERENCE_MODE   = 1,
} lsm303ctr_hpm_a_t;
int32_t lsm303ctr_xl_high_pass_mode_set(stmdev_ctx_t *ctx,
                                        lsm303ctr_hpm_a_t val);
int32_t lsm303ctr_xl_high_pass_mode_get(stmdev_ctx_t *ctx,
                                        lsm303ctr_hpm_a_t *val);

typedef enum {
  LSM303CTR_2g   = 0,
  LSM303CTR_NA   = 1,
  LSM303CTR_4g   = 2,
  LSM303CTR_8g  = 3,
} lsm303ctr_fs_a_t;
int32_t lsm303ctr_xl_full_scale_set(stmdev_ctx_t *ctx,
                                    lsm303ctr_fs_a_t val);
int32_t lsm303ctr_xl_full_scale_get(stmdev_ctx_t *ctx,
                                    lsm303ctr_fs_a_t *val);

int32_t lsm303ctr_xl_block_data_update_set(stmdev_ctx_t *ctx,
                                           uint8_t val);
int32_t lsm303ctr_xl_block_data_update_get(stmdev_ctx_t *ctx,
                                           uint8_t *val);

int32_t lsm303ctr_xl_filter_reference_set(stmdev_ctx_t *ctx,
                                          uint8_t *buff);
int32_t lsm303ctr_xl_filter_reference_get(stmdev_ctx_t *ctx,
                                          uint8_t *buff);

int32_t lsm303ctr_xl_data_ready_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_xl_data_ovr_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_acceleration_raw_get(stmdev_ctx_t *ctx,
                                       int16_t *val);

int32_t lsm303ctr_xl_device_id_get(stmdev_ctx_t *ctx, uint8_t *buff);

typedef enum {
  LSM303CTR_ST_DISABLE   ,
  LSM303CTR_ST_POSITIVE  ,
  LSM303CTR_ST_NEGATIVE  ,
  LSM303CTR_ST_NA		 ,
} lsm303ctr_st_a_t;
int32_t lsm303ctr_xl_self_test_set(stmdev_ctx_t *ctx,
                                   lsm303ctr_st_a_t val);
int32_t lsm303ctr_xl_self_test_get(stmdev_ctx_t *ctx,
                                   lsm303ctr_st_a_t *val);

typedef enum {
  LSM303CTR_XL_LSB_AT_LOW_ADD = 0,
  LSM303CTR_XL_MSB_AT_LOW_ADD = 1,
} lsm303ctr_ble_a_t;
int32_t lsm303ctr_xl_data_format_set(stmdev_ctx_t *ctx,
                                     lsm303ctr_ble_a_t val);
int32_t lsm303ctr_xl_data_format_get(stmdev_ctx_t *ctx,
                                     lsm303ctr_ble_a_t *val);

int32_t lsm303ctr_xl_boot_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_xl_boot_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_xl_status_get(stmdev_ctx_t *ctx,
                                lsm303ctr_status_reg_a_t *val);

int32_t lsm303ctr_xl_int1_gen_conf_set(stmdev_ctx_t *ctx,
                                       lsm303ctr_int1_cfg_a_t *val);
int32_t lsm303ctr_xl_int1_gen_conf_get(stmdev_ctx_t *ctx,
                                       lsm303ctr_int1_cfg_a_t *val);

int32_t lsm303ctr_xl_int1_gen_source_get(stmdev_ctx_t *ctx,
                                         lsm303ctr_int1_src_a_t *val);

int32_t lsm303ctr_xl_int1_gen_threshold_set(stmdev_ctx_t *ctx,
                                            uint8_t val);
int32_t lsm303ctr_xl_int1_gen_threshold_get(stmdev_ctx_t *ctx,
                                            uint8_t *val);

int32_t lsm303ctr_xl_int1_gen_duration_set(stmdev_ctx_t *ctx,
                                           uint8_t val);
int32_t lsm303ctr_xl_int1_gen_duration_get(stmdev_ctx_t *ctx,
                                           uint8_t *val);

int32_t lsm303ctr_xl_int2_gen_conf_set(stmdev_ctx_t *ctx,
                                       lsm303ctr_int2_cfg_a_t *val);
int32_t lsm303ctr_xl_int2_gen_conf_get(stmdev_ctx_t *ctx,
                                       lsm303ctr_int2_cfg_a_t *val);

int32_t lsm303ctr_xl_int2_gen_source_get(stmdev_ctx_t *ctx,
                                         lsm303ctr_int2_src_a_t *val);

int32_t lsm303ctr_xl_int2_gen_threshold_set(stmdev_ctx_t *ctx,
                                            uint8_t val);
int32_t lsm303ctr_xl_int2_gen_threshold_get(stmdev_ctx_t *ctx,
                                            uint8_t *val);

int32_t lsm303ctr_xl_int2_gen_duration_set(stmdev_ctx_t *ctx,
                                           uint8_t val);
int32_t lsm303ctr_xl_int2_gen_duration_get(stmdev_ctx_t *ctx,
                                           uint8_t *val);

typedef enum {
  LSM303CTR_DISC_FROM_INT_GENERATOR  = 0,
  LSM303CTR_ON_INT1_GEN              = 1,
  LSM303CTR_ON_INT2_GEN              = 2,
  LSM303CTR_ON_TAP_GEN               = 4,
  LSM303CTR_ON_INT1_INT2_GEN         = 3,
  LSM303CTR_ON_INT1_TAP_GEN          = 5,
  LSM303CTR_ON_INT2_TAP_GEN          = 6,
  LSM303CTR_ON_INT1_INT2_TAP_GEN     = 7,
} lsm303ctr_hp_a_t;
int32_t lsm303ctr_xl_high_pass_int_conf_set(stmdev_ctx_t *ctx,
                                            lsm303ctr_hp_a_t val);
int32_t lsm303ctr_xl_high_pass_int_conf_get(stmdev_ctx_t *ctx,
                                            lsm303ctr_hp_a_t *val);

int32_t lsm303ctr_xl_pin_int1_config_set(stmdev_ctx_t *ctx,
                                         lsm303ctr_ctrl_reg3_a_t *val);
int32_t lsm303ctr_xl_pin_int1_config_get(stmdev_ctx_t *ctx,
                                         lsm303ctr_ctrl_reg3_a_t *val);

int32_t lsm303ctr_xl_int2_pin_detect_4d_set(stmdev_ctx_t *ctx,
                                            uint8_t val);
int32_t lsm303ctr_xl_int2_pin_detect_4d_get(stmdev_ctx_t *ctx,
                                            uint8_t *val);

typedef enum {
  LSM303CTR_INT2_PULSED   = 0,
  LSM303CTR_INT2_LATCHED  = 1,
} lsm303ctr_lir_int2_a_t;
int32_t lsm303ctr_xl_int2pin_notification_mode_set(stmdev_ctx_t *ctx,
                                                   lsm303ctr_lir_int2_a_t val);
int32_t lsm303ctr_xl_int2pin_notification_mode_get(stmdev_ctx_t *ctx,
                                                   lsm303ctr_lir_int2_a_t *val);

int32_t lsm303ctr_xl_int1_pin_detect_4d_set(stmdev_ctx_t *ctx,
                                            uint8_t val);
int32_t lsm303ctr_xl_int1_pin_detect_4d_get(stmdev_ctx_t *ctx,
                                            uint8_t *val);

typedef enum {
  LSM303CTR_INT1_PULSED   = 0,
  LSM303CTR_INT1_LATCHED  = 1,
} lsm303ctr_lir_int1_a_t;
int32_t lsm303ctr_xl_int1pin_notification_mode_set(stmdev_ctx_t *ctx,
                                                   lsm303ctr_lir_int1_a_t val);
int32_t lsm303ctr_xl_int1pin_notification_mode_get(stmdev_ctx_t *ctx,
                                                   lsm303ctr_lir_int1_a_t *val);

int32_t lsm303ctr_xl_pin_int2_config_set(stmdev_ctx_t *ctx,
                                         lsm303ctr_ctrl_reg6_a_t *val);
int32_t lsm303ctr_xl_pin_int2_config_get(stmdev_ctx_t *ctx,
                                         lsm303ctr_ctrl_reg6_a_t *val);

int32_t lsm303ctr_xl_fifo_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_xl_fifo_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_xl_fifo_watermark_set(stmdev_ctx_t *ctx,
                                        uint8_t val);
int32_t lsm303ctr_xl_fifo_watermark_get(stmdev_ctx_t *ctx,
                                        uint8_t *val);

typedef enum {
  LSM303CTR_INT1_GEN = 0,
  LSM303CTR_INT2_GEN = 1,
} lsm303ctr_tr_a_t;
int32_t lsm303ctr_xl_fifo_trigger_event_set(stmdev_ctx_t *ctx,
                                            lsm303ctr_tr_a_t val);
int32_t lsm303ctr_xl_fifo_trigger_event_get(stmdev_ctx_t *ctx,
                                            lsm303ctr_tr_a_t *val);

typedef enum {
  LSM303CTR_BYPASS_MODE           = 0,
  LSM303CTR_FIFO_MODE             = 1,
  LSM303CTR_DYNAMIC_STREAM_MODE   = 2,
  LSM303CTR_STREAM_TO_FIFO_MODE   = 3,
} lsm303ctr_fm_a_t;
int32_t lsm303ctr_xl_fifo_mode_set(stmdev_ctx_t *ctx,
                                   lsm303ctr_fm_a_t val);
int32_t lsm303ctr_xl_fifo_mode_get(stmdev_ctx_t *ctx,
                                   lsm303ctr_fm_a_t *val);

int32_t lsm303ctr_xl_fifo_status_get(stmdev_ctx_t *ctx,
                                     lsm303ctr_fifo_src_reg_a_t *val);

int32_t lsm303ctr_xl_fifo_data_level_get(stmdev_ctx_t *ctx,
                                         uint8_t *val);

int32_t lsm303ctr_xl_fifo_empty_flag_get(stmdev_ctx_t *ctx,
                                         uint8_t *val);

int32_t lsm303ctr_xl_fifo_ovr_flag_get(stmdev_ctx_t *ctx,
                                       uint8_t *val);

int32_t lsm303ctr_xl_fifo_fth_flag_get(stmdev_ctx_t *ctx,
                                       uint8_t *val);

int32_t lsm303ctr_tap_conf_set(stmdev_ctx_t *ctx,
                               lsm303ctr_click_cfg_a_t *val);
int32_t lsm303ctr_tap_conf_get(stmdev_ctx_t *ctx,
                               lsm303ctr_click_cfg_a_t *val);

int32_t lsm303ctr_tap_source_get(stmdev_ctx_t *ctx,
                                 lsm303ctr_click_src_a_t *val);

int32_t lsm303ctr_tap_threshold_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_tap_threshold_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_shock_dur_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_shock_dur_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_quiet_dur_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_quiet_dur_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_double_tap_timeout_set(stmdev_ctx_t *ctx,
                                         uint8_t val);
int32_t lsm303ctr_double_tap_timeout_get(stmdev_ctx_t *ctx,
                                         uint8_t *val);

int32_t lsm303ctr_act_threshold_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_act_threshold_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_act_timeout_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_act_timeout_get(stmdev_ctx_t *ctx, uint8_t *val);

typedef enum {
  LSM303CTR_SPI_4_WIRE = 0,
  LSM303CTR_SPI_3_WIRE = 1,
} lsm303ctr_sim_a_t;
int32_t lsm303ctr_xl_spi_mode_set(stmdev_ctx_t *ctx,
                                  lsm303ctr_sim_a_t val);
int32_t lsm303ctr_xl_spi_mode_get(stmdev_ctx_t *ctx,
                                  lsm303ctr_sim_a_t *val);

int32_t lsm303ctr_mag_user_offset_set(stmdev_ctx_t *ctx,
                                      int16_t *val);
int32_t lsm303ctr_mag_user_offset_get(stmdev_ctx_t *ctx,
                                      int16_t *val);

typedef enum {
  LSM303CTR_CONTINUOUS_MODE  = 0,
  LSM303CTR_SINGLE_TRIGGER   = 1,
  LSM303CTR_POWER_DOWN       = 2,
} lsm303ctr_md_m_t;
int32_t lsm303ctr_mag_operating_mode_set(stmdev_ctx_t *ctx,
                                         lsm303ctr_md_m_t val);
int32_t lsm303ctr_mag_operating_mode_get(stmdev_ctx_t *ctx,
                                         lsm303ctr_md_m_t *val);

typedef enum {
  LSM303CTR_MG_ODR_625mHz ,
  LSM303CTR_MG_ODR_1Hz5   ,
  LSM303CTR_MG_ODR_2Hz5   ,
  LSM303CTR_MG_ODR_5Hz    ,
  LSM303CTR_MG_ODR_10Hz   ,
  LSM303CTR_MG_ODR_20Hz   ,
  LSM303CTR_MG_ODR_40Hz   ,
  LSM303CTR_MG_ODR_80Hz   ,
} lsm303ctr_mg_odr_m_t;
int32_t lsm303ctr_mag_data_rate_set(stmdev_ctx_t *ctx,
                                    lsm303ctr_mg_odr_m_t val);
int32_t lsm303ctr_mag_data_rate_get(stmdev_ctx_t *ctx,
                                    lsm303ctr_mg_odr_m_t *val);

typedef enum {
  LSM303CTR_LOW_POWER        				,
  LSM303CTR_MEDIUM_PERFORMANCE 				,
  LSM303CTR_HIGH_PERFORMANCE 				,
  LSM303CTR_ULTRA_HIGH_PERFORMANCE        	,
} lsm303ctr_lp_m_t;
int32_t lsm303ctr_mag_power_mode_set(stmdev_ctx_t *ctx,
                                     lsm303ctr_lp_m_t val);
int32_t lsm303ctr_mag_power_mode_get(stmdev_ctx_t *ctx,
                                     lsm303ctr_lp_m_t *val);

int32_t lsm303ctr_mag_offset_temp_comp_set(stmdev_ctx_t *ctx,
                                           uint8_t val);
int32_t lsm303ctr_mag_offset_temp_comp_get(stmdev_ctx_t *ctx,
                                           uint8_t *val);

typedef enum {
  LSM303CTR_ODR_DIV_2  = 0,
  LSM303CTR_ODR_DIV_4  = 1,
} lsm303ctr_lpf_m_t;
int32_t lsm303ctr_mag_low_pass_bandwidth_set(stmdev_ctx_t *ctx,
                                             lsm303ctr_lpf_m_t val);
int32_t lsm303ctr_mag_low_pass_bandwidth_get(stmdev_ctx_t *ctx,
                                             lsm303ctr_lpf_m_t *val);

typedef enum {
  LSM303CTR_SET_SENS_ODR_DIV_63        = 0,
  LSM303CTR_SENS_OFF_CANC_EVERY_ODR    = 1,
  LSM303CTR_SET_SENS_ONLY_AT_POWER_ON  = 2,
} lsm303ctr_set_rst_m_t;
int32_t lsm303ctr_mag_set_rst_mode_set(stmdev_ctx_t *ctx,
                                       lsm303ctr_set_rst_m_t val);
int32_t lsm303ctr_mag_set_rst_mode_get(stmdev_ctx_t *ctx,
                                       lsm303ctr_set_rst_m_t *val);

int32_t lsm303ctr_mag_set_rst_sensor_single_set(stmdev_ctx_t *ctx,
                                                uint8_t val);
int32_t lsm303ctr_mag_set_rst_sensor_single_get(stmdev_ctx_t *ctx,
                                                uint8_t *val);

int32_t lsm303ctr_mag_block_data_update_set(stmdev_ctx_t *ctx,
                                            uint8_t val);
int32_t lsm303ctr_mag_block_data_update_get(stmdev_ctx_t *ctx,
                                            uint8_t *val);

int32_t lsm303ctr_mag_data_ready_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_mag_data_ovr_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_magnetic_raw_get(stmdev_ctx_t *ctx, int16_t *val);

int32_t lsm303ctr_mag_device_id_get(stmdev_ctx_t *ctx, uint8_t *buff);

int32_t lsm303ctr_mag_reset_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_mag_reset_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_mag_boot_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_mag_boot_get(stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm303ctr_mag_self_test_set(stmdev_ctx_t *ctx,
                                    uint8_t val);
int32_t lsm303ctr_mag_self_test_get(stmdev_ctx_t *ctx,
                                    uint8_t *val);

typedef enum {
  LSM303CTR_MG_LSB_AT_LOW_ADD  = 0,
  LSM303CTR_MG_MSB_AT_LOW_ADD  = 1,
} lsm303ctr_ble_m_t;
int32_t lsm303ctr_mag_data_format_set(stmdev_ctx_t *ctx,
                                      lsm303ctr_ble_m_t val);
int32_t lsm303ctr_mag_data_format_get(stmdev_ctx_t *ctx,
                                      lsm303ctr_ble_m_t *val);

int32_t lsm303ctr_mag_status_get(stmdev_ctx_t *ctx,
                                 lsm303ctr_status_reg_m_t *val);

typedef enum {
  LSM303CTR_CHECK_BEFORE  = 0,
  LSM303CTR_CHECK_AFTER   = 1,
} lsm303ctr_int_on_dataoff_m_t;
int32_t lsm303ctr_mag_offset_int_conf_set(stmdev_ctx_t *ctx,
                                          lsm303ctr_int_on_dataoff_m_t val);
int32_t lsm303ctr_mag_offset_int_conf_get(stmdev_ctx_t *ctx,
                                          lsm303ctr_int_on_dataoff_m_t *val);

int32_t lsm303ctr_mag_drdy_on_pin_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_mag_drdy_on_pin_get(stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lsm303ctr_mag_int_on_pin_set(stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm303ctr_mag_int_on_pin_get(stmdev_ctx_t *ctx, uint8_t *val);

/*int32_t lsm303ctr_mag_int_gen_conf_set(stmdev_ctx_t *ctx,
                                       lsm303ctr_int_crtl_reg_m_t *val);
int32_t lsm303ctr_mag_int_gen_conf_get(stmdev_ctx_t *ctx,
                                       lsm303ctr_int_crtl_reg_m_t *val);

int32_t lsm303ctr_mag_int_gen_source_get(stmdev_ctx_t *ctx,
                                         lsm303ctr_int_source_reg_m_t *val);

int32_t lsm303ctr_mag_int_gen_treshold_set(stmdev_ctx_t *ctx,
                                           int16_t val);
int32_t lsm303ctr_mag_int_gen_treshold_get(stmdev_ctx_t *ctx,
                                           int16_t *val);
*/
typedef enum {
  LSM303CTR_I2C_ENABLE   = 0,
  LSM303CTR_I2C_DISABLE  = 1,
} lsm303ctr_i2c_dis_m_t;
int32_t lsm303ctr_mag_i2c_interface_set(stmdev_ctx_t *ctx,
                                        lsm303ctr_i2c_dis_m_t val);
int32_t lsm303ctr_mag_i2c_interface_get(stmdev_ctx_t *ctx,
                                        lsm303ctr_i2c_dis_m_t *val);

/**
  * @}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /* LSM303CTR_REGS_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
