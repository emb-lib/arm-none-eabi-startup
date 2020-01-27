//******************************************************************************
//*
//*      LPC8XX vector table
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
    SPI0_IRQHandler,       // SPI0 controller
    SPI1_IRQHandler,       // SPI1 controller
    0,                     // Reserved
    UART0_IRQHandler,      // UART0
    UART1_IRQHandler,      // UART1
    UART2_IRQHandler,      // UART2
    0,                     // Reserved
    0,                     // Reserved
    I2C_IRQHandler,        // I2C controller
    SCT_IRQHandler,        // Smart Counter Timer
    MRT_IRQHandler,        // Multi-Rate Timer
    CMP_IRQHandler,        // Comparator
    WDT_IRQHandler,        // PIO1 (0:11)
    BOD_IRQHandler,        // Brown Out Detect
    0,                     // Reserved
    WKT_IRQHandler,        // Wakeup timer
    0,                     // Reserved
    0,                     // Reserved
    0,                     // Reserved
    0,                     // Reserved
    0,                     // Reserved
    0,                     // Reserved
    0,                     // Reserved
    0,                     // Reserved
    PININT0_IRQHandler,    // PIO INT0
    PININT1_IRQHandler,    // PIO INT1
    PININT2_IRQHandler,    // PIO INT2
    PININT3_IRQHandler,    // PIO INT3
    PININT4_IRQHandler,    // PIO INT4
    PININT5_IRQHandler,    // PIO INT5
    PININT6_IRQHandler,    // PIO INT6
    PININT7_IRQHandler     // PIO INT7
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

#pragma weak SPI0_IRQHandler    = default_handler
#pragma weak SPI1_IRQHandler    = default_handler
#pragma weak UART0_IRQHandler   = default_handler
#pragma weak UART1_IRQHandler   = default_handler
#pragma weak UART2_IRQHandler   = default_handler
#pragma weak I2C_IRQHandler     = default_handler
#pragma weak SCT_IRQHandler     = default_handler
#pragma weak MRT_IRQHandler     = default_handler
#pragma weak CMP_IRQHandler     = default_handler
#pragma weak WDT_IRQHandler     = default_handler
#pragma weak BOD_IRQHandler     = default_handler
#pragma weak WKT_IRQHandler     = default_handler
#pragma weak PININT0_IRQHandler = default_handler
#pragma weak PININT1_IRQHandler = default_handler
#pragma weak PININT2_IRQHandler = default_handler
#pragma weak PININT3_IRQHandler = default_handler
#pragma weak PININT4_IRQHandler = default_handler
#pragma weak PININT5_IRQHandler = default_handler
#pragma weak PININT6_IRQHandler = default_handler
#pragma weak PININT7_IRQHandler = default_handler

#else // NDEBUG

WEAK void SPI0_IRQHandler    ()  { default_handler(); }
WEAK void SPI1_IRQHandler    ()  { default_handler(); }
WEAK void UART0_IRQHandler   ()  { default_handler(); }
WEAK void UART1_IRQHandler   ()  { default_handler(); }
WEAK void UART2_IRQHandler   ()  { default_handler(); }
WEAK void I2C_IRQHandler     ()  { default_handler(); }
WEAK void SCT_IRQHandler     ()  { default_handler(); }
WEAK void MRT_IRQHandler     ()  { default_handler(); }
WEAK void CMP_IRQHandler     ()  { default_handler(); }
WEAK void WDT_IRQHandler     ()  { default_handler(); }
WEAK void BOD_IRQHandler     ()  { default_handler(); }
WEAK void WKT_IRQHandler     ()  { default_handler(); }
WEAK void PININT0_IRQHandler ()  { default_handler(); }
WEAK void PININT1_IRQHandler ()  { default_handler(); }
WEAK void PININT2_IRQHandler ()  { default_handler(); }
WEAK void PININT3_IRQHandler ()  { default_handler(); }
WEAK void PININT4_IRQHandler ()  { default_handler(); }
WEAK void PININT5_IRQHandler ()  { default_handler(); }
WEAK void PININT6_IRQHandler ()  { default_handler(); }
WEAK void PININT7_IRQHandler ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
