//******************************************************************************
//*
//*      STM32F10X_LD_VL vector table
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
    ADC1_IRQHandler,                  // ADC1
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    EXTI9_5_IRQHandler,               // EXTI Line 9..5
    TIM1_BRK_TIM15_IRQHandler,        // TIM1 Break and TIM15
    TIM1_UP_TIM16_IRQHandler,         // TIM1 Update and TIM16
    TIM1_TRG_COM_TIM17_IRQHandler,    // TIM1 Trigger and Commutation and TIM17
    TIM1_CC_IRQHandler,               // TIM1 Capture Compare
    TIM2_IRQHandler,                  // TIM2
    TIM3_IRQHandler,                  // TIM3
    0,                                // Reserved
    I2C1_EV_IRQHandler,               // I2C1 Event
    I2C1_ER_IRQHandler,               // I2C1 Error
    0,                                // Reserved
    0,                                // Reserved
    SPI1_IRQHandler,                  // SPI1
    0,                                // Reserved
    USART1_IRQHandler,                // USART1
    USART2_IRQHandler,                // USART2
    0,                                // Reserved
    EXTI15_10_IRQHandler,             // EXTI Line 15..10
    RTCAlarm_IRQHandler,              // RTC Alarm through EXTI Line
    CEC_IRQHandler,                   // HDMI-CEC
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved 
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved 
    0,                                // Reserved
    0,                                // Reserved
    0,                                // Reserved
    TIM6_DAC_IRQHandler,              // TIM6 and DAC underrun
    TIM7_IRQHandler                   // TIM7
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
WEAK void ADC1_IRQHandler               ()  { default_handler(); }
WEAK void EXTI9_5_IRQHandler            ()  { default_handler(); }
WEAK void TIM1_BRK_TIM15_IRQHandler     ()  { default_handler(); }
WEAK void TIM1_UP_TIM16_IRQHandler      ()  { default_handler(); }
WEAK void TIM1_TRG_COM_TIM17_IRQHandler ()  { default_handler(); }
WEAK void TIM1_CC_IRQHandler            ()  { default_handler(); }
WEAK void TIM2_IRQHandler               ()  { default_handler(); }
WEAK void TIM3_IRQHandler               ()  { default_handler(); }
WEAK void I2C1_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C1_ER_IRQHandler            ()  { default_handler(); }
WEAK void SPI1_IRQHandler               ()  { default_handler(); }
WEAK void USART1_IRQHandler             ()  { default_handler(); }
WEAK void USART2_IRQHandler             ()  { default_handler(); }
WEAK void EXTI15_10_IRQHandler          ()  { default_handler(); }
WEAK void RTCAlarm_IRQHandler           ()  { default_handler(); }
WEAK void CEC_IRQHandler                ()  { default_handler(); }
WEAK void TIM6_DAC_IRQHandler           ()  { default_handler(); }
WEAK void TIM7_IRQHandler               ()  { default_handler(); }
//------------------------------------------------------------------------------
