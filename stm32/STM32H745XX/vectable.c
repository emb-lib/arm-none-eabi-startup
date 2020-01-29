//******************************************************************************
//*
//*      STM32H745XX vector table
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
    WWDG_IRQHandler,                  // Window WatchDog interrupt ( wwdg1_it, wwdg2_it)                                         
    PVD_AVD_IRQHandler,               // PVD/AVD through EXTI Line detection                        
    TAMP_STAMP_IRQHandler,            // Tamper and TimeStamps through the EXTI line            
    RTC_WKUP_IRQHandler,              // RTC Wakeup through the EXTI line                       
    FLASH_IRQHandler,                 // FLASH                                           
    RCC_IRQHandler,                   // RCC                                             
    EXTI0_IRQHandler,                 // EXTI Line0                                             
    EXTI1_IRQHandler,                 // EXTI Line1                                             
    EXTI2_IRQHandler,                 // EXTI Line2                                             
    EXTI3_IRQHandler,                 // EXTI Line3                                             
    EXTI4_IRQHandler,                 // EXTI Line4 
    DMA1_Stream0_IRQHandler,          // DMA1 Stream 0
    DMA1_Stream1_IRQHandler,          // DMA1 Stream 1                                   
    DMA1_Stream2_IRQHandler,          // DMA1 Stream 2                                   
    DMA1_Stream3_IRQHandler,          // DMA1 Stream 3                                   
    DMA1_Stream4_IRQHandler,          // DMA1 Stream 4                                   
    DMA1_Stream5_IRQHandler,          // DMA1 Stream 5                                   
    DMA1_Stream6_IRQHandler,          // DMA1 Stream 6  
    ADC_IRQHandler,                   // ADC1, ADC2                             
    FDCAN1_IT0_IRQHandler,            // FDCAN1 interrupt line 0                        
    FDCAN2_IT0_IRQHandler,            // FDCAN2 interrupt line 0                               
    FDCAN1_IT1_IRQHandler,            // FDCAN1 interrupt line 1                        
    FDCAN2_IT1_IRQHandler,            // FDCAN2 interrupt line 1                                               
    EXTI9_5_IRQHandler,               // External Line[9:5]s                                    
    TIM1_BRK_IRQHandler,              // TIM1 Break interrupt                   
    TIM1_UP_IRQHandler,               // TIM1 Update Interrupt                 
    TIM1_TRG_COM_IRQHandler,          // TIM1 Trigger and Commutation Interrupt 
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
    EXTI15_10_IRQHandler,             // External Line[15:10]  
    RTC_Alarm_IRQHandler,             // RTC Alarm (A and B) through EXTI Line
    0,                                // Reserved                                          
    TIM8_BRK_TIM12_IRQHandler,        // TIM8 Break Interrupt and TIM12 global interrupt                 
    TIM8_UP_TIM13_IRQHandler,         // TIM8 Update Interrupt and TIM13 global interrupt
    TIM8_TRG_COM_TIM14_IRQHandler,    // TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt
    TIM8_CC_IRQHandler,               // TIM8 Capture Compare Interrupt
    DMA1_Stream7_IRQHandler,          // DMA1 Stream7                                           
    FMC_IRQHandler,                   // FMC                             
    SDMMC1_IRQHandler,                // SDMMC1                            
    TIM5_IRQHandler,                  // TIM5                            
    SPI3_IRQHandler,                  // SPI3                            
    UART4_IRQHandler,                 // UART4                           
    UART5_IRQHandler,                 // UART5                           
    TIM6_DAC_IRQHandler,              // TIM6 and DAC1&2 underrun errors           
    TIM7_IRQHandler,                  // TIM7           
    DMA2_Stream0_IRQHandler,          // DMA2 Stream 0                   
    DMA2_Stream1_IRQHandler,          // DMA2 Stream 1                   
    DMA2_Stream2_IRQHandler,          // DMA2 Stream 2                   
    DMA2_Stream3_IRQHandler,          // DMA2 Stream 3                   
    DMA2_Stream4_IRQHandler,          // DMA2 Stream 4                   
    ETH_IRQHandler,                   // Ethernet                        
    ETH_WKUP_IRQHandler,              // Ethernet Wakeup through EXTI line              
    FDCAN_CAL_IRQHandler,             // FDCAN calibration unit interrupt                        
    CM7_SEV_IRQHandler,               // CM7 Send event interrupt for CM4                              
    CM4_SEV_IRQHandler,               // CM4 Send event interrupt for CM7 
    0,                                // Reserved 
    0,                                // Reserved                      
    DMA2_Stream5_IRQHandler,          // DMA2 Stream 5                   
    DMA2_Stream6_IRQHandler,          // DMA2 Stream 6                   
    DMA2_Stream7_IRQHandler,          // DMA2 Stream 7                   
    USART6_IRQHandler,                // USART6                           
    I2C3_EV_IRQHandler,               // I2C3 event                             
    I2C3_ER_IRQHandler,               // I2C3 error                             
    OTG_HS_EP1_OUT_IRQHandler,        // USB OTG HS End Point 1 Out                      
    OTG_HS_EP1_IN_IRQHandler,         // USB OTG HS End Point 1 In                       
    OTG_HS_WKUP_IRQHandler,           // USB OTG HS Wakeup through EXTI                         
    OTG_HS_IRQHandler,                // USB OTG HS                    
    DCMI_IRQHandler,                  // DCMI                            
    0,                                // Reserved                                     
    RNG_IRQHandler,                   // Rng
    FPU_IRQHandler,                   // FPU
    UART7_IRQHandler,                 // UART7
    UART8_IRQHandler,                 // UART8
    SPI4_IRQHandler,                  // SPI4
    SPI5_IRQHandler,                  // SPI5
    SPI6_IRQHandler,                  // SPI6
    SAI1_IRQHandler,                  // SAI1
    LTDC_IRQHandler,                  // LTDC
    LTDC_ER_IRQHandler,               // LTDC error
    DMA2D_IRQHandler,                 // DMA2D
    SAI2_IRQHandler,                  // SAI2
    QUADSPI_IRQHandler,               // QUADSPI
    LPTIM1_IRQHandler,                // LPTIM1
    CEC_IRQHandler,                   // HDMI_CEC
    I2C4_EV_IRQHandler,               // I2C4 Event                             
    I2C4_ER_IRQHandler,               // I2C4 Error 
    SPDIF_RX_IRQHandler,              // SPDIF_RX
    OTG_FS_EP1_OUT_IRQHandler,        // USB OTG FS End Point 1 Out                      
    OTG_FS_EP1_IN_IRQHandler,         // USB OTG FS End Point 1 In                       
    OTG_FS_WKUP_IRQHandler,           // USB OTG FS Wakeup through EXTI                         
    OTG_FS_IRQHandler,                // USB OTG FS                 
    DMAMUX1_OVR_IRQHandler,           // DMAMUX1 Overrun interrupt  
    HRTIM1_Master_IRQHandler,         //  HRTIM Master Timer global Interrupts                              
    HRTIM1_TIMA_IRQHandler,           //  HRTIM Timer A global Interrupt                                    
    HRTIM1_TIMB_IRQHandler,           //  HRTIM Timer B global Interrupt                                    
    HRTIM1_TIMC_IRQHandler,           //  HRTIM Timer C global Interrupt                                    
    HRTIM1_TIMD_IRQHandler,           //  HRTIM Timer D global Interrupt                                    
    HRTIM1_TIME_IRQHandler,           //  HRTIM Timer E global Interrupt                                    
    HRTIM1_FLT_IRQHandler,            //  HRTIM Fault global Interrupt 
    DFSDM1_FLT0_IRQHandler,           // DFSDM Filter0 Interrupt   
    DFSDM1_FLT1_IRQHandler,           // DFSDM Filter1 Interrupt                                            
    DFSDM1_FLT2_IRQHandler,           // DFSDM Filter2 Interrupt                                            
    DFSDM1_FLT3_IRQHandler,           // DFSDM Filter3 Interrupt                                                                                    
    SAI3_IRQHandler,                  //  SAI3 global Interrupt                                             
    SWPMI1_IRQHandler,                //  Serial Wire Interface 1 global interrupt                          
    TIM15_IRQHandler,                 //  TIM15 global Interrupt                                            
    TIM16_IRQHandler,                 //  TIM16 global Interrupt                                            
    TIM17_IRQHandler,                 //  TIM17 global Interrupt                                            
    MDIOS_WKUP_IRQHandler,            //  MDIOS Wakeup  Interrupt                                           
    MDIOS_IRQHandler,                 //  MDIOS global Interrupt                                            
    JPEG_IRQHandler,                  //  JPEG global Interrupt                                             
    MDMA_IRQHandler,                  //  MDMA global Interrupt                                             
    0,                                // Reserved                                              
    SDMMC2_IRQHandler,                //  SDMMC2 global Interrupt                                           
    HSEM1_IRQHandler,                 //  HSEM1 global Interrupt                                             
    HSEM2_IRQHandler,                 //  HSEM2 global Interrupt                                             
    ADC3_IRQHandler,                  //  ADC3 global Interrupt                                              
    DMAMUX2_OVR_IRQHandler,           // DMAMUX Overrun interrupt                                           
    BDMA_Channel0_IRQHandler,         //  BDMA Channel 0 global Interrupt                                    
    BDMA_Channel1_IRQHandler,         //  BDMA Channel 1 global Interrupt                                    
    BDMA_Channel2_IRQHandler,         //  BDMA Channel 2 global Interrupt                                    
    BDMA_Channel3_IRQHandler,         //  BDMA Channel 3 global Interrupt                                    
    BDMA_Channel4_IRQHandler,         //  BDMA Channel 4 global Interrupt                                    
    BDMA_Channel5_IRQHandler,         //  BDMA Channel 5 global Interrupt                                    
    BDMA_Channel6_IRQHandler,         //  BDMA Channel 6 global Interrupt                                    
    BDMA_Channel7_IRQHandler,         //  BDMA Channel 7 global Interrupt                                    
    COMP1_IRQHandler,                 //  COMP1 global Interrupt                                            
    LPTIM2_IRQHandler,                //  LP TIM2 global interrupt                                          
    LPTIM3_IRQHandler,                //  LP TIM3 global interrupt                                          
    LPTIM4_IRQHandler,                //  LP TIM4 global interrupt                                          
    LPTIM5_IRQHandler,                //  LP TIM5 global interrupt                                          
    LPUART1_IRQHandler,               //  LP UART1 interrupt                                                
    WWDG_RST_IRQHandler,              // Window Watchdog reset interrupt (exti_d2_wwdg_it, exti_d1_wwdg_it)                                
    CRS_IRQHandler,                   //  Clock Recovery Global Interrupt                                   
    ECC_IRQHandler,                   // ECC diagnostic Global Interrupt                                             
    SAI4_IRQHandler,                  //  SAI4 global interrupt                                                
    0,                                // Reserved                                
    HOLD_CORE_IRQHandler,             //  Hold core interrupt                                   
    WAKEUP_PIN_IRQHandler             //  Interrupt for all 6 wake-up pins 
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

