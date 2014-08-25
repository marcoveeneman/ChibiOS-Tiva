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
void tiva_clock_init(void)
{
#if 0
  uint32_t moscctl, rsclkcfg, pllfreq0;

  // read current register value
  moscctl = SYSCTL->MOSCCTL;

  //clear moscpowerdown, highosc, nocrystalpresend
  moscctl &= ~(MOSCCTL_OSCRNG | MOSCCTL_PWRDN | MOSCCTL_NOXTAL);

  // if fmosc > 10mhz set high osc setting
  moscctl|= MOSCCTL_OSCRNG;   // high osc setting

  // write new register value
  SYSCTL->MOSCCTL = moscctl;

//-----------------------------------------

  //set memory timings for maximum external frequency (25MHz)
  SYSCTL->MEMTIM0 = (MEMTIM0_FBCHT_0_5 | MEMTIM0_FBCE | MEMTIM0_FWS_1 |
                      MEMTIM0_EBCHT_0_5 | MEMTIM0_EBCE | MEMTIM0_EWS_1 | MEMTIM0_MB1);

  // read current register value
  rsclkcfg = SYSCTL->RSCLKCFG;

  // clear old pll divider and source in case it was set
  rsclkcfg &= ~(RSCLKCFG_PSYSDIV_bm | RSCLKCFG_OSCSRC_bm | RSCLKCFG_PLLSRC_bm | RSCLKCFG_USEPLL);

  // update memory timings
  rsclkcfg |= RSCLKCFG_MEMTIMU;

  // set new register value, switch back to piosc
  SYSCTL->RSCLKCFG = rsclkcfg;

//-------------------------------------------
  // new pll settings

  // set osc source
  SYSCTL->RSCLKCFG |= (RSCLKCFG_OSCSRC_MOSC | RSCLKCFG_PLLSRC_MOSC);  // set osc and pll source to mosc

  SYSCTL->PLLFREQ1 = (0x04 << 0); // 5 - 1
  SYSCTL->PLLFREQ0 = (0x60 << 0) | PLLFREQ0_PLLPWR;

//----------------------------------------------
  // new memory timing
  SYSCTL->MEMTIM0 = (MEMTIM0_FBCHT_3_5 | MEMTIM0_FWS_5 | MEMTIM0_EBCHT_3_5 | MEMTIM0_EWS_5 | MEMTIM0_MB1);

  SYSCTL->RSCLKCFG |= RSCLKCFG_NEWFREQ;

  //while (!SYSCTL->PLLSTAT & PLLSTAT_LOCK);

  rsclkcfg = SYSCTL->RSCLKCFG;

  rsclkcfg |= (RSCLKCFG_USEPLL | (0x03 << 0) | (0x03 << 20) | (0x03 << 24));

  //rsclkcfg |= ((0x03 << 0) | (1 << 28) | (0x03 << 20));

  rsclkcfg |= RSCLKCFG_MEMTIMU;

  // set new configuration
  SYSCTL->RSCLKCFG = rsclkcfg;
#else
  uint32_t moscctl, rsclkcfg;

  /*
   * 1. Once POR has completed, the PIOSC is acting as the system clock.
   */

  /*
   * 2. Power up the MOSC by clearing the NOXTAL bit in the MOSCCTL register.
   */
  moscctl = SYSCTL->MOSCCTL;
  moscctl &= ~MOSCCTL_NOXTAL;

  /*
   * 3. If single-ended MOSC mode is required, the MOSC is ready to use. If crystal mode is required,
   * clear the PWRDN bit and wait for the MOSCPUPRIS bit to be set in the Raw Interrupt Status
   * (RIS), indicating MOSC crystal mode is ready.
   */
#if defined(MOSC_SINGLE_ENDED)
  SYSCTL->MOSCCTL = moscctl;
#else
  moscctl &= ~MOSCCTL_PWRDN;
  SYSCTL->MOSCCTL = moscctl;

  while (!(SYSCTL->RIS & SYSCTL_RIS_MOSCPUPRIS));
#endif

  /*
   * 4. Set the OSCSRC field to 0x3 in the RSCLKCFG register at offset 0x0B0.
   */
  rsclkcfg = SYSCTL->RSCLKCFG;

  rsclkcfg |= RSCLKCFG_OSCSRC_MOSC;

  /*
   * 5. If the application also requires the MOSC to be the deep-sleep clock source, then program the
   * DSOSCSRC field in the DSCLKCFG register to 0x3.
   */

  /*
   * 6. Write the PLLFREQ0 and PLLFREQ1 registers with the values of Q, N, MINT, and MFRAC to
   * the configure the desired VCO frequency setting.
   */
  SYSCTL->PLLFREQ1 = (0x04 << 0); // 5 - 1
  SYSCTL->PLLFREQ0 = (0x60 << 0) | PLLFREQ0_PLLPWR;

  /*
   * 7. Write the MEMTIM0 register to correspond to the new system clock setting.
   */
  SYSCTL->MEMTIM0 = (MEMTIM0_FBCHT_3_5 | MEMTIM0_FWS_5 | MEMTIM0_EBCHT_3_5 | MEMTIM0_EWS_5 | MEMTIM0_MB1);

  /*
   * Wait for the PLLSTAT register to indicate the PLL has reached lock at the new operating point
   * (or that a timeout period has passed and lock has failed, in which case an error condition exists
   * and this sequence is abandoned and error processing is initiated).
   */
  while (!SYSCTL->PLLSTAT & PLLSTAT_LOCK);

  /*
   * 9. Write the RSCLKCFG register's PSYSDIV value, set the USEPLL bit to enabled, and MEMTIMU
   * bit.
   */

  rsclkcfg = SYSCTL->RSCLKCFG;

  rsclkcfg |= (RSCLKCFG_USEPLL | (0x03 << 0) | (0x03 << 20) | (0x03 << 24));

  //rsclkcfg |= ((0x03 << 0) | (1 << 28) | (0x03 << 20));

  rsclkcfg |= RSCLKCFG_MEMTIMU;

  // set new configuration
  SYSCTL->RSCLKCFG = rsclkcfg;

#endif
  //

  /* 1. Once POR has completed, the PIOSC is acting as the system clock. */


  /* 2. Power up the MOSC by clearing the NOXTAL bit in the MOSCCTL register. */
//  moscctl = SYSCTL->MOSCCTL;

//  moscctl &= ~(0x04);

  /* 3. If single-ended MOSC mode is required, the MOSC is ready to use.
   * If crystal mode is required, clear the PWRDN bit and wait for the
   *  MOSCPUPRIS bit to be set in the Raw Interrupt Status (RIS), indicating
   *  MOSC crystal mode is ready.
   */
//#if defined(MOSC_SINGLE_ENDED)
//  moscctl |= 0x08;                  // set
//#else /* MOSC_CRYSTAL */
//  moscctl &= ~(0x08);     // clear
//#endif

//  SYSCTL->MOSCCTL = moscctl;

  /* 4. Set the OSCSRC field to 0x3 in the RSCLKCFG register at offset 0x0B0. */
//  SYSCTL->RSCLKCFG = (0x03 << 20);

  /* 5. If the application also requires the MOSC to be the deep-sleep clock
   *  source, then program the DSOSCSRC field in the DSCLKCFG register to 0x3.
   */
////  SYSCTL->DSCLKCFG = 0;

  /* 6. Write the PLLFREQ0 and PLLFREQ1 registers with the values of Q, N,
   * MINT, and MFRAC to the configure the desired VCO frequency setting.
   */
  // q = 0, n = 4, mint = 0x60 mfraq = 0
  // fvco = 480 MHz
//  pllfreq0 = SYSCTL->PLLFREQ0;
//  pllfreq1 = SYSCTL->PLLFREQ1;

//  pllfreq0 |= 0x60; // mfraq, mint
//  pllfreq1 |= 0x04; // q, n

//  SYSCTL->PLLFREQ0 = pllfreq0;
//  SYSCTL->PLLFREQ1 = pllfreq1;

  /* 7. Write the MEMTIM0 register to correspond to the new system clock setting. */
//  SYSCTL->MEMTIM0 |= 0x06 << 22;
//  SYSCTL->MEMTIM0 &= ~(0x01 << 21);
//  SYSCTL->MEMTIM0 |= 0x05 << 22;

//  SYSCTL->MEMTIM0 |= 0x06 << 6;
//  SYSCTL->MEMTIM0 &= ~(0x01 << 5);
//  SYSCTL->MEMTIM0 |= 0x05 << 0;

  /* 8. Wait for the PLLSTAT register to indicate the PLL has reached lock at
   * the new operating point (or that a timeout period has passed and lock has
   * failed, in which case an error condition exists and this sequence is
   * abandoned and error processing is initiated).
   */
//  while (!(SYSCTL->PLLSTAT & 0x01));

  /* 9. Write the RSCLKCFG register's PSYSDIV value, set the USEPLL bit to
   * enabled, and MEMTIMU bit.
   */
//  rsclkcfg = SYSCTL->RSCLKCFG;

//  rsclkcfg |= (1 << 31); // MEMTIMU
//  rsclkcfg |= (1 << 28); // USEPLL
//  rsclkcfg |= (1 << 30); // NEWFREQ
//  rsclkcfg |= (4 << 0); // PSYSDIV
//  rsclkcfg |= (3 << 24); // PLLSRC

//  SYSCTL->RSCLKCFG = rsclkcfg;
}

/**
 * @}
 */
