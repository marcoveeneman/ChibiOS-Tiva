/*
    Copyright (C) 2014 Marco Veeneman

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    TM4C123x/tiva_isr.h
 * @brief   TM4C123x ISR remapper driver header.
 *
 * @addtogroup TM4C123x_ISR
 * @{
 */

#ifndef _TIVA_ISR_H_
#define _TIVA_ISR_H_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */

/*
 * UART units.
 */
#define TIVA_UART0_HANDLER                  Vector54
#define TIVA_UART1_HANDLER                  Vector58
#define TIVA_UART2_HANDLER                  VectorC4
#define TIVA_UART3_HANDLER                  Vector12C
#define TIVA_UART4_HANDLER                  Vector130
#define TIVA_UART5_HANDLER                  Vector134
#define TIVA_UART6_HANDLER                  Vector138
#define TIVA_UART7_HANDLER                  Vector13C

#define TIVA_UART0_NUMBER                   5
#define TIVA_UART1_NUMBER                   6
#define TIVA_UART2_NUMBER                   33
#define TIVA_UART3_NUMBER                   59
#define TIVA_UART4_NUMBER                   60
#define TIVA_UART5_NUMBER                   61
#define TIVA_UART6_NUMBER                   62
#define TIVA_UART7_NUMBER                   63

/*
 * Timer units.
 */
#define TIVA_GPT0A_HANDLER                   Vector8C
#define TIVA_GPT0B_HANDLER                   Vector90
#define TIVA_GPT1A_HANDLER                   Vector94
#define TIVA_GPT1B_HANDLER                   Vector98
#define TIVA_GPT2A_HANDLER                   Vector9C
#define TIVA_GPT2B_HANDLER                   VectorA0
#define TIVA_GPT3A_HANDLER                   VectorCC
#define TIVA_GPT3B_HANDLER                   VectorD0
#define TIVA_GPT4A_HANDLER                   Vector158
#define TIVA_GPT4B_HANDLER                   Vector15C
#define TIVA_GPT5A_HANDLER                   Vector1B0
#define TIVA_GPT5B_HANDLER                   Vector1B4

#define TIVA_GPT0A_NUMBER                    19
#define TIVA_GPT0B_NUMBER                    20
#define TIVA_GPT1A_NUMBER                    21
#define TIVA_GPT1B_NUMBER                    22
#define TIVA_GPT2A_NUMBER                    23
#define TIVA_GPT2B_NUMBER                    24
#define TIVA_GPT3A_NUMBER                    35
#define TIVA_GPT3B_NUMBER                    36
#define TIVA_GPT4A_NUMBER                    70
#define TIVA_GPT4B_NUMBER                    71
#define TIVA_GPT5A_NUMBER                    92
#define TIVA_GPT5B_NUMBER                    93

#define TIVA_WGPT0A_HANDLER                  Vector1B8
#define TIVA_WGPT0B_HANDLER                  Vector1BC
#define TIVA_WGPT1A_HANDLER                  Vector1C0
#define TIVA_WGPT1B_HANDLER                  Vector1C4
#define TIVA_WGPT2A_HANDLER                  Vector1C8
#define TIVA_WGPT2B_HANDLER                  Vector1CC
#define TIVA_WGPT3A_HANDLER                  Vector1D0
#define TIVA_WGPT3B_HANDLER                  Vector1D4
#define TIVA_WGPT4A_HANDLER                  Vector1D8
#define TIVA_WGPT4B_HANDLER                  Vector1DC
#define TIVA_WGPT5A_HANDLER                  Vector1E0
#define TIVA_WGPT5B_HANDLER                  Vector1E4

#define TIVA_WGPT0A_NUMBER                   94
#define TIVA_WGPT0B_NUMBER                   95
#define TIVA_WGPT1A_NUMBER                   96
#define TIVA_WGPT1B_NUMBER                   97
#define TIVA_WGPT2A_NUMBER                   98
#define TIVA_WGPT2B_NUMBER                   99
#define TIVA_WGPT3A_NUMBER                   100
#define TIVA_WGPT3B_NUMBER                   101
#define TIVA_WGPT4A_NUMBER                   102
#define TIVA_WGPT4B_NUMBER                   103
#define TIVA_WGPT5A_NUMBER                   104
#define TIVA_WGPT5B_NUMBER                   105

/**
 * @}
 */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#endif /* _TIVA_ISR_H_ */

/**
 * @}
 */
