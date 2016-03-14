//******************************************************************************
//*
//*      EFM32HG vector table
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
    DMA_IRQHandler,          // 0: DMA Interrupt
    GPIO_EVEN_IRQHandler,    // 1: GPIO_EVEN Interrupt
    TIMER0_IRQHandler,       // 2: TIMER0 Interrupt
    ACMP0_IRQHandler,        // 3: ACMP0 Interrupt
    ADC0_IRQHandler,         // 4: ADC0 Interrupt
    I2C0_IRQHandler,         // 5: I2C0 Interrupt
    GPIO_ODD_IRQHandler,     // 6: GPIO_ODD Interrupt
    TIMER1_IRQHandler,       // 7: TIMER1 Interrupt
    USART1_RX_IRQHandler,    // 8: USART1_RX Interrupt
    USART1_TX_IRQHandler,    // 9: USART1_TX Interrupt
    LEUART0_IRQHandler,      // 10: LEUART0 Interrupt
    PCNT0_IRQHandler,        // 11: PCNT0 Interrupt
    RTC_IRQHandler,          // 12: RTC Interrupt
    CMU_IRQHandler,          // 13: CMU Interrupt
    VCMP_IRQHandler,         // 14: VCMP Interrupt
    MSC_IRQHandler,          // 15: MSC Interrupt
    AES_IRQHandler,          // 16: AES Interrupt
    USART0_RX_IRQHandler,    // 17: USART0_RX Interrupt
    USART0_TX_IRQHandler,    // 18: USART0_TX Interrupt
    USB_IRQHandler,          // 19: USB Interrupt
    TIMER2_IRQHandler        // 20: TIMER2 Interrupt
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

#pragma weak DMA_IRQHandler       = default_handler
#pragma weak GPIO_EVEN_IRQHandler = default_handler
#pragma weak TIMER0_IRQHandler    = default_handler
#pragma weak ACMP0_IRQHandler     = default_handler
#pragma weak ADC0_IRQHandler      = default_handler
#pragma weak I2C0_IRQHandler      = default_handler
#pragma weak GPIO_ODD_IRQHandler  = default_handler
#pragma weak TIMER1_IRQHandler    = default_handler
#pragma weak USART1_RX_IRQHandler = default_handler
#pragma weak USART1_TX_IRQHandler = default_handler
#pragma weak LEUART0_IRQHandler   = default_handler
#pragma weak PCNT0_IRQHandler     = default_handler
#pragma weak RTC_IRQHandler       = default_handler
#pragma weak CMU_IRQHandler       = default_handler
#pragma weak VCMP_IRQHandler      = default_handler
#pragma weak MSC_IRQHandler       = default_handler
#pragma weak AES_IRQHandler       = default_handler
#pragma weak USART0_RX_IRQHandler = default_handler
#pragma weak USART0_TX_IRQHandler = default_handler
#pragma weak USB_IRQHandler       = default_handler
#pragma weak TIMER2_IRQHandler    = default_handler

#else // NDEBUG

WEAK void DMA_IRQHandler       ()  { default_handler(); }
WEAK void GPIO_EVEN_IRQHandler ()  { default_handler(); }
WEAK void TIMER0_IRQHandler    ()  { default_handler(); }
WEAK void ACMP0_IRQHandler     ()  { default_handler(); }
WEAK void ADC0_IRQHandler      ()  { default_handler(); }
WEAK void I2C0_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_ODD_IRQHandler  ()  { default_handler(); }
WEAK void TIMER1_IRQHandler    ()  { default_handler(); }
WEAK void USART1_RX_IRQHandler ()  { default_handler(); }
WEAK void USART1_TX_IRQHandler ()  { default_handler(); }
WEAK void LEUART0_IRQHandler   ()  { default_handler(); }
WEAK void PCNT0_IRQHandler     ()  { default_handler(); }
WEAK void RTC_IRQHandler       ()  { default_handler(); }
WEAK void CMU_IRQHandler       ()  { default_handler(); }
WEAK void VCMP_IRQHandler      ()  { default_handler(); }
WEAK void MSC_IRQHandler       ()  { default_handler(); }
WEAK void AES_IRQHandler       ()  { default_handler(); }
WEAK void USART0_RX_IRQHandler ()  { default_handler(); }
WEAK void USART0_TX_IRQHandler ()  { default_handler(); }
WEAK void USB_IRQHandler       ()  { default_handler(); }
WEAK void TIMER2_IRQHandler    ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
