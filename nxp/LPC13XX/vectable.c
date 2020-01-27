//******************************************************************************
//*
//*      LPC13XX vector table
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
    PIN_INT0_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT1_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT2_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT3_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT4_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT5_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT6_Handler,      // All GPIO pin can be routed to PIN_INTx
    PIN_INT7_Handler,      // All GPIO pin can be routed to PIN_INTx
    GINT0_Handler,         // All GPIO pin can be routed to PIN_INTx
    GINT1_Handler,         // PIO0 (0:7) 
    0,                     // Reserved
    0,                     // Reserved
    OSTIMER_Handler,       // OS Timer
    0,                     // Reserved
    SSP1_Handler,          // SSP1 
    I2C_Handler,           // I2C 
    CT16B0_Handler,        // 16-bit Timer0 
    CT16B1_Handler,        // 16-bit Timer1 
    CT32B0_Handler,        // 32-bit Timer0 
    CT32B1_Handler,        // 32-bit Timer1 
    SSP0_Handler,          // SSP0 
    USART_Handler,         // USART 
    USB_Handler,           // USB IRQ 
    USB_FIQHandler,        // USB FIQ 
    ADC_Handler,           // A/D Converter 
    WDT_Handler,           // Watchdog timer 
    BOD_Handler,           // Brown Out Detect 
    FMC_Handler,           // IP2111 Flash Memory Controller 
    OSCFAIL_Handler,       // OSC FAIL 
    PVTCIRCUIT_Handler,    // PVT CIRCUIT 
    USBWakeup_Handler,     // USB wake up 
    0                      // Reserved
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

#pragma weak PIN_INT0_Handler   = default_handler
#pragma weak PIN_INT1_Handler   = default_handler
#pragma weak PIN_INT2_Handler   = default_handler
#pragma weak PIN_INT3_Handler   = default_handler
#pragma weak PIN_INT4_Handler   = default_handler
#pragma weak PIN_INT5_Handler   = default_handler
#pragma weak PIN_INT6_Handler   = default_handler
#pragma weak PIN_INT7_Handler   = default_handler
#pragma weak GINT0_Handler      = default_handler
#pragma weak GINT1_Handler      = default_handler
#pragma weak OSTIMER_Handler    = default_handler
#pragma weak SSP1_Handler       = default_handler
#pragma weak I2C_Handler        = default_handler
#pragma weak CT16B0_Handler     = default_handler
#pragma weak CT16B1_Handler     = default_handler
#pragma weak CT32B0_Handler     = default_handler
#pragma weak CT32B1_Handler     = default_handler
#pragma weak SSP0_Handler       = default_handler
#pragma weak USART_Handler      = default_handler
#pragma weak USB_Handler        = default_handler
#pragma weak USB_FIQHandler     = default_handler
#pragma weak ADC_Handler        = default_handler
#pragma weak WDT_Handler        = default_handler
#pragma weak BOD_Handler        = default_handler
#pragma weak FMC_Handler        = default_handler
#pragma weak OSCFAIL_Handler    = default_handler
#pragma weak PVTCIRCUIT_Handler = default_handler
#pragma weak USBWakeup_Handler  = default_handler

#else // NDEBUG

WEAK void PIN_INT0_Handler   ()  { default_handler(); }
WEAK void PIN_INT1_Handler   ()  { default_handler(); }
WEAK void PIN_INT2_Handler   ()  { default_handler(); }
WEAK void PIN_INT3_Handler   ()  { default_handler(); }
WEAK void PIN_INT4_Handler   ()  { default_handler(); }
WEAK void PIN_INT5_Handler   ()  { default_handler(); }
WEAK void PIN_INT6_Handler   ()  { default_handler(); }
WEAK void PIN_INT7_Handler   ()  { default_handler(); }
WEAK void GINT0_Handler      ()  { default_handler(); }
WEAK void GINT1_Handler      ()  { default_handler(); }
WEAK void OSTIMER_Handler    ()  { default_handler(); }
WEAK void SSP1_Handler       ()  { default_handler(); }
WEAK void I2C_Handler        ()  { default_handler(); }
WEAK void CT16B0_Handler     ()  { default_handler(); }
WEAK void CT16B1_Handler     ()  { default_handler(); }
WEAK void CT32B0_Handler     ()  { default_handler(); }
WEAK void CT32B1_Handler     ()  { default_handler(); }
WEAK void SSP0_Handler       ()  { default_handler(); }
WEAK void USART_Handler      ()  { default_handler(); }
WEAK void USB_Handler        ()  { default_handler(); }
WEAK void USB_FIQHandler     ()  { default_handler(); }
WEAK void ADC_Handler        ()  { default_handler(); }
WEAK void WDT_Handler        ()  { default_handler(); }
WEAK void BOD_Handler        ()  { default_handler(); }
WEAK void FMC_Handler        ()  { default_handler(); }
WEAK void OSCFAIL_Handler    ()  { default_handler(); }
WEAK void PVTCIRCUIT_Handler ()  { default_handler(); }
WEAK void USBWakeup_Handler  ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
