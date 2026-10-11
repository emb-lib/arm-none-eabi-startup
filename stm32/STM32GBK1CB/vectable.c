//******************************************************************************
//*
//*      STM32GBK1CB vector table
//*
//*      Version 1.2
//*
//*      Copyright (c) 2016-2026, emb-lib Project Team
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
    WWDG_IRQHandler,                  // Window WatchDog
    PVD_PVM_IRQHandler,               // PVD/PVM1/PVM2/PVM3/PVM4 through EXTI Line detection
    RTC_TAMP_LSECSS_IRQHandler,       // RTC, TAMP and RCC LSE_CSS through the EXTI line
    RTC_WKUP_IRQHandler,              // RTC Wakeup through the EXTI line
    FLASH_IRQHandler,                 // FLASH
    RCC_IRQHandler,                   // RCC
    EXTI0_IRQHandler,                 // EXTI Line0
    EXTI1_IRQHandler,                 // EXTI Line1
    EXTI2_IRQHandler,                 // EXTI Line2
    EXTI3_IRQHandler,                 // EXTI Line3
    EXTI4_IRQHandler,                 // EXTI Line4
    DMA1_Channel1_IRQHandler,         // DMA1 Channel 1
    DMA1_Channel2_IRQHandler,         // DMA1 Channel 2
    DMA1_Channel3_IRQHandler,         // DMA1 Channel 3
    DMA1_Channel4_IRQHandler,         // DMA1 Channel 4
    DMA1_Channel5_IRQHandler,         // DMA1 Channel 5
    DMA1_Channel6_IRQHandler,         // DMA1 Channel 6
    0,                                // Reserved
    ADC1_2_IRQHandler,                // ADC1 and ADC2
    USB_HP_IRQHandler,                // USB Device High Priority
    USB_LP_IRQHandler,                // USB Device Low Priority
    FDCAN1_IT0_IRQHandler,            // FDCAN1 interrupt line 0
    FDCAN1_IT1_IRQHandler,            // FDCAN1 interrupt line 1
    EXTI9_5_IRQHandler,               // External Line[9:5]s
    TIM1_BRK_TIM15_IRQHandler,        // TIM1 Break, Transition error, Index error and TIM15
    TIM1_UP_TIM16_IRQHandler,         // TIM1 Update and TIM16
    TIM1_TRG_COM_TIM17_IRQHandler,    // TIM1 Trigger, Commutation, Direction change, Index and TIM17
    TIM1_CC_IRQHandler,               // TIM1 Capture Compare
    TIM2_IRQHandler,                  // TIM2
    TIM3_IRQHandler,                  // TIM3
    TIM4_IRQHandler,                  // TIM4
    I2C1_EV_IRQHandler,               // I2C1 Event
    I2C1_ER_IRQHandler,               // I2C1 Error
    I2C2_EV_IRQHandler,               // I2C2 Event
    I2C2_ER_IRQHandler,               // I2C2 Error
    SPI1_IRQHandler,                  // SPI1
    SPI2_IRQHandler,                  // SPI2
    USART1_IRQHandler,                // USART1
    USART2_IRQHandler,                // USART2
    USART3_IRQHandler,                // USART3
    EXTI15_10_IRQHandler,             // External Line[15:10]
    RTC_Alarm_IRQHandler,             // RTC Alarm (A and B) through EXTI Line
    USBWakeUp_IRQHandler,             // USB Wakeup through EXTI line
    TIM8_BRK_IRQHandler,              // TIM8 Break, Transition error and Index error Interrupt
    TIM8_UP_IRQHandler,               // TIM8 Update Interrupt
    TIM8_TRG_COM_IRQHandler,          // TIM8 Trigger, Commutation, Direction change and Index Interrupt
    TIM8_CC_IRQHandler,               // TIM8 Capture Compare Interrupt
    0,                                // Reserved
    0,                                // Reserved
    LPTIM1_IRQHandler,                // LP TIM1 interrupt
    0,                                // Reserved
    SPI3_IRQHandler,                  // SPI3
    0,                                // Reserved
    0,                                // Reserved
    TIM6_DAC_IRQHandler,              // TIM6 and DAC1&3 underrun errors
    TIM7_IRQHandler,                  // TIM7
    DMA2_Channel1_IRQHandler,         // DMA2 Channel 1
    DMA2_Channel2_IRQHandler,         // DMA2 Channel 2
    DMA2_Channel3_IRQHandler,         // DMA2 Channel 3
    DMA2_Channel4_IRQHandler,         // DMA2 Channel 4
    DMA2_Channel5_IRQHandler,         // DMA2 Channel 5
    0,                                // Reserved
    0,                                // Reserved
    UCPD1_IRQHandler,                 // UCPD1
    COMP1_2_3_IRQHandler,             // COMP1, COMP2 and COMP3
    COMP4_IRQHandler,                 // COMP4
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    CRS_IRQHandler,                   // CRS Interrupt
    SAI1_IRQHandler,                  // Serial Audio Interface 1 global interrupt
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    FPU_IRQHandler,                   // FPU
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    RNG_IRQHandler,                   // RNG global interrupt
    LPUART1_IRQHandler,               // LP UART 1 interrupt
    I2C3_EV_IRQHandler,               // I2C3 Event
    I2C3_ER_IRQHandler,               // I2C3 Error
    DMAMUX_OVR_IRQHandler,            // DMAMUX overrun global interrupt
    0,                                // Reserved
    0,                                // Reserved
    DMA2_Channel6_IRQHandler,         // DMA2 Channel 6
    0,                                // Reserved
    0,                                // Reserved
    CORDIC_IRQHandler,                // CORDIC
    FMAC_IRQHandler                   // FMAC
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

