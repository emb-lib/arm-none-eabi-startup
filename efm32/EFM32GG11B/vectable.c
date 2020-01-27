//******************************************************************************
//*
//*      EFM32GG11B vector table
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
    WDOG0_IRQHandler,        // 1: WDOG0 Interrupt
    LDMA_IRQHandler,         // 2: LDMA Interrupt
    GPIO_EVEN_IRQHandler,    // 3: GPIO_EVEN Interrupt
    SMU_IRQHandler,          // 4: SMU Interrupt
    TIMER0_IRQHandler,       // 5: TIMER0 Interrupt
    USART0_RX_IRQHandler,    // 6: USART0_RX Interrupt
    USART0_TX_IRQHandler,    // 7: USART0_TX Interrupt
    ACMP0_IRQHandler,        // 8: ACMP0 Interrupt
    ADC0_IRQHandler,         // 9: ADC0 Interrupt
    IDAC0_IRQHandler,        // 10: IDAC0 Interrupt
    I2C0_IRQHandler,         // 11: I2C0 Interrupt
    I2C1_IRQHandler,         // 12: I2C1 Interrupt
    GPIO_ODD_IRQHandler,     // 13: GPIO_ODD Interrupt
    TIMER1_IRQHandler,       // 14: TIMER1 Interrupt
    TIMER2_IRQHandler,       // 15: TIMER2 Interrupt
    TIMER3_IRQHandler,       // 16: TIMER3 Interrupt
    USART1_RX_IRQHandler,    // 17: USART1_RX Interrupt
    USART1_TX_IRQHandler,    // 18: USART1_TX Interrupt
    USART2_RX_IRQHandler,    // 19: USART2_RX Interrupt
    USART2_TX_IRQHandler,    // 20: USART2_TX Interrupt
    UART0_RX_IRQHandler,     // 21: UART0_RX Interrupt
    UART0_TX_IRQHandler,     // 22: UART0_TX Interrupt
    UART1_RX_IRQHandler,     // 23: UART1_RX Interrupt
    UART1_TX_IRQHandler,     // 24: UART1_TX Interrupt
    LEUART0_IRQHandler,      // 25: LEUART0 Interrupt
    LEUART1_IRQHandler,      // 26: LEUART1 Interrupt
    LETIMER0_IRQHandler,     // 27: LETIMER0 Interrupt
    PCNT0_IRQHandler,        // 28: PCNT0 Interrupt
    PCNT1_IRQHandler,        // 29: PCNT1 Interrupt
    PCNT2_IRQHandler,        // 30: PCNT2 Interrupt
    RTCC_IRQHandler,         // 31: RTCC Interrupt
    CMU_IRQHandler,          // 32: CMU Interrupt
    MSC_IRQHandler,          // 33: MSC Interrupt
    CRYPTO0_IRQHandler,      // 34: CRYPTO0 Interrupt
    CRYOTIMER_IRQHandler,    // 35: CRYOTIMER Interrupt
    FPUEH_IRQHandler,        // 36: FPUEH Interrupt
    USART3_RX_IRQHandler,    // 37: USART3_RX Interrupt
    USART3_TX_IRQHandler,    // 38: USART3_TX Interrupt
    USART4_RX_IRQHandler,    // 39: USART4_RX Interrupt
    USART4_TX_IRQHandler,    // 40: USART4_TX Interrupt
    WTIMER0_IRQHandler,      // 41: WTIMER0 Interrupt
    WTIMER1_IRQHandler,      // 42: WTIMER1 Interrupt
    WTIMER2_IRQHandler,      // 43: WTIMER2 Interrupt
    WTIMER3_IRQHandler,      // 44: WTIMER3 Interrupt
    I2C2_IRQHandler,         // 45: I2C2 Interrupt
    VDAC0_IRQHandler,        // 46: VDAC0 Interrupt
    TIMER4_IRQHandler,       // 47: TIMER4 Interrupt
    TIMER5_IRQHandler,       // 48: TIMER5 Interrupt
    TIMER6_IRQHandler,       // 49: TIMER6 Interrupt
    USART5_RX_IRQHandler,    // 50: USART5_RX Interrupt
    USART5_TX_IRQHandler,    // 51: USART5_TX Interrupt
    CSEN_IRQHandler,         // 52: CSEN Interrupt
    LESENSE_IRQHandler,      // 53: LESENSE Interrupt
    EBI_IRQHandler,          // 54: EBI Interrupt
    ACMP2_IRQHandler,        // 55: ACMP2 Interrupt
    ADC1_IRQHandler,         // 56: ADC1 Interrupt
    LCD_IRQHandler,          // 57: LCD Interrupt
    SDIO_IRQHandler,         // 58: SDIO Interrupt
    ETH_IRQHandler,          // 59: ETH Interrupt
    CAN0_IRQHandler,         // 60: CAN0 Interrupt
    CAN1_IRQHandler,         // 61: CAN1 Interrupt
    USB_IRQHandler,          // 62: USB Interrupt
    RTC_IRQHandler,          // 63: RTC Interrupt
    WDOG1_IRQHandler,        // 64: WDOG1 Interrupt
    LETIMER1_IRQHandler,     // 65: LETIMER1 Interrupt
    TRNG0_IRQHandler,        // 66: TRNG0 Interrupt
    QSPI0_IRQHandler         // 67: QSPI0 Interrupt
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
#pragma weak WDOG0_IRQHandler     = default_handler
#pragma weak LDMA_IRQHandler      = default_handler
#pragma weak GPIO_EVEN_IRQHandler = default_handler
#pragma weak SMU_IRQHandler       = default_handler
#pragma weak TIMER0_IRQHandler    = default_handler
#pragma weak USART0_RX_IRQHandler = default_handler
#pragma weak USART0_TX_IRQHandler = default_handler
#pragma weak ACMP0_IRQHandler     = default_handler
#pragma weak ADC0_IRQHandler      = default_handler
#pragma weak IDAC0_IRQHandler     = default_handler
#pragma weak I2C0_IRQHandler      = default_handler
#pragma weak I2C1_IRQHandler      = default_handler
#pragma weak GPIO_ODD_IRQHandler  = default_handler
#pragma weak TIMER1_IRQHandler    = default_handler
#pragma weak TIMER2_IRQHandler    = default_handler
#pragma weak TIMER3_IRQHandler    = default_handler
#pragma weak USART1_RX_IRQHandler = default_handler
#pragma weak USART1_TX_IRQHandler = default_handler
#pragma weak USART2_RX_IRQHandler = default_handler
#pragma weak USART2_TX_IRQHandler = default_handler
#pragma weak UART0_RX_IRQHandler  = default_handler
#pragma weak UART0_TX_IRQHandler  = default_handler
#pragma weak UART1_RX_IRQHandler  = default_handler
#pragma weak UART1_TX_IRQHandler  = default_handler
#pragma weak LEUART0_IRQHandler   = default_handler
#pragma weak LEUART1_IRQHandler   = default_handler
#pragma weak LETIMER0_IRQHandler  = default_handler
#pragma weak PCNT0_IRQHandler     = default_handler
#pragma weak PCNT1_IRQHandler     = default_handler
#pragma weak PCNT2_IRQHandler     = default_handler
#pragma weak RTCC_IRQHandler      = default_handler
#pragma weak CMU_IRQHandler       = default_handler
#pragma weak MSC_IRQHandler       = default_handler
#pragma weak CRYPTO0_IRQHandler   = default_handler
#pragma weak CRYOTIMER_IRQHandler = default_handler
#pragma weak FPUEH_IRQHandler     = default_handler
#pragma weak USART3_RX_IRQHandler = default_handler
#pragma weak USART3_TX_IRQHandler = default_handler
#pragma weak USART4_RX_IRQHandler = default_handler
#pragma weak USART4_TX_IRQHandler = default_handler
#pragma weak WTIMER0_IRQHandler   = default_handler
#pragma weak WTIMER1_IRQHandler   = default_handler
#pragma weak WTIMER2_IRQHandler   = default_handler
#pragma weak WTIMER3_IRQHandler   = default_handler
#pragma weak I2C2_IRQHandler      = default_handler
#pragma weak VDAC0_IRQHandler     = default_handler
#pragma weak TIMER4_IRQHandler    = default_handler
#pragma weak TIMER5_IRQHandler    = default_handler
#pragma weak TIMER6_IRQHandler    = default_handler
#pragma weak USART5_RX_IRQHandler = default_handler
#pragma weak USART5_TX_IRQHandler = default_handler
#pragma weak CSEN_IRQHandler      = default_handler
#pragma weak LESENSE_IRQHandler   = default_handler
#pragma weak EBI_IRQHandler       = default_handler
#pragma weak ACMP2_IRQHandler     = default_handler
#pragma weak ADC1_IRQHandler      = default_handler
#pragma weak LCD_IRQHandler       = default_handler
#pragma weak SDIO_IRQHandler      = default_handler
#pragma weak ETH_IRQHandler       = default_handler
#pragma weak CAN0_IRQHandler      = default_handler
#pragma weak CAN1_IRQHandler      = default_handler
#pragma weak USB_IRQHandler       = default_handler
#pragma weak RTC_IRQHandler       = default_handler
#pragma weak WDOG1_IRQHandler     = default_handler
#pragma weak LETIMER1_IRQHandler  = default_handler
#pragma weak TRNG0_IRQHandler     = default_handler
#pragma weak QSPI0_IRQHandler     = default_handler

