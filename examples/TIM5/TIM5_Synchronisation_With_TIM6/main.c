/**
  ******************************************************************************
  * @file TIM5_Synchronisation_with_TIM6\main.c
  * @brief This file contains the main function for TIM5 example.
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
  * @addtogroup TIM5_Synchronisation_with_TIM6
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TIMEOUT ((u8)0xFF)
/* Private macro -------------------------------------------------------------*/
#define TIM5_Status() (TIM5->CR1 & TIM5_CR1_CEN)
/* Private variables ---------------------------------------------------------*/
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
	
	u8 Result = 0;
	u8 timeout = TIMEOUT;
  
	/*DeInit all TIM5 and TIM6 registers*/
	TIM5_DeInit();
	TIM6_DeInit();
	
	/* Time base configuration */
	TIM5_TimeBaseInit(TIM5_PRESCALER_1, 0xFF );
	TIM6_TimeBaseInit(TIM6_PRESCALER_1, 0xFF );

	/* Select TIM6 Update event as source of TIM6 Trigger Output*/
	TIM6_SelectOutputTrigger(TIM6_TRGOSOURCE_UPDATE);
	
	/* Select TIM6 as source of TIM5 Trigger Input*/
	TIM5_SelectInputTrigger(TIM5_TS_TIM6);
	
	/* configurate TIM5 as slave of Trigger input*/
	TIM5_SelectSlaveMode(TIM5_SLAVEMODE_TRIGGER);

	/*Enable TIM6*/
Inc1:	TIM6_Cmd(ENABLE);/* if this line is commented, TIM6 will not be enabled and */
	                 /* TIM5  will not detect an Edge on its TRGI => Result =0  */
	
	while((TIM5_Status() == DISABLE) && (timeout != 0))
	{
		/* Decrement timeout */
		timeout--;
	}
	
	if (TIM5_Status() != DISABLE)
	{
		/*If the program counter reachs this section, 
		the TIM5 is correctly triggered by TIM6 */
		/*Insert break point in the folloing line */
Inc2:		Result = 1;
	}
	else
	{
		/*If the program counter reachs this section, 
		the TIM5 is not correctly triggered by TIM6 */
		/*Insert break point in the folloing line */
Inc3:		Result = 0;
	}
	/* infinite loop */
  while(1);
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
