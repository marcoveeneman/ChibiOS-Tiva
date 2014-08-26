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
