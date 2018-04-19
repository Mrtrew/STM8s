/** @page I2C_10bitsMasterCommunication Master transmitter Communication between two I2C peripherals 


  @par Example description

  This example provides a short description of how to communicate with the I2C:
  - In 10bit addressing mode master transmitter with a clock speed set to 200KHz.
  

  @par Directory contents

  - I2C\I2C_10bitsCommunication\master\main.c                    Main file containing the "main" functions 
  - I2C\I2C_10bitsCommunication\master\stm8s_conf.h              Library Configuration file
  - I2C\I2C_10bitsCommunication\master\stm8s_it.c                Interrupt routines source (not used in this example)
  - I2C\I2C_10bitsCommunication\master\stm8s_it.h                Interrupt routines declaration
  - I2C\I2C_10bitsCommunication\master\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - This examples needs two STM8/128-EVAL boards (or equivalent hardware)
    - Connect the STM8S I2C to a second I2C 
      - SDA pin (PE2) -> SDA pin.
      - SCL pin (PE1) -> SCL pin.
      - On SDA & SCL pins do not forget pull-up resistors (4.7k ohms)
      --> already present on the STM8/128-EVAL board.
      - Set the slave I2C address to 0x102.
	  	  

  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_i2c.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Before perfoming the next step, be sure that the slave program is already running
  - Run program: Debug->Run (Ctrl+F5).
  - The four LEDs toggle when the I2C communication is terminated.

   
  */
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
