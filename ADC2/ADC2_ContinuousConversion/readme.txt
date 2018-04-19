/** @page ADC2_ContinuousConversion Displaying the ADC2 conversion result using LEDs


  @par Example description

  This example provides a short description of how to use the ADC2 peripheral:
  - The ADC2 peripheral is configured in Continuous conversion mode with interrupt
  - Depending on the range of voltage, LEDs from 1 to 4 light up.
 

  @par Directory contents

  - ADC2\ADC2_ContinuousConversion\main.c                   Main file containing the "main" function
  - ADC2\ADC2_ContinuousConversion\main.h                    Main functions prototype
  - ADC2\ADC2_ContinuousConversion\stm8s_conf.h             Library Configuration file
  - ADC2\ADC2_ContinuousConversion\stm8s_it.c               Interrupt routines source
  - ADC2\ADC2_ContinuousConversion\stm8s_it.h               Interrupt routines declaration
  - ADC2\ADC2_ContinuousConversion\stm8_interrupt_vector.c  Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208 and STM8S207 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Use the potentiometer RV1 to change the voltage value to convert


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_adc2.c
    - stm8s_gpio.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - Turn the potentiometer RV1 on the board to change the voltage to be converted
  - The four LEDs (LD1, LD2, LD3 and LD4) follow the ADC2 value

  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
