/** @page EXTI_InterruptPriority Reading buttons state using external interrupts


  @par Example description

  This example provides a short description of how to use the EXTI peripheral:
  - Configuration of External Interrupt / Falling edge and TLI
  - LEDs are toggling at each interrupt detected


  @par Directory contents

  - EXTI\EXTI_InterruptPriority\main.c                    Main file containing the "main" function
  - EXTI\EXTI_InterruptPriority\stm8s_conf.h              Library Configuration file
  - EXTI\EXTI_InterruptPriority\stm8s_it.c                Interrupt routines source
  - EXTI\EXTI_InterruptPriority\stm8s_it.h                Interrupt routines declaration
  - EXTI\EXTI_InterruptPriority\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Four leds LD1 to LD4 are used.
     - Joystick LEFT, RIGHT, UP, DOWN and SEL buttons are used.


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_exti.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The LD1, LD2, LD3 and LD4 are ON per default
  - Joystick LEFT  pressed: toggle LED1
  - Joystick RIGHT pressed: toggle LED2
  - Joystick UP    pressed: toggle LED3
  - Joystick DOWN  pressed: toggle LED4
  - Joystick SEL   pressed: toggle all LEDs

 
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
