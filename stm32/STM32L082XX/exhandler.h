//******************************************************************************
//*
//*      STM32L082XX exception/intrrupt handlers stuff header file
//*
//*      Version 1.1
//*
//*      Copyright (c) 2016, emb-lib Project Team
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
    intfun_t      vectors[47];
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
WEAK void WWDG_IRQHandler();
WEAK void PVD_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void FLASH_IRQHandler();
WEAK void RCC_CRS_IRQHandler();
WEAK void EXTI0_1_IRQHandler();
WEAK void EXTI2_3_IRQHandler();
WEAK void EXTI4_15_IRQHandler();
WEAK void TSC_IRQHandler();
WEAK void DMA1_Channel1_IRQHandler();
WEAK void DMA1_Channel2_3_IRQHandler();
WEAK void DMA1_Channel4_5_6_7_IRQHandler();
WEAK void ADC1_COMP_IRQHandler();
WEAK void LPTIM1_IRQHandler();
WEAK void USART4_5_IRQHandler();
WEAK void TIM2_IRQHandler();
WEAK void TIM3_IRQHandler();
WEAK void TIM6_DAC_IRQHandler();
WEAK void TIM7_IRQHandler();
WEAK void TIM21_IRQHandler();
WEAK void I2C3_IRQHandler();
WEAK void TIM22_IRQHandler();
WEAK void I2C1_IRQHandler();
WEAK void I2C2_IRQHandler();
WEAK void SPI1_IRQHandler();
WEAK void SPI2_IRQHandler();
WEAK void USART1_IRQHandler();
WEAK void USART2_IRQHandler();
WEAK void AES_RNG_LPUART1_IRQHandler();
WEAK void USB_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
