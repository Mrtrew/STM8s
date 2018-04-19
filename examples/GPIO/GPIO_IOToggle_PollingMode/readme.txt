/** @page GPIO_IOToggle_PollingMode LEDs toggling, Button reading in polling mode


  @par Example description

  This example provides a short description of how to use the GPIO peripheral:
  - Initialization of the GPIO in output and input modes
  - LEDs toggling
  - Button state reading in polling mode


  @par Directory contents

  - GPIO\GPIO_IOToggle_PollingMode\main.c                   Main file containing the "main" function
  - GPIO\GPIO_IOToggle_PollingMode\stm8s_conf.h             Library Configuration file
  - GPIO\GPIO_IOToggle_PollingMode\stm8s_it.c               Interrupt routines source (not used in this example)
  - GPIO\GPIO_IOToggle_PollingMode\stm8s_it.h               Interrupt routines declaration
  - GPIO\GPIO_IOToggle_PollingMode\stm8_interrupt_vector.c  Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208 and STM8S207 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Four leds LD1 to LD4 and Key push button are used.


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The LD1 and LD4 blink continuously
  - If you press the button only LD2 and LD3 blink
  - Release the button, the LD1 and LD4 blink again
 
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
