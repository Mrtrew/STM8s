/** @page CLK_ClockSelection How to select the different clock sources


  @par Example description

  This example demonstrates the possibility to select the different clock sources 
  using the joystick available on the evaluation board.
  - To select a clock source, push the joystick in the corresponding direction. 
    UP = HSE, DOWN = LSI & RIGHT = HSI
  - The current clock selection will be displayed on the LCD.
  - Each one is associated to LEDs from 1 to 3 respectively.
  - LEDs frequency blinking will change according to the selected clock.


  @par Directory contents

  - CLK\CLK_ClockSelection\main.c                    Main file containing the "main" function
  - CLK\CLK_ClockSelection\stm8s_conf.h              Library Configuration file
  - CLK\CLK_ClockSelection\stm8s_it.c                Interrupt routines source
  - CLK\CLK_ClockSelection\stm8s_it.h                Interrupt routines declaration
  - CLK\CLK_ClockSelection\stm8_interrupt_vector.c   Interrupt vectors table


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
    - stm8s_spi.c
    - stm8s_clk.c
    - stm8s_gpio.c
    - mono_lcd.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - Using the joystick choose the desired clock source to apply:
    UP = HSE, DOWN = LSI & LEFT = HSI
  - Observe that the LED associated with the clock is blinking: 
    LD1 -> HSE, LD2 -> LSI, LD3 -> HSI
  - A message is displayed on the LCD to indicate the currently used clock.
  - The clock switching can be monitored by putting a scope on PE0 (CCO).


  @par Hint
  
  - Before using the HSE clock ensure that the "Flash_Wait_States" is set to 1. This is 
    accessed in Debug instrument -> MCU configuration -> Options
  - Before using the LSI clock you have to configure the option bytes in order 
    to enable the "LSI_EN". This is accessed through 
    Debug instrument -> MCU configuration -> Options.
  
 
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
