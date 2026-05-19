/**
  ******************************************************************************
  * @file    myswpart_io.c
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

/* Includes ------------------------------------------------------------------*/
#include "myswpart_io.h"

/* Private function prototypes -----------------------------------------------*/
static void myswpart_io_select(const myswpart_io_t *pio);
static void myswpart_io_unselect(const myswpart_io_t *pio);

/**
  * @brief  Drive chip-select active.
  * @param  pio Pointer to the I/O object.
  */
static void myswpart_io_select(const myswpart_io_t *pio)
{
  HAL_GPIO_WritePin(pio->cs_port, pio->cs_pin, HAL_GPIO_PIN_RESET);
}

/**
  * @brief  Drive chip-select inactive.
  * @param  pio Pointer to the I/O object.
  */
static void myswpart_io_unselect(const myswpart_io_t *pio)
{
  HAL_GPIO_WritePin(pio->cs_port, pio->cs_pin, HAL_GPIO_PIN_SET);
}

/**
  * @brief  Assign hardware resources to the I/O object.
  * @param  pio Pointer to the I/O object.
  * @retval 0 in case of success, -1 otherwise.
  * @note   Override this weak function in generated code or user code.
  */
__WEAK int32_t myswpart_io_init(myswpart_io_t *pio)
{
  (void)pio;
  return -1;
}

/**
  * @brief  Write one register frame over SPI.
  * @param  pio Pointer to the I/O object.
  * @param  reg Register address.
  * @param  p_data Pointer to the source buffer.
  * @param  length Number of bytes to write.
  * @retval 0 in case of success, -1 otherwise.
  */
int32_t myswpart_io_write_reg(myswpart_io_t *pio, uint8_t reg, const uint8_t *p_data, uint16_t length)
{
  uint8_t header;

  if ((pio == NULL) || (pio->hspi == NULL))
  {
    return -1;
  }

  if ((p_data == NULL) && (length > 0U))
  {
    return -1;
  }

  header = reg;
  myswpart_io_select(pio);

  if (HAL_SPI_Transmit(pio->hspi, &header, 1U, MYSWPART_SPI_TIMEOUT_MS) != HAL_OK)
  {
    myswpart_io_unselect(pio);
    return -1;
  }

  if ((length > 0U) &&
      (HAL_SPI_Transmit(pio->hspi, (uint8_t *)p_data, length, MYSWPART_SPI_TIMEOUT_MS) != HAL_OK))
  {
    myswpart_io_unselect(pio);
    return -1;
  }

  myswpart_io_unselect(pio);

  return 0;
}

/**
  * @brief  Read one register frame over SPI.
  * @param  pio Pointer to the I/O object.
  * @param  reg Register address.
  * @param  p_data Pointer to the destination buffer.
  * @param  length Number of bytes to read.
  * @retval 0 in case of success, -1 otherwise.
  */
int32_t myswpart_io_read_reg(myswpart_io_t *pio, uint8_t reg, uint8_t *p_data, uint16_t length)
{
  uint8_t header;

  if ((pio == NULL) || (pio->hspi == NULL))
  {
    return -1;
  }

  if ((p_data == NULL) && (length > 0U))
  {
    return -1;
  }

  header = reg | 0x80U;
  myswpart_io_select(pio);

  if (HAL_SPI_Transmit(pio->hspi, &header, 1U, MYSWPART_SPI_TIMEOUT_MS) != HAL_OK)
  {
    myswpart_io_unselect(pio);
    return -1;
  }

  if ((length > 0U) &&
      (HAL_SPI_Receive(pio->hspi, p_data, length, MYSWPART_SPI_TIMEOUT_MS) != HAL_OK))
  {
    myswpart_io_unselect(pio);
    return -1;
  }

  myswpart_io_unselect(pio);

  return 0;
}