#pragma weak WWDG_IRQHandler               = default_handler
#pragma weak PVD_PVM_IRQHandler            = default_handler
#pragma weak RTC_TAMP_LSECSS_IRQHandler    = default_handler
#pragma weak RTC_WKUP_IRQHandler           = default_handler
#pragma weak FLASH_IRQHandler              = default_handler
#pragma weak RCC_IRQHandler                = default_handler
#pragma weak EXTI0_IRQHandler              = default_handler
#pragma weak EXTI1_IRQHandler              = default_handler
#pragma weak EXTI2_IRQHandler              = default_handler
#pragma weak EXTI3_IRQHandler              = default_handler
#pragma weak EXTI4_IRQHandler              = default_handler
#pragma weak DMA1_Channel1_IRQHandler      = default_handler
#pragma weak DMA1_Channel2_IRQHandler      = default_handler
#pragma weak DMA1_Channel3_IRQHandler      = default_handler
#pragma weak DMA1_Channel4_IRQHandler      = default_handler
#pragma weak DMA1_Channel5_IRQHandler      = default_handler
#pragma weak DMA1_Channel6_IRQHandler      = default_handler
#pragma weak ADC1_2_IRQHandler             = default_handler
#pragma weak USB_HP_IRQHandler             = default_handler
#pragma weak USB_LP_IRQHandler             = default_handler
#pragma weak FDCAN1_IT0_IRQHandler         = default_handler
#pragma weak FDCAN1_IT1_IRQHandler         = default_handler
#pragma weak EXTI9_5_IRQHandler            = default_handler
#pragma weak TIM1_BRK_TIM15_IRQHandler     = default_handler
#pragma weak TIM1_UP_TIM16_IRQHandler      = default_handler
#pragma weak TIM1_TRG_COM_TIM17_IRQHandler = default_handler
#pragma weak TIM1_CC_IRQHandler            = default_handler
#pragma weak TIM2_IRQHandler               = default_handler
#pragma weak TIM3_IRQHandler               = default_handler
#pragma weak TIM4_IRQHandler               = default_handler
#pragma weak I2C1_EV_IRQHandler            = default_handler
#pragma weak I2C1_ER_IRQHandler            = default_handler
#pragma weak I2C2_EV_IRQHandler            = default_handler
#pragma weak I2C2_ER_IRQHandler            = default_handler
#pragma weak SPI1_IRQHandler               = default_handler
#pragma weak SPI2_IRQHandler               = default_handler
#pragma weak USART1_IRQHandler             = default_handler
#pragma weak USART2_IRQHandler             = default_handler
#pragma weak USART3_IRQHandler             = default_handler
#pragma weak EXTI15_10_IRQHandler          = default_handler
#pragma weak RTC_Alarm_IRQHandler          = default_handler
#pragma weak USBWakeUp_IRQHandler          = default_handler
#pragma weak TIM8_BRK_IRQHandler           = default_handler
#pragma weak TIM8_UP_IRQHandler            = default_handler
#pragma weak TIM8_TRG_COM_IRQHandler       = default_handler
#pragma weak TIM8_CC_IRQHandler            = default_handler
#pragma weak LPTIM1_IRQHandler             = default_handler
#pragma weak SPI3_IRQHandler               = default_handler
#pragma weak TIM6_DAC_IRQHandler           = default_handler
#pragma weak TIM7_IRQHandler               = default_handler
#pragma weak DMA2_Channel1_IRQHandler      = default_handler
#pragma weak DMA2_Channel2_IRQHandler      = default_handler
#pragma weak DMA2_Channel3_IRQHandler      = default_handler
#pragma weak DMA2_Channel4_IRQHandler      = default_handler
#pragma weak DMA2_Channel5_IRQHandler      = default_handler
#pragma weak UCPD1_IRQHandler              = default_handler
#pragma weak COMP1_2_3_IRQHandler          = default_handler
#pragma weak COMP4_IRQHandler              = default_handler
#pragma weak CRS_IRQHandler                = default_handler
#pragma weak SAI1_IRQHandler               = default_handler
#pragma weak FPU_IRQHandler                = default_handler
#pragma weak RNG_IRQHandler                = default_handler
#pragma weak LPUART1_IRQHandler            = default_handler
#pragma weak I2C3_EV_IRQHandler            = default_handler
#pragma weak I2C3_ER_IRQHandler            = default_handler
#pragma weak DMAMUX_OVR_IRQHandler         = default_handler
#pragma weak DMA2_Channel6_IRQHandler      = default_handler
#pragma weak CORDIC_IRQHandler             = default_handler
#pragma weak FMAC_IRQHandler               = default_handler

