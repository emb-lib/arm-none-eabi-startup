//******************************************************************************
//*
//*      EFM32WG exception/intrrupt handlers stuff header file
//*
//*      Version 1.0
//*
//*      Copyright (c) 2016, emb-lib Project Team
//*
//------------------------------------------------------------------------------


#ifndef EXHANDLER_H
#define EXHANDLER_H

//------------------------------------------------------------------------------
//
//   Weak attribute allows to replace default handler with the user's one
//
#define WEAK __attribute__ ((weak))
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
extern unsigned long __top_of_stack[];

//------------------------------------------------------------------------------
//
//   Vector table item. Can be pointer to function or plain address value
//
typedef void (*intfun_t)();
typedef union
{
    intfun_t intfun;
    void *__ptr;
}
intvec_item_t;

//------------------------------------------------------------------------------
//
//   Startup handler
//
void Reset_Handler();

//------------------------------------------------------------------------------
//
//   Cortex-M internal exceptions
//
WEAK void NMI_Handler();
WEAK void HardFault_Handler();
WEAK void MemManage_Handler();
WEAK void BusFault_Handler();
WEAK void UsageFault_Handler();
WEAK void SVC_Handler();
WEAK void DebugMon_Handler();
WEAK void PendSV_Handler();
WEAK void SysTick_Handler();

//------------------------------------------------------------------------------
//
//   Controller specific peripheral interrupts
//
WEAK void DMA_IRQHandler();
WEAK void GPIO_EVEN_IRQHandler();
WEAK void TIMER0_IRQHandler();
WEAK void USART0_RX_IRQHandler();
WEAK void USART0_TX_IRQHandler();
WEAK void USB_IRQHandler();
WEAK void ACMP0_IRQHandler();
WEAK void ADC0_IRQHandler();
WEAK void DAC0_IRQHandler();
WEAK void I2C0_IRQHandler();
WEAK void I2C1_IRQHandler();
WEAK void GPIO_ODD_IRQHandler();
WEAK void TIMER1_IRQHandler();
WEAK void TIMER2_IRQHandler();
WEAK void TIMER3_IRQHandler();
WEAK void USART1_RX_IRQHandler();
WEAK void USART1_TX_IRQHandler();
WEAK void LESENSE_IRQHandler();
WEAK void USART2_RX_IRQHandler();
WEAK void USART2_TX_IRQHandler();
WEAK void UART0_RX_IRQHandler();
WEAK void UART0_TX_IRQHandler();
WEAK void UART1_RX_IRQHandler();
WEAK void UART1_TX_IRQHandler();
WEAK void LEUART0_IRQHandler();
WEAK void LEUART1_IRQHandler();
WEAK void LETIMER0_IRQHandler();
WEAK void PCNT0_IRQHandler();
WEAK void PCNT1_IRQHandler();
WEAK void PCNT2_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void BURTC_IRQHandler();
WEAK void CMU_IRQHandler();
WEAK void VCMP_IRQHandler();
WEAK void LCD_IRQHandler();
WEAK void MSC_IRQHandler();
WEAK void AES_IRQHandler();
WEAK void EBI_IRQHandler();
WEAK void EMU_IRQHandler();
WEAK void FPUEH_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
