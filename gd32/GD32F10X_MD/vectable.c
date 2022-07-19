//******************************************************************************
//*
//*      GD32F10X_MD vector table
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
    WWDGT_IRQHandler,               // 16:Window Watchdog Timer
    LVD_IRQHandler,                 // 17:LVD through EXTI Line detect
    TAMPER_IRQHandler,              // 18:Tamper Interrupt   
    RTC_IRQHandler,                 // 19:RTC through EXTI Line
    FMC_IRQHandler,                 // 20:FMC
    RCU_IRQHandler,                 // 21:RCU
    EXTI0_IRQHandler,               // 22:EXTI Line 0
    EXTI1_IRQHandler,               // 23:EXTI Line 1
    EXTI2_IRQHandler,               // 24:EXTI Line 2
    EXTI3_IRQHandler,               // 25:EXTI Line 3
    EXTI4_IRQHandler,               // 26:EXTI Line 4
    DMA0_Channel0_IRQHandler,       // 27:DMA0 Channel 0
    DMA0_Channel1_IRQHandler,       // 28:DMA0 Channel 1
    DMA0_Channel2_IRQHandler,       // 29:DMA0 Channel 2
    DMA0_Channel3_IRQHandler,       // 30:DMA0 Channel 3
    DMA0_Channel4_IRQHandler,       // 31:DMA0 Channel 4
    DMA0_Channel5_IRQHandler,       // 32:DMA0 Channel 5 
    DMA0_Channel6_IRQHandler,       // 33:DMA0 Channel 6
    ADC0_1_IRQHandler,              // 34:ADC0 and ADC1
    USBD_HP_CAN0_TX_IRQHandler,     // 35:USBD and CAN0 TX
    USBD_LP_CAN0_RX0_IRQHandler,    // 36:USBD and CAN0 RX0
    CAN0_RX1_IRQHandler,            // 37:CAN0 RX1
    CAN0_EWMC_IRQHandler,           // 38:CAN0 EWMC
    EXTI5_9_IRQHandler,             // 39:EXTI Line 5 to EXTI Line 9
    TIMER0_BRK_IRQHandler,          // 40:TIMER0 Break
    TIMER0_UP_IRQHandler,           // 41:TIMER0 Update
    TIMER0_TRG_CMT_IRQHandler,      // 42:TIMER0 Trigger
    TIMER0_Channel_IRQHandler,      // 43:TIMER0 Channel Capture Compare
    TIMER1_IRQHandler,              // 44:TIMER1
    TIMER2_IRQHandler,              // 45:TIMER2
    TIMER3_IRQHandler,              // 46:TIMER3
    I2C0_EV_IRQHandler,             // 47:I2C0 Event
    I2C0_ER_IRQHandler,             // 48:I2C0 Error
    I2C1_EV_IRQHandler,             // 49:I2C1 Event
    I2C1_ER_IRQHandler,             // 50:I2C1 Error
    SPI0_IRQHandler,                // 51:SPI0
    SPI1_IRQHandler,                // 52:SPI1
    USART0_IRQHandler,              // 53:USART0
    USART1_IRQHandler,              // 54:USART1
    USART2_IRQHandler,              // 55:USART2
    EXTI10_15_IRQHandler,           // 56:EXTI Line 10 to EXTI Line 15
    RTC_Alarm_IRQHandler,           // 57:RTC Alarm through EXTI Line
    USBD_WKUP_IRQHandler,           // 58:USBD WakeUp from suspend through EXTI Line
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    0,                              // Reserved
    EXMC_IRQHandler                 // 64:EXMC
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

