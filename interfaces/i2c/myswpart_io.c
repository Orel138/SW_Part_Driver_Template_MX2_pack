/**
  ******************************************************************************
  * @file    myswpart_io.c
  * @brief   Minimal I2C I/O layer for the MySWPart driver template.
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
  * @brief  Write one register frame over I2C.
  * @param  pio Pointer to the I/O object.
  * @param  reg Register address.
  * @param  p_data Pointer to the source buffer.
  * @param  length Number of bytes to write.
  * @retval 0 in case of success, -1 otherwise.
  */
int32_t myswpart_io_write_reg(myswpart_io_t *pio, uint8_t reg, const uint8_t *p_data, uint16_t length)
{
  if ((pio == NULL) || (pio->hi2c == NULL))
  {
    return -1;
  }

  if ((p_data == NULL) && (length > 0U))
  {
    return -1;
  }

  if (HAL_I2C_MASTER_MemWrite(pio->hi2c, pio->addr, reg, HAL_I2C_MEM_ADDR_8BIT,
                              (uint8_t *)p_data, length, MYSWPART_I2C_TIMEOUT_MS) != HAL_OK)
  {
    return -1;
  }

  return 0;
}

/**
  * @brief  Read one register frame over I2C.
  * @param  pio Pointer to the I/O object.
  * @param  reg Register address.
  * @param  p_data Pointer to the destination buffer.
  * @param  length Number of bytes to read.
  * @retval 0 in case of success, -1 otherwise.
  */
int32_t myswpart_io_read_reg(myswpart_io_t *pio, uint8_t reg, uint8_t *p_data, uint16_t length)
{
  if ((pio == NULL) || (pio->hi2c == NULL))
  {
    return -1;
  }

  if ((p_data == NULL) && (length > 0U))
  {
    return -1;
  }

  if (HAL_I2C_MASTER_MemRead(pio->hi2c, pio->addr, reg, HAL_I2C_MEM_ADDR_8BIT,
                             p_data, length, MYSWPART_I2C_TIMEOUT_MS) != HAL_OK)
  {
    return -1;
  }

  return 0;
}
