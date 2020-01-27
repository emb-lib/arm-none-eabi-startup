//******************************************************************************
//*
//*      LPC4337 exception/intrrupt handlers stuff header file
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
typedef struct
{
    unsigned long *tos;
    intfun_t      vectors[68];
}
__vector_table_t;

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
WEAK void DAC_IRQHandler();
WEAK void MX_CORE_IRQHandler();
WEAK void DMA_IRQHandler();
WEAK void UnHandled_Vector();
WEAK void FLASHEEPROM_IRQHandler();
WEAK void ETH_IRQHandler();
WEAK void SDIO_IRQHandler();
WEAK void LCD_IRQHandler();
WEAK void USB0_IRQHandler();
WEAK void USB1_IRQHandler();
WEAK void SCT_IRQHandler();
WEAK void RIT_IRQHandler();
WEAK void TIMER0_IRQHandler();
WEAK void TIMER1_IRQHandler();
WEAK void TIMER2_IRQHandler();
WEAK void TIMER3_IRQHandler();
WEAK void MCPWM_IRQHandler();
WEAK void ADC0_IRQHandler();
WEAK void I2C0_IRQHandler();
WEAK void I2C1_IRQHandler();
WEAK void SPI_IRQHandler();
WEAK void ADC1_IRQHandler();
WEAK void SSP0_IRQHandler();
WEAK void SSP1_IRQHandler();
WEAK void UART0_IRQHandler();
WEAK void UART1_IRQHandler();
WEAK void UART2_IRQHandler();
WEAK void UART3_IRQHandler();
WEAK void I2S0_IRQHandler();
WEAK void I2S1_IRQHandler();
WEAK void SPIFI_IRQHandler();
WEAK void SGPIO_IRQHandler();
WEAK void GPIO0_IRQHandler();
WEAK void GPIO1_IRQHandler();
WEAK void GPIO2_IRQHandler();
WEAK void GPIO3_IRQHandler();
WEAK void GPIO4_IRQHandler();
WEAK void GPIO5_IRQHandler();
WEAK void GPIO6_IRQHandler();
WEAK void GPIO7_IRQHandler();
WEAK void GINT0_IRQHandler();
WEAK void GINT1_IRQHandler();
WEAK void EVRT_IRQHandler();
WEAK void CAN1_IRQHandler();
WEAK void UnHandled_Vector();
WEAK void VADC_IRQHandler();
WEAK void ATIMER_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void UnHandled_Vector();
WEAK void WDT_IRQHandler();
WEAK void UnHandled_Vector();
WEAK void CAN0_IRQHandler();
WEAK void QEI_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
