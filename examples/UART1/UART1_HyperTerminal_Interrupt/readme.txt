/** @page UART1_HyperTerminal_Interrupt Communication between UART1 and hyperterminal using interrupts


  @par Example description

  This example provides a description of how  to use the UART1 interrupts to 
  communicate with the hyperterminal.
  The UART1 sends a predefined buffer to the hyperterminal and still waiting 
  for a string from the hyperterminal which length is defined by RxBufferSize. 
  The communication is managed by Transmit and Receive interrupts. 

  The UART1 is configured as follow:
    - BaudRate = 9600 baud  
    - Word Length = 8 Bits (Word Length = 7 data bit + 1 parity bit)
    - One Stop Bit
    - Odd parity
    - Receive and transmit enabled
    - UART1 Clock disabled
  
  @note When the parity is enabled, the computed parity is inserted at the MSB
          position of the transmitted data.

    
  @par Directory contents

    - UART1\UART1_HyperTerminal_Interrupt\main.c                    Main file containing the "main" function
    - UART1\UART1_HyperTerminal_Interrupt\stm8s_conf.h              Library Configuration file
    - UART1\UART1_HyperTerminal_Interrupt\stm8s_it.c                Interrupt routines source (not used in this example)
    - UART1\UART1_HyperTerminal_Interrupt\stm8s_it.h                Interrupt routines declaration
    - UART1\UART1_HyperTerminal_Interrupt\stm8_interrupt_vector.c   Interrupt vectors table


  @par Hardware and Software environment

  - This example runs only on STM8S208, STM8S207, STM8S103 and STM8S903 devices.
  
  - This example has been tested with STMicroelectronics STM8/128-EVAL evaluation
    board (STM8S208) and ST Visual Develop (STVD) toolchain (Cosmic compiler).
    And can be easily tailored to any other supported device and development board.

  - STM8/128-EVAL Set-up
     - Connect a null-modem female/female RS232 cable between the DB9 connector 
       CN13 and PC serial port.  
     - Hyperterminal configuration:
      - Word Length = 7 Bits
      - One Stop Bit
      - Odd parity
      - BaudRate = 9600 baud
      - flow control: None 


  @par How to use it ?

  In order to make the program work, you must do the following:
  - Create a project and setup all project configuration        
  - Compile the directory content files and required Library files
    - stm8s_clk.c
    - stm8s_exti.c
    - stm8s_uart1.c       
  - Edit stm8s.h file to select the device you are working on (#define STM8S208, in this case).
  
  @b Tip: You can tailor the provided project template to run this example, for more
          details please refer to "stm8s_fwlib_um.chm" user manual; select "Peripheral Examples"
          then follow the instructions provided in "How to proceed" section.   
  - Rebuild all files: Build-> Rebuild all.
  - Load project image: Debug->Start Debugging
  - Run program: Debug->Run (Ctrl+F5)
 
  */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
