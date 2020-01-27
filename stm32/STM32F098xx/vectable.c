//******************************************************************************
//*
//*      STM32F098XX vector table
//*
//*      Version 1.2
//*
//*      Copyright (c) 2016-2020, emb-lib Project Team
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

#include "exhandler.h"

//------------------------------------------------------------------------------
__attribute__ ((used))
__attribute__ ((section(".isr_vector")))
const __vector_table_t __vector_table =
{
    __top_of_stack,
    
    {
    Reset_Handler,

    //--------------------------------------------------------------------------
    //
    // Cortex-M core exceptions 
    // 
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,                          // Reserved
    0,                          // Reserved
    0,                          // Reserved
    0,                          // Reserved
    SVC_Handler,
    DebugMon_Handler,
    0,                          // Reserved
    PendSV_Handler,             // The OS context switch interrupt
    SysTick_Handler,            // The OS timer

    //--------------------------------------------------------------------------
    //
    // Peripheral interrupts
    // 
    WWDG_IRQHandler,                     // Window Watchdog
    VDDIO2_IRQHandler,                   // VDDIO2 Monitor through EXTI Line 31
    RTC_IRQHandler,                      // RTC through EXTI Line
    FLASH_IRQHandler,                    // FLASH
    RCC_CRS_IRQHandler,                  // RCC and CRS
    EXTI0_1_IRQHandler,                  // EXTI Line 0 and 1
    EXTI2_3_IRQHandler,                  // EXTI Line 2 and 3
    EXTI4_15_IRQHandler,                 // EXTI Line 4 to 15
    TSC_IRQHandler,                      // TS
    DMA1_Ch1_IRQHandler,                 // DMA1 Channel 1
    DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler,    // DMA1 Channel 2 and 3 & DMA2 Channel 1 and 2
    DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler,    // DMA1 Channel 4 to 7 & DMA2 Channel 3 to 5 
    ADC1_COMP_IRQHandler,                // ADC1, COMP1 and COMP2 
    TIM1_BRK_UP_TRG_COM_IRQHandler,      // TIM1 Break, Update, Trigger and Commutation
    TIM1_CC_IRQHandler,                  // TIM1 Capture Compare
    TIM2_IRQHandler,                     // TIM2
    TIM3_IRQHandler,                     // TIM3
    TIM6_DAC_IRQHandler,                 // TIM6 and DAC
    TIM7_IRQHandler,                     // TIM7
    TIM14_IRQHandler,                    // TIM14
    TIM15_IRQHandler,                    // TIM15
    TIM16_IRQHandler,                    // TIM16
    TIM17_IRQHandler,                    // TIM17
    I2C1_IRQHandler,                     // I2C1
    I2C2_IRQHandler,                     // I2C2
    SPI1_IRQHandler,                     // SPI1
    SPI2_IRQHandler,                     // SPI2
    USART1_IRQHandler,                   // USART1
    USART2_IRQHandler,                   // USART2
    USART3_8_IRQHandler,                 // USART3, USART4, USART5, USART6, USART7, USART8
    CEC_CAN_IRQHandler                   // CEC and CAN
    }
};
//------------------------------------------------------------------------------
__attribute__ ((noreturn))
static void default_handler() { for(;;) { } }
#ifndef NDEBUG
static void hf_handler()
{
    volatile int i = 0;         //  debug variable: set non-zero value to 
    while(!i) { }               //  return from handler - this figures out 
                                //  an address where HW fault raises
}
#endif // NDEBUG
//------------------------------------------------------------------------------
//
//   Default exception handlers
//
#ifdef NDEBUG

#pragma weak NMI_Handler        = default_handler
#pragma weak HardFault_Handler  = default_handler
#pragma weak MemManage_Handler  = default_handler
#pragma weak BusFault_Handler   = default_handler
#pragma weak UsageFault_Handler = default_handler
#pragma weak SVC_Handler        = default_handler
#pragma weak DebugMon_Handler   = default_handler
#pragma weak PendSV_Handler     = default_handler
#pragma weak SysTick_Handler    = default_handler

#else // NDEBUG

WEAK void NMI_Handler        ()  { default_handler(); }
WEAK void HardFault_Handler  ()  { hf_handler();      }
WEAK void MemManage_Handler  ()  { default_handler(); }
WEAK void BusFault_Handler   ()  { default_handler(); }
WEAK void UsageFault_Handler ()  { default_handler(); }
WEAK void SVC_Handler        ()  { default_handler(); }
WEAK void DebugMon_Handler   ()  { default_handler(); }
WEAK void PendSV_Handler     ()  { default_handler(); }
WEAK void SysTick_Handler    ()  { default_handler(); }

