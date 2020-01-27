//******************************************************************************
//*
//*      LPC11U6X vector table
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
    PIN_INT0_IRQHandler,     // 16+ 0  GPIO pin interrupt 0
    PIN_INT1_IRQHandler,     // 16+ 1  GPIO pin interrupt 1
    PIN_INT2_IRQHandler,     // 16+ 2  GPIO pin interrupt 2
    PIN_INT3_IRQHandler,     // 16+ 3  GPIO pin interrupt 3
    PIN_INT4_IRQHandler,     // 16+ 4  GPIO pin interrupt 4
    PIN_INT5_IRQHandler,     // 16+ 5  GPIO pin interrupt 5
    PIN_INT6_IRQHandler,     // 16+ 6  GPIO pin interrupt 6
    PIN_INT7_IRQHandler,     // 16+ 7  GPIO pin interrupt 7
    GINT0_IRQHandler,        // 16+ 8  GPIO GROUP0 interrupt
    GINT1_IRQHandler,        // 16+ 9  GPIO GROUP1 interrupt
    I2C1_IRQHandler,         // 16+10  I2C1 interrupt
    USART1_4_IRQHandler,     // 16+11  Combined USART1 and USART4 interrupts
    USART2_3_IRQHandler,     // 16+12  Combined USART2 and USART3 interrupts
    SCT0_1_IRQHandler,       // 16+13  Combined SCT0 and SCT1 interrupts
    SSP1_IRQHandler,         // 16+14  SSP1 interrupt
    I2C0_IRQHandler,         // 16+15  I2C0 interrupt
    CT16B0_IRQHandler,       // 16+16  CT16B0 interrupt
    CT16B1_IRQHandler,       // 16+17  CT16B1 interrupt
    CT32B0_IRQHandler,       // 16+18  CT32B0 interrupt
    CT32B1_IRQHandler,       // 16+19  CT32B1 interrupt
    SSP0_IRQHandler,         // 16+20  SSP0 interrupt
    USART0_IRQHandler,       // 16+21  USART0 interrupt
    USB_IRQHandler,          // 16+22  USB interrupt
    USB_FIQ_IRQHandler,      // 16+23  USB_FIQ interrupt
    ADC_A_IRQHandler,        // 16+24  Combined ADC_A end-of-sequence A and threshold crossing interrupts
    RTC_IRQHandler,          // 16+25  RTC interrupt
    BOD_WDT_IRQHandler,      // 16+26  Combined BOD and WWDT interrupt
    FLASH_IRQHandler,        // 16+27  Combined flash and EEPROM controller interrupts
    DMA_IRQHandler,          // 16+28  DMA interrupt
    ADC_B_IRQHandler,        // 16+29  Combined ADC_A end-of-sequence A and threshold crossing interrupts
    USBWAKEUP_IRQHandler,    // 16+30  USB_WAKEUP interrupt
    0                        // 16+31  Reserved
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

#pragma weak PIN_INT0_IRQHandler  = default_handler
#pragma weak PIN_INT1_IRQHandler  = default_handler
#pragma weak PIN_INT2_IRQHandler  = default_handler
#pragma weak PIN_INT3_IRQHandler  = default_handler
#pragma weak PIN_INT4_IRQHandler  = default_handler
#pragma weak PIN_INT5_IRQHandler  = default_handler
#pragma weak PIN_INT6_IRQHandler  = default_handler
#pragma weak PIN_INT7_IRQHandler  = default_handler
#pragma weak GINT0_IRQHandler     = default_handler
#pragma weak GINT1_IRQHandler     = default_handler
#pragma weak I2C1_IRQHandler      = default_handler
#pragma weak USART1_4_IRQHandler  = default_handler
#pragma weak USART2_3_IRQHandler  = default_handler
#pragma weak SCT0_1_IRQHandler    = default_handler
#pragma weak SSP1_IRQHandler      = default_handler
#pragma weak I2C0_IRQHandler      = default_handler
#pragma weak CT16B0_IRQHandler    = default_handler
#pragma weak CT16B1_IRQHandler    = default_handler
#pragma weak CT32B0_IRQHandler    = default_handler
#pragma weak CT32B1_IRQHandler    = default_handler
#pragma weak SSP0_IRQHandler      = default_handler
#pragma weak USART0_IRQHandler    = default_handler
#pragma weak USB_IRQHandler       = default_handler
#pragma weak USB_FIQ_IRQHandler   = default_handler
#pragma weak ADC_A_IRQHandler     = default_handler
#pragma weak RTC_IRQHandler       = default_handler
#pragma weak BOD_WDT_IRQHandler   = default_handler
#pragma weak FLASH_IRQHandler     = default_handler
#pragma weak DMA_IRQHandler       = default_handler
#pragma weak ADC_B_IRQHandler     = default_handler
#pragma weak USBWAKEUP_IRQHandler = default_handler

#else // NDEBUG

WEAK void PIN_INT0_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT1_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT2_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT3_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT4_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT5_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT6_IRQHandler  ()  { default_handler(); }
WEAK void PIN_INT7_IRQHandler  ()  { default_handler(); }
WEAK void GINT0_IRQHandler     ()  { default_handler(); }
WEAK void GINT1_IRQHandler     ()  { default_handler(); }
WEAK void I2C1_IRQHandler      ()  { default_handler(); }
WEAK void USART1_4_IRQHandler  ()  { default_handler(); }
WEAK void USART2_3_IRQHandler  ()  { default_handler(); }
WEAK void SCT0_1_IRQHandler    ()  { default_handler(); }
WEAK void SSP1_IRQHandler      ()  { default_handler(); }
WEAK void I2C0_IRQHandler      ()  { default_handler(); }
WEAK void CT16B0_IRQHandler    ()  { default_handler(); }
WEAK void CT16B1_IRQHandler    ()  { default_handler(); }
WEAK void CT32B0_IRQHandler    ()  { default_handler(); }
WEAK void CT32B1_IRQHandler    ()  { default_handler(); }
WEAK void SSP0_IRQHandler      ()  { default_handler(); }
WEAK void USART0_IRQHandler    ()  { default_handler(); }
WEAK void USB_IRQHandler       ()  { default_handler(); }
WEAK void USB_FIQ_IRQHandler   ()  { default_handler(); }
WEAK void ADC_A_IRQHandler     ()  { default_handler(); }
WEAK void RTC_IRQHandler       ()  { default_handler(); }
WEAK void BOD_WDT_IRQHandler   ()  { default_handler(); }
WEAK void FLASH_IRQHandler     ()  { default_handler(); }
WEAK void DMA_IRQHandler       ()  { default_handler(); }
WEAK void ADC_B_IRQHandler     ()  { default_handler(); }
WEAK void USBWAKEUP_IRQHandler ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
