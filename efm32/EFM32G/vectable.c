//******************************************************************************
//*
//*      EFM32G vector table
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
    ACMP0_IRQHandler,        // 5: ACMP0 Interrupt
    ADC0_IRQHandler,         // 6: ADC0 Interrupt
    DAC0_IRQHandler,         // 7: DAC0 Interrupt
    I2C0_IRQHandler,         // 8: I2C0 Interrupt
    GPIO_ODD_IRQHandler,     // 9: GPIO_ODD Interrupt
    TIMER1_IRQHandler,       // 10: TIMER1 Interrupt
    TIMER2_IRQHandler,       // 11: TIMER2 Interrupt
    USART1_RX_IRQHandler,    // 12: USART1_RX Interrupt
    USART1_TX_IRQHandler,    // 13: USART1_TX Interrupt
    USART2_RX_IRQHandler,    // 14: USART2_RX Interrupt
    USART2_TX_IRQHandler,    // 15: USART2_TX Interrupt
    UART0_RX_IRQHandler,     // 16: UART0_RX Interrupt
    UART0_TX_IRQHandler,     // 17: UART0_TX Interrupt
    LEUART0_IRQHandler,      // 18: LEUART0 Interrupt
    LEUART1_IRQHandler,      // 19: LEUART1 Interrupt
    LETIMER0_IRQHandler,     // 20: LETIMER0 Interrupt
    PCNT0_IRQHandler,        // 21: PCNT0 Interrupt
    PCNT1_IRQHandler,        // 22: PCNT1 Interrupt
    PCNT2_IRQHandler,        // 23: PCNT2 Interrupt
    RTC_IRQHandler,          // 24: RTC Interrupt
    CMU_IRQHandler,          // 25: CMU Interrupt
    VCMP_IRQHandler,         // 26: VCMP Interrupt
    LCD_IRQHandler,          // 27: LCD Interrupt
    MSC_IRQHandler,          // 28: MSC Interrupt
    AES_IRQHandler,          // 29: AES Interrupt
    0                        // 30: Reserved
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
WEAK void ACMP0_IRQHandler     ()  { default_handler(); }
WEAK void ADC0_IRQHandler      ()  { default_handler(); }
WEAK void DAC0_IRQHandler      ()  { default_handler(); }
WEAK void I2C0_IRQHandler      ()  { default_handler(); }
WEAK void GPIO_ODD_IRQHandler  ()  { default_handler(); }
WEAK void TIMER1_IRQHandler    ()  { default_handler(); }
WEAK void TIMER2_IRQHandler    ()  { default_handler(); }
WEAK void USART1_RX_IRQHandler ()  { default_handler(); }
WEAK void USART1_TX_IRQHandler ()  { default_handler(); }
WEAK void USART2_RX_IRQHandler ()  { default_handler(); }
WEAK void USART2_TX_IRQHandler ()  { default_handler(); }
WEAK void UART0_RX_IRQHandler  ()  { default_handler(); }
WEAK void UART0_TX_IRQHandler  ()  { default_handler(); }
WEAK void LEUART0_IRQHandler   ()  { default_handler(); }
WEAK void LEUART1_IRQHandler   ()  { default_handler(); }
WEAK void LETIMER0_IRQHandler  ()  { default_handler(); }
WEAK void PCNT0_IRQHandler     ()  { default_handler(); }
WEAK void PCNT1_IRQHandler     ()  { default_handler(); }
WEAK void PCNT2_IRQHandler     ()  { default_handler(); }
WEAK void RTC_IRQHandler       ()  { default_handler(); }
WEAK void CMU_IRQHandler       ()  { default_handler(); }
WEAK void VCMP_IRQHandler      ()  { default_handler(); }
WEAK void LCD_IRQHandler       ()  { default_handler(); }
WEAK void MSC_IRQHandler       ()  { default_handler(); }
WEAK void AES_IRQHandler       ()  { default_handler(); }
//------------------------------------------------------------------------------
