/** @page AWU_ActiveHaltMode Using the AWU to wake-up the CPU from Active Halt mode


  @par Example description

  This example provides a short description of how to use the AWU peripheral:
  - Initialization of the AWU peripheral
  - Initialization of GPIO pins in output mode in order to drive LEDs
  - Initialization of a GPIO in input mode in order to read the Key Button state


  @par Directory contents

  - AWU\AWU_ActiveHaltMode\main.c                    Main file containing the "main" function
  - AWU\AWU_ActiveHaltMode\stm8s_conf.h              Library Configuration file
  - AWU\AWU_ActiveHaltMode\stm8s_it.c                Interrupt routines source (not used in this example)
  - AWU\AWU_ActiveHaltMode\stm8s_it.h                Interrupt routines declaration
  - AWU\AWU_ActiveHaltMode\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.
    
  @note: to run this example with STM8S103 and STM8S903 devices, TIM1 should be used 
  instead of TIM3 for LSI calibration (AWU_AutoLSICalibration function has to be updated accordingly).
  
  - STM8/128-EVAL Set-up
     - Four leds LD1 to LD4 and Key push button are used.


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_awu.c
    - stm8s_clk.c
    - stm8s_exti.c
    - stm8s_gpio.c
    - stm8s_spi.c
    - stm8s_tim3.c
    - mono_lcd.c (under FWLib\examples\Common)
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - The 4 LEDs (LD1 to LD4) blink continuously and slowly
  - If you press the Key button on the board, the LEDs will blink faster for
    a few seconds and then will be switched off.
  - At this stage, the CPU is in Active Halt mode.
  - After few seconds (12s), the MCU will exit from halt mode thanks to the AWU.
  - The 4 LEDs will continue to blink slowly.
  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
