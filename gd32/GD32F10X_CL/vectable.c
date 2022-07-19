//******************************************************************************
//*
//*      GD32F10X_CL vector table
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
    WWDGT_IRQHandler,             // 16:Window Watchdog Timer
    LVD_IRQHandler,               // 17:LVD through EXTI Line detect
    TAMPER_IRQHandler,            // 18:Tamper Interrupt   
    RTC_IRQHandler,               // 19:RTC through EXTI Line
    FMC_IRQHandler,               // 20:FMC
    RCU_IRQHandler,               // 21:RCU
    EXTI0_IRQHandler,             // 22:EXTI Line 0
    EXTI1_IRQHandler,             // 23:EXTI Line 1
    EXTI2_IRQHandler,             // 24:EXTI Line 2
    EXTI3_IRQHandler,             // 25:EXTI Line 3
    EXTI4_IRQHandler,             // 26:EXTI Line 4
    DMA0_Channel0_IRQHandler,     // 27:DMA0 Channel 0
    DMA0_Channel1_IRQHandler,     // 28:DMA0 Channel 1
    DMA0_Channel2_IRQHandler,     // 29:DMA0 Channel 2
    DMA0_Channel3_IRQHandler,     // 30:DMA0 Channel 3
    DMA0_Channel4_IRQHandler,     // 31:DMA0 Channel 4
    DMA0_Channel5_IRQHandler,     // 32:DMA0 Channel 5 
    DMA0_Channel6_IRQHandler,     // 33:DMA0 Channel 6
    ADC0_1_IRQHandler,            // 34:ADC0 and ADC1
    CAN0_TX_IRQHandler,           // 35:CAN0 TX
    CAN0_RX0_IRQHandler,          // 36:CAN0 RX0
    CAN0_RX1_IRQHandler,          // 37:CAN0 RX1
    CAN0_EWMC_IRQHandler,         // 38:CAN0 EWMC
    EXTI5_9_IRQHandler,           // 39:EXTI Line 5 to EXTI Line 9
    TIMER0_BRK_IRQHandler,        // 40:TIMER0 Break
    TIMER0_UP_IRQHandler,         // 41:TIMER0 Update
    TIMER0_TRG_CMT_IRQHandler,    // 42:TIMER0 Trigger and Commutation
    TIMER0_Channel_IRQHandler,    // 43:TIMER0 Channel Capture Compare
    TIMER1_IRQHandler,            // 44:TIMER1
    TIMER2_IRQHandler,            // 45:TIMER2
    TIMER3_IRQHandler,            // 46:TIMER3
    I2C0_EV_IRQHandler,           // 47:I2C0 Event
    I2C0_ER_IRQHandler,           // 48:I2C0 Error
    I2C1_EV_IRQHandler,           // 49:I2C1 Event
    I2C1_ER_IRQHandler,           // 50:I2C1 Error
    SPI0_IRQHandler,              // 51:SPI0
    SPI1_IRQHandler,              // 52:SPI1
    USART0_IRQHandler,            // 53:USART0
    USART1_IRQHandler,            // 54:USART1
    USART2_IRQHandler,            // 55:USART2
    EXTI10_15_IRQHandler,         // 56:EXTI Line 10 to EXTI Line 15
    RTC_Alarm_IRQHandler,         // 57:RTC Alarm through EXTI Line
    USBFS_WKUP_IRQHandler,        // 58:USBFS WakeUp from suspend through EXTI Line
    TIMER7_BRK_IRQHandler,        // 59:TIMER7 Break Interrupt
    TIMER7_UP_IRQHandler,         // 60:TIMER7 Update Interrupt
    TIMER7_TRG_CMT_IRQHandler,    // 61:TIMER7 Trigger
    TIMER7_Channel_IRQHandler,    // 62:TIMER7 Channel Capture Compare 
    0,                            // Reserved
    EXMC_IRQHandler,              // 64:EXMC
    0,                            // Reserved
    TIMER4_IRQHandler,            // 66:TIMER4
    SPI2_IRQHandler,              // 67:SPI2
    UART3_IRQHandler,             // 68:UART3
    UART4_IRQHandler,             // 69:UART4
    TIMER5_IRQHandler,            // 70:TIMER5
    TIMER6_IRQHandler,            // 71:TIMER6
    DMA1_Channel0_IRQHandler,     // 72:DMA1 Channel0
    DMA1_Channel1_IRQHandler,     // 73:DMA1 Channel1
    DMA1_Channel2_IRQHandler,     // 74:DMA1 Channel2
    DMA1_Channel3_IRQHandler,     // 75:DMA1 Channel3
    DMA1_Channel4_IRQHandler,     // 76:DMA1 Channel4
    ENET_IRQHandler,              // 77:Ethernet
    ENET_WKUP_IRQHandler,         // 78:Ethernet Wakeup through EXTI line
    CAN1_TX_IRQHandler,           // 79:CAN1 TX
    CAN1_RX0_IRQHandler,          // 80:CAN1 RX0
    CAN1_RX1_IRQHandler,          // 81:CAN1 RX1
    CAN1_EWMC_IRQHandler,         // 82:CAN1 EWMC
    USBFS_IRQHandler              // 83:USBFS
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

