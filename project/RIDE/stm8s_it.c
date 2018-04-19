/**
  ******************************************************************************
  * @file RIDE\stm8s_it.c
  * @brief This file contains all the interrupt routines.
  * @author STMicroelectronics
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

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/* Public Interruption routines ----------------------------------------------*/
void TLI_IRQHandler (void) interrupt 0
{
}
void AWU_IRQHandler (void) interrupt 1
{
}
void CLK_IRQHandler (void) interrupt 2
{
}
void EXTI_PORTA_IRQHandler (void) interrupt 3
{
}
void EXTI_PORTB_IRQHandler (void) interrupt 4
{
}
void EXTI_PORTC_IRQHandler (void) interrupt 5
{
}
void EXTI_PORTD_IRQHandler (void) interrupt 6
{
}
void EXTI_PORTE_IRQHandler (void) interrupt 7
{
}
#ifdef STM8S903
void EXTI_PORTF_IRQHandler (void) interrupt 8
{
}
#endif /*STM8S903*/
#ifdef STM8S208
void CAN_RX_IRQHandler (void) interrupt 8
{
}
void CAN_TX_IRQHandler (void) interrupt 9
{
}
#endif /*STM8S208*/
void SPI_IRQHandler (void) interrupt 10
{
}
void TIM1_UPD_OVF_TRG_BRK_IRQHandler (void) interrupt 11
{
}
void TIM1_CAP_COM_IRQHandler (void) interrupt 12
{
}
#ifdef STM8S903
void TIM5_UPD_OVF_BRK_IRQHandler (void) interrupt 13
{
}
void TIM5_CAP_COM_IRQHandler (void) interrupt 14
{
}
#else /*STM8S208, STM8S207, STM8S105 or STM8S103*/
void TIM2_UPD_OVF_BRK_IRQHandler (void) interrupt 13
{
}
void TIM2_CAP_COM_IRQHandler (void) interrupt 14
{
}
#endif /*STM8S903*/
#if defined (STM8S208) || defined(STM8S207) || defined(STM8S105)
void TIM3_UPD_OVF_BRK_IRQHandler (void) interrupt 15
{
}
void TIM3_CAP_COM_IRQHandler (void) interrupt 16
{
}
#endif /*STM8S208, STM8S207 or STM8S105*/
#ifndef STM8S105
void UART1_TX_IRQHandler (void) interrupt 17
{
}
void UART1_RX_IRQHandler (void) interrupt 18
{
}
#endif /*STM8S105*/
void I2C_IRQHandler (void) interrupt 19
{
}
#ifdef STM8S105
void UART2_TX_IRQHandler (void) interrupt 20
{
}
void UART2_RX_IRQHandler (void) interrupt 21
{
}
#endif /* STM8S105*/
#if defined(STM8S207) || defined(STM8S208)
void UART3_TX_IRQHandler (void) interrupt 20
{
}
void UART3_RX_IRQHandler (void) interrupt 21
{
}
#endif /*STM8S207, STM8S208*/
#if defined(STM8S207) || defined(STM8S208)
void ADC2_IRQHandler (void) interrupt 22
{
}
#else /*STM8S105, STM8S103 or STM8S903*/
void ADC1_IRQHandler (void) interrupt 22
{
}
#endif /*STM8S207, STM8S208*/
#ifdef STM8S903
void TIM4_UPD_OVF_TRG_IRQHandler (void) interrupt 23
{
}
#else /*STM8S208, STM8S207, STM8S105 or STM8S103*/
void TIM4_UPD_OVF_IRQHandler (void) interrupt 23
{
}
#endif /*STM8S903*/
void EEPROM_EEC_IRQHandler (void) interrupt 24
{
}



/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
