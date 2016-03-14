//******************************************************************************
//*
//*      STM32L071XX vector table
//*
//*      Version 1.0
//*
//*      Copyright (c) 2016, emb-lib Project Team
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
const intvec_item_t __vector_table[] =
{
    { .__ptr = __top_of_stack },
    Reset_Handler,

    //--------------------------------------------------------------------------
    //
    // Cortex-M3 core exceptions 
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
    WWDG_IRQHandler,                   // Window Watchdog
    PVD_IRQHandler,                    // PVD through EXTI Line detect
    RTC_IRQHandler,                    // RTC through EXTI Line
    FLASH_IRQHandler,                  // FLASH
    RCC_IRQHandler,                    // RCC
    EXTI0_1_IRQHandler,                // EXTI Line 0 and 1
    EXTI2_3_IRQHandler,                // EXTI Line 2 and 3
    EXTI4_15_IRQHandler,               // EXTI Line 4 to 15
    0,                                 // Reserved
    DMA1_Channel1_IRQHandler,          // DMA1 Channel 1
    DMA1_Channel2_3_IRQHandler,        // DMA1 Channel 2 and Channel 3
    DMA1_Channel4_5_6_7_IRQHandler,    // DMA1 Channel 4, Channel 5, Channel 6 and Channel 7
    ADC1_COMP_IRQHandler,              // ADC1, COMP1 and COMP2 
    LPTIM1_IRQHandler,                 // LPTIM1
    USART4_5_IRQHandler,               // USART4 and USART5
    TIM2_IRQHandler,                   // TIM2
    TIM3_IRQHandler,                   // TIM3
    TIM6_IRQHandler,                   // TIM6
    TIM7_IRQHandler,                   // TIM7
    0,                                 // Reserved
    TIM21_IRQHandler,                  // TIM21
    I2C3_IRQHandler,                   // I2C3
    TIM22_IRQHandler,                  // TIM22
    I2C1_IRQHandler,                   // I2C1
    I2C2_IRQHandler,                   // I2C2
    SPI1_IRQHandler,                   // SPI1
    SPI2_IRQHandler,                   // SPI2
    USART1_IRQHandler,                 // USART1
    USART2_IRQHandler,                 // USART2
    LPUART1_IRQHandler,                // LPUART1
    0,                                 // Reserved
    0                                  // Reserved
};
//------------------------------------------------------------------------------
static void default_handler() { for(;;) { } }
static void hf_handler()
{
    volatile int i = 0;         //  debug variable: set non-zero value to 
    while(!i) { }               //  return from handler - this figures out 
                                //  an address where HW fault raises
}
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

#pragma weak WWDG_IRQHandler                = default_handler
#pragma weak PVD_IRQHandler                 = default_handler
#pragma weak RTC_IRQHandler                 = default_handler
#pragma weak FLASH_IRQHandler               = default_handler
#pragma weak RCC_IRQHandler                 = default_handler
#pragma weak EXTI0_1_IRQHandler             = default_handler
#pragma weak EXTI2_3_IRQHandler             = default_handler
#pragma weak EXTI4_15_IRQHandler            = default_handler
#pragma weak DMA1_Channel1_IRQHandler       = default_handler
#pragma weak DMA1_Channel2_3_IRQHandler     = default_handler
#pragma weak DMA1_Channel4_5_6_7_IRQHandler = default_handler
#pragma weak ADC1_COMP_IRQHandler           = default_handler
#pragma weak LPTIM1_IRQHandler              = default_handler
#pragma weak USART4_5_IRQHandler            = default_handler
#pragma weak TIM2_IRQHandler                = default_handler
#pragma weak TIM3_IRQHandler                = default_handler
#pragma weak TIM6_IRQHandler                = default_handler
#pragma weak TIM7_IRQHandler                = default_handler
#pragma weak TIM21_IRQHandler               = default_handler
#pragma weak I2C3_IRQHandler                = default_handler
#pragma weak TIM22_IRQHandler               = default_handler
#pragma weak I2C1_IRQHandler                = default_handler
#pragma weak I2C2_IRQHandler                = default_handler
#pragma weak SPI1_IRQHandler                = default_handler
#pragma weak SPI2_IRQHandler                = default_handler
#pragma weak USART1_IRQHandler              = default_handler
#pragma weak USART2_IRQHandler              = default_handler
#pragma weak LPUART1_IRQHandler             = default_handler

#else // NDEBUG

WEAK void WWDG_IRQHandler                ()  { default_handler(); }
WEAK void PVD_IRQHandler                 ()  { default_handler(); }
WEAK void RTC_IRQHandler                 ()  { default_handler(); }
WEAK void FLASH_IRQHandler               ()  { default_handler(); }
WEAK void RCC_IRQHandler                 ()  { default_handler(); }
WEAK void EXTI0_1_IRQHandler             ()  { default_handler(); }
WEAK void EXTI2_3_IRQHandler             ()  { default_handler(); }
WEAK void EXTI4_15_IRQHandler            ()  { default_handler(); }
WEAK void DMA1_Channel1_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Channel2_3_IRQHandler     ()  { default_handler(); }
WEAK void DMA1_Channel4_5_6_7_IRQHandler ()  { default_handler(); }
WEAK void ADC1_COMP_IRQHandler           ()  { default_handler(); }
WEAK void LPTIM1_IRQHandler              ()  { default_handler(); }
WEAK void USART4_5_IRQHandler            ()  { default_handler(); }
WEAK void TIM2_IRQHandler                ()  { default_handler(); }
WEAK void TIM3_IRQHandler                ()  { default_handler(); }
WEAK void TIM6_IRQHandler                ()  { default_handler(); }
WEAK void TIM7_IRQHandler                ()  { default_handler(); }
WEAK void TIM21_IRQHandler               ()  { default_handler(); }
WEAK void I2C3_IRQHandler                ()  { default_handler(); }
WEAK void TIM22_IRQHandler               ()  { default_handler(); }
WEAK void I2C1_IRQHandler                ()  { default_handler(); }
WEAK void I2C2_IRQHandler                ()  { default_handler(); }
WEAK void SPI1_IRQHandler                ()  { default_handler(); }
WEAK void SPI2_IRQHandler                ()  { default_handler(); }
WEAK void USART1_IRQHandler              ()  { default_handler(); }
WEAK void USART2_IRQHandler              ()  { default_handler(); }
WEAK void LPUART1_IRQHandler             ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
