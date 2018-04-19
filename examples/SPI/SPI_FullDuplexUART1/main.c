/**
  ******************************************************************************
  * @file SPI_FullDuplexUART1\main.c
  * @brief This file contains the main function for SPI full duplex communication with UART1 example.
  * @author STMicroelectronics - MCD Application Team
  * @version V1.1.0
  * @date 02/27/2009
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
  * @image html logo.bmp
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "mono_lcd.h"
#include "main.h"

/**
  * @addtogroup SPI_FullDuplexUART1
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
bool ButtonPressed = FALSE;

/* Public functions ----------------------------------------------------------*/

/**
  * @brief Validation firmware main entry point.
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  */
void main(void)
{
  u8 ButtonIndex = 0;
  u8 i;
  u8 DataTx;
  u8 DataRx;
  
  /* Initialize I/Os in Output Mode for LEDs */
  GPIO_Init(LEDS_PORT, LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN,GPIO_MODE_OUT_PP_LOW_FAST);

  /* Initialization of I/O in Input Mode with Interrupt for Key button */
  GPIO_Init(BUTTON_PORT, BUTTON_PIN, GPIO_MODE_IN_FL_IT);

  /* Initialization of the Interrupt sensitivity */
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);

  /* Initialize SPI in Master mode (for LCD only) */
  SPI_DeInit();
	SPI_Init(SPI_FIRSTBIT_MSB, SPI_BAUDRATEPRESCALER_128, SPI_MODE_MASTER, SPI_CLOCKPOLARITY_HIGH, SPI_CLOCKPHASE_2EDGE, SPI_DATADIRECTION_1LINE_TX, SPI_NSS_SOFT, 0x07);
  SPI_Cmd(ENABLE);

  /* Initialize UART1 in Master mode */
  UART1_DeInit();
  UART1_Init((u32)4800, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_ENABLE |UART1_SYNCMODE_CPOL_LOW |UART1_SYNCMODE_CPHA_MIDDLE |UART1_SYNCMODE_LASTBIT_ENABLE, UART1_MODE_TXRX_ENABLE);
	
	
  UART1_Cmd(DISABLE);

  /* Initialize LCD and display welcome message */
  LCD_Init();
  LCD_PrintString(LCD_LINE1, ENABLE, DISABLE, "  *** STM8S *** ");
  LCD_PrintString(LCD_LINE2, ENABLE, DISABLE, "  SPI example  ");
  for (i = 0; i < 5; i++)
  {
    Delay(0xFFFF);
  }
  LCD_Clear();
  LCD_PrintString(LCD_LINE1, ENABLE, DISABLE, "Press KEY...");
  
  DataTx = 0x00;

  /* Enable general interrupts for Key button reading */
  enableInterrupts();

  while (1)
  {
    /* Check button status */
    if (GetVar_ButtonPressed() == TRUE) /* Button is pressed */
    {
      
      ButtonPressed = FALSE;
      
      /* Set SPI in Slave mode for communication with UART1 */
      SPI_Init(SPI_FIRSTBIT_LSB, SPI_BAUDRATEPRESCALER_128, SPI_MODE_SLAVE, SPI_CLOCKPOLARITY_LOW, SPI_CLOCKPHASE_1EDGE, SPI_DATADIRECTION_2LINES_FULLDUPLEX, SPI_NSS_SOFT, 0x07);
      UART1_Cmd(ENABLE);
      Delay(300);
			SPI_Cmd(ENABLE);
			
      /* Send data with UART1 */
      UART1_SendData8(DataTx);
      
      /* Wait UART1 end of transmission */
      while (UART1_GetFlagStatus(UART1_FLAG_TC) == RESET);
      
      /* Wait byte received by SPI */
      while (SPI_GetFlagStatus(SPI_FLAG_RXNE) == RESET);
      DataRx = SPI_ReceiveData();
      
      UART1_Cmd(DISABLE);
      
      /* Set SPI in Master mode to display result on LCD */
      SPI_Init(SPI_FIRSTBIT_MSB, SPI_BAUDRATEPRESCALER_128, SPI_MODE_MASTER, SPI_CLOCKPOLARITY_HIGH, SPI_CLOCKPHASE_2EDGE, SPI_DATADIRECTION_1LINE_TX, SPI_NSS_SOFT, 0x07);
      SPI_Cmd(ENABLE);
      
      LCD_Init();
      LCD_PrintString(LCD_LINE1, ENABLE, DISABLE, "Press KEY...");
      LCD_PrintString(LCD_LINE2, DISABLE, DISABLE, "TX=");
      LCD_PrintHex2(DataTx);
      LCD_PrintString(LCD_LINE2, DISABLE, ENABLE, " RX=");
      LCD_PrintHex2(DataRx);
      
      DataTx++; /* Change next data to be sent */
      
    }
  }

}
/**
  * @brief Returns ButtonPressed value.
  * @par Parameters:
  * None
  * @retval check if button pressed
  * - bool: ButtonPressed
  * @par Required preconditions:
  * None
  * @par Library functions called:
  * None
  */
bool GetVar_ButtonPressed(void)
{
  return ButtonPressed;
}
/**
  * @brief Set the ButtonPressed value.
  * @par Parameters:
  * None
  * @retval None
  * @par Required preconditions:
  * None
  * @par Library functions called:
  * None
  */
void SetVar_ButtonPressed(void)
{
  ButtonPressed = TRUE;
}

/**
  * @brief Delay.
  * @param[in] nCount
  * @retval None
  * @par Required preconditions:
  * None
  * @par Library functions called:
  * None
  */
void Delay(u16 nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}
/**
  * @brief Reports the name of the source file and the source line number where
  * the assert error has occurred.
  * User can add his own implementation to report the file name and line number.
  * ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line)
  * @retval void None
  * @par Required preconditions:
  * None
  * @par Called functions:
  * None
  */
#ifdef FULL_ASSERT
void assert_failed(u8 *file, u16 line)
#else
void assert_failed(void)
#endif
{
  /* Add your own code to manage an assert error */
  /* Infinite loop */
  while (1)
  {
  }
}

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
