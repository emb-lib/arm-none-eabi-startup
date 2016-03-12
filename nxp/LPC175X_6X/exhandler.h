//******************************************************************************
//*
//*      LPC175X_6X exception/intrrupt handlers stuff header file
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
WEAK void WDT_IRQHandler();
WEAK void TIMER0_IRQHandler();
WEAK void TIMER1_IRQHandler();
WEAK void TIMER2_IRQHandler();
WEAK void TIMER3_IRQHandler();
WEAK void UART0_IRQHandler();
WEAK void UART1_IRQHandler();
WEAK void UART2_IRQHandler();
WEAK void UART3_IRQHandler();
WEAK void PWM1_IRQHandler();
WEAK void I2C0_IRQHandler();
WEAK void I2C1_IRQHandler();
WEAK void I2C2_IRQHandler();
WEAK void SPI_IRQHandler();
WEAK void SSP0_IRQHandler();
WEAK void SSP1_IRQHandler();
WEAK void PLL0_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void EINT0_IRQHandler();
WEAK void EINT1_IRQHandler();
WEAK void EINT2_IRQHandler();
WEAK void EINT3_IRQHandler();
WEAK void ADC_IRQHandler();
WEAK void BOD_IRQHandler();
WEAK void USB_IRQHandler();
WEAK void CAN_IRQHandler();
WEAK void DMA_IRQHandler();
WEAK void I2S_IRQHandler();
WEAK void ETH_IRQHandler();
WEAK void RIT_IRQHandler();
WEAK void MCPWM_IRQHandler();
WEAK void QEI_IRQHandler();
WEAK void PLL1_IRQHandler();
WEAK void USBActivity_IRQHandler();
WEAK void CANActivity_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
