//******************************************************************************
//*
//*      STM32F10X_XL vector table
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
    WWDG_IRQHandler,                  // Window Watchdog
    PVD_IRQHandler,                   // PVD through EXTI Line detect
    TAMPER_IRQHandler,                // Tamper
    RTC_IRQHandler,                   // RTC
    FLASH_IRQHandler,                 // Flash
    RCC_IRQHandler,                   // RCC
    EXTI0_IRQHandler,                 // EXTI Line 0
    EXTI1_IRQHandler,                 // EXTI Line 1
    EXTI2_IRQHandler,                 // EXTI Line 2
    EXTI3_IRQHandler,                 // EXTI Line 3
    EXTI4_IRQHandler,                 // EXTI Line 4
    DMA1_Channel1_IRQHandler,         // DMA1 Channel 1
    DMA1_Channel2_IRQHandler,         // DMA1 Channel 2
    DMA1_Channel3_IRQHandler,         // DMA1 Channel 3
    DMA1_Channel4_IRQHandler,         // DMA1 Channel 4
    DMA1_Channel5_IRQHandler,         // DMA1 Channel 5
    DMA1_Channel6_IRQHandler,         // DMA1 Channel 6
    DMA1_Channel7_IRQHandler,         // DMA1 Channel 7
    ADC1_2_IRQHandler,                // ADC1 & ADC2
    USB_HP_CAN1_TX_IRQHandler,        // USB High Priority or CAN1 TX
    USB_LP_CAN1_RX0_IRQHandler,       // USB Low  Priority or CAN1 RX0
    CAN1_RX1_IRQHandler,              // CAN1 RX1
    CAN1_SCE_IRQHandler,              // CAN1 SCE
    EXTI9_5_IRQHandler,               // EXTI Line 9..5
    TIM1_BRK_TIM9_IRQHandler,         // TIM1 Break and TIM9
    TIM1_UP_TIM10_IRQHandler,         // TIM1 Update and TIM10
    TIM1_TRG_COM_TIM11_IRQHandler,    // TIM1 Trigger and Commutation and TIM11
    TIM1_CC_IRQHandler,               // TIM1 Capture Compare
    TIM2_IRQHandler,                  // TIM2
    TIM3_IRQHandler,                  // TIM3
    TIM4_IRQHandler,                  // TIM4
    I2C1_EV_IRQHandler,               // I2C1 Event
    I2C1_ER_IRQHandler,               // I2C1 Error
    I2C2_EV_IRQHandler,               // I2C2 Event
    I2C2_ER_IRQHandler,               // I2C2 Error
    SPI1_IRQHandler,                  // SPI1
    SPI2_IRQHandler,                  // SPI2
    USART1_IRQHandler,                // USART1
    USART2_IRQHandler,                // USART2
    USART3_IRQHandler,                // USART3
    EXTI15_10_IRQHandler,             // EXTI Line 15..10
    RTCAlarm_IRQHandler,              // RTC Alarm through EXTI Line
    USBWakeUp_IRQHandler,             // USB Wakeup from suspend
    TIM8_BRK_TIM12_IRQHandler,        // TIM8 Break and TIM12
    TIM8_UP_TIM13_IRQHandler,         // TIM8 Update and TIM13
    TIM8_TRG_COM_TIM14_IRQHandler,    // TIM8 Trigger and Commutation and TIM14
    TIM8_CC_IRQHandler,               // TIM8 Capture Compare
    ADC3_IRQHandler,                  // ADC3
    FSMC_IRQHandler,                  // FSMC
    SDIO_IRQHandler,                  // SDIO
    TIM5_IRQHandler,                  // TIM5
    SPI3_IRQHandler,                  // SPI3
    UART4_IRQHandler,                 // UART4
    UART5_IRQHandler,                 // UART5
    TIM6_IRQHandler,                  // TIM6
    TIM7_IRQHandler,                  // TIM7
    DMA2_Channel1_IRQHandler,         // DMA2 Channel1
    DMA2_Channel2_IRQHandler,         // DMA2 Channel2
    DMA2_Channel3_IRQHandler,         // DMA2 Channel3
    DMA2_Channel4_5_IRQHandler        // DMA2 Channel4 & Channel5
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
WEAK void WWDG_IRQHandler               ()  { default_handler(); }
WEAK void PVD_IRQHandler                ()  { default_handler(); }
WEAK void TAMPER_IRQHandler             ()  { default_handler(); }
WEAK void RTC_IRQHandler                ()  { default_handler(); }
WEAK void FLASH_IRQHandler              ()  { default_handler(); }
WEAK void RCC_IRQHandler                ()  { default_handler(); }
WEAK void EXTI0_IRQHandler              ()  { default_handler(); }
WEAK void EXTI1_IRQHandler              ()  { default_handler(); }
WEAK void EXTI2_IRQHandler              ()  { default_handler(); }
WEAK void EXTI3_IRQHandler              ()  { default_handler(); }
WEAK void EXTI4_IRQHandler              ()  { default_handler(); }
WEAK void DMA1_Channel1_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel2_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel3_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel4_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel5_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel6_IRQHandler      ()  { default_handler(); }
WEAK void DMA1_Channel7_IRQHandler      ()  { default_handler(); }
WEAK void ADC1_2_IRQHandler             ()  { default_handler(); }
WEAK void USB_HP_CAN1_TX_IRQHandler     ()  { default_handler(); }
WEAK void USB_LP_CAN1_RX0_IRQHandler    ()  { default_handler(); }
WEAK void CAN1_RX1_IRQHandler           ()  { default_handler(); }
WEAK void CAN1_SCE_IRQHandler           ()  { default_handler(); }
WEAK void EXTI9_5_IRQHandler            ()  { default_handler(); }
WEAK void TIM1_BRK_TIM9_IRQHandler      ()  { default_handler(); }
WEAK void TIM1_UP_TIM10_IRQHandler      ()  { default_handler(); }
WEAK void TIM1_TRG_COM_TIM11_IRQHandler ()  { default_handler(); }
WEAK void TIM1_CC_IRQHandler            ()  { default_handler(); }
WEAK void TIM2_IRQHandler               ()  { default_handler(); }
WEAK void TIM3_IRQHandler               ()  { default_handler(); }
WEAK void TIM4_IRQHandler               ()  { default_handler(); }
WEAK void I2C1_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C1_ER_IRQHandler            ()  { default_handler(); }
WEAK void I2C2_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C2_ER_IRQHandler            ()  { default_handler(); }
WEAK void SPI1_IRQHandler               ()  { default_handler(); }
WEAK void SPI2_IRQHandler               ()  { default_handler(); }
WEAK void USART1_IRQHandler             ()  { default_handler(); }
WEAK void USART2_IRQHandler             ()  { default_handler(); }
WEAK void USART3_IRQHandler             ()  { default_handler(); }
WEAK void EXTI15_10_IRQHandler          ()  { default_handler(); }
WEAK void RTCAlarm_IRQHandler           ()  { default_handler(); }
WEAK void USBWakeUp_IRQHandler          ()  { default_handler(); }
WEAK void TIM8_BRK_TIM12_IRQHandler     ()  { default_handler(); }
WEAK void TIM8_UP_TIM13_IRQHandler      ()  { default_handler(); }
WEAK void TIM8_TRG_COM_TIM14_IRQHandler ()  { default_handler(); }
WEAK void TIM8_CC_IRQHandler            ()  { default_handler(); }
WEAK void ADC3_IRQHandler               ()  { default_handler(); }
WEAK void FSMC_IRQHandler               ()  { default_handler(); }
WEAK void SDIO_IRQHandler               ()  { default_handler(); }
WEAK void TIM5_IRQHandler               ()  { default_handler(); }
WEAK void SPI3_IRQHandler               ()  { default_handler(); }
WEAK void UART4_IRQHandler              ()  { default_handler(); }
WEAK void UART5_IRQHandler              ()  { default_handler(); }
WEAK void TIM6_IRQHandler               ()  { default_handler(); }
WEAK void TIM7_IRQHandler               ()  { default_handler(); }
WEAK void DMA2_Channel1_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel2_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel3_IRQHandler      ()  { default_handler(); }
WEAK void DMA2_Channel4_5_IRQHandler    ()  { default_handler(); }
//------------------------------------------------------------------------------