#pragma weak WWDG_IRQHandler               = default_handler
#pragma weak PVD_AVD_IRQHandler            = default_handler
#pragma weak TAMP_STAMP_IRQHandler         = default_handler
#pragma weak RTC_WKUP_IRQHandler           = default_handler
#pragma weak FLASH_IRQHandler              = default_handler
#pragma weak RCC_IRQHandler                = default_handler
#pragma weak EXTI0_IRQHandler              = default_handler
#pragma weak EXTI1_IRQHandler              = default_handler
#pragma weak EXTI2_IRQHandler              = default_handler
#pragma weak EXTI3_IRQHandler              = default_handler
#pragma weak EXTI4_IRQHandler              = default_handler
#pragma weak DMA1_Stream0_IRQHandler       = default_handler
#pragma weak DMA1_Stream1_IRQHandler       = default_handler
#pragma weak DMA1_Stream2_IRQHandler       = default_handler
#pragma weak DMA1_Stream3_IRQHandler       = default_handler
#pragma weak DMA1_Stream4_IRQHandler       = default_handler
#pragma weak DMA1_Stream5_IRQHandler       = default_handler
#pragma weak DMA1_Stream6_IRQHandler       = default_handler
#pragma weak ADC_IRQHandler                = default_handler
#pragma weak FDCAN1_IT0_IRQHandler         = default_handler
#pragma weak FDCAN2_IT0_IRQHandler         = default_handler
#pragma weak FDCAN1_IT1_IRQHandler         = default_handler
#pragma weak FDCAN2_IT1_IRQHandler         = default_handler
#pragma weak EXTI9_5_IRQHandler            = default_handler
#pragma weak TIM1_BRK_IRQHandler           = default_handler
#pragma weak TIM1_UP_IRQHandler            = default_handler
#pragma weak TIM1_TRG_COM_IRQHandler       = default_handler
#pragma weak TIM1_CC_IRQHandler            = default_handler
#pragma weak TIM2_IRQHandler               = default_handler
#pragma weak TIM3_IRQHandler               = default_handler
#pragma weak TIM4_IRQHandler               = default_handler
#pragma weak I2C1_EV_IRQHandler            = default_handler
#pragma weak I2C1_ER_IRQHandler            = default_handler
#pragma weak I2C2_EV_IRQHandler            = default_handler
#pragma weak I2C2_ER_IRQHandler            = default_handler
#pragma weak SPI1_IRQHandler               = default_handler
#pragma weak SPI2_IRQHandler               = default_handler
#pragma weak USART1_IRQHandler             = default_handler
#pragma weak USART2_IRQHandler             = default_handler
#pragma weak USART3_IRQHandler             = default_handler
#pragma weak EXTI15_10_IRQHandler          = default_handler
#pragma weak RTC_Alarm_IRQHandler          = default_handler
#pragma weak TIM8_BRK_TIM12_IRQHandler     = default_handler
#pragma weak TIM8_UP_TIM13_IRQHandler      = default_handler
#pragma weak TIM8_TRG_COM_TIM14_IRQHandler = default_handler
#pragma weak TIM8_CC_IRQHandler            = default_handler
#pragma weak DMA1_Stream7_IRQHandler       = default_handler
#pragma weak FMC_IRQHandler                = default_handler
#pragma weak SDMMC1_IRQHandler             = default_handler
#pragma weak TIM5_IRQHandler               = default_handler
#pragma weak SPI3_IRQHandler               = default_handler
#pragma weak UART4_IRQHandler              = default_handler
#pragma weak UART5_IRQHandler              = default_handler
#pragma weak TIM6_DAC_IRQHandler           = default_handler
#pragma weak TIM7_IRQHandler               = default_handler
#pragma weak DMA2_Stream0_IRQHandler       = default_handler
#pragma weak DMA2_Stream1_IRQHandler       = default_handler
#pragma weak DMA2_Stream2_IRQHandler       = default_handler
#pragma weak DMA2_Stream3_IRQHandler       = default_handler
#pragma weak DMA2_Stream4_IRQHandler       = default_handler
#pragma weak ETH_IRQHandler                = default_handler
#pragma weak ETH_WKUP_IRQHandler           = default_handler
#pragma weak FDCAN_CAL_IRQHandler          = default_handler
#pragma weak CM7_SEV_IRQHandler            = default_handler
#pragma weak CM4_SEV_IRQHandler            = default_handler
#pragma weak DMA2_Stream5_IRQHandler       = default_handler
#pragma weak DMA2_Stream6_IRQHandler       = default_handler
#pragma weak DMA2_Stream7_IRQHandler       = default_handler
#pragma weak USART6_IRQHandler             = default_handler
#pragma weak I2C3_EV_IRQHandler            = default_handler
#pragma weak I2C3_ER_IRQHandler            = default_handler
#pragma weak OTG_HS_EP1_OUT_IRQHandler     = default_handler
#pragma weak OTG_HS_EP1_IN_IRQHandler      = default_handler
#pragma weak OTG_HS_WKUP_IRQHandler        = default_handler
#pragma weak OTG_HS_IRQHandler             = default_handler
#pragma weak DCMI_IRQHandler               = default_handler
#pragma weak RNG_IRQHandler                = default_handler
#pragma weak FPU_IRQHandler                = default_handler
#pragma weak UART7_IRQHandler              = default_handler
#pragma weak UART8_IRQHandler              = default_handler
#pragma weak SPI4_IRQHandler               = default_handler
#pragma weak SPI5_IRQHandler               = default_handler
#pragma weak SPI6_IRQHandler               = default_handler
#pragma weak SAI1_IRQHandler               = default_handler
#pragma weak LTDC_IRQHandler               = default_handler
#pragma weak LTDC_ER_IRQHandler            = default_handler
#pragma weak DMA2D_IRQHandler              = default_handler
#pragma weak SAI2_IRQHandler               = default_handler
#pragma weak QUADSPI_IRQHandler            = default_handler
#pragma weak LPTIM1_IRQHandler             = default_handler
#pragma weak CEC_IRQHandler                = default_handler
#pragma weak I2C4_EV_IRQHandler            = default_handler
#pragma weak I2C4_ER_IRQHandler            = default_handler
#pragma weak SPDIF_RX_IRQHandler           = default_handler
#pragma weak OTG_FS_EP1_OUT_IRQHandler     = default_handler
#pragma weak OTG_FS_EP1_IN_IRQHandler      = default_handler
#pragma weak OTG_FS_WKUP_IRQHandler        = default_handler
#pragma weak OTG_FS_IRQHandler             = default_handler
#pragma weak DMAMUX1_OVR_IRQHandler        = default_handler
#pragma weak HRTIM1_Master_IRQHandler      = default_handler
#pragma weak HRTIM1_TIMA_IRQHandler        = default_handler
#pragma weak HRTIM1_TIMB_IRQHandler        = default_handler
#pragma weak HRTIM1_TIMC_IRQHandler        = default_handler
#pragma weak HRTIM1_TIMD_IRQHandler        = default_handler
#pragma weak HRTIM1_TIME_IRQHandler        = default_handler
#pragma weak HRTIM1_FLT_IRQHandler         = default_handler
#pragma weak DFSDM1_FLT0_IRQHandler        = default_handler
#pragma weak DFSDM1_FLT1_IRQHandler        = default_handler
#pragma weak DFSDM1_FLT2_IRQHandler        = default_handler
#pragma weak DFSDM1_FLT3_IRQHandler        = default_handler
#pragma weak SAI3_IRQHandler               = default_handler
#pragma weak SWPMI1_IRQHandler             = default_handler
#pragma weak TIM15_IRQHandler              = default_handler
#pragma weak TIM16_IRQHandler              = default_handler
#pragma weak TIM17_IRQHandler              = default_handler
#pragma weak MDIOS_WKUP_IRQHandler         = default_handler
#pragma weak MDIOS_IRQHandler              = default_handler
#pragma weak JPEG_IRQHandler               = default_handler
#pragma weak MDMA_IRQHandler               = default_handler
#pragma weak SDMMC2_IRQHandler             = default_handler
#pragma weak HSEM1_IRQHandler              = default_handler
#pragma weak HSEM2_IRQHandler              = default_handler
#pragma weak ADC3_IRQHandler               = default_handler
#pragma weak DMAMUX2_OVR_IRQHandler        = default_handler
#pragma weak BDMA_Channel0_IRQHandler      = default_handler
#pragma weak BDMA_Channel1_IRQHandler      = default_handler
#pragma weak BDMA_Channel2_IRQHandler      = default_handler
#pragma weak BDMA_Channel3_IRQHandler      = default_handler
#pragma weak BDMA_Channel4_IRQHandler      = default_handler
#pragma weak BDMA_Channel5_IRQHandler      = default_handler
#pragma weak BDMA_Channel6_IRQHandler      = default_handler
#pragma weak BDMA_Channel7_IRQHandler      = default_handler
#pragma weak COMP1_IRQHandler              = default_handler
#pragma weak LPTIM2_IRQHandler             = default_handler
#pragma weak LPTIM3_IRQHandler             = default_handler
#pragma weak LPTIM4_IRQHandler             = default_handler
#pragma weak LPTIM5_IRQHandler             = default_handler
#pragma weak LPUART1_IRQHandler            = default_handler
#pragma weak WWDG_RST_IRQHandler           = default_handler
#pragma weak CRS_IRQHandler                = default_handler
#pragma weak ECC_IRQHandler                = default_handler
#pragma weak SAI4_IRQHandler               = default_handler
#pragma weak HOLD_CORE_IRQHandler          = default_handler
#pragma weak WAKEUP_PIN_IRQHandler         = default_handler

