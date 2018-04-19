/** @page CLK_MaxSpeed Configuring clocks for maximum speed


  @par Example description

  This example provides two optimal clock configurations
  - Fcpu running at 24Mhz (HSE)
  - Fcpu running at 16Mhz (HSI)


  @par Directory contents

  - CLK\CLK_MaxSpeed\main.c                    Main file containing the "main" function
	- CLK\CLK_MaxSpeed\main.h                    Main functions prototype
  - CLK\CLK_MaxSpeed\stm8s_conf.h              Library Configuration file
  - CLK\CLK_MaxSpeed\stm8s_it.c                Interrupt routines source
  - CLK\CLK_MaxSpeed\stm8s_it.h                Interrupt routines declaration
  - CLK\CLK_MaxSpeed\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
      - Connect PE0 (CCO pin) to an oscilloscope 


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_clk.c
    - stm8s_exti.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - Using the KEY button switch from HSE to HSI.
  - The clock switching can be monitored by putting a scope on PE0 (CCO).

  @par Hint

  - Before using the HSE clock ensure that the "Flash_Wait_States" is set to 1. This is 
    accessed in Debug instrument -> MCU configuration -> Options

  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
