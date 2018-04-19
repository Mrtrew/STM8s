/** @page I2C_Interrupt I2C data transfer in interrupt mode


  @par Example description

  This example provides a short description of how to: 
  - Transfer a data byte to a second I2C using interrupts.
  - The communication is configured in 7bit addressing mode with a clock speed set to 100KHz.
  - The event and buffer interrupts are enabled for the I2C.
  - Once the start signal is generated the interrupt function detects each interrupt and sends a byte to the slave
  then generate a STOP condition.


  @par Directory contents

  - I2C\I2C_Interrupt\main.c                    Main file containing the "main" function
  - I2C\I2C_Interrupt\stm8s_conf.h              Library Configuration file
  - I2C\I2C_Interrupt\stm8s_it.c                Interrupt routines source
  - I2C\I2C_Interrupt\stm8s_it.h                Interrupt routines declaration
  - I2C\I2C_Interrupt\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208, STM8S207, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - This examples can be tested using either of hardware 2 solutions:
    - Solution 1 :
      - Connect the STM8S I2C to a second I2C 
      - SDA pin (PE2) -> SDA pin.
      - SCL pin (PE1) -> SCL pin.
      - On SDA & SCL pins do not forget pull-up resistors (4.7k ohms)
      --> already present on the STM8/128-EVAL board.

    - Solution 2 :	  
     - Connect the STM8S I2C to an Aardvark I2C/SPI module
      - SDA pin -> SDA pin (PE2).
      - SCL pin -> SCL pin (PE1).
      - Pull-up is integrated by default in the Aardvark module.
      - Set the Aardvark module as slave. In the graphical interface set address 0x50(=0xA0) in 100KHz.
	  

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
  - Configure and enable the Aardvark as slave.
  - Run program: Debug->Run (Ctrl+F5).
  - The buffer will be filled up with the sent byte.
  - The four LEDs will blink at the end of I2C communication sequence.

  
  */
/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
