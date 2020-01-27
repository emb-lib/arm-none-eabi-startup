//******************************************************************************
//*
//*      EFR32FG1P vector table
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
    EMU_IRQHandler,          // 0: EMU Interrupt
    FRC_PRI_IRQHandler,      // 1: FRC_PRI Interrupt
    WDOG0_IRQHandler,        // 2: WDOG0 Interrupt
    FRC_IRQHandler,          // 3: FRC Interrupt
    MODEM_IRQHandler,        // 4: MODEM Interrupt
    RAC_SEQ_IRQHandler,      // 5: RAC_SEQ Interrupt
    RAC_RSM_IRQHandler,      // 6: RAC_RSM Interrupt
    BUFC_IRQHandler,         // 7: BUFC Interrupt
    LDMA_IRQHandler,         // 8: LDMA Interrupt
    GPIO_EVEN_IRQHandler,    // 9: GPIO_EVEN Interrupt
    TIMER0_IRQHandler,       // 10: TIMER0 Interrupt
    USART0_RX_IRQHandler,    // 11: USART0_RX Interrupt
    USART0_TX_IRQHandler,    // 12: USART0_TX Interrupt
    ACMP0_IRQHandler,        // 13: ACMP0 Interrupt
    ADC0_IRQHandler,         // 14: ADC0 Interrupt
    IDAC0_IRQHandler,        // 15: IDAC0 Interrupt
    I2C0_IRQHandler,         // 16: I2C0 Interrupt
    GPIO_ODD_IRQHandler,     // 17: GPIO_ODD Interrupt
    TIMER1_IRQHandler,       // 18: TIMER1 Interrupt
    USART1_RX_IRQHandler,    // 19: USART1_RX Interrupt
    USART1_TX_IRQHandler,    // 20: USART1_TX Interrupt
    LEUART0_IRQHandler,      // 21: LEUART0 Interrupt
    PCNT0_IRQHandler,        // 22: PCNT0 Interrupt
    CMU_IRQHandler,          // 23: CMU Interrupt
    MSC_IRQHandler,          // 24: MSC Interrupt
    CRYPTO_IRQHandler,       // 25: CRYPTO Interrupt
    LETIMER0_IRQHandler,     // 26: LETIMER0 Interrupt
    AGC_IRQHandler,          // 27: AGC Interrupt
    PROTIMER_IRQHandler,     // 28: PROTIMER Interrupt
    RTCC_IRQHandler,         // 29: RTCC Interrupt
    SYNTH_IRQHandler,        // 30: SYNTH Interrupt
    CRYOTIMER_IRQHandler,    // 31: CRYOTIMER Interrupt
    RFSENSE_IRQHandler,      // 32: RFSENSE Interrupt
    FPUEH_IRQHandler         // 33: FPUEH Interrupt
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

#pragma weak EMU_IRQHandler       = default_handler
#pragma weak FRC_PRI_IRQHandler   = default_handler
#pragma weak WDOG0_IRQHandler     = default_handler
#pragma weak FRC_IRQHandler       = default_handler
#pragma weak MODEM_IRQHandler     = default_handler
#pragma weak RAC_SEQ_IRQHandler   = default_handler
#pragma weak RAC_RSM_IRQHandler   = default_handler
#pragma weak BUFC_IRQHandler      = default_handler
#pragma weak LDMA_IRQHandler      = default_handler
#pragma weak GPIO_EVEN_IRQHandler = default_handler
#pragma weak TIMER0_IRQHandler    = default_handler
#pragma weak USART0_RX_IRQHandler = default_handler
#pragma weak USART0_TX_IRQHandler = default_handler
#pragma weak ACMP0_IRQHandler     = default_handler
#pragma weak ADC0_IRQHandler      = default_handler
#pragma weak IDAC0_IRQHandler     = default_handler
#pragma weak I2C0_IRQHandler      = default_handler
#pragma weak GPIO_ODD_IRQHandler  = default_handler
#pragma weak TIMER1_IRQHandler    = default_handler
#pragma weak USART1_RX_IRQHandler = default_handler
#pragma weak USART1_TX_IRQHandler = default_handler
#pragma weak LEUART0_IRQHandler   = default_handler
#pragma weak PCNT0_IRQHandler     = default_handler
#pragma weak CMU_IRQHandler       = default_handler
#pragma weak MSC_IRQHandler       = default_handler
#pragma weak CRYPTO_IRQHandler    = default_handler
#pragma weak LETIMER0_IRQHandler  = default_handler
#pragma weak AGC_IRQHandler       = default_handler
#pragma weak PROTIMER_IRQHandler  = default_handler
#pragma weak RTCC_IRQHandler      = default_handler
#pragma weak SYNTH_IRQHandler     = default_handler
#pragma weak CRYOTIMER_IRQHandler = default_handler
#pragma weak RFSENSE_IRQHandler   = default_handler
#pragma weak FPUEH_IRQHandler     = default_handler

#else // NDEBUG

WEAK void EMU_IRQHandler       ()  { default_handler(); }
WEAK void FRC_PRI_IRQHandler   ()  { default_handler(); }
WEAK void WDOG0_IRQHandler     ()  { default_handler(); }
WEAK void FRC_IRQHandler       ()  { default_handler(); }
WEAK void MODEM_IRQHandler     ()  { default_handler(); }
WEAK void RAC_SEQ_IRQHandler   ()  { default_handler(); }
WEAK void RAC_RSM_IRQHandler   ()  { default_handler(); }
WEAK void BUFC_IRQHandler      ()  { default_handler(); }
WEAK void LDMA_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_EVEN_IRQHandler ()  { default_handler(); }
WEAK void TIMER0_IRQHandler    ()  { default_handler(); }
WEAK void USART0_RX_IRQHandler ()  { default_handler(); }
WEAK void USART0_TX_IRQHandler ()  { default_handler(); }
WEAK void ACMP0_IRQHandler     ()  { default_handler(); }
WEAK void ADC0_IRQHandler      ()  { default_handler(); }
WEAK void IDAC0_IRQHandler     ()  { default_handler(); }
WEAK void I2C0_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_ODD_IRQHandler  ()  { default_handler(); }
WEAK void TIMER1_IRQHandler    ()  { default_handler(); }
WEAK void USART1_RX_IRQHandler ()  { default_handler(); }
WEAK void USART1_TX_IRQHandler ()  { default_handler(); }
WEAK void LEUART0_IRQHandler   ()  { default_handler(); }
WEAK void PCNT0_IRQHandler     ()  { default_handler(); }
WEAK void CMU_IRQHandler       ()  { default_handler(); }
WEAK void MSC_IRQHandler       ()  { default_handler(); }
WEAK void CRYPTO_IRQHandler    ()  { default_handler(); }
WEAK void LETIMER0_IRQHandler  ()  { default_handler(); }
WEAK void AGC_IRQHandler       ()  { default_handler(); }
WEAK void PROTIMER_IRQHandler  ()  { default_handler(); }
WEAK void RTCC_IRQHandler      ()  { default_handler(); }
WEAK void SYNTH_IRQHandler     ()  { default_handler(); }
WEAK void CRYOTIMER_IRQHandler ()  { default_handler(); }
WEAK void RFSENSE_IRQHandler   ()  { default_handler(); }
WEAK void FPUEH_IRQHandler     ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
