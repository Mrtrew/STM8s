/**
  ******************************************************************************
  * @file I2C_EEPROM\main.c
  * @brief This file contains the main function for I2C EEPROM Read Write example.
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
#include "i2c_ee.h"

/**
  * @addtogroup I2C_EEPROM
  * @{
  */

/* Private define ------------------------------------------------------------*/
/* Evalboard I/Os configuration */

#define LEDS_PORT (GPIOH)
#define LED1_PIN  (GPIO_PIN_3)
#define LED2_PIN  (GPIO_PIN_2)
#define LED3_PIN  (GPIO_PIN_1)
#define LED4_PIN  (GPIO_PIN_0)

#define BUFFER_SIZE ((u8)8)
#define BASE_ADDRESS ((u16)0x0000)

/* Private typedef -----------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void Delay (u16 nCount);
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/**
  * @brief How to make  a write followed by a read in the E²PROM.
  * @par Examples description
	* - Write 8 bytes on the devive  (E²PROM) 0xA0.
  * - Read back the 8 bytes written on the devive  (E²PROM) 0xA0.
	* - Check the coherency between the written and read data.
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  */
void main()
{

    u8 i = 0;
    u8 data[8] = {0,0,0,0,0,0,0,0};
    u8 Buffer_size = BUFFER_SIZE;
    u8 Buffer[BUFFER_SIZE] = {0x04, 0x42, 0x53, 0x38, 0x97, 0x03, 0x09, 0x77}; /* Using a 2ko E² you cannot program a buff > 8 bytes in write page mode */
    u16 Base_Add = BASE_ADDRESS;

    /* Initialize I/Os in Output Mode */
    GPIO_Init(LEDS_PORT, (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN), GPIO_MODE_OUT_PP_LOW_FAST);

    /* Optional: put here as example only */
    I2C_DeInit();

    /* Initialize the I2C */
    I2C_EEInit();

    /* All LEDs are ON per default */
    GPIO_WriteHigh(LEDS_PORT, (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN));

    /*** WRITE SEQUENCE ***/
   I2C_EE_PageWrite(Buffer, Base_Add, Buffer_size);
    Delay(1000); /* To let eeprom the time to finish the write operation */

    /***  READ SEQUENCE ***/
    I2C_EE_BufferRead(data, Base_Add, Buffer_size);
        
     /*** Check transmitted and received buffers ***/
    for (i =Buffer_size; i > 0; i--)
    {
        if (Buffer[i-1] != data[i-1])
        {
            /* Toggle only LED1 if error is detected */
            while (1)
            {
                GPIO_WriteReverse(LEDS_PORT, LED1_PIN);
                Delay((u16)60000);
            }
        }
    }

    /* Toggle all LEDs when I2C communication is terminated and buffers are ok */
    while (1)
    {
        GPIO_WriteReverse(LEDS_PORT, (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN));
        Delay((u16)60000);
    }

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
