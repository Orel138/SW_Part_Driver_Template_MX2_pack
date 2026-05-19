/**
  ******************************************************************************
  * @file    myswpart_io.h
  * @brief   Minimal SPI I/O layer for the MySWPart driver template.
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

/* Exported macros -----------------------------------------------------------*/
#define MYSWPART_SPI_TIMEOUT_MS 0x1000UL

/* Exported types ------------------------------------------------------------*/
typedef struct myswpart_io_s
{
  uint32_t id;                   /*!< Instance identifier. */
  hal_spi_handle_t *hspi;        /*!< HAL SPI handle assigned by user code. */
  hal_gpio_t cs_port;            /*!< Chip-select GPIO port. */
  uint32_t cs_pin;               /*!< Chip-select GPIO pin. */
  hal_exti_handle_t *hexti_int1; /*!< Optional EXTI handle reserved for user extensions. */
  hal_exti_handle_t *hexti_int2; /*!< Optional EXTI handle reserved for user extensions. */
} myswpart_io_t;

/* Exported functions --------------------------------------------------------*/
int32_t myswpart_io_init(myswpart_io_t *pio);
int32_t myswpart_io_write_reg(myswpart_io_t *pio, uint8_t reg, const uint8_t *p_data, uint16_t length);
int32_t myswpart_io_read_reg(myswpart_io_t *pio, uint8_t reg, uint8_t *p_data, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* MYSWPART_IO_H */
