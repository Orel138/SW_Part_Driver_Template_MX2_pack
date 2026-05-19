# origin-pack: MyVendor::myswpart_part_drivers@1.0.0
# file-format: 1.0.0
project(MyVendor_myswpart_part_drivers_1_0_0)
cmake_minimum_required(VERSION 3.20)
add_library(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE)

# List of all CMSIS properties that influence conditions for this package


# Device specific defined symbols








# Enable all components in this package
if(CMSIS_ENTIRE_MyVendor_myswpart_part_drivers_1_0_0)
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart Core#Cversion:0.10.0")
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart IO#Cvariant:I2C Polling#Cversion:0.2.0")
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart IO#Cvariant:SPI Polling#Cversion:0.2.0")
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart IO#Cvariant:Custom#Cversion:0.2.0")
endif()

# All conditions used by this package

# condition: MyVendor.myswpart_part_drivers.1.0.0:MySWPart CFG Condition
# description: MyVendor configuration for MySWPart part driver
set(MyVendor.myswpart_part_drivers.1.0.0_MySWPart_CFG_Condition "1")
message(DEBUG "CMSIS condition MyVendor.myswpart_part_drivers.1.0.0_MySWPart_CFG_Condition enabled")


# condition: MyVendor.myswpart_part_drivers.1.0.0:MySWPart Core Condition
# description: MyVendor MySWPart Core Driver
set(MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Core_Condition "1")
message(DEBUG "CMSIS condition MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Core_Condition enabled")


# condition: MyVendor.myswpart_part_drivers.1.0.0:MySWPart Custom IO Condition
# description: 
set(MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Custom_IO_Condition "1")
message(DEBUG "CMSIS condition MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Custom_IO_Condition enabled")


# condition: MyVendor.myswpart_part_drivers.1.0.0:MySWPart IO I2C Polling Condition
# description: MyVendor MySWPart IO I2C Polling Driver
set(MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_I2C_Polling_Condition "$<AND:$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:I2C(#.*|$)>,>>,$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:GPIO(#.*|$)>,>>,$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:EXTI(#.*|$)>,>>>")
message(DEBUG "CMSIS condition MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_I2C_Polling_Condition enabled")


# condition: MyVendor.myswpart_part_drivers.1.0.0:MySWPart IO SPI Polling Condition
# description: MyVendor MySWPart IO SPI Polling Driver
set(MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_SPI_Polling_Condition "$<AND:$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:SPI(#.*|$)>,>>,$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:GPIO(#.*|$)>,>>,$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:EXTI(#.*|$)>,>>>")
message(DEBUG "CMSIS condition MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_SPI_Polling_Condition enabled")

# Files and components in this package
if("Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart Core#Cversion:0.10.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Minimal core driver template for MySWPart
  message(DEBUG "Using component Board_Part_Sensor_MySWPart_Core_0_10_0")
  target_compile_definitions(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Core_Condition}:-DCMSIS_USE_Board_Part_Sensor_MySWPart_Core_0_10_0=1>")
  target_include_directories(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Core_Condition}:${CMAKE_CURRENT_LIST_DIR}/.>")
  target_sources(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Core_Condition}:${CMAKE_CURRENT_LIST_DIR}/myswpart.c>")
endif()

if("Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart IO#Cvariant:I2C Polling#Cversion:0.2.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Minimal I2C I/O layer for MySWPart
  message(DEBUG "Using component Board_Part_Sensor_MySWPart_IO_I2C_Polling_0_2_0")
  target_compile_definitions(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_I2C_Polling_Condition}:-DCMSIS_USE_Board_Part_Sensor_MySWPart_IO_I2C_Polling_0_2_0=1>")
  target_include_directories(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_I2C_Polling_Condition}:${CMAKE_CURRENT_LIST_DIR}/interfaces/i2c>")
  target_sources(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_I2C_Polling_Condition}:${CMAKE_CURRENT_LIST_DIR}/interfaces/i2c/myswpart_io.c>")
endif()

if("Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart IO#Cvariant:SPI Polling#Cversion:0.2.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Minimal SPI I/O layer for MySWPart
  message(DEBUG "Using component Board_Part_Sensor_MySWPart_IO_SPI_Polling_0_2_0")
  target_compile_definitions(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_SPI_Polling_Condition}:-DCMSIS_USE_Board_Part_Sensor_MySWPart_IO_SPI_Polling_0_2_0=1>")
  target_include_directories(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_SPI_Polling_Condition}:${CMAKE_CURRENT_LIST_DIR}/interfaces/spi>")
  target_sources(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_IO_SPI_Polling_Condition}:${CMAKE_CURRENT_LIST_DIR}/interfaces/spi/myswpart_io.c>")
endif()

if("Cvendor:MyVendor#Cclass:Board Part#Cgroup:Sensor#Csub:MySWPart IO#Cvariant:Custom#Cversion:0.2.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Custom I/O layer template for MySWPart
  message(DEBUG "Using component Board_Part_Sensor_MySWPart_IO_Custom_0_2_0")
  target_compile_definitions(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Custom_IO_Condition}:-DCMSIS_USE_Board_Part_Sensor_MySWPart_IO_Custom_0_2_0=1>")
  target_include_directories(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Custom_IO_Condition}:${CMAKE_CURRENT_LIST_DIR}/interfaces/custom>")
  if(EXISTS ${CMSIS_RTE_FOLDER}/Board Part/myswpart_io.c)
    target_sources(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Custom_IO_Condition}:${CMSIS_RTE_FOLDER}/Board Part/myswpart_io.c>")
  else()
    target_sources(MyVendor_myswpart_part_drivers_1_0_0 INTERFACE "$<${MyVendor.myswpart_part_drivers.1.0.0_MySWPart_Custom_IO_Condition}:${CMAKE_CURRENT_LIST_DIR}/interfaces/custom/myswpart_io.c>")
  endif()
endif()
