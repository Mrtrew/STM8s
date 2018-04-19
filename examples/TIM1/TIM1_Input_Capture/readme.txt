/** @page TIM1_Input_Capture LSI Capture by TIM1 

  @par Example description

  This example shows how to configure the TIM1 peripheral to capture the LSI.
  
  TIM1CLK is fixed to 2 MHz, the TIM1 Prescaler is equal to 0 so the TIM1 counter
  clock used is 2 MHz. (By default, fTIM1= fMaster/8 )
  
  The TIM1 Channel 1 is configured as Input capture.
  The LSI signal is redirected to the CCO output Pin.
  The TIM1 Channel 1 is connected to the CCO Pin. 
  
  The captured value of LSI Frequency is stored in the LSIClockFreq variable.


  @par Directory contents

  - TIM1\TIM1_Input_Capture\main.c                    Main file containing the "main" function
  - TIM1\TIM1_Input_Capture\stm8s_conf.h              Library Configuration file
  - TIM1\TIM1_Input_Capture\stm8s_it.c                Interrupt routines source (not used in this example)
  - TIM1\TIM1_Input_Capture\stm8s_it.h                Interrupt routines declaration
  - TIM1\TIM1_Input_Capture\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Connect the configurable Clock Output pin CCO (PE.0) to the  TIM1_CC1  pin (PC.1)


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_tim1.c
    - stm8s_clk.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - Connect the TIM1_CC1 pin to COO pin
  - Read the value of LSIClockFreq variable
  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
