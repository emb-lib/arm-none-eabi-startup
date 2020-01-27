//******************************************************************************
//*
//*      EFR32FG12P exception/intrrupt handlers stuff header file
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
    intfun_t      vectors[66];
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
WEAK void EMU_IRQHandler();
WEAK void FRC_PRI_IRQHandler();
WEAK void WDOG0_IRQHandler();
WEAK void WDOG1_IRQHandler();
WEAK void FRC_IRQHandler();
WEAK void MODEM_IRQHandler();
WEAK void RAC_SEQ_IRQHandler();
WEAK void RAC_RSM_IRQHandler();
WEAK void BUFC_IRQHandler();
WEAK void LDMA_IRQHandler();
WEAK void GPIO_EVEN_IRQHandler();
WEAK void TIMER0_IRQHandler();
WEAK void USART0_RX_IRQHandler();
WEAK void USART0_TX_IRQHandler();
WEAK void ACMP0_IRQHandler();
WEAK void ADC0_IRQHandler();
WEAK void IDAC0_IRQHandler();
WEAK void I2C0_IRQHandler();
WEAK void GPIO_ODD_IRQHandler();
WEAK void TIMER1_IRQHandler();
WEAK void USART1_RX_IRQHandler();
WEAK void USART1_TX_IRQHandler();
WEAK void LEUART0_IRQHandler();
WEAK void PCNT0_IRQHandler();
WEAK void CMU_IRQHandler();
WEAK void MSC_IRQHandler();
WEAK void CRYPTO0_IRQHandler();
WEAK void LETIMER0_IRQHandler();
WEAK void AGC_IRQHandler();
WEAK void PROTIMER_IRQHandler();
WEAK void RTCC_IRQHandler();
WEAK void SYNTH_IRQHandler();
WEAK void CRYOTIMER_IRQHandler();
WEAK void RFSENSE_IRQHandler();
WEAK void FPUEH_IRQHandler();
WEAK void SMU_IRQHandler();
WEAK void WTIMER0_IRQHandler();
WEAK void WTIMER1_IRQHandler();
WEAK void PCNT1_IRQHandler();
WEAK void PCNT2_IRQHandler();
WEAK void USART2_RX_IRQHandler();
WEAK void USART2_TX_IRQHandler();
WEAK void I2C1_IRQHandler();
WEAK void USART3_RX_IRQHandler();
WEAK void USART3_TX_IRQHandler();
WEAK void VDAC0_IRQHandler();
WEAK void CSEN_IRQHandler();
WEAK void LESENSE_IRQHandler();
WEAK void CRYPTO1_IRQHandler();
WEAK void TRNG0_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
