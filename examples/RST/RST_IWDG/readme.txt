/** @page RST_IWDG IWDG Reset


  @par Example description

  This example provides a short description of how to generate detect and
  manage an	IWDG reset.
	The TIM4 is used to refresh the IWDG each 16 ms.
	Pressing the KEY button will stop refreshing the IWDG, so a reset is generated. 
  LEDs from 1 to 4 blink five times, signaling the IWDG reset. 
  When the reset flag is cleared they stay lit continuously.	


  @par Directory contents

  - RST\RST_IWDG\main.c                    Main file containing the "main" function
  - RST\RST_IWDG\stm8s_conf.h              Library Configuration file
  - RST\RST_IWDG\stm8s_it.c                Interrupt routines source
  - RST\RST_IWDG\stm8s_it.h                Interrupt routines declaration
  - RST\RST_IWDG\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Four leds LD1 to LD4 and Key push button are used.


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_iwdg.c
    - stm8s_tim4.c
    - stm8s_gpio.c
    - stm8s_clk.c
    - stm8s_rst.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The LED1, LED2, LED3 and LED4 are ON
  - If you press the button, a Reset occurs and LEDs blink


  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
