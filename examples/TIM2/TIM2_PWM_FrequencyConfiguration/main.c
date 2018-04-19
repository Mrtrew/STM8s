/**
  ******************************************************************************
  * @file TIM2_PWM_FrequencyConfiguration\main.c
  * @brief This file contains the main function for TIM2 PWM  Frequency Configuration example .
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

/**
  * @addtogroup TIM2_PWM_FrequencyConfiguration
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u16 CCR1_Val = 32768;
u16 CCR2_Val = 16384;
u16 CCR3_Val =  8192;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @brief Example firmware main entry point.
  * @par Parameters:
  * None
  * @retval void None
  * @par Required preconditions:
  * None
  */
void main(void)
{
 
  /* Time base configuration */
  /*
	    TIM2_Prescaler = TIM2_PRESCALER_2
	    TIM2_Period = 65535
	*/
	TIM2_TimeBaseInit(TIM2_PRESCALER_2, 65535);

  /* Output Compare Toggle Mode configuration: Channel1 */
	/*
      TIM2_OCMode = TIM2_OCMODE_TOGGLE
      TIM2_OutputState = TIM2_OUTPUTSTATE_ENABLE
      TIM2_Pulse = CCR1_Val
      TIM2_OCPolarity = TIM2_OCPOLARITY_LOW
	*/
  TIM2_OC1Init(TIM2_OCMODE_TOGGLE, TIM2_OUTPUTSTATE_ENABLE,CCR1_Val, TIM2_OCPOLARITY_LOW);
  TIM2_OC1PreloadConfig(DISABLE);

  /* Output Compare Toggle Mode configuration: Channel2 */
  /*TIM2_Pulse = CCR2_Val*/
  TIM2_OC2Init(TIM2_OCMODE_TOGGLE, TIM2_OUTPUTSTATE_ENABLE,CCR2_Val, TIM2_OCPOLARITY_LOW); 
  TIM2_OC2PreloadConfig(DISABLE);

  /* Output Compare Toggle Mode configuration: Channel3 */
  /*TIM2_Pulse = CCR3_Val */
	TIM2_OC3Init(TIM2_OCMODE_TOGGLE, TIM2_OUTPUTSTATE_ENABLE,CCR3_Val, TIM2_OCPOLARITY_LOW); 
  TIM2_OC3PreloadConfig(DISABLE);

  /* TIM2 IT enable */
  TIM2_ITConfig(TIM2_IT_CC1,ENABLE);
  TIM2_ITConfig(TIM2_IT_CC2,ENABLE);
  TIM2_ITConfig(TIM2_IT_CC3,ENABLE);

	/* TIM2 enable counter */
  TIM2_Cmd(ENABLE);

  enableInterrupts();
  while (1);
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
  while (1);
}

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
