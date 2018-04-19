/** @page IWDG_RearmReset IWDG refreshing, IWDG Reset


  @par Example description

  This example provides a short description of how to use the IWDG peripheral:
	If the Key Button is not pressed the IWDG is refreshed continually and LED1,
	and LED3 are ON.
	If the Key Button is pressed, the refresh of the IWDG is stopped and after a
	short time, the IWDG generates a Reset. If an IWDG Reset has occurred, LED2 
	and LED4 will blink n times. In this example, n is fixed to 2.
	
	

  @par Directory contents

  - IWDG\IWDG_RearmReset\main.c                    Main file containing the "main" function
  - IWDG\IWDG_RearmReset\stm8s_conf.h              Library Configuration file
  - IWDG\IWDG_RearmReset\stm8s_it.c                Interrupt routines source 
  - IWDG\IWDG_RearmReset\stm8s_it.h                Interrupt routines declaration
  - IWDG\IWDG_RearmReset\stm8_interrupt_vector.c   Interrupt vectors table


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
    - stm8s_rst.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The LED1 and LED3 are ON
  - If you press the button, a Reset occurs and LED2 and LD4 blink 2 times
    
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
