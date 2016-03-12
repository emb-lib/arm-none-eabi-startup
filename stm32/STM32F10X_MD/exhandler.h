//******************************************************************************
//*
//*      STM32F10X_MD exception/intrrupt handlers stuff header file
//*
//*      Version 1.0
//*
//*      Copyright (c) 2016, emb-lib Project Team
//*
//------------------------------------------------------------------------------


#ifndef EXHANDLER_H
#define EXHANDLER_H

//------------------------------------------------------------------------------
//
//   Weak attribute allows to replace default handler with the user's one
//
#define WEAK __attribute__ ((weak))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
extern unsigned long __top_of_stack[];

//------------------------------------------------------------------------------
//
//   Vector table item. Can be pointer to function or plain address value
//
typedef void (*intfun_t)();
typedef union
{
    intfun_t intfun;
    void *__ptr;
}
intvec_item_t;

//------------------------------------------------------------------------------
//
//   Startup handler
//
void Reset_Handler();

//------------------------------------------------------------------------------
//
//   Cortex-M internal exceptions
//
WEAK void NMI_Handler();
WEAK void HardFault_Handler();
WEAK void MemManage_Handler();
WEAK void BusFault_Handler();
WEAK void UsageFault_Handler();
WEAK void SVC_Handler();
WEAK void DebugMon_Handler();
WEAK void PendSV_Handler();
WEAK void SysTick_Handler();

//------------------------------------------------------------------------------
//
//   Controller specific peripheral interrupts
//
WEAK void WWDG_IRQHandler();
WEAK void PVD_IRQHandler();
WEAK void TAMPER_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void FLASH_IRQHandler();
WEAK void RCC_IRQHandler();
WEAK void EXTI0_IRQHandler();
WEAK void EXTI1_IRQHandler();
WEAK void EXTI2_IRQHandler();
WEAK void EXTI3_IRQHandler();
WEAK void EXTI4_IRQHandler();
WEAK void DMA1_Channel1_IRQHandler();
WEAK void DMA1_Channel2_IRQHandler();
WEAK void DMA1_Channel3_IRQHandler();
WEAK void DMA1_Channel4_IRQHandler();
WEAK void DMA1_Channel5_IRQHandler();
WEAK void DMA1_Channel6_IRQHandler();
WEAK void DMA1_Channel7_IRQHandler();
WEAK void ADC1_2_IRQHandler();
WEAK void USB_HP_CAN1_TX_IRQHandler();
WEAK void USB_LP_CAN1_RX0_IRQHandler();
WEAK void CAN1_RX1_IRQHandler();
WEAK void CAN1_SCE_IRQHandler();
WEAK void EXTI9_5_IRQHandler();
WEAK void TIM1_BRK_IRQHandler();
WEAK void TIM1_UP_IRQHandler();
WEAK void TIM1_TRG_COM_IRQHandler();
WEAK void TIM1_CC_IRQHandler();
WEAK void TIM2_IRQHandler();
WEAK void TIM3_IRQHandler();
WEAK void TIM4_IRQHandler();
WEAK void I2C1_EV_IRQHandler();
WEAK void I2C1_ER_IRQHandler();
WEAK void I2C2_EV_IRQHandler();
WEAK void I2C2_ER_IRQHandler();
WEAK void SPI1_IRQHandler();
WEAK void SPI2_IRQHandler();
WEAK void USART1_IRQHandler();
WEAK void USART2_IRQHandler();
WEAK void USART3_IRQHandler();
WEAK void EXTI15_10_IRQHandler();
WEAK void RTCAlarm_IRQHandler();
WEAK void USBWakeUp_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
