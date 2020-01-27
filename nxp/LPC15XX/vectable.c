//******************************************************************************
//*
//*      LPC15XX vector table
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
    WDT_IRQHandler,           // 16+ 0 Windowed watchdog timer interrupt
    BOD_IRQHandler,           // 16+ 1 BOD interrupt
    FLASH_IRQHandler,         // 16+ 2 Flash controller interrupt
    EE_IRQHandler,            // 16+ 3 EEPROM controller interrupt
    DMA_IRQHandler,           // 16+ 4 DMA interrupt
    GINT0_IRQHandler,         // 16+ 5 GPIO group0 interrupt
    GINT1_IRQHandler,         // 16+ 6 GPIO group1 interrupt
    PIN_INT0_IRQHandler,      // 16+ 7 Pin interrupt 0 or pattern match engine slice 0 interrupt
    PIN_INT1_IRQHandler,      // 16+ 8 Pin interrupt 1 or pattern match engine slice 1 interrupt
    PIN_INT2_IRQHandler,      // 16+ 9 Pin interrupt 2 or pattern match engine slice 2 interrupt
    PIN_INT3_IRQHandler,      // 16+10 Pin interrupt 3 or pattern match engine slice 3 interrupt
    PIN_INT4_IRQHandler,      // 16+11 Pin interrupt 4 or pattern match engine slice 4 interrupt
    PIN_INT5_IRQHandler,      // 16+12 Pin interrupt 5 or pattern match engine slice 5 interrupt
    PIN_INT6_IRQHandler,      // 16+13 Pin interrupt 6 or pattern match engine slice 6 interrupt
    PIN_INT7_IRQHandler,      // 16+14 Pin interrupt 7 or pattern match engine slice 7 interrupt
    RIT_IRQHandler,           // 16+15 RIT interrupt
    SCT0_IRQHandler,          // 16+16 State configurable timer interrupt
    SCT1_IRQHandler,          // 16+17 State configurable timer interrupt
    SCT2_IRQHandler,          // 16+18 State configurable timer interrupt
    SCT3_IRQHandler,          // 16+19 State configurable timer interrupt
    MRT_IRQHandler,           // 16+20 Multi-rate timer interrupt
    UART0_IRQHandler,         // 16+21 USART0 interrupt
    UART1_IRQHandler,         // 16+22 USART1 interrupt
    UART2_IRQHandler,         // 16+23 USART2 interrupt
    I2C0_IRQHandler,          // 16+24 I2C0 interrupt
    SPI0_IRQHandler,          // 16+25 SPI0 interrupt
    SPI1_IRQHandler,          // 16+26 SPI1 interrupt
    C_CAN0_IRQHandler,        // 16+27 C_CAN0 interrupt
    USB_IRQ_IRQHandler,       // 16+28 USB interrupt
    USB_FIQ_IRQHandler,       // 16+29 USB interrupt
    USBWAKEUP_IRQHandler,     // 16+30 USB wake-up interrupt
    ADC0_SEQA_IRQHandler,     // 16+31 ADC0 sequence A completion.
    ADC0_SEQB_IRQHandler,     // 16+32 ADC0 sequence B completion.
    ADC0_THCMP_IRQHandler,    // 16+33 ADC0 threshold compare
    ADC0_OVR_IRQHandler,      // 16+34 ADC0 overrun
    ADC1_SEQA_IRQHandler,     // 16+35 ADC1 sequence A completion.
    ADC1_SEQB_IRQHandler,     // 16+36 ADC1 sequence B completion.
    ADC1_THCMP_IRQHandler,    // 16+37 ADC1 threshold compare
    ADC1_OVR_IRQHandler,      // 16+38 ADC1 overrun
    DAC_IRQHandler,           // 16+39 DAC interrupt
    CMP0_IRQHandler,          // 16+40 Analog comparator 0 interrupt (ACMP0)
    CMP1_IRQHandler,          // 16+41 Analog comparator 1 interrupt (ACMP1)
    CMP2_IRQHandler,          // 16+42 Analog comparator 2 interrupt (ACMP2)
    CMP3_IRQHandler,          // 16+43 Analog comparator 3 interrupt (ACMP3)
    QEI_IRQHandler,           // 16+44 QEI interrupt
    RTC_ALARM_IRQHandler,     // 16+45 RTC alarm interrupt
    RTC_WAKE_IRQHandler       // 16+46 RTC wake-up interrut
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

