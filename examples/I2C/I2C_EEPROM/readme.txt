/** @page I2C_EEPROM Write & Read data in an I2C EEPROM memory


  @par Example description

  This example provides a short description of how to: 
  - Communicate with an EEPROM
  - Perform a write data buffer in the EEPROM memory
  - Perform a random read of the previous written buffer
  - Compare the written and received data buffers.
  - The communication is configured in 7-bit addressing mode with a clock speed set to 400 KHz. 


  @par Directory contents

  - I2C\I2C_EEPROM\main.c                    Main file containing the "main" function
  - I2C\I2C_EEPROM\stm8s_conf.h              Library Configuration file
  - I2C\I2C_EEPROM\stm8s_it.c                Interrupt routines source (not used in this example)
  - I2C\I2C_EEPROM\stm8s_it.h                Interrupt routines declaration
  - I2C\I2C_EEPROM\stm8_interrupt_vector.c   Interrupt vectors table
  - I2C\I2C_EEPROM\i2c_ee.c                  M24C64 EEPROM functions to manage communication with I2C
  - I2C\I2C_EEPROM\i2c_ee.h                  M24C64 EEPROM functions declaration


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - This example uses the I2C EEPROM already available on STM8/128-EVAL board.
     - Before Running the example make sure that JP8 is fitted.
     

  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_i2c.c
    - stm8s_gpio.c
    - i2c_ee.c (under FWLib\examples\I2C\I2C_EEPROM)
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The test will compare the sent buffer & received buffer data.
  - The four LEDs will blink if both buffers are equals otherwise only the LED1 will blink.

  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
