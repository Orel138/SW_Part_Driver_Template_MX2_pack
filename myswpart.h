/**
  ******************************************************************************
  * @file    myswpart.h
  * @brief   Minimal public interface for the MySWPart driver template.
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

#ifndef MYSWPART_H
#define MYSWPART_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "myswpart_io.h"

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  MySWPart_OK = 0,
  MySWPart_ERROR = -1
} myswpart_drv_status_t;

typedef struct
{
  uint32_t id;             /*!< Instance identifier selected by the application. */
  uint8_t is_initialized;  /*!< Initialization state of the object. */
  myswpart_io_t io;        /*!< Low-level I/O resources used by the driver. */
} myswpart_object_t;

/* Exported functions --------------------------------------------------------*/
myswpart_drv_status_t myswpart_drv_init(myswpart_object_t *p_obj, uint32_t id);
myswpart_drv_status_t myswpart_drv_deinit(myswpart_object_t *p_obj);
myswpart_drv_status_t myswpart_drv_write_reg(myswpart_object_t *p_obj, uint8_t reg,
                                             const uint8_t *p_data, uint16_t length);
myswpart_drv_status_t myswpart_drv_read_reg(myswpart_object_t *p_obj, uint8_t reg,
                                            uint8_t *p_data, uint16_t length);

#ifdef __cplusplus
}
#endif

#endif /* MYSWPART_H */
