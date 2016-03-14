//******************************************************************************
//*
//*      LPC175X_6X vector table
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
    WDT_IRQHandler,            // 16 Watchdog Timer
    TIMER0_IRQHandler,         // 17 Timer0
    TIMER1_IRQHandler,         // 18 Timer1
    TIMER2_IRQHandler,         // 19 Timer2
    TIMER3_IRQHandler,         // 20 Timer3
    UART0_IRQHandler,          // 21 UART0
    UART1_IRQHandler,          // 22 UART1
    UART2_IRQHandler,          // 23 UART2
    UART3_IRQHandler,          // 24 UART3
    PWM1_IRQHandler,           // 25 PWM1
    I2C0_IRQHandler,           // 26 I2C0
    I2C1_IRQHandler,           // 27 I2C1
    I2C2_IRQHandler,           // 28 I2C2
    SPI_IRQHandler,            // 29 SPI (only on the 175x/6x, reserved on other devices)
    SSP0_IRQHandler,           // 30 SSP0
    SSP1_IRQHandler,           // 31 SSP1
    PLL0_IRQHandler,           // 32 PLL0 Lock (Main PLL)
    RTC_IRQHandler,            // 33 RTC
    EINT0_IRQHandler,          // 34 External Interrupt 0
    EINT1_IRQHandler,          // 35 External Interrupt 1
    EINT2_IRQHandler,          // 36 External Interrupt 2
    EINT3_IRQHandler,          // 37 External Interrupt 3
    ADC_IRQHandler,            // 38 A/D Converter
    BOD_IRQHandler,            // 39 Brown-Out Detect
    USB_IRQHandler,            // 40 USB
    CAN_IRQHandler,            // 41 CAN
    DMA_IRQHandler,            // 42 General Purpose DMA
    I2S_IRQHandler,            // 43 I2S
    ETH_IRQHandler,            // 44 Ethernet
    RIT_IRQHandler,            // 45 RITIMER
    MCPWM_IRQHandler,          // 46 Motor Control PWM
    QEI_IRQHandler,            // 47 QEI
    PLL1_IRQHandler,           // 48 PLL1 Lock (USB PLL)
    USBActivity_IRQHandler,    // 49 USB Activity interrupt to wakeup
    CANActivity_IRQHandler     // 50 CAN Activity interrupt to wakeup
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

#pragma weak WDT_IRQHandler         = default_handler
#pragma weak TIMER0_IRQHandler      = default_handler
#pragma weak TIMER1_IRQHandler      = default_handler
#pragma weak TIMER2_IRQHandler      = default_handler
#pragma weak TIMER3_IRQHandler      = default_handler
#pragma weak UART0_IRQHandler       = default_handler
#pragma weak UART1_IRQHandler       = default_handler
#pragma weak UART2_IRQHandler       = default_handler
#pragma weak UART3_IRQHandler       = default_handler
#pragma weak PWM1_IRQHandler        = default_handler
#pragma weak I2C0_IRQHandler        = default_handler
#pragma weak I2C1_IRQHandler        = default_handler
#pragma weak I2C2_IRQHandler        = default_handler
#pragma weak SPI_IRQHandler         = default_handler
#pragma weak SSP0_IRQHandler        = default_handler
#pragma weak SSP1_IRQHandler        = default_handler
#pragma weak PLL0_IRQHandler        = default_handler
#pragma weak RTC_IRQHandler         = default_handler
#pragma weak EINT0_IRQHandler       = default_handler
#pragma weak EINT1_IRQHandler       = default_handler
#pragma weak EINT2_IRQHandler       = default_handler
#pragma weak EINT3_IRQHandler       = default_handler
#pragma weak ADC_IRQHandler         = default_handler
#pragma weak BOD_IRQHandler         = default_handler
#pragma weak USB_IRQHandler         = default_handler
#pragma weak CAN_IRQHandler         = default_handler
#pragma weak DMA_IRQHandler         = default_handler
#pragma weak I2S_IRQHandler         = default_handler
#pragma weak ETH_IRQHandler         = default_handler
#pragma weak RIT_IRQHandler         = default_handler
#pragma weak MCPWM_IRQHandler       = default_handler
#pragma weak QEI_IRQHandler         = default_handler
#pragma weak PLL1_IRQHandler        = default_handler
#pragma weak USBActivity_IRQHandler = default_handler
#pragma weak CANActivity_IRQHandler = default_handler

#else // NDEBUG

WEAK void WDT_IRQHandler         ()  { default_handler(); }
WEAK void TIMER0_IRQHandler      ()  { default_handler(); }
WEAK void TIMER1_IRQHandler      ()  { default_handler(); }
WEAK void TIMER2_IRQHandler      ()  { default_handler(); }
WEAK void TIMER3_IRQHandler      ()  { default_handler(); }
WEAK void UART0_IRQHandler       ()  { default_handler(); }
WEAK void UART1_IRQHandler       ()  { default_handler(); }
WEAK void UART2_IRQHandler       ()  { default_handler(); }
WEAK void UART3_IRQHandler       ()  { default_handler(); }
WEAK void PWM1_IRQHandler        ()  { default_handler(); }
WEAK void I2C0_IRQHandler        ()  { default_handler(); }
WEAK void I2C1_IRQHandler        ()  { default_handler(); }
WEAK void I2C2_IRQHandler        ()  { default_handler(); }
WEAK void SPI_IRQHandler         ()  { default_handler(); }
WEAK void SSP0_IRQHandler        ()  { default_handler(); }
WEAK void SSP1_IRQHandler        ()  { default_handler(); }
WEAK void PLL0_IRQHandler        ()  { default_handler(); }
WEAK void RTC_IRQHandler         ()  { default_handler(); }
WEAK void EINT0_IRQHandler       ()  { default_handler(); }
WEAK void EINT1_IRQHandler       ()  { default_handler(); }
WEAK void EINT2_IRQHandler       ()  { default_handler(); }
WEAK void EINT3_IRQHandler       ()  { default_handler(); }
WEAK void ADC_IRQHandler         ()  { default_handler(); }
WEAK void BOD_IRQHandler         ()  { default_handler(); }
WEAK void USB_IRQHandler         ()  { default_handler(); }
WEAK void CAN_IRQHandler         ()  { default_handler(); }
WEAK void DMA_IRQHandler         ()  { default_handler(); }
WEAK void I2S_IRQHandler         ()  { default_handler(); }
WEAK void ETH_IRQHandler         ()  { default_handler(); }
WEAK void RIT_IRQHandler         ()  { default_handler(); }
WEAK void MCPWM_IRQHandler       ()  { default_handler(); }
WEAK void QEI_IRQHandler         ()  { default_handler(); }
WEAK void PLL1_IRQHandler        ()  { default_handler(); }
WEAK void USBActivity_IRQHandler ()  { default_handler(); }
WEAK void CANActivity_IRQHandler ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
