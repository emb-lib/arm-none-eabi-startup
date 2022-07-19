//******************************************************************************
//*
//*      GD32F10X_XD exception/intrrupt handlers stuff header file
//*
//*      Version 1.2
//*
//*      Copyright (c) 2016-2021, emb-lib Project Team
//*
//*      This file is part of the arm-none-eabi-startup project.
//*      Visit https://github.com/emb-lib/arm-none-eabi-startup for new versions.
//*
//*      Permission is hereby granted, free of charge, to any person
//*      obtaining  a copy of this software and associated documentation
//*      files (the "Software"), to deal in the Software without restriction,
//*      including without limitation the rights to use, copy, modify, merge,
//*      publish, distribute, sublicense, and/or sell copies of the Software,
//*      and to permit persons to whom the Software is furnished to do so,
//*      subject to the following conditions:
//*
//*      The above copyright notice and this permission notice shall be included
//*      in all copies or substantial portions of the Software.
//*
//*      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//*      EXPRESS  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
//*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
//*      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
//*      THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
typedef struct
{
    unsigned long *tos;
    intfun_t      vectors[75];
}
__vector_table_t;

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
WEAK void WWDGT_IRQHandler();
WEAK void LVD_IRQHandler();
WEAK void TAMPER_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void FMC_IRQHandler();
WEAK void RCU_IRQHandler();
WEAK void EXTI0_IRQHandler();
WEAK void EXTI1_IRQHandler();
WEAK void EXTI2_IRQHandler();
WEAK void EXTI3_IRQHandler();
WEAK void EXTI4_IRQHandler();
WEAK void DMA0_Channel0_IRQHandler();
WEAK void DMA0_Channel1_IRQHandler();
WEAK void DMA0_Channel2_IRQHandler();
WEAK void DMA0_Channel3_IRQHandler();
WEAK void DMA0_Channel4_IRQHandler();
WEAK void DMA0_Channel5_IRQHandler();
WEAK void DMA0_Channel6_IRQHandler();
WEAK void ADC0_1_IRQHandler();
WEAK void USBD_HP_CAN0_TX_IRQHandler();
WEAK void USBD_LP_CAN0_RX0_IRQHandler();
WEAK void CAN0_RX1_IRQHandler();
WEAK void CAN0_EWMC_IRQHandler();
WEAK void EXTI5_9_IRQHandler();
WEAK void TIMER0_BRK_TIMER8_IRQHandler();
WEAK void TIMER0_UP_TIMER9_IRQHandler();
WEAK void TIMER0_TRG_CMT_TIMER10_IRQHandler();
WEAK void TIMER0_Channel_IRQHandler();
WEAK void TIMER1_IRQHandler();
WEAK void TIMER2_IRQHandler();
WEAK void TIMER3_IRQHandler();
WEAK void I2C0_EV_IRQHandler();
WEAK void I2C0_ER_IRQHandler();
WEAK void I2C1_EV_IRQHandler();
WEAK void I2C1_ER_IRQHandler();
WEAK void SPI0_IRQHandler();
WEAK void SPI1_IRQHandler();
WEAK void USART0_IRQHandler();
WEAK void USART1_IRQHandler();
WEAK void USART2_IRQHandler();
WEAK void EXTI10_15_IRQHandler();
WEAK void RTC_Alarm_IRQHandler();
WEAK void USBD_WKUP_IRQHandler();
WEAK void TIMER7_BRK_TIMER11_IRQHandler();
WEAK void TIMER7_UP_TIMER12_IRQHandler();
WEAK void TIMER7_TRG_CMT_TIMER13_IRQHandler();
WEAK void TIMER7_Channel_IRQHandler();
WEAK void ADC2_IRQHandler();
WEAK void EXMC_IRQHandler();
WEAK void SDIO_IRQHandler();
WEAK void TIMER4_IRQHandler();
WEAK void SPI2_IRQHandler();
WEAK void UART3_IRQHandler();
WEAK void UART4_IRQHandler();
WEAK void TIMER5_IRQHandler();
WEAK void TIMER6_IRQHandler();
WEAK void DMA1_Channel0_IRQHandler();
WEAK void DMA1_Channel1_IRQHandler();
WEAK void DMA1_Channel2_IRQHandler();
WEAK void DMA1_Channel3_4_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
