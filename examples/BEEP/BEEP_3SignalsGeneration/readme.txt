/** @page BEEP_3SignalsGeneration Generation of the 3 beep signals


  @par Example description

  This example provides a short description of how to use the BEEP peripheral:
  - Initialization of the BEEP peripheral
  - Initialization of a GPIO in input mode in order to read the Key Button state
  - Initialization of GPIO in output mode to drive LEDs
  - Each action on the Key button toggles between the 3 beep frequencies


  @par Directory contents

  - BEEP\BEEP_3SignalsGeneration\main.c                    Main file containing the "main" function
  - BEEP\BEEP_3SignalsGeneration\stm8s_conf.h              Library Configuration file
  - BEEP\BEEP_3SignalsGeneration\stm8s_it.c                Interrupt routines source (not used in this example)
  - BEEP\BEEP_3SignalsGeneration\stm8s_it.h                Interrupt routines declaration
  - BEEP\BEEP_3SignalsGeneration\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.
    
  @note: to run this example with STM8S103 and STM8S903 devices, TIM1 should be used 
  instead of TIM3 for LSI calibration (BEEP_AutoLSICalibration function has to be updated accordingly).

  - STM8/128-EVAL Set-up
     - Four leds LD1 to LD4 and Key push button are used.
     - PD4 used to drive the buzzer 


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_beep.c
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
  - Per default, the BEEP signal is OFF and the 4 LEDs are ON.
  - Everytime you press the Key button on the board, you will toggle the
    buzzer frequency in this way: 1kHz -> 2kHz -> 4kHz -> OFF -> 1kHz -> etc...
  - The 4 LEDs will toggle respectively.
	
@par Hint

   - Enable the beeper alternate function (menu: Debug Instrument -> MCU configuration->AFR7: Alternate active)
   - Verify that the JP14 is on the up position (to enable the speaker on the STM8/128-EVAL)
   - Verify the speaker volume by adjusting the RV2 potentiometer position on the STM8/128-EVAL

  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
