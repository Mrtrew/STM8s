/** @page SPI_SimplexLCD Communication with a monochrome LCD


  @par Example description

  This example provides a short description of how to use the SPI peripheral 
  in order to communicate with a monochrome LCD peripheral like the one present 
  on the eval-board.


  @par Directory contents

  - SPI\SPI_SimplexLCD\main.c                    Main file containing the "main" function
  - SPI\SPI_SimplexLCD\main.h                    Main functions prototype
  - SPI\SPI_SimplexLCD\stm8s_conf.h              Library Configuration file
  - SPI\SPI_SimplexLCD\stm8s_it.c                Interrupt routines source (not used in this example)
  - SPI\SPI_SimplexLCD\stm8s_it.h                Interrupt routines declaration
  - SPI\SPI_SimplexLCD\stm8_interrupt_vector.c   Interrupt vectors table
  

  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
    - The mono LCD is used for the purpose of this example.
 
 
  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_exti.c
    - stm8s_gpio.c
    - stm8s_spi.c
    - mono_lcd.c (under FWLib\examples\Common)    
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - A welcome message should be displayed on the LCD
  - Press the Key button in order to change the message on the LCD
  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