#endif // NDEBUG

//------------------------------------------------------------------------------
//
//   Default interrupt handlers
//
#ifdef NDEBUG

#pragma weak WWDG_IRQHandler                  = default_handler
#pragma weak VDDIO2_IRQHandler                = default_handler
#pragma weak RTC_IRQHandler                   = default_handler
#pragma weak FLASH_IRQHandler                 = default_handler
#pragma weak RCC_CRS_IRQHandler               = default_handler
#pragma weak EXTI0_1_IRQHandler               = default_handler
#pragma weak EXTI2_3_IRQHandler               = default_handler
#pragma weak EXTI4_15_IRQHandler              = default_handler
#pragma weak TSC_IRQHandler                   = default_handler
#pragma weak DMA1_Ch1_IRQHandler              = default_handler
#pragma weak DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler = default_handler
#pragma weak DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler = default_handler
#pragma weak ADC1_COMP_IRQHandler             = default_handler
#pragma weak TIM1_BRK_UP_TRG_COM_IRQHandler   = default_handler
#pragma weak TIM1_CC_IRQHandler               = default_handler
#pragma weak TIM2_IRQHandler                  = default_handler
#pragma weak TIM3_IRQHandler                  = default_handler
#pragma weak TIM6_DAC_IRQHandler              = default_handler
#pragma weak TIM7_IRQHandler                  = default_handler
#pragma weak TIM14_IRQHandler                 = default_handler
#pragma weak TIM15_IRQHandler                 = default_handler
#pragma weak TIM16_IRQHandler                 = default_handler
#pragma weak TIM17_IRQHandler                 = default_handler
#pragma weak I2C1_IRQHandler                  = default_handler
#pragma weak I2C2_IRQHandler                  = default_handler
#pragma weak SPI1_IRQHandler                  = default_handler
#pragma weak SPI2_IRQHandler                  = default_handler
#pragma weak USART1_IRQHandler                = default_handler
#pragma weak USART2_IRQHandler                = default_handler
#pragma weak USART3_8_IRQHandler              = default_handler
#pragma weak CEC_CAN_IRQHandler               = default_handler

#else // NDEBUG

WEAK void WWDG_IRQHandler                  ()  { default_handler(); }
WEAK void VDDIO2_IRQHandler                ()  { default_handler(); }
WEAK void RTC_IRQHandler                   ()  { default_handler(); }
WEAK void FLASH_IRQHandler                 ()  { default_handler(); }
WEAK void RCC_CRS_IRQHandler               ()  { default_handler(); }
WEAK void EXTI0_1_IRQHandler               ()  { default_handler(); }
WEAK void EXTI2_3_IRQHandler               ()  { default_handler(); }
WEAK void EXTI4_15_IRQHandler              ()  { default_handler(); }
WEAK void TSC_IRQHandler                   ()  { default_handler(); }
WEAK void DMA1_Ch1_IRQHandler              ()  { default_handler(); }
WEAK void DMA1_Ch2_3_DMA2_Ch1_2_IRQHandler ()  { default_handler(); }
WEAK void DMA1_Ch4_7_DMA2_Ch3_5_IRQHandler ()  { default_handler(); }
WEAK void ADC1_COMP_IRQHandler             ()  { default_handler(); }
WEAK void TIM1_BRK_UP_TRG_COM_IRQHandler   ()  { default_handler(); }
WEAK void TIM1_CC_IRQHandler               ()  { default_handler(); }
WEAK void TIM2_IRQHandler                  ()  { default_handler(); }
WEAK void TIM3_IRQHandler                  ()  { default_handler(); }
WEAK void TIM6_DAC_IRQHandler              ()  { default_handler(); }
WEAK void TIM7_IRQHandler                  ()  { default_handler(); }
WEAK void TIM14_IRQHandler                 ()  { default_handler(); }
WEAK void TIM15_IRQHandler                 ()  { default_handler(); }
WEAK void TIM16_IRQHandler                 ()  { default_handler(); }
WEAK void TIM17_IRQHandler                 ()  { default_handler(); }
WEAK void I2C1_IRQHandler                  ()  { default_handler(); }
WEAK void I2C2_IRQHandler                  ()  { default_handler(); }
WEAK void SPI1_IRQHandler                  ()  { default_handler(); }
WEAK void SPI2_IRQHandler                  ()  { default_handler(); }
WEAK void USART1_IRQHandler                ()  { default_handler(); }
WEAK void USART2_IRQHandler                ()  { default_handler(); }
WEAK void USART3_8_IRQHandler              ()  { default_handler(); }
WEAK void CEC_CAN_IRQHandler               ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