#pragma weak WWDGT_IRQHandler          = default_handler
#pragma weak LVD_IRQHandler            = default_handler
#pragma weak TAMPER_IRQHandler         = default_handler
#pragma weak RTC_IRQHandler            = default_handler
#pragma weak FMC_IRQHandler            = default_handler
#pragma weak RCU_IRQHandler            = default_handler
#pragma weak EXTI0_IRQHandler          = default_handler
#pragma weak EXTI1_IRQHandler          = default_handler
#pragma weak EXTI2_IRQHandler          = default_handler
#pragma weak EXTI3_IRQHandler          = default_handler
#pragma weak EXTI4_IRQHandler          = default_handler
#pragma weak DMA0_Channel0_IRQHandler  = default_handler
#pragma weak DMA0_Channel1_IRQHandler  = default_handler
#pragma weak DMA0_Channel2_IRQHandler  = default_handler
#pragma weak DMA0_Channel3_IRQHandler  = default_handler
#pragma weak DMA0_Channel4_IRQHandler  = default_handler
#pragma weak DMA0_Channel5_IRQHandler  = default_handler
#pragma weak DMA0_Channel6_IRQHandler  = default_handler
#pragma weak ADC0_1_IRQHandler         = default_handler
#pragma weak CAN0_TX_IRQHandler        = default_handler
#pragma weak CAN0_RX0_IRQHandler       = default_handler
#pragma weak CAN0_RX1_IRQHandler       = default_handler
#pragma weak CAN0_EWMC_IRQHandler      = default_handler
#pragma weak EXTI5_9_IRQHandler        = default_handler
#pragma weak TIMER0_BRK_IRQHandler     = default_handler
#pragma weak TIMER0_UP_IRQHandler      = default_handler
#pragma weak TIMER0_TRG_CMT_IRQHandler = default_handler
#pragma weak TIMER0_Channel_IRQHandler = default_handler
#pragma weak TIMER1_IRQHandler         = default_handler
#pragma weak TIMER2_IRQHandler         = default_handler
#pragma weak TIMER3_IRQHandler         = default_handler
#pragma weak I2C0_EV_IRQHandler        = default_handler
#pragma weak I2C0_ER_IRQHandler        = default_handler
#pragma weak I2C1_EV_IRQHandler        = default_handler
#pragma weak I2C1_ER_IRQHandler        = default_handler
#pragma weak SPI0_IRQHandler           = default_handler
#pragma weak SPI1_IRQHandler           = default_handler
#pragma weak USART0_IRQHandler         = default_handler
#pragma weak USART1_IRQHandler         = default_handler
#pragma weak USART2_IRQHandler         = default_handler
#pragma weak EXTI10_15_IRQHandler      = default_handler
#pragma weak RTC_Alarm_IRQHandler      = default_handler
#pragma weak USBFS_WKUP_IRQHandler     = default_handler
#pragma weak TIMER7_BRK_IRQHandler     = default_handler
#pragma weak TIMER7_UP_IRQHandler      = default_handler
#pragma weak TIMER7_TRG_CMT_IRQHandler = default_handler
#pragma weak TIMER7_Channel_IRQHandler = default_handler
#pragma weak EXMC_IRQHandler           = default_handler
#pragma weak TIMER4_IRQHandler         = default_handler
#pragma weak SPI2_IRQHandler           = default_handler
#pragma weak UART3_IRQHandler          = default_handler
#pragma weak UART4_IRQHandler          = default_handler
#pragma weak TIMER5_IRQHandler         = default_handler
#pragma weak TIMER6_IRQHandler         = default_handler
#pragma weak DMA1_Channel0_IRQHandler  = default_handler
#pragma weak DMA1_Channel1_IRQHandler  = default_handler
#pragma weak DMA1_Channel2_IRQHandler  = default_handler
#pragma weak DMA1_Channel3_IRQHandler  = default_handler
#pragma weak DMA1_Channel4_IRQHandler  = default_handler
#pragma weak ENET_IRQHandler           = default_handler
#pragma weak ENET_WKUP_IRQHandler      = default_handler
#pragma weak CAN1_TX_IRQHandler        = default_handler
#pragma weak CAN1_RX0_IRQHandler       = default_handler
#pragma weak CAN1_RX1_IRQHandler       = default_handler
#pragma weak CAN1_EWMC_IRQHandler      = default_handler
#pragma weak USBFS_IRQHandler          = default_handler

#else // NDEBUG

