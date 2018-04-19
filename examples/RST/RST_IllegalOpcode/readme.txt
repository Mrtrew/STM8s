/** @page RST_IllegalOpcode Illegal Opcode Reset


  @par Example description

  This example provides a short description of how to generate detect 
  and manage an illegal opcode reset. 
	Pressing the KEY button will cause a jump to a specific memory 
  address where an illegal opcode is written, so a reset is generated. 
  LEDs from 1 to 4 start blinking fast signaling the ILLOP reset.
	When the reset flag is cleared they will blink slowly.


  @par Directory contents

  - RST\RST_IllegalOpcode\main.c                    Main file containing the "main" function
  - RST\RST_IllegalOpcode\stm8s_conf.h              Library Configuration file
  - RST\RST_IllegalOpcode\stm8s_it.c                Interrupt routines source
  - RST\RST_IllegalOpcode\stm8s_it.h                Interrupt routines declaration
  - RST\RST_IllegalOpcode\stm8_interrupt_vector.c   Interrupt vectors table


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
    - stm8s_exti.c
    - stm8s_flash.c
    - stm8s_rst.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The LD1, LD2, LD3 and LD4 are ON
  - If you press the button, a Reset occurs and LD1,2,3 and 4 blink fast


  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
