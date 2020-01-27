//******************************************************************************
//*
//*      LPC11XX exception/intrrupt handlers stuff header file
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
    intfun_t      vectors[47];
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
WEAK void SLWU_INT0_IRQHandler();
WEAK void SLWU_INT1_IRQHandler();
WEAK void SLWU_INT2_IRQHandler();
WEAK void SLWU_INT3_IRQHandler();
WEAK void SLWU_INT4_IRQHandler();
WEAK void SLWU_INT5_IRQHandler();
WEAK void SLWU_INT6_IRQHandler();
WEAK void SLWU_INT7_IRQHandler();
WEAK void SLWU_INT8_IRQHandler();
WEAK void SLWU_INT9_IRQHandler();
WEAK void SLWU_INT10_IRQHandler();
WEAK void SLWU_INT11_IRQHandler();
WEAK void SLWU_INT12_IRQHandler();
WEAK void C_CAN_IRQHandler();
WEAK void SSP1_IRQHandler();
WEAK void I2C_IRQHandler();
WEAK void TIMER16_0_IRQHandler();
WEAK void TIMER16_1_IRQHandler();
WEAK void TIMER32_0_IRQHandler();
WEAK void TIMER32_1_IRQHandler();
WEAK void SSP0_IRQHandler();
WEAK void UART_IRQHandler();
WEAK void Reserved_IRQHandler();
WEAK void Reserved_IRQHandler();
WEAK void ADC_IRQHandler();
WEAK void WDT_IRQHandler();
WEAK void BOD_IRQHandler();
WEAK void Reserved_IRQHandler();
WEAK void PIO_3_IRQHandler();
WEAK void PIO_2_IRQHandler();
WEAK void PIO_1_IRQHandler();
WEAK void PIO_0_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