WEAK void WWDGT_IRQHandler          ()  { default_handler(); }
WEAK void LVD_IRQHandler            ()  { default_handler(); }
WEAK void TAMPER_IRQHandler         ()  { default_handler(); }
WEAK void RTC_IRQHandler            ()  { default_handler(); }
WEAK void FMC_IRQHandler            ()  { default_handler(); }
WEAK void RCU_IRQHandler            ()  { default_handler(); }
WEAK void EXTI0_IRQHandler          ()  { default_handler(); }
WEAK void EXTI1_IRQHandler          ()  { default_handler(); }
WEAK void EXTI2_IRQHandler          ()  { default_handler(); }
WEAK void EXTI3_IRQHandler          ()  { default_handler(); }
WEAK void EXTI4_IRQHandler          ()  { default_handler(); }
WEAK void DMA0_Channel0_IRQHandler  ()  { default_handler(); }
WEAK void DMA0_Channel1_IRQHandler  ()  { default_handler(); }
WEAK void DMA0_Channel2_IRQHandler  ()  { default_handler(); }
WEAK void DMA0_Channel3_IRQHandler  ()  { default_handler(); }
WEAK void DMA0_Channel4_IRQHandler  ()  { default_handler(); }
WEAK void DMA0_Channel5_IRQHandler  ()  { default_handler(); }
WEAK void DMA0_Channel6_IRQHandler  ()  { default_handler(); }
WEAK void ADC0_1_IRQHandler         ()  { default_handler(); }
WEAK void CAN0_TX_IRQHandler        ()  { default_handler(); }
WEAK void CAN0_RX0_IRQHandler       ()  { default_handler(); }
WEAK void CAN0_RX1_IRQHandler       ()  { default_handler(); }
WEAK void CAN0_EWMC_IRQHandler      ()  { default_handler(); }
WEAK void EXTI5_9_IRQHandler        ()  { default_handler(); }
WEAK void TIMER0_BRK_IRQHandler     ()  { default_handler(); }
WEAK void TIMER0_UP_IRQHandler      ()  { default_handler(); }
WEAK void TIMER0_TRG_CMT_IRQHandler ()  { default_handler(); }
WEAK void TIMER0_Channel_IRQHandler ()  { default_handler(); }
WEAK void TIMER1_IRQHandler         ()  { default_handler(); }
WEAK void TIMER2_IRQHandler         ()  { default_handler(); }
WEAK void TIMER3_IRQHandler         ()  { default_handler(); }
WEAK void I2C0_EV_IRQHandler        ()  { default_handler(); }
WEAK void I2C0_ER_IRQHandler        ()  { default_handler(); }
WEAK void I2C1_EV_IRQHandler        ()  { default_handler(); }
WEAK void I2C1_ER_IRQHandler        ()  { default_handler(); }
WEAK void SPI0_IRQHandler           ()  { default_handler(); }
WEAK void SPI1_IRQHandler           ()  { default_handler(); }
WEAK void USART0_IRQHandler         ()  { default_handler(); }
WEAK void USART1_IRQHandler         ()  { default_handler(); }
WEAK void USART2_IRQHandler         ()  { default_handler(); }
WEAK void EXTI10_15_IRQHandler      ()  { default_handler(); }
WEAK void RTC_Alarm_IRQHandler      ()  { default_handler(); }
WEAK void USBFS_WKUP_IRQHandler     ()  { default_handler(); }
WEAK void TIMER7_BRK_IRQHandler     ()  { default_handler(); }
WEAK void TIMER7_UP_IRQHandler      ()  { default_handler(); }
WEAK void TIMER7_TRG_CMT_IRQHandler ()  { default_handler(); }
WEAK void TIMER7_Channel_IRQHandler ()  { default_handler(); }
WEAK void EXMC_IRQHandler           ()  { default_handler(); }
WEAK void TIMER4_IRQHandler         ()  { default_handler(); }
WEAK void SPI2_IRQHandler           ()  { default_handler(); }
WEAK void UART3_IRQHandler          ()  { default_handler(); }
WEAK void UART4_IRQHandler          ()  { default_handler(); }
WEAK void TIMER5_IRQHandler         ()  { default_handler(); }
WEAK void TIMER6_IRQHandler         ()  { default_handler(); }
WEAK void DMA1_Channel0_IRQHandler  ()  { default_handler(); }
WEAK void DMA1_Channel1_IRQHandler  ()  { default_handler(); }
WEAK void DMA1_Channel2_IRQHandler  ()  { default_handler(); }
WEAK void DMA1_Channel3_IRQHandler  ()  { default_handler(); }
WEAK void DMA1_Channel4_IRQHandler  ()  { default_handler(); }
WEAK void ENET_IRQHandler           ()  { default_handler(); }
WEAK void ENET_WKUP_IRQHandler      ()  { default_handler(); }
WEAK void CAN1_TX_IRQHandler        ()  { default_handler(); }
WEAK void CAN1_RX0_IRQHandler       ()  { default_handler(); }
WEAK void CAN1_RX1_IRQHandler       ()  { default_handler(); }
WEAK void CAN1_EWMC_IRQHandler      ()  { default_handler(); }
WEAK void USBFS_IRQHandler          ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------