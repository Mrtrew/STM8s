/** @page TIM4_TimeBase_InterruptConfiguration Toggling an output with TIM4 update interrupt 


  @par Example description

  This example provides a short description of how to use the TIM4 peripheral
  In this example, the PG.5 pin toggles each time the Update interrupt occurs
	
  The TIM4CLK frequency is 2MHz, the Prescaler is 1 so the TIM4 counter clock is 2MHz. 

  The TIM4 is running at 7.8125 KHz: TIM4 Frequency = TIM4 counter clock/(ARR value + 1) 
  So the TIM4 generates an Update Interrupt each 128 us.
  
  @note The square signal frequency on PG.5 is the half of Update Interrupt frequency
   (signal Period = 2 x Update interrupt period).
  


  @par Directory contents

  - TIM4\TIM4_TimeBase_InterruptConfiguration\main.c                    Main file containing the "main" function
  - TIM4\TIM4_TimeBase_InterruptConfiguration\stm8s_conf.h              Library Configuration file
  - TIM4\TIM4_TimeBase_InterruptConfiguration\stm8s_it.c                Interrupt routines source
  - TIM4\TIM4_TimeBase_InterruptConfiguration\stm8s_it.h                Interrupt routines declaration
  - TIM4\TIM4_TimeBase_InterruptConfiguration\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208, STM8S207, STM8S105 and STM8S103 devices.	  
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
    - Connect PG.5 pin to an oscilloscope.


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_tim4.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - Connect the PG.5 pin to an oscilloscope 
  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
