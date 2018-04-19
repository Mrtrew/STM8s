/**
  ******************************************************************************
  * @file TIM1_Input_Capture\main.c
  * @brief This file contains the main function for TIM1 example4.
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
  * @addtogroup TIM1_Input_Capture
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u32 TIM1ClockFreq = 2000000;
u32 LSIClockFreq = 0;
u16 ICValue1 =0, ICValue2 =0;
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
  
	/* Capture only every 8 events!!! */
  /* Enable capture of TI1 */
  /*
	TIM1_Channel = TIM1_CHANNEL_1
  TIM1_ICPolarity = TIM1_ICPOLARITY_FALLING
  TIM1_ICSelection = TIM1_ICSELECTION_DIRECTTI
  TIM1_ICPrescaler = TIM1_ICPSC_DIV8
  TIM1_ICFilter = 0x0
  */

	TIM1_ICInit( TIM1_CHANNEL_1, TIM1_ICPOLARITY_FALLING, TIM1_ICSELECTION_DIRECTTI,  TIM1_ICPSC_DIV8, 0x0);
  
	/* Enable CC1 interrupt */
	TIM1_ITConfig(TIM1_IT_CC1, ENABLE); 
	
	/* Enable TIM1 */
  TIM1_Cmd(ENABLE);

	/* Clear CC1 Flag*/
  TIM1_ClearFlag(TIM1_FLAG_CC1);
  
	/* Connect LSI to COO pin*/
  GPIO_Init(GPIOE, GPIO_PIN_0, GPIO_MODE_OUT_PP_LOW_FAST);
	CLK_CCOConfig(CLK_OUTPUT_LSI);
	CLK_CCOCmd(ENABLE);
	
	
	/* wait a capture on CC1 */
  while((TIM1->SR1 & TIM1_FLAG_CC1) != TIM1_FLAG_CC1);
  /* Get CCR1 value*/
	ICValue1 = TIM1_GetCapture1();
	TIM1_ClearFlag(TIM1_FLAG_CC1);
  
	/* wait a capture on cc1 */
  while((TIM1->SR1 & TIM1_FLAG_CC1) != TIM1_FLAG_CC1);
  /* Get CCR1 value*/
	ICValue2 = TIM1_GetCapture1();
	TIM1_ClearFlag(TIM1_FLAG_CC1);

  /* Compute LSI clock frequency */
  LSIClockFreq = (8 * TIM1ClockFreq) / (ICValue2 - ICValue1);
  
	/* Insert a break point here */
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
