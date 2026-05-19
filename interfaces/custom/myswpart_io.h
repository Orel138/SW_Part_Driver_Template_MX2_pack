/**
  ******************************************************************************
  * @file    myswpart_io.h
  * @brief   Custom I/O layer template for the MySWPart driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 MyVendor.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef MYSWPART_IO_H
#define MYSWPART_IO_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32_hal.h"

/* Exported types ------------------------------------------------------------*/
typedef struct myswpart_io_s
{
  uint32_t id;                   /*!< Instance identifier. */
  void *bus_handle;              /*!< Replace with the bus handle type used by your project. */
  uint16_t address;              /*!< Optional device address for bus protocols that need one. */
  hal_gpio_t cs_port;            /*!< Optional chip-select GPIO port for SPI-like buses. */
  uint32_t cs_pin;               /*!< Optional chip-select GPIO pin for SPI-like buses. */
  hal_exti_handle_t *hexti_int1; /*!< Optional interrupt handle reserved for user extensions. */
  hal_exti_handle_t *hexti_int2; /*!< Optional interrupt handle reserved for user extensions. */
} myswpart_io_t;

/* Exported functions --------------------------------------------------------*/
int32_t myswpart_io_init(myswpart_io_t *pio);
int32_t myswpart_io_write_reg(myswpart_io_t *pio, uint8_t reg, const uint8_t *p_data, uint16_t length);
int32_t myswpart_io_read_reg(myswpart_io_t *pio, uint8_t reg, uint8_t *p_data, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* MYSWPART_IO_H */
