//******************************************************************************
//*
//*      LPC43XX vector table
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
    DAC_IRQHandler,            // 16 D/A Converter
    MX_CORE_IRQHandler,        // 17 M0/M4 IRQ handler (LPC43XX ONLY)
    DMA_IRQHandler,            // 18 General Purpose DMA
    UnHandled_Vector,          // 19 Reserved
    FLASHEEPROM_IRQHandler,    // 20 ORed flash bank A, flash bank B, EEPROM interrupts
    ETH_IRQHandler,            // 21 Ethernet
    SDIO_IRQHandler,           // 22 SD/MMC
    LCD_IRQHandler,            // 23 LCD
    USB0_IRQHandler,           // 24 USB0
    USB1_IRQHandler,           // 25 USB1
    SCT_IRQHandler,            // 26 State Configurable Timer
    RIT_IRQHandler,            // 27 Repetitive Interrupt Timer
    TIMER0_IRQHandler,         // 28 Timer0
    TIMER1_IRQHandler,         // 29 Timer1
    TIMER2_IRQHandler,         // 30 Timer2
    TIMER3_IRQHandler,         // 31 Timer3
    MCPWM_IRQHandler,          // 32 Motor Control PWM
    ADC0_IRQHandler,           // 33 A/D Converter 0
    I2C0_IRQHandler,           // 34 I2C0
    I2C1_IRQHandler,           // 35 I2C1
    SPI_IRQHandler,            // 36 SPI (LPC43XX ONLY)
    ADC1_IRQHandler,           // 37 A/D Converter 1
    SSP0_IRQHandler,           // 38 SSP0
    SSP1_IRQHandler,           // 39 SSP1
    UART0_IRQHandler,          // 40 UART0
    UART1_IRQHandler,          // 41 UART1
    UART2_IRQHandler,          // 42 UART2
    UART3_IRQHandler,          // 43 UART3
    I2S0_IRQHandler,           // 44 I2S0
    I2S1_IRQHandler,           // 45 I2S1
    SPIFI_IRQHandler,          // 46 SPI Flash Interface
    SGPIO_IRQHandler,          // 47 SGPIO (LPC43XX ONLY)
    GPIO0_IRQHandler,          // 48 GPIO0
    GPIO1_IRQHandler,          // 49 GPIO1
    GPIO2_IRQHandler,          // 50 GPIO2
    GPIO3_IRQHandler,          // 51 GPIO3
    GPIO4_IRQHandler,          // 52 GPIO4
    GPIO5_IRQHandler,          // 53 GPIO5
    GPIO6_IRQHandler,          // 54 GPIO6
    GPIO7_IRQHandler,          // 55 GPIO7
    GINT0_IRQHandler,          // 56 GINT0
    GINT1_IRQHandler,          // 57 GINT1
    EVRT_IRQHandler,           // 58 Event Router
    CAN1_IRQHandler,           // 59 C_CAN1
    UnHandled_Vector,          // 60 Reserved
    VADC_IRQHandler,           // 61 VADC
    ATIMER_IRQHandler,         // 62 ATIMER
    RTC_IRQHandler,            // 63 RTC
    UnHandled_Vector,          // 64 Reserved
    WDT_IRQHandler,            // 65 WDT
    UnHandled_Vector,          // 66 M0s
    CAN0_IRQHandler,           // 67 C_CAN0
    QEI_IRQHandler             // 68 QEI
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

#pragma weak DAC_IRQHandler         = default_handler
#pragma weak MX_CORE_IRQHandler     = default_handler
#pragma weak DMA_IRQHandler         = default_handler
#pragma weak UnHandled_Vector       = default_handler
#pragma weak FLASHEEPROM_IRQHandler = default_handler
#pragma weak ETH_IRQHandler         = default_handler
#pragma weak SDIO_IRQHandler        = default_handler
#pragma weak LCD_IRQHandler         = default_handler
#pragma weak USB0_IRQHandler        = default_handler
#pragma weak USB1_IRQHandler        = default_handler
#pragma weak SCT_IRQHandler         = default_handler
#pragma weak RIT_IRQHandler         = default_handler
#pragma weak TIMER0_IRQHandler      = default_handler
#pragma weak TIMER1_IRQHandler      = default_handler
#pragma weak TIMER2_IRQHandler      = default_handler
#pragma weak TIMER3_IRQHandler      = default_handler
#pragma weak MCPWM_IRQHandler       = default_handler
#pragma weak ADC0_IRQHandler        = default_handler
#pragma weak I2C0_IRQHandler        = default_handler
#pragma weak I2C1_IRQHandler        = default_handler
#pragma weak SPI_IRQHandler         = default_handler
#pragma weak ADC1_IRQHandler        = default_handler
#pragma weak SSP0_IRQHandler        = default_handler
#pragma weak SSP1_IRQHandler        = default_handler
#pragma weak UART0_IRQHandler       = default_handler
#pragma weak UART1_IRQHandler       = default_handler
#pragma weak UART2_IRQHandler       = default_handler
#pragma weak UART3_IRQHandler       = default_handler
#pragma weak I2S0_IRQHandler        = default_handler
#pragma weak I2S1_IRQHandler        = default_handler
#pragma weak SPIFI_IRQHandler       = default_handler
#pragma weak SGPIO_IRQHandler       = default_handler
#pragma weak GPIO0_IRQHandler       = default_handler
#pragma weak GPIO1_IRQHandler       = default_handler
#pragma weak GPIO2_IRQHandler       = default_handler
#pragma weak GPIO3_IRQHandler       = default_handler
#pragma weak GPIO4_IRQHandler       = default_handler
#pragma weak GPIO5_IRQHandler       = default_handler
#pragma weak GPIO6_IRQHandler       = default_handler
#pragma weak GPIO7_IRQHandler       = default_handler
#pragma weak GINT0_IRQHandler       = default_handler
#pragma weak GINT1_IRQHandler       = default_handler
#pragma weak EVRT_IRQHandler        = default_handler
#pragma weak CAN1_IRQHandler        = default_handler
#pragma weak UnHandled_Vector       = default_handler
#pragma weak VADC_IRQHandler        = default_handler
#pragma weak ATIMER_IRQHandler      = default_handler
#pragma weak RTC_IRQHandler         = default_handler
#pragma weak UnHandled_Vector       = default_handler
#pragma weak WDT_IRQHandler         = default_handler
#pragma weak UnHandled_Vector       = default_handler
#pragma weak CAN0_IRQHandler        = default_handler
#pragma weak QEI_IRQHandler         = default_handler

