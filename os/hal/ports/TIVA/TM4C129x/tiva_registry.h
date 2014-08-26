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
 * @file    TM4C129x/tiva_registry.h
 * @brief   TM4C123x capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef _TIVA_REGISTRY_H_
#define _TIVA_REGISTRY_H_

/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/**
 * @name    TM4C129x capabilities
 * @{
 */
 
/* GPIO attributes.*/
#define TIVA_HAS_GPIOA                      TRUE
#define TIVA_HAS_GPIOB                      TRUE
#define TIVA_HAS_GPIOC                      TRUE
#define TIVA_HAS_GPIOD                      TRUE
#define TIVA_HAS_GPIOE                      TRUE
#define TIVA_HAS_GPIOF                      TRUE
#define TIVA_HAS_GPIOG                      TRUE
#define TIVA_HAS_GPIOH                      TRUE
#define TIVA_HAS_GPIOJ                      TRUE
#define TIVA_HAS_GPIOK                      TRUE
#define TIVA_HAS_GPIOL                      TRUE
#define TIVA_HAS_GPIOM                      TRUE
#define TIVA_HAS_GPION                      TRUE
#define TIVA_HAS_GPIOP                      TRUE
#define TIVA_HAS_GPIOQ                      TRUE

/* UART attributes.*/
#define TIVA_HAS_UART0                      TRUE
#define TIVA_HAS_UART1                      TRUE
#define TIVA_HAS_UART2                      TRUE
#define TIVA_HAS_UART3                      TRUE
#define TIVA_HAS_UART4                      TRUE
#define TIVA_HAS_UART5                      TRUE
#define TIVA_HAS_UART6                      TRUE
#define TIVA_HAS_UART7                      TRUE

/**
 * @}
 */

#endif /* _TIVA_REGISTRY_H_ */

/**
 * @}
 */
