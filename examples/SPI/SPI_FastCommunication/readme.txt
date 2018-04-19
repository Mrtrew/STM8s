/** @page SPI_FastCommunication Fast communication with a MicroSD memory card


  @par Example description

  This example provides a short description of how to make a communication (Write & Read data)  
  between the SPI and a MicroSD memory card like the one present on the evalboard.
	
  First, Fill the Tx_Buffer and write them into the MicroSD memory followed by a read of the written data.
  Then data read from the MicroSD memory stored in the Rx_Buffer are compared with the expected values 
  of the Tx_Buffer. The result of this comparison is stored in the "TransferStatus" variable.

 @note To avoid the conflict between LCD and MicroSD memory card on the STM8/128-EVAL evaluation board 
       the LCD should be disabled.

 @par Directory contents

  - SPI\SPI_FastCommunication\main.c                    Main file containing the "main" function
  - SPI\SPI_FastCommunication\stm8s_conf.h              Library Configuration file
  - SPI\SPI_FastCommunication\stm8s_it.c                Interrupt routines source (not used in this example)
  - SPI\SPI_FastCommunication\stm8s_it.h                Interrupt routines declaration
  - SPI\SPI_FastCommunication\stm8_interrupt_vector.c   Interrupt vectors table
  

  @par Hardware and Software environment

  - This example runs on STM8S208, STM8S207, STM8S105, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Plug a MicroSD memory card into the dedicated connector (CN9).

  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_clk.c
    - stm8s_gpio.c
    - stm8s_spi.c    
    - mono_lcd.c (under FWLib\examples\Common)
    - microsd.c (under FWLib\examples\Common)
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  - If the program is pass, the four LEDs toggles. Otherwise only the LED1 toggles.
  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