#else // NDEBUG

WEAK void DAC_IRQHandler         ()  { default_handler(); }
WEAK void MX_CORE_IRQHandler     ()  { default_handler(); }
WEAK void DMA_IRQHandler         ()  { default_handler(); }
WEAK void UnHandled_Vector       ()  { default_handler(); }
WEAK void FLASHEEPROM_IRQHandler ()  { default_handler(); }
WEAK void ETH_IRQHandler         ()  { default_handler(); }
WEAK void SDIO_IRQHandler        ()  { default_handler(); }
WEAK void LCD_IRQHandler         ()  { default_handler(); }
WEAK void USB0_IRQHandler        ()  { default_handler(); }
WEAK void USB1_IRQHandler        ()  { default_handler(); }
WEAK void SCT_IRQHandler         ()  { default_handler(); }
WEAK void RIT_IRQHandler         ()  { default_handler(); }
WEAK void TIMER0_IRQHandler      ()  { default_handler(); }
WEAK void TIMER1_IRQHandler      ()  { default_handler(); }
WEAK void TIMER2_IRQHandler      ()  { default_handler(); }
WEAK void TIMER3_IRQHandler      ()  { default_handler(); }
WEAK void MCPWM_IRQHandler       ()  { default_handler(); }
WEAK void ADC0_IRQHandler        ()  { default_handler(); }
WEAK void I2C0_IRQHandler        ()  { default_handler(); }
WEAK void I2C1_IRQHandler        ()  { default_handler(); }
WEAK void SPI_IRQHandler         ()  { default_handler(); }
WEAK void ADC1_IRQHandler        ()  { default_handler(); }
WEAK void SSP0_IRQHandler        ()  { default_handler(); }
WEAK void SSP1_IRQHandler        ()  { default_handler(); }
WEAK void UART0_IRQHandler       ()  { default_handler(); }
WEAK void UART1_IRQHandler       ()  { default_handler(); }
WEAK void UART2_IRQHandler       ()  { default_handler(); }
WEAK void UART3_IRQHandler       ()  { default_handler(); }
WEAK void I2S0_IRQHandler        ()  { default_handler(); }
WEAK void I2S1_IRQHandler        ()  { default_handler(); }
WEAK void SPIFI_IRQHandler       ()  { default_handler(); }
WEAK void SGPIO_IRQHandler       ()  { default_handler(); }
WEAK void GPIO0_IRQHandler       ()  { default_handler(); }
WEAK void GPIO1_IRQHandler       ()  { default_handler(); }
WEAK void GPIO2_IRQHandler       ()  { default_handler(); }
WEAK void GPIO3_IRQHandler       ()  { default_handler(); }
WEAK void GPIO4_IRQHandler       ()  { default_handler(); }
WEAK void GPIO5_IRQHandler       ()  { default_handler(); }
WEAK void GPIO6_IRQHandler       ()  { default_handler(); }
WEAK void GPIO7_IRQHandler       ()  { default_handler(); }
WEAK void GINT0_IRQHandler       ()  { default_handler(); }
WEAK void GINT1_IRQHandler       ()  { default_handler(); }
WEAK void EVRT_IRQHandler        ()  { default_handler(); }
WEAK void CAN1_IRQHandler        ()  { default_handler(); }
WEAK void UnHandled_Vector       ()  { default_handler(); }
WEAK void VADC_IRQHandler        ()  { default_handler(); }
WEAK void ATIMER_IRQHandler      ()  { default_handler(); }
WEAK void RTC_IRQHandler         ()  { default_handler(); }
WEAK void UnHandled_Vector       ()  { default_handler(); }
WEAK void WDT_IRQHandler         ()  { default_handler(); }
WEAK void UnHandled_Vector       ()  { default_handler(); }
WEAK void CAN0_IRQHandler        ()  { default_handler(); }
WEAK void QEI_IRQHandler         ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