#pragma weak WDT_IRQHandler        = default_handler
#pragma weak BOD_IRQHandler        = default_handler
#pragma weak FLASH_IRQHandler      = default_handler
#pragma weak EE_IRQHandler         = default_handler
#pragma weak DMA_IRQHandler        = default_handler
#pragma weak GINT0_IRQHandler      = default_handler
#pragma weak GINT1_IRQHandler      = default_handler
#pragma weak PIN_INT0_IRQHandler   = default_handler
#pragma weak PIN_INT1_IRQHandler   = default_handler
#pragma weak PIN_INT2_IRQHandler   = default_handler
#pragma weak PIN_INT3_IRQHandler   = default_handler
#pragma weak PIN_INT4_IRQHandler   = default_handler
#pragma weak PIN_INT5_IRQHandler   = default_handler
#pragma weak PIN_INT6_IRQHandler   = default_handler
#pragma weak PIN_INT7_IRQHandler   = default_handler
#pragma weak RIT_IRQHandler        = default_handler
#pragma weak SCT0_IRQHandler       = default_handler
#pragma weak SCT1_IRQHandler       = default_handler
#pragma weak SCT2_IRQHandler       = default_handler
#pragma weak SCT3_IRQHandler       = default_handler
#pragma weak MRT_IRQHandler        = default_handler
#pragma weak UART0_IRQHandler      = default_handler
#pragma weak UART1_IRQHandler      = default_handler
#pragma weak UART2_IRQHandler      = default_handler
#pragma weak I2C0_IRQHandler       = default_handler
#pragma weak SPI0_IRQHandler       = default_handler
#pragma weak SPI1_IRQHandler       = default_handler
#pragma weak C_CAN0_IRQHandler     = default_handler
#pragma weak USB_IRQ_IRQHandler    = default_handler
#pragma weak USB_FIQ_IRQHandler    = default_handler
#pragma weak USBWAKEUP_IRQHandler  = default_handler
#pragma weak ADC0_SEQA_IRQHandler  = default_handler
#pragma weak ADC0_SEQB_IRQHandler  = default_handler
#pragma weak ADC0_THCMP_IRQHandler = default_handler
#pragma weak ADC0_OVR_IRQHandler   = default_handler
#pragma weak ADC1_SEQA_IRQHandler  = default_handler
#pragma weak ADC1_SEQB_IRQHandler  = default_handler
#pragma weak ADC1_THCMP_IRQHandler = default_handler
#pragma weak ADC1_OVR_IRQHandler   = default_handler
#pragma weak DAC_IRQHandler        = default_handler
#pragma weak CMP0_IRQHandler       = default_handler
#pragma weak CMP1_IRQHandler       = default_handler
#pragma weak CMP2_IRQHandler       = default_handler
#pragma weak CMP3_IRQHandler       = default_handler
#pragma weak QEI_IRQHandler        = default_handler
#pragma weak RTC_ALARM_IRQHandler  = default_handler
#pragma weak RTC_WAKE_IRQHandler   = default_handler

#else // NDEBUG

WEAK void WDT_IRQHandler        ()  { default_handler(); }
WEAK void BOD_IRQHandler        ()  { default_handler(); }
WEAK void FLASH_IRQHandler      ()  { default_handler(); }
WEAK void EE_IRQHandler         ()  { default_handler(); }
WEAK void DMA_IRQHandler        ()  { default_handler(); }
WEAK void GINT0_IRQHandler      ()  { default_handler(); }
WEAK void GINT1_IRQHandler      ()  { default_handler(); }
WEAK void PIN_INT0_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT1_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT2_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT3_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT4_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT5_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT6_IRQHandler   ()  { default_handler(); }
WEAK void PIN_INT7_IRQHandler   ()  { default_handler(); }
WEAK void RIT_IRQHandler        ()  { default_handler(); }
WEAK void SCT0_IRQHandler       ()  { default_handler(); }
WEAK void SCT1_IRQHandler       ()  { default_handler(); }
WEAK void SCT2_IRQHandler       ()  { default_handler(); }
WEAK void SCT3_IRQHandler       ()  { default_handler(); }
WEAK void MRT_IRQHandler        ()  { default_handler(); }
WEAK void UART0_IRQHandler      ()  { default_handler(); }
WEAK void UART1_IRQHandler      ()  { default_handler(); }
WEAK void UART2_IRQHandler      ()  { default_handler(); }
WEAK void I2C0_IRQHandler       ()  { default_handler(); }
WEAK void SPI0_IRQHandler       ()  { default_handler(); }
WEAK void SPI1_IRQHandler       ()  { default_handler(); }
WEAK void C_CAN0_IRQHandler     ()  { default_handler(); }
WEAK void USB_IRQ_IRQHandler    ()  { default_handler(); }
WEAK void USB_FIQ_IRQHandler    ()  { default_handler(); }
WEAK void USBWAKEUP_IRQHandler  ()  { default_handler(); }
WEAK void ADC0_SEQA_IRQHandler  ()  { default_handler(); }
WEAK void ADC0_SEQB_IRQHandler  ()  { default_handler(); }
WEAK void ADC0_THCMP_IRQHandler ()  { default_handler(); }
WEAK void ADC0_OVR_IRQHandler   ()  { default_handler(); }
WEAK void ADC1_SEQA_IRQHandler  ()  { default_handler(); }
WEAK void ADC1_SEQB_IRQHandler  ()  { default_handler(); }
WEAK void ADC1_THCMP_IRQHandler ()  { default_handler(); }
WEAK void ADC1_OVR_IRQHandler   ()  { default_handler(); }
WEAK void DAC_IRQHandler        ()  { default_handler(); }
WEAK void CMP0_IRQHandler       ()  { default_handler(); }
WEAK void CMP1_IRQHandler       ()  { default_handler(); }
WEAK void CMP2_IRQHandler       ()  { default_handler(); }
WEAK void CMP3_IRQHandler       ()  { default_handler(); }
WEAK void QEI_IRQHandler        ()  { default_handler(); }
WEAK void RTC_ALARM_IRQHandler  ()  { default_handler(); }
WEAK void RTC_WAKE_IRQHandler   ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
