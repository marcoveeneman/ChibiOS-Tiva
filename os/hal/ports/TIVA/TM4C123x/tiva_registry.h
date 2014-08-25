/**
 * @file    TM4C123x/tiva_registry.h
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
 * @name    TM4C123x capabilities
 * @{
 */
 
/* GPIO attributes.*/
#define TIVA_HAS_GPIOA                      TRUE
#define TIVA_HAS_GPIOB                      TRUE
#define TIVA_HAS_GPIOC                      TRUE
#define TIVA_HAS_GPIOD                      TRUE
#define TIVA_HAS_GPIOE                      TRUE
#define TIVA_HAS_GPIOF                      TRUE
#define TIVA_HAS_GPIOG                      FALSE
#define TIVA_HAS_GPIOH                      FALSE
#define TIVA_HAS_GPIOJ                      FALSE
#define TIVA_HAS_GPIOK                      FALSE
#define TIVA_HAS_GPIOL                      FALSE
#define TIVA_HAS_GPIOM                      FALSE
#define TIVA_HAS_GPION                      FALSE
#define TIVA_HAS_GPIOP                      FALSE
#define TIVA_HAS_GPIOQ                      FALSE

/* UART attributes.*/
#define TIVA_HAS_UART0                      TRUE
#define TIVA_HAS_UART1                      TRUE
#define TIVA_HAS_UART2                      TRUE
#define TIVA_HAS_UART3                      TRUE
#define TIVA_HAS_UART4                      TRUE
#define TIVA_HAS_UART5                      TRUE
#define TIVA_HAS_UART6                      TRUE
#define TIVA_HAS_UART7                      TRUE

/* GPT attributes.*/
#define TIVA_HAS_GPT0                       TRUE
#define TIVA_HAS_GPT1                       TRUE
#define TIVA_HAS_GPT2                       TRUE
#define TIVA_HAS_GPT3                       TRUE
#define TIVA_HAS_GPT4                       TRUE
#define TIVA_HAS_GPT5                       TRUE

/* WGPT attributes.*/
#define TIVA_HAS_WGPT0                      TRUE
#define TIVA_HAS_WGPT1                      TRUE
#define TIVA_HAS_WGPT2                      TRUE
#define TIVA_HAS_WGPT3                      TRUE
#define TIVA_HAS_WGPT4                      TRUE
#define TIVA_HAS_WGPT5                      TRUE

/**
 * @}
 */

#endif /* _TIVA_REGISTRY_H_ */

/**
 * @}
 */