#else // NDEBUG

WEAK void WWDG_IRQHandler               ()  { default_handler(); }
WEAK void PVD_AVD_IRQHandler            ()  { default_handler(); }
WEAK void TAMP_STAMP_IRQHandler         ()  { default_handler(); }
WEAK void RTC_WKUP_IRQHandler           ()  { default_handler(); }
WEAK void FLASH_IRQHandler              ()  { default_handler(); }
WEAK void RCC_IRQHandler                ()  { default_handler(); }
WEAK void EXTI0_IRQHandler              ()  { default_handler(); }
WEAK void EXTI1_IRQHandler              ()  { default_handler(); }
WEAK void EXTI2_IRQHandler              ()  { default_handler(); }
WEAK void EXTI3_IRQHandler              ()  { default_handler(); }
WEAK void EXTI4_IRQHandler              ()  { default_handler(); }
WEAK void DMA1_Stream0_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Stream1_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Stream2_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Stream3_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Stream4_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Stream5_IRQHandler       ()  { default_handler(); }
WEAK void DMA1_Stream6_IRQHandler       ()  { default_handler(); }
WEAK void ADC_IRQHandler                ()  { default_handler(); }
WEAK void FDCAN1_IT0_IRQHandler         ()  { default_handler(); }
WEAK void FDCAN2_IT0_IRQHandler         ()  { default_handler(); }
WEAK void FDCAN1_IT1_IRQHandler         ()  { default_handler(); }
WEAK void FDCAN2_IT1_IRQHandler         ()  { default_handler(); }
WEAK void EXTI9_5_IRQHandler            ()  { default_handler(); }
WEAK void TIM1_BRK_IRQHandler           ()  { default_handler(); }
WEAK void TIM1_UP_IRQHandler            ()  { default_handler(); }
WEAK void TIM1_TRG_COM_IRQHandler       ()  { default_handler(); }
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
WEAK void RTC_Alarm_IRQHandler          ()  { default_handler(); }
WEAK void TIM8_BRK_TIM12_IRQHandler     ()  { default_handler(); }
WEAK void TIM8_UP_TIM13_IRQHandler      ()  { default_handler(); }
WEAK void TIM8_TRG_COM_TIM14_IRQHandler ()  { default_handler(); }
WEAK void TIM8_CC_IRQHandler            ()  { default_handler(); }
WEAK void DMA1_Stream7_IRQHandler       ()  { default_handler(); }
WEAK void FMC_IRQHandler                ()  { default_handler(); }
WEAK void SDMMC1_IRQHandler             ()  { default_handler(); }
WEAK void TIM5_IRQHandler               ()  { default_handler(); }
WEAK void SPI3_IRQHandler               ()  { default_handler(); }
WEAK void UART4_IRQHandler              ()  { default_handler(); }
WEAK void UART5_IRQHandler              ()  { default_handler(); }
WEAK void TIM6_DAC_IRQHandler           ()  { default_handler(); }
WEAK void TIM7_IRQHandler               ()  { default_handler(); }
WEAK void DMA2_Stream0_IRQHandler       ()  { default_handler(); }
WEAK void DMA2_Stream1_IRQHandler       ()  { default_handler(); }
WEAK void DMA2_Stream2_IRQHandler       ()  { default_handler(); }
WEAK void DMA2_Stream3_IRQHandler       ()  { default_handler(); }
WEAK void DMA2_Stream4_IRQHandler       ()  { default_handler(); }
WEAK void ETH_IRQHandler                ()  { default_handler(); }
WEAK void ETH_WKUP_IRQHandler           ()  { default_handler(); }
WEAK void FDCAN_CAL_IRQHandler          ()  { default_handler(); }
WEAK void CM7_SEV_IRQHandler            ()  { default_handler(); }
WEAK void CM4_SEV_IRQHandler            ()  { default_handler(); }
WEAK void DMA2_Stream5_IRQHandler       ()  { default_handler(); }
WEAK void DMA2_Stream6_IRQHandler       ()  { default_handler(); }
WEAK void DMA2_Stream7_IRQHandler       ()  { default_handler(); }
WEAK void USART6_IRQHandler             ()  { default_handler(); }
WEAK void I2C3_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C3_ER_IRQHandler            ()  { default_handler(); }
WEAK void OTG_HS_EP1_OUT_IRQHandler     ()  { default_handler(); }
WEAK void OTG_HS_EP1_IN_IRQHandler      ()  { default_handler(); }
WEAK void OTG_HS_WKUP_IRQHandler        ()  { default_handler(); }
WEAK void OTG_HS_IRQHandler             ()  { default_handler(); }
WEAK void DCMI_IRQHandler               ()  { default_handler(); }
WEAK void RNG_IRQHandler                ()  { default_handler(); }
WEAK void FPU_IRQHandler                ()  { default_handler(); }
WEAK void UART7_IRQHandler              ()  { default_handler(); }
WEAK void UART8_IRQHandler              ()  { default_handler(); }
WEAK void SPI4_IRQHandler               ()  { default_handler(); }
WEAK void SPI5_IRQHandler               ()  { default_handler(); }
WEAK void SPI6_IRQHandler               ()  { default_handler(); }
WEAK void SAI1_IRQHandler               ()  { default_handler(); }
WEAK void LTDC_IRQHandler               ()  { default_handler(); }
WEAK void LTDC_ER_IRQHandler            ()  { default_handler(); }
WEAK void DMA2D_IRQHandler              ()  { default_handler(); }
WEAK void SAI2_IRQHandler               ()  { default_handler(); }
WEAK void QUADSPI_IRQHandler            ()  { default_handler(); }
WEAK void LPTIM1_IRQHandler             ()  { default_handler(); }
WEAK void CEC_IRQHandler                ()  { default_handler(); }
WEAK void I2C4_EV_IRQHandler            ()  { default_handler(); }
WEAK void I2C4_ER_IRQHandler            ()  { default_handler(); }
WEAK void SPDIF_RX_IRQHandler           ()  { default_handler(); }
WEAK void OTG_FS_EP1_OUT_IRQHandler     ()  { default_handler(); }
WEAK void OTG_FS_EP1_IN_IRQHandler      ()  { default_handler(); }
WEAK void OTG_FS_WKUP_IRQHandler        ()  { default_handler(); }
WEAK void OTG_FS_IRQHandler             ()  { default_handler(); }
WEAK void DMAMUX1_OVR_IRQHandler        ()  { default_handler(); }
WEAK void HRTIM1_Master_IRQHandler      ()  { default_handler(); }
WEAK void HRTIM1_TIMA_IRQHandler        ()  { default_handler(); }
WEAK void HRTIM1_TIMB_IRQHandler        ()  { default_handler(); }
WEAK void HRTIM1_TIMC_IRQHandler        ()  { default_handler(); }
WEAK void HRTIM1_TIMD_IRQHandler        ()  { default_handler(); }
WEAK void HRTIM1_TIME_IRQHandler        ()  { default_handler(); }
WEAK void HRTIM1_FLT_IRQHandler         ()  { default_handler(); }
WEAK void DFSDM1_FLT0_IRQHandler        ()  { default_handler(); }
WEAK void DFSDM1_FLT1_IRQHandler        ()  { default_handler(); }
WEAK void DFSDM1_FLT2_IRQHandler        ()  { default_handler(); }
WEAK void DFSDM1_FLT3_IRQHandler        ()  { default_handler(); }
WEAK void SAI3_IRQHandler               ()  { default_handler(); }
WEAK void SWPMI1_IRQHandler             ()  { default_handler(); }
WEAK void TIM15_IRQHandler              ()  { default_handler(); }
WEAK void TIM16_IRQHandler              ()  { default_handler(); }
WEAK void TIM17_IRQHandler              ()  { default_handler(); }
WEAK void MDIOS_WKUP_IRQHandler         ()  { default_handler(); }
WEAK void MDIOS_IRQHandler              ()  { default_handler(); }
WEAK void JPEG_IRQHandler               ()  { default_handler(); }
WEAK void MDMA_IRQHandler               ()  { default_handler(); }
WEAK void SDMMC2_IRQHandler             ()  { default_handler(); }
WEAK void HSEM1_IRQHandler              ()  { default_handler(); }
WEAK void HSEM2_IRQHandler              ()  { default_handler(); }
WEAK void ADC3_IRQHandler               ()  { default_handler(); }
WEAK void DMAMUX2_OVR_IRQHandler        ()  { default_handler(); }
WEAK void BDMA_Channel0_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel1_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel2_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel3_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel4_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel5_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel6_IRQHandler      ()  { default_handler(); }
WEAK void BDMA_Channel7_IRQHandler      ()  { default_handler(); }
WEAK void COMP1_IRQHandler              ()  { default_handler(); }
WEAK void LPTIM2_IRQHandler             ()  { default_handler(); }
WEAK void LPTIM3_IRQHandler             ()  { default_handler(); }
WEAK void LPTIM4_IRQHandler             ()  { default_handler(); }
WEAK void LPTIM5_IRQHandler             ()  { default_handler(); }
WEAK void LPUART1_IRQHandler            ()  { default_handler(); }
WEAK void WWDG_RST_IRQHandler           ()  { default_handler(); }
WEAK void CRS_IRQHandler                ()  { default_handler(); }
WEAK void ECC_IRQHandler                ()  { default_handler(); }
WEAK void SAI4_IRQHandler               ()  { default_handler(); }
WEAK void HOLD_CORE_IRQHandler          ()  { default_handler(); }
WEAK void WAKEUP_PIN_IRQHandler         ()  { default_handler(); }

#endif // NDEBUG
//------------------------------------------------------------------------------
