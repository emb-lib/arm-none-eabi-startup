//******************************************************************************
//*
//*      LPC11U6X exception/intrrupt handlers stuff header file
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
WEAK void PIN_INT0_IRQHandler();
WEAK void PIN_INT1_IRQHandler();
WEAK void PIN_INT2_IRQHandler();
WEAK void PIN_INT3_IRQHandler();
WEAK void PIN_INT4_IRQHandler();
WEAK void PIN_INT5_IRQHandler();
WEAK void PIN_INT6_IRQHandler();
WEAK void PIN_INT7_IRQHandler();
WEAK void GINT0_IRQHandler();
WEAK void GINT1_IRQHandler();
WEAK void I2C1_IRQHandler();
WEAK void USART1_4_IRQHandler();
WEAK void USART2_3_IRQHandler();
WEAK void SCT0_1_IRQHandler();
WEAK void SSP1_IRQHandler();
WEAK void I2C0_IRQHandler();
WEAK void CT16B0_IRQHandler();
WEAK void CT16B1_IRQHandler();
WEAK void CT32B0_IRQHandler();
WEAK void CT32B1_IRQHandler();
WEAK void SSP0_IRQHandler();
WEAK void USART0_IRQHandler();
WEAK void USB_IRQHandler();
WEAK void USB_FIQ_IRQHandler();
WEAK void ADC_A_IRQHandler();
WEAK void RTC_IRQHandler();
WEAK void BOD_WDT_IRQHandler();
WEAK void FLASH_IRQHandler();
WEAK void DMA_IRQHandler();
WEAK void ADC_B_IRQHandler();
WEAK void USBWAKEUP_IRQHandler();
//------------------------------------------------------------------------------

#endif // EXHANDLER_H

//------------------------------------------------------------------------------
