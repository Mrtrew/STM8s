/** @page UART1_IrDA_Transmit UART1 IrDA transmit mode communication


  @par Example description

  This example provides a basic communication USART IrDA transmit mode. 
  Five pins, configured in input floating mode, are used to select the byte to
  be sent at each pin state change

  The byte can be:
   - 0x00 if no key pressed
   - 0x01 if PD.07 pin state change (Joystick Sel pressed)
   - 0x02 if PB.05 pin state change (Joystick Right pressed) 
   - 0x03 if PB.04 pin state change (Joystick Left pressed)
   - 0x04 if PB.06 pin state change (Joystick Up pressed)
   - 0x05 if PB.07 pin state change (Joystick Down pressed)
  
  UART1 configured as follow:
    - BaudRate = 9600 baud  
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Receive and transmit enabled

  The example provides two IrDA programs: transmitter&receiver and requires two boards
  to be able to run all the demonstration:
    - One board will act as IrDA transmitter
    - One board will act as IrDA receiver
 
  @par Directory contents

  - UART1\UART1_IrDA\Transmit\main.c                    Main file containing the "main" function
  - UART1\UART1_IrDA\Transmit\stm8s_conf.h              Library Configuration file
  - UART1\UART1_IrDA\Transmit\stm8s_it.c                Interrupt routines source (not used in this example)
  - UART1\UART1_IrDA\Transmit\stm8s_it.h                Interrupt routines declaration
  - UART1\UART1_IrDA\Transmit\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208, STM8S207, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Joystick Sel, Down, Up, Right and Left push-buttons are used.
     - IrDA tranceiver (U14) is used, make sure that JP10 jumper must be fitted.


  @par How to use it ?

  In order to make the program work, you must do the following :
  - Create a project and setup all project configuration
  - Add the required Library files :
    - stm8s_clk.c
    - stm8s_gpio.c
    - stm8s_uart1.c
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all. 
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
  
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
