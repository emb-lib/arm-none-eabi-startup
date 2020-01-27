//******************************************************************************
//*
//*      LPC11XX vector table
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
    SLWU_INT0_IRQHandler,     // Start logic wake-up interrupt 0
    SLWU_INT1_IRQHandler,     // Start logic wake-up interrupt 1
    SLWU_INT2_IRQHandler,     // Start logic wake-up interrupt 2
    SLWU_INT3_IRQHandler,     // Start logic wake-up interrupt 3
    SLWU_INT4_IRQHandler,     // Start logic wake-up interrupt 4
    SLWU_INT5_IRQHandler,     // Start logic wake-up interrupt 5
    SLWU_INT6_IRQHandler,     // Start logic wake-up interrupt 6
    SLWU_INT7_IRQHandler,     // Start logic wake-up interrupt 7
    SLWU_INT8_IRQHandler,     // Start logic wake-up interrupt 8
    SLWU_INT9_IRQHandler,     // Start logic wake-up interrupt 9
    SLWU_INT10_IRQHandler,    // Start logic wake-up interrupt 10
    SLWU_INT11_IRQHandler,    // Start logic wake-up interrupt 11
    SLWU_INT12_IRQHandler,    // Start logic wake-up interrupt 12
    C_CAN_IRQHandler,         // C_CAN
    SSP1_IRQHandler,          // SSP1
    I2C_IRQHandler,           // I2C
    TIMER16_0_IRQHandler,     // 16-bit Timer0
    TIMER16_1_IRQHandler,     // 16-bit Timer1
    TIMER32_0_IRQHandler,     // 32-bit Timer0
    TIMER32_1_IRQHandler,     // 32-bit Timer1
    SSP0_IRQHandler,          // SSP0
    UART_IRQHandler,          // UART
    Reserved_IRQHandler,      // Reserved
    Reserved_IRQHandler,      // Reserved
    ADC_IRQHandler,           // A/D Converter
    WDT_IRQHandler,           // Watchdog timer
    BOD_IRQHandler,           // Brown Out Detect
    Reserved_IRQHandler,      // Reserved
    PIO_3_IRQHandler,         // GPIO interrupt status of port 3
    PIO_2_IRQHandler,         // GPIO interrupt status of port 2
    PIO_1_IRQHandler,         // GPIO interrupt status of port 1
    PIO_0_IRQHandler          // GPIO interrupt status of port 0
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

#pragma weak SLWU_INT0_IRQHandler  = default_handler
#pragma weak SLWU_INT1_IRQHandler  = default_handler
#pragma weak SLWU_INT2_IRQHandler  = default_handler
#pragma weak SLWU_INT3_IRQHandler  = default_handler
#pragma weak SLWU_INT4_IRQHandler  = default_handler
#pragma weak SLWU_INT5_IRQHandler  = default_handler
#pragma weak SLWU_INT6_IRQHandler  = default_handler
#pragma weak SLWU_INT7_IRQHandler  = default_handler
#pragma weak SLWU_INT8_IRQHandler  = default_handler
#pragma weak SLWU_INT9_IRQHandler  = default_handler
#pragma weak SLWU_INT10_IRQHandler = default_handler
#pragma weak SLWU_INT11_IRQHandler = default_handler
#pragma weak SLWU_INT12_IRQHandler = default_handler
#pragma weak C_CAN_IRQHandler      = default_handler
#pragma weak SSP1_IRQHandler       = default_handler
#pragma weak I2C_IRQHandler        = default_handler
#pragma weak TIMER16_0_IRQHandler  = default_handler
#pragma weak TIMER16_1_IRQHandler  = default_handler
#pragma weak TIMER32_0_IRQHandler  = default_handler
#pragma weak TIMER32_1_IRQHandler  = default_handler
#pragma weak SSP0_IRQHandler       = default_handler
#pragma weak UART_IRQHandler       = default_handler
#pragma weak Reserved_IRQHandler   = default_handler
#pragma weak Reserved_IRQHandler   = default_handler
#pragma weak ADC_IRQHandler        = default_handler
#pragma weak WDT_IRQHandler        = default_handler
#pragma weak BOD_IRQHandler        = default_handler
#pragma weak Reserved_IRQHandler   = default_handler
#pragma weak PIO_3_IRQHandler      = default_handler
#pragma weak PIO_2_IRQHandler      = default_handler
#pragma weak PIO_1_IRQHandler      = default_handler
#pragma weak PIO_0_IRQHandler      = default_handler

#else // NDEBUG

WEAK void SLWU_INT0_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT1_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT2_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT3_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT4_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT5_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT6_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT7_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT8_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT9_IRQHandler  ()  { default_handler(); }
WEAK void SLWU_INT10_IRQHandler ()  { default_handler(); }
WEAK void SLWU_INT11_IRQHandler ()  { default_handler(); }
WEAK void SLWU_INT12_IRQHandler ()  { default_handler(); }
WEAK void C_CAN_IRQHandler      ()  { default_handler(); }
WEAK void SSP1_IRQHandler       ()  { default_handler(); }
WEAK void I2C_IRQHandler        ()  { default_handler(); }
WEAK void TIMER16_0_IRQHandler  ()  { default_handler(); }
WEAK void TIMER16_1_IRQHandler  ()  { default_handler(); }
WEAK void TIMER32_0_IRQHandler  ()  { default_handler(); }
WEAK void TIMER32_1_IRQHandler  ()  { default_handler(); }
WEAK void SSP0_IRQHandler       ()  { default_handler(); }
WEAK void UART_IRQHandler       ()  { default_handler(); }
WEAK void Reserved_IRQHandler   ()  { default_handler(); }
WEAK void Reserved_IRQHandler   ()  { default_handler(); }
WEAK void ADC_IRQHandler        ()  { default_handler(); }
WEAK void WDT_IRQHandler        ()  { default_handler(); }
WEAK void BOD_IRQHandler        ()  { default_handler(); }
WEAK void Reserved_IRQHandler   ()  { default_handler(); }
WEAK void PIO_3_IRQHandler      ()  { default_handler(); }
WEAK void PIO_2_IRQHandler      ()  { default_handler(); }
WEAK void PIO_1_IRQHandler      ()  { default_handler(); }
WEAK void PIO_0_IRQHandler      ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
