/**
  ******************************************************************************
  * @file CLK_ClockSelection\main.c
  * @brief This file contains the main function for the CLK Clock Selection example.
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
#include "main.h"
#include "mono_lcd.h"

/**
  * @addtogroup CLK_ClockSelection
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
u8 ReadJoystick(void);
void Delay (u16 nCount);

/* Private functions ---------------------------------------------------------*/
u8 ReadJoystick(void)
{
    u8 key = 0x00;
    /* "right" key is pressed */
    if ((GPIO_ReadInputData(GPIOB) & GPIO_PIN_4) == (u8)0x00)
    {
        while ((GPIO_ReadInputData(GPIOB) & GPIO_PIN_4) == Bit_RESET);
        key =  LEFT;
    }
    /* "up" key is pressed */
    else if ((GPIO_ReadInputData(GPIOB) & GPIO_PIN_6) == (u8)0x00)
    {
        while ((GPIO_ReadInputData(GPIOB) & GPIO_PIN_6) == Bit_RESET);
        key =  UP;
    }
    /* "down" key is pressed */
    if ((GPIO_ReadInputData(GPIOB) & GPIO_PIN_7) == (u8)0x00)
    {
        while ((GPIO_ReadInputData(GPIOB) & GPIO_PIN_7) == Bit_RESET);
        key =  DOWN;
    }
    
    return key;
}

void Delay(u16 nCount)
{
    /* Decrement nCount value */
    while (nCount != 0)
    {
        nCount--;
    }
}
/* Public functions ----------------------------------------------------------*/

/**
  * @brief Example  main entry point.
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  * @par Library functions called:
  * - GPIO_Init()
	* - GPIO_WriteReverse()
	* - GPIO_WriteLow()
  * - CLK_DeInit()
  * - CLK_Init()
  * - CLK_ClockSwitchConfig()
  * - CLK_CCOConfig()

  */
void main(void)
{

    ErrorStatus status = FALSE;
    u8 MyKey = 0;
    u8 i = 0;

    /* Init GPIO for LED  */
    GPIO_Init(LEDS_PORT, (LED1_PIN |LED2_PIN |LED3_PIN |LED4_PIN), GPIO_MODE_OUT_PP_LOW_FAST);

    /* Initialize SPI for LCD */
    SPI_DeInit();
    SPI_Init(SPI_FIRSTBIT_MSB, SPI_BAUDRATEPRESCALER_128, SPI_MODE_MASTER, SPI_CLOCKPOLARITY_HIGH, SPI_CLOCKPHASE_2EDGE, SPI_DATADIRECTION_1LINE_TX, SPI_NSS_SOFT, 0x07);
    SPI_Cmd(ENABLE);

    /* Initialize LCD */
    LCD_Init();

    /* Clear LCD lines */
    LCD_Clear();

    LCD_Backlight(ENABLE);

    LCD_PrintString(LCD_LINE1, ENABLE, DISABLE, "Clock Selection");
    LCD_PrintString(LCD_LINE2, ENABLE, DISABLE, " Use joystick");

    GPIO_WriteHigh(LEDS_PORT, (LED1_PIN | LED2_PIN | LED3_PIN));

    CLK_DeInit();

    /* Output Fcpu on CLK_CCO pin */
    CLK_CCOConfig(CLK_OUTPUT_MASTER);

    while (1)
    {
        /* Read Key */
        MyKey = ReadJoystick();


        /*  Toggle the LEDs depending on the clock selected */
        if ((MyKey == UP))
        {
            status = CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, DISABLE);
            LCD_PrintString(LCD_LINE2, ENABLE, DISABLE, "CLK = HSE");
            GPIO_WriteLow(LEDS_PORT, (LED2_PIN | LED3_PIN));
            GPIO_WriteHigh(LEDS_PORT, LED1_PIN);
            for (i = 2; i > 0; i--)
            {
                Delay((u16)60000);
            }
        }
        if (MyKey == DOWN)
        {
            status = CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_LSI, DISABLE, DISABLE);
            LCD_PrintString(LCD_LINE2, ENABLE, DISABLE, "CLK = LSI");
            GPIO_WriteLow(LEDS_PORT, (LED1_PIN | LED3_PIN));
            GPIO_WriteHigh(LEDS_PORT, LED2_PIN);
            for (i = 2; i > 0; i--)
            {
                Delay((u16)5000);
            }
        }
        if (MyKey == LEFT)
        {
            status = CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, DISABLE);
            LCD_PrintString(LCD_LINE2, ENABLE, DISABLE, "CLK = HSI");
            GPIO_WriteLow(LEDS_PORT, (LED2_PIN | LED1_PIN));
            GPIO_WriteHigh(LEDS_PORT, LED3_PIN);
            for (i = 2; i > 0; i--)
            {
                Delay((u16)60000);
            }
        }

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
