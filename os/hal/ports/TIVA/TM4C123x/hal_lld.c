/**
 * @file    Tiva/TM4C123x/hal_lld.c
 * @brief   TM4C123x HAL Driver subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void)
{
}

/**
 * @brief   TM4C123x clocks and PLL initialization.
 * @note    All the involved constants come from the file @p board.h and 
 *          @p mcuconf.h.
 * @note    This function should be invoked just after the system reset.
 *
 * @special
 */
void tiva_clock_init(void) {
  uint32_t rcc, rcc2, i;

  /* 1. Bypass the PLL and system clock divider by setting the BYPASS bit and
   * clearing the USESYSDIV bit in the RCC register, thereby configuring the
   * microcontroller to run off a "raw" clock source and allowing for the new
   * PLL configuration to be validated before switching the system clock to the
   * PLL. */
  /* read */
  rcc = SYSCTL->RCC;
  rcc2 = SYSCTL->RCC2;
  
  /* modify */
  rcc |= TIVA_RCC_BYPASS;
  rcc &= ~TIVA_RCC_USESYSDIV;
  rcc2 |= TIVA_RCC2_BYPASS2 | TIVA_RCC2_USERCC2;
  
  /* write */
  SYSCTL->RCC = rcc;
  SYSCTL->RCC2 = rcc2;

  /* 2 Select the crystal value (XTAL) and oscillator source (OSCSRC), and
   * clear the PWRDN bit in RCC and RCC2. Setting the XTAL field automatically
   * pulls valid PLL configuration data for the appropriate crystal, and
   * clearing the PWRDN bit powers and enables the PLL and its output. */
  /* modify */
  rcc &= ~(TIVA_RCC_OSCSRC_MASK | TIVA_RCC_XTAL_MASK | TIVA_RCC_PWRDN | TIVA_RCC_MOSCDIS);
  rcc |= ((TIVA_XTAL | TIVA_OSCSRC | TIVA_MOSCDIS) & (TIVA_RCC_XTAL_MASK | TIVA_RCC_OSCSRC_MASK | TIVA_RCC_MOSCDIS));
  rcc2 &= ~(TIVA_RCC2_OSCSRC2_MASK | TIVA_RCC2_PWRDN2);
  rcc2 |= ((TIVA_OSCSRC | TIVA_DIV400) & (TIVA_RCC2_OSCSRC2_MASK | TIVA_RCC2_DIV400));
  
  /* write */
  SYSCTL->RCC = rcc;
  SYSCTL->RCC2 = rcc2;
  for(i = 100000; i; i--);

  /* 3. Select the desired system divider (SYSDIV) in RCC and RCC2 and set the
   * USESYSDIV bit in RCC. The SYSDIV field determines the system frequency for
   * the microcontroller. */
  /* modify */
  rcc &= ~TIVA_RCC_SYSDIV_MASK;
  rcc |= (TIVA_SYSDIV & TIVA_RCC_SYSDIV_MASK) | TIVA_USESYSDIV;
  rcc2 &= ~(TIVA_RCC2_SYSDIV2_MASK | TIVA_RCC2_SYSDIV2LSB);
  rcc2 |= ((TIVA_SYSDIV2 | TIVA_SYSDIV2LSB) & (TIVA_RCC2_SYSDIV2_MASK | TIVA_RCC2_SYSDIV2LSB));
  
  /* write */
  SYSCTL->RCC = rcc;
  SYSCTL->RCC2 = rcc2;

  /* 4. Wait for the PLL to lock by polling the PLLLRIS bit in the Raw
   * Interrupt Status (RIS) register. */
  while ((SYSCTL->RIS & SYSCTL_RIS_PLLLRIS) == 0);

  /* 5. Enable use of the PLL by clearing the BYPASS bit in RCC and RCC2. */
  rcc &= ~TIVA_RCC_BYPASS;
  rcc2 &= ~TIVA_RCC2_BYPASS2;
  rcc |= TIVA_BYPASS;
  rcc2 |= TIVA_BYPASS;
  SYSCTL->RCC = rcc;
  SYSCTL->RCC2 = rcc2;
}

/**
 * @}
 */
