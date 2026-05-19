/**
  ******************************************************************************
  * @file    myswpart.c
  * @brief   Minimal core implementation for the MySWPart driver template.
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
#include "myswpart.h"
#include <string.h>

/* Private function prototypes -----------------------------------------------*/
static myswpart_drv_status_t myswpart_drv_check_object(const myswpart_object_t *p_obj);

/**
  * @brief  Check that the object is valid and initialized.
  * @param  p_obj Pointer to the driver object.
  * @retval MySWPart_OK when the object can be used, MySWPart_ERROR otherwise.
  */
static myswpart_drv_status_t myswpart_drv_check_object(const myswpart_object_t *p_obj)
{
  myswpart_drv_status_t status = MySWPart_ERROR;

  if ((p_obj != NULL) && (p_obj->is_initialized == 1U))
  {
    status = MySWPart_OK;
  }

  return status;
}

/**
  * @brief  Initialize a MySWPart object.
  * @param  p_obj Pointer to the driver object.
  * @param  id User-defined object identifier.
  * @retval MySWPart_OK in case of success, MySWPart_ERROR otherwise.
  */
myswpart_drv_status_t myswpart_drv_init(myswpart_object_t *p_obj, uint32_t id)
{
  if (p_obj == NULL)
  {
    return MySWPart_ERROR;
  }

  (void)memset(p_obj, 0, sizeof(*p_obj));
  p_obj->id = id;
  p_obj->io.id = id;

  if (myswpart_io_init(&p_obj->io) != 0)
  {
    (void)memset(p_obj, 0, sizeof(*p_obj));
    return MySWPart_ERROR;
  }

  p_obj->is_initialized = 1U;

  return MySWPart_OK;
}

/**
  * @brief  Deinitialize a MySWPart object.
  * @param  p_obj Pointer to the driver object.
  * @retval MySWPart_OK in case of success, MySWPart_ERROR otherwise.
  */
myswpart_drv_status_t myswpart_drv_deinit(myswpart_object_t *p_obj)
{
  if (p_obj == NULL)
  {
    return MySWPart_ERROR;
  }

  if (p_obj->is_initialized == 0U)
  {
    return MySWPart_OK;
  }

  p_obj->is_initialized = 0U;
  p_obj->id = 0U;
  (void)memset(&p_obj->io, 0, sizeof(p_obj->io));

  return MySWPart_OK;
}

/**
  * @brief  Write a register through the selected I/O layer.
  * @param  p_obj Pointer to the driver object.
  * @param  reg Register address.
  * @param  p_data Pointer to the write buffer.
  * @param  length Number of bytes to write.
  * @retval MySWPart_OK in case of success, MySWPart_ERROR otherwise.
  */
myswpart_drv_status_t myswpart_drv_write_reg(myswpart_object_t *p_obj, uint8_t reg,
                                             const uint8_t *p_data, uint16_t length)
{
  if (myswpart_drv_check_object(p_obj) != MySWPart_OK)
  {
    return MySWPart_ERROR;
  }

  if ((p_data == NULL) && (length > 0U))
  {
    return MySWPart_ERROR;
  }

  if (length == 0U)
  {
    return MySWPart_OK;
  }

  if (myswpart_io_write_reg(&p_obj->io, reg, p_data, length) != 0)
  {
    return MySWPart_ERROR;
  }

  return MySWPart_OK;
}

/**
  * @brief  Read a register through the selected I/O layer.
  * @param  p_obj Pointer to the driver object.
  * @param  reg Register address.
  * @param  p_data Pointer to the destination buffer.
  * @param  length Number of bytes to read.
  * @retval MySWPart_OK in case of success, MySWPart_ERROR otherwise.
  */
myswpart_drv_status_t myswpart_drv_read_reg(myswpart_object_t *p_obj, uint8_t reg,
                                            uint8_t *p_data, uint16_t length)
{
  if (myswpart_drv_check_object(p_obj) != MySWPart_OK)
  {
    return MySWPart_ERROR;
  }

  if ((p_data == NULL) && (length > 0U))
  {
    return MySWPart_ERROR;
  }

  if (length == 0U)
  {
    return MySWPart_OK;
  }

  if (myswpart_io_read_reg(&p_obj->io, reg, p_data, length) != 0)
  {
    return MySWPart_ERROR;
  }

  return MySWPart_OK;
}