#else // NDEBUG

WEAK void EMU_IRQHandler       ()  { default_handler(); }
WEAK void WDOG0_IRQHandler     ()  { default_handler(); }
WEAK void LDMA_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_EVEN_IRQHandler ()  { default_handler(); }
WEAK void SMU_IRQHandler       ()  { default_handler(); }
WEAK void TIMER0_IRQHandler    ()  { default_handler(); }
WEAK void USART0_RX_IRQHandler ()  { default_handler(); }
WEAK void USART0_TX_IRQHandler ()  { default_handler(); }
WEAK void ACMP0_IRQHandler     ()  { default_handler(); }
WEAK void ADC0_IRQHandler      ()  { default_handler(); }
WEAK void IDAC0_IRQHandler     ()  { default_handler(); }
WEAK void I2C0_IRQHandler      ()  { default_handler(); }
WEAK void I2C1_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_ODD_IRQHandler  ()  { default_handler(); }
WEAK void TIMER1_IRQHandler    ()  { default_handler(); }
WEAK void TIMER2_IRQHandler    ()  { default_handler(); }
WEAK void TIMER3_IRQHandler    ()  { default_handler(); }
WEAK void USART1_RX_IRQHandler ()  { default_handler(); }
WEAK void USART1_TX_IRQHandler ()  { default_handler(); }
WEAK void USART2_RX_IRQHandler ()  { default_handler(); }
WEAK void USART2_TX_IRQHandler ()  { default_handler(); }
WEAK void UART0_RX_IRQHandler  ()  { default_handler(); }
WEAK void UART0_TX_IRQHandler  ()  { default_handler(); }
WEAK void UART1_RX_IRQHandler  ()  { default_handler(); }
WEAK void UART1_TX_IRQHandler  ()  { default_handler(); }
WEAK void LEUART0_IRQHandler   ()  { default_handler(); }
WEAK void LEUART1_IRQHandler   ()  { default_handler(); }
WEAK void LETIMER0_IRQHandler  ()  { default_handler(); }
WEAK void PCNT0_IRQHandler     ()  { default_handler(); }
WEAK void PCNT1_IRQHandler     ()  { default_handler(); }
WEAK void PCNT2_IRQHandler     ()  { default_handler(); }
WEAK void RTCC_IRQHandler      ()  { default_handler(); }
WEAK void CMU_IRQHandler       ()  { default_handler(); }
WEAK void MSC_IRQHandler       ()  { default_handler(); }
WEAK void CRYPTO0_IRQHandler   ()  { default_handler(); }
WEAK void CRYOTIMER_IRQHandler ()  { default_handler(); }
WEAK void FPUEH_IRQHandler     ()  { default_handler(); }
WEAK void USART3_RX_IRQHandler ()  { default_handler(); }
WEAK void USART3_TX_IRQHandler ()  { default_handler(); }
WEAK void USART4_RX_IRQHandler ()  { default_handler(); }
WEAK void USART4_TX_IRQHandler ()  { default_handler(); }
WEAK void WTIMER0_IRQHandler   ()  { default_handler(); }
WEAK void WTIMER1_IRQHandler   ()  { default_handler(); }
WEAK void WTIMER2_IRQHandler   ()  { default_handler(); }
WEAK void WTIMER3_IRQHandler   ()  { default_handler(); }
WEAK void I2C2_IRQHandler      ()  { default_handler(); }
WEAK void VDAC0_IRQHandler     ()  { default_handler(); }
WEAK void TIMER4_IRQHandler    ()  { default_handler(); }
WEAK void TIMER5_IRQHandler    ()  { default_handler(); }
WEAK void TIMER6_IRQHandler    ()  { default_handler(); }
WEAK void USART5_RX_IRQHandler ()  { default_handler(); }
WEAK void USART5_TX_IRQHandler ()  { default_handler(); }
WEAK void CSEN_IRQHandler      ()  { default_handler(); }
WEAK void LESENSE_IRQHandler   ()  { default_handler(); }
WEAK void EBI_IRQHandler       ()  { default_handler(); }
WEAK void ACMP2_IRQHandler     ()  { default_handler(); }
WEAK void ADC1_IRQHandler      ()  { default_handler(); }
WEAK void LCD_IRQHandler       ()  { default_handler(); }
WEAK void SDIO_IRQHandler      ()  { default_handler(); }
WEAK void ETH_IRQHandler       ()  { default_handler(); }
WEAK void CAN0_IRQHandler      ()  { default_handler(); }
WEAK void CAN1_IRQHandler      ()  { default_handler(); }
WEAK void USB_IRQHandler       ()  { default_handler(); }
WEAK void RTC_IRQHandler       ()  { default_handler(); }
WEAK void WDOG1_IRQHandler     ()  { default_handler(); }
WEAK void LETIMER1_IRQHandler  ()  { default_handler(); }
WEAK void TRNG0_IRQHandler     ()  { default_handler(); }
WEAK void QSPI0_IRQHandler     ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