#else // NDEBUG

WEAK void WWDG_IRQHandler               ()  { default_handler(); }
WEAK void PVD_PVM_IRQHandler            ()  { default_handler(); }
WEAK void RTC_TAMP_LSECSS_IRQHandler    ()  { default_handler(); }
WEAK void RTC_WKUP_IRQHandler           ()  { default_handler(); }
WEAK void FLASH_IRQHandler              ()  { default_handler(); }
WEAK void RCC_IRQHandler                ()  { default_handler(); }
WEAK void EXTI0_IRQHandler              ()  { default_handler(); }
WEAK void EXTI1_IRQHandler              ()  { default_handler(); }
WEAK void EXTI2_IRQHandler              ()  { default_handler(); }
WEAK void EXTI3_IRQHandler              ()  { default_handler(); }
WEAK void EXTI4_IRQHandler              ()  { default_handler(); }
WEAK void DMA1_Channel1_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel2_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel3_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel4_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel5_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel6_IRQHandler      ()  { default_handler(); }
WEAK void ADC1_2_IRQHandler             ()  { default_handler(); }
WEAK void USB_HP_IRQHandler             ()  { default_handler(); }
WEAK void USB_LP_IRQHandler             ()  { default_handler(); }
WEAK void FDCAN1_IT0_IRQHandler         ()  { default_handler(); }
WEAK void FDCAN1_IT1_IRQHandler         ()  { default_handler(); }
WEAK void EXTI9_5_IRQHandler            ()  { default_handler(); }
WEAK void TIM1_BRK_TIM15_IRQHandler     ()  { default_handler(); }
WEAK void TIM1_UP_TIM16_IRQHandler      ()  { default_handler(); }
WEAK void TIM1_TRG_COM_TIM17_IRQHandler ()  { default_handler(); }
WEAK void TIM1_CC_IRQHandler            ()  { default_handler(); }
WEAK void TIM2_IRQHandler               ()  { default_handler(); }
WEAK void TIM3_IRQHandler               ()  { default_handler(); }
WEAK void TIM4_IRQHandler               ()  { default_handler(); }
WEAK void I2C1_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C1_ER_IRQHandler            ()  { default_handler(); }
WEAK void I2C2_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C2_ER_IRQHandler            ()  { default_handler(); }
WEAK void SPI1_IRQHandler               ()  { default_handler(); }
WEAK void SPI2_IRQHandler               ()  { default_handler(); }
WEAK void USART1_IRQHandler             ()  { default_handler(); }
WEAK void USART2_IRQHandler             ()  { default_handler(); }
WEAK void USART3_IRQHandler             ()  { default_handler(); }
WEAK void EXTI15_10_IRQHandler          ()  { default_handler(); }
WEAK void RTC_Alarm_IRQHandler          ()  { default_handler(); }
WEAK void USBWakeUp_IRQHandler          ()  { default_handler(); }
WEAK void TIM8_BRK_IRQHandler           ()  { default_handler(); }
WEAK void TIM8_UP_IRQHandler            ()  { default_handler(); }
WEAK void TIM8_TRG_COM_IRQHandler       ()  { default_handler(); }
WEAK void TIM8_CC_IRQHandler            ()  { default_handler(); }
WEAK void LPTIM1_IRQHandler             ()  { default_handler(); }
WEAK void SPI3_IRQHandler               ()  { default_handler(); }
WEAK void TIM6_DAC_IRQHandler           ()  { default_handler(); }
WEAK void TIM7_IRQHandler               ()  { default_handler(); }
WEAK void DMA2_Channel1_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel2_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel3_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel4_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel5_IRQHandler      ()  { default_handler(); }
WEAK void UCPD1_IRQHandler              ()  { default_handler(); }
WEAK void COMP1_2_3_IRQHandler          ()  { default_handler(); }
WEAK void COMP4_IRQHandler              ()  { default_handler(); }
WEAK void CRS_IRQHandler                ()  { default_handler(); }
WEAK void SAI1_IRQHandler               ()  { default_handler(); }
WEAK void FPU_IRQHandler                ()  { default_handler(); }
WEAK void RNG_IRQHandler                ()  { default_handler(); }
WEAK void LPUART1_IRQHandler            ()  { default_handler(); }
WEAK void I2C3_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C3_ER_IRQHandler            ()  { default_handler(); }
WEAK void DMAMUX_OVR_IRQHandler         ()  { default_handler(); }
WEAK void DMA2_Channel6_IRQHandler      ()  { default_handler(); }
WEAK void CORDIC_IRQHandler             ()  { default_handler(); }
WEAK void FMAC_IRQHandler               ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
