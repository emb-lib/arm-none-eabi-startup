//******************************************************************************
//*
//*      EFM32WG vector table
//*
//*      Version 1.0
//*
//*      Copyright (c) 2016, emb-lib Project Team
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
    USART0_RX_IRQHandler,    // 3: USART0_RX Interrupt
    USART0_TX_IRQHandler,    // 4: USART0_TX Interrupt
    USB_IRQHandler,          // 5: USB Interrupt
    ACMP0_IRQHandler,        // 6: ACMP0 Interrupt
    ADC0_IRQHandler,         // 7: ADC0 Interrupt
    DAC0_IRQHandler,         // 8: DAC0 Interrupt
    I2C0_IRQHandler,         // 9: I2C0 Interrupt
    I2C1_IRQHandler,         // 10: I2C1 Interrupt
    GPIO_ODD_IRQHandler,     // 11: GPIO_ODD Interrupt
    TIMER1_IRQHandler,       // 12: TIMER1 Interrupt
    TIMER2_IRQHandler,       // 13: TIMER2 Interrupt
    TIMER3_IRQHandler,       // 14: TIMER3 Interrupt
    USART1_RX_IRQHandler,    // 15: USART1_RX Interrupt
    USART1_TX_IRQHandler,    // 16: USART1_TX Interrupt
    LESENSE_IRQHandler,      // 17: LESENSE Interrupt
    USART2_RX_IRQHandler,    // 18: USART2_RX Interrupt
    USART2_TX_IRQHandler,    // 19: USART2_TX Interrupt
    UART0_RX_IRQHandler,     // 20: UART0_RX Interrupt
    UART0_TX_IRQHandler,     // 21: UART0_TX Interrupt
    UART1_RX_IRQHandler,     // 22: UART1_RX Interrupt
    UART1_TX_IRQHandler,     // 23: UART1_TX Interrupt
    LEUART0_IRQHandler,      // 24: LEUART0 Interrupt
    LEUART1_IRQHandler,      // 25: LEUART1 Interrupt
    LETIMER0_IRQHandler,     // 26: LETIMER0 Interrupt
    PCNT0_IRQHandler,        // 27: PCNT0 Interrupt
    PCNT1_IRQHandler,        // 28: PCNT1 Interrupt
    PCNT2_IRQHandler,        // 29: PCNT2 Interrupt
    RTC_IRQHandler,          // 30: RTC Interrupt
    BURTC_IRQHandler,        // 31: BURTC Interrupt
    CMU_IRQHandler,          // 32: CMU Interrupt
    VCMP_IRQHandler,         // 33: VCMP Interrupt
    LCD_IRQHandler,          // 34: LCD Interrupt
    MSC_IRQHandler,          // 35: MSC Interrupt
    AES_IRQHandler,          // 36: AES Interrupt
    EBI_IRQHandler,          // 37: EBI Interrupt
    EMU_IRQHandler,          // 38: EMU Interrupt
    FPUEH_IRQHandler         // 39: FPUEH Interrupt
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
WEAK void NMI_Handler        ()  { default_handler(); }
WEAK void HardFault_Handler  ()  { hf_handler();      }
WEAK void MemManage_Handler  ()  { default_handler(); }
WEAK void BusFault_Handler   ()  { default_handler(); }
WEAK void UsageFault_Handler ()  { default_handler(); }
WEAK void SVC_Handler        ()  { default_handler(); }
WEAK void DebugMon_Handler   ()  { default_handler(); }
WEAK void PendSV_Handler     ()  { default_handler(); }
WEAK void SysTick_Handler    ()  { default_handler(); }

//------------------------------------------------------------------------------
//
//   Default interrupt handlers
//
WEAK void DMA_IRQHandler       ()  { default_handler(); }
WEAK void GPIO_EVEN_IRQHandler ()  { default_handler(); }
WEAK void TIMER0_IRQHandler    ()  { default_handler(); }
WEAK void USART0_RX_IRQHandler ()  { default_handler(); }
WEAK void USART0_TX_IRQHandler ()  { default_handler(); }
WEAK void USB_IRQHandler       ()  { default_handler(); }
WEAK void ACMP0_IRQHandler     ()  { default_handler(); }
WEAK void ADC0_IRQHandler      ()  { default_handler(); }
WEAK void DAC0_IRQHandler      ()  { default_handler(); }
WEAK void I2C0_IRQHandler      ()  { default_handler(); }
WEAK void I2C1_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_ODD_IRQHandler  ()  { default_handler(); }
WEAK void TIMER1_IRQHandler    ()  { default_handler(); }
WEAK void TIMER2_IRQHandler    ()  { default_handler(); }
WEAK void TIMER3_IRQHandler    ()  { default_handler(); }
WEAK void USART1_RX_IRQHandler ()  { default_handler(); }
WEAK void USART1_TX_IRQHandler ()  { default_handler(); }
WEAK void LESENSE_IRQHandler   ()  { default_handler(); }
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
WEAK void RTC_IRQHandler       ()  { default_handler(); }
WEAK void BURTC_IRQHandler     ()  { default_handler(); }
WEAK void CMU_IRQHandler       ()  { default_handler(); }
WEAK void VCMP_IRQHandler      ()  { default_handler(); }
WEAK void LCD_IRQHandler       ()  { default_handler(); }
WEAK void MSC_IRQHandler       ()  { default_handler(); }
WEAK void AES_IRQHandler       ()  { default_handler(); }
WEAK void EBI_IRQHandler       ()  { default_handler(); }
WEAK void EMU_IRQHandler       ()  { default_handler(); }
WEAK void FPUEH_IRQHandler     ()  { default_handler(); }
//------------------------------------------------------------------------------