#pragma weak WWDGT_IRQHandler            = default_handler
#pragma weak LVD_IRQHandler              = default_handler
#pragma weak TAMPER_IRQHandler           = default_handler
#pragma weak RTC_IRQHandler              = default_handler
#pragma weak FMC_IRQHandler              = default_handler
#pragma weak RCU_IRQHandler              = default_handler
#pragma weak EXTI0_IRQHandler            = default_handler
#pragma weak EXTI1_IRQHandler            = default_handler
#pragma weak EXTI2_IRQHandler            = default_handler
#pragma weak EXTI3_IRQHandler            = default_handler
#pragma weak EXTI4_IRQHandler            = default_handler
#pragma weak DMA0_Channel0_IRQHandler    = default_handler
#pragma weak DMA0_Channel1_IRQHandler    = default_handler
#pragma weak DMA0_Channel2_IRQHandler    = default_handler
#pragma weak DMA0_Channel3_IRQHandler    = default_handler
#pragma weak DMA0_Channel4_IRQHandler    = default_handler
#pragma weak DMA0_Channel5_IRQHandler    = default_handler
#pragma weak DMA0_Channel6_IRQHandler    = default_handler
#pragma weak ADC0_1_IRQHandler           = default_handler
#pragma weak USBD_HP_CAN0_TX_IRQHandler  = default_handler
#pragma weak USBD_LP_CAN0_RX0_IRQHandler = default_handler
#pragma weak CAN0_RX1_IRQHandler         = default_handler
#pragma weak CAN0_EWMC_IRQHandler        = default_handler
#pragma weak EXTI5_9_IRQHandler          = default_handler
#pragma weak TIMER0_BRK_IRQHandler       = default_handler
#pragma weak TIMER0_UP_IRQHandler        = default_handler
#pragma weak TIMER0_TRG_CMT_IRQHandler   = default_handler
#pragma weak TIMER0_Channel_IRQHandler   = default_handler
#pragma weak TIMER1_IRQHandler           = default_handler
#pragma weak TIMER2_IRQHandler           = default_handler
#pragma weak TIMER3_IRQHandler           = default_handler
#pragma weak I2C0_EV_IRQHandler          = default_handler
#pragma weak I2C0_ER_IRQHandler          = default_handler
#pragma weak I2C1_EV_IRQHandler          = default_handler
#pragma weak I2C1_ER_IRQHandler          = default_handler
#pragma weak SPI0_IRQHandler             = default_handler
#pragma weak SPI1_IRQHandler             = default_handler
#pragma weak USART0_IRQHandler           = default_handler
#pragma weak USART1_IRQHandler           = default_handler
#pragma weak USART2_IRQHandler           = default_handler
#pragma weak EXTI10_15_IRQHandler        = default_handler
#pragma weak RTC_Alarm_IRQHandler        = default_handler
#pragma weak USBD_WKUP_IRQHandler        = default_handler
#pragma weak EXMC_IRQHandler             = default_handler

#else // NDEBUG

WEAK void WWDGT_IRQHandler            ()  { default_handler(); }
WEAK void LVD_IRQHandler              ()  { default_handler(); }
WEAK void TAMPER_IRQHandler           ()  { default_handler(); }
WEAK void RTC_IRQHandler              ()  { default_handler(); }
WEAK void FMC_IRQHandler              ()  { default_handler(); }
WEAK void RCU_IRQHandler              ()  { default_handler(); }
WEAK void EXTI0_IRQHandler            ()  { default_handler(); }
WEAK void EXTI1_IRQHandler            ()  { default_handler(); }
WEAK void EXTI2_IRQHandler            ()  { default_handler(); }
WEAK void EXTI3_IRQHandler            ()  { default_handler(); }
WEAK void EXTI4_IRQHandler            ()  { default_handler(); }
WEAK void DMA0_Channel0_IRQHandler    ()  { default_handler(); }
WEAK void DMA0_Channel1_IRQHandler    ()  { default_handler(); }
WEAK void DMA0_Channel2_IRQHandler    ()  { default_handler(); }
WEAK void DMA0_Channel3_IRQHandler    ()  { default_handler(); }
WEAK void DMA0_Channel4_IRQHandler    ()  { default_handler(); }
WEAK void DMA0_Channel5_IRQHandler    ()  { default_handler(); }
WEAK void DMA0_Channel6_IRQHandler    ()  { default_handler(); }
WEAK void ADC0_1_IRQHandler           ()  { default_handler(); }
WEAK void USBD_HP_CAN0_TX_IRQHandler  ()  { default_handler(); }
WEAK void USBD_LP_CAN0_RX0_IRQHandler ()  { default_handler(); }
WEAK void CAN0_RX1_IRQHandler         ()  { default_handler(); }
WEAK void CAN0_EWMC_IRQHandler        ()  { default_handler(); }
WEAK void EXTI5_9_IRQHandler          ()  { default_handler(); }
WEAK void TIMER0_BRK_IRQHandler       ()  { default_handler(); }
WEAK void TIMER0_UP_IRQHandler        ()  { default_handler(); }
WEAK void TIMER0_TRG_CMT_IRQHandler   ()  { default_handler(); }
WEAK void TIMER0_Channel_IRQHandler   ()  { default_handler(); }
WEAK void TIMER1_IRQHandler           ()  { default_handler(); }
WEAK void TIMER2_IRQHandler           ()  { default_handler(); }
WEAK void TIMER3_IRQHandler           ()  { default_handler(); }
WEAK void I2C0_EV_IRQHandler          ()  { default_handler(); }
WEAK void I2C0_ER_IRQHandler          ()  { default_handler(); }
WEAK void I2C1_EV_IRQHandler          ()  { default_handler(); }
WEAK void I2C1_ER_IRQHandler          ()  { default_handler(); }
WEAK void SPI0_IRQHandler             ()  { default_handler(); }
WEAK void SPI1_IRQHandler             ()  { default_handler(); }
WEAK void USART0_IRQHandler           ()  { default_handler(); }
WEAK void USART1_IRQHandler           ()  { default_handler(); }
WEAK void USART2_IRQHandler           ()  { default_handler(); }
WEAK void EXTI10_15_IRQHandler        ()  { default_handler(); }
WEAK void RTC_Alarm_IRQHandler        ()  { default_handler(); }
WEAK void USBD_WKUP_IRQHandler        ()  { default_handler(); }
WEAK void EXMC_IRQHandler             ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
