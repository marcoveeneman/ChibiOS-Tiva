/**
 * @file    TM4C123/pal_lld.c
 * @brief   TM4C123 PAL subsystem low level driver.
 *
 * @addtogroup PAL
 * @{
 */

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

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
 * @brief   TM4C123x I/O ports configuration.
 * @details Ports A-F(G, H, J, K, L, M, N, P, Q) clocks enabled.
 *
 * @param[in] config    the TM4C123x ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config)
{
  SYSCTL->RCGCGPIO |= (1 << 0) |
                      (1 << 1) |
                      (1 << 2) |
                      (1 << 3) |
                      (1 << 4) |
                      (1 << 5);
                      
  __NOP();
  __NOP();
  __NOP();
  
  GPIOA->DATA = config->PAData.data;
  GPIOA->DIR = config->PAData.dir;
  GPIOA->AFSEL = config->PAData.afsel;
  GPIOA->DR2R = config->PAData.dr2r;
  GPIOA->DR4R = config->PAData.dr4r;
  GPIOA->DR8R = config->PAData.dr8r;
  GPIOA->ODR = config->PAData.odr;
  GPIOA->PUR = config->PAData.pur;
  GPIOA->PDR = config->PAData.pdr;
  GPIOA->SLR = config->PAData.slr;
  GPIOA->DEN = config->PAData.den;
  GPIOA->AMSEL = config->PAData.amsel;
  GPIOA->PCTL = config->PAData.pctl;
  
  GPIOB->DATA = config->PBData.data;
  GPIOB->DIR = config->PBData.dir;
  GPIOB->AFSEL = config->PBData.afsel;
  GPIOB->DR2R = config->PBData.dr2r;
  GPIOB->DR4R = config->PBData.dr4r;
  GPIOB->DR8R = config->PBData.dr8r;
  GPIOB->ODR = config->PBData.odr;
  GPIOB->PUR = config->PBData.pur;
  GPIOB->PDR = config->PBData.pdr;
  GPIOB->SLR = config->PBData.slr;
  GPIOB->DEN = config->PBData.den;
  GPIOB->AMSEL = config->PBData.amsel;
  GPIOB->PCTL = config->PBData.pctl;
  
  GPIOC->LOCK = TIVA_GPIO_LOCK_PWD;
  GPIOC->CR = 0x01;
  GPIOC->DATA = config->PCData.data;
  GPIOC->DIR = config->PCData.dir;
  GPIOC->AFSEL = config->PCData.afsel;
  GPIOC->DR2R = config->PCData.dr2r;
  GPIOC->DR4R = config->PCData.dr4r;
  GPIOC->DR8R = config->PCData.dr8r;
  GPIOC->ODR = config->PCData.odr;
  GPIOC->PUR = config->PCData.pur;
  GPIOC->PDR = config->PCData.pdr;
  GPIOC->SLR = config->PCData.slr;
  GPIOC->DEN = config->PCData.den;
  GPIOC->AMSEL = config->PCData.amsel;
  GPIOC->PCTL = config->PCData.pctl;
  GPIOF->LOCK = 0;
  
  GPIOD->DATA = config->PDData.data;
  GPIOD->DIR = config->PDData.dir;
  GPIOD->AFSEL = config->PDData.afsel;
  GPIOD->DR2R = config->PDData.dr2r;
  GPIOD->DR4R = config->PDData.dr4r;
  GPIOD->DR8R = config->PDData.dr8r;
  GPIOD->ODR = config->PDData.odr;
  GPIOD->PUR = config->PDData.pur;
  GPIOD->PDR = config->PDData.pdr;
  GPIOD->SLR = config->PDData.slr;
  GPIOD->DEN = config->PDData.den;
  GPIOD->AMSEL = config->PDData.amsel;
  GPIOD->PCTL = config->PDData.pctl;
  
  GPIOE->DATA = config->PEData.data;
  GPIOE->DIR = config->PEData.dir;
  GPIOE->AFSEL = config->PEData.afsel;
  GPIOE->DR2R = config->PEData.dr2r;
  GPIOE->DR4R = config->PEData.dr4r;
  GPIOE->DR8R = config->PEData.dr8r;
  GPIOE->ODR = config->PEData.odr;
  GPIOE->PUR = config->PEData.pur;
  GPIOE->PDR = config->PEData.pdr;
  GPIOE->SLR = config->PEData.slr;
  GPIOE->DEN = config->PEData.den;
  GPIOE->AMSEL = config->PEData.amsel;
  GPIOE->PCTL = config->PEData.pctl;
  
  GPIOF->LOCK = TIVA_GPIO_LOCK_PWD;
  GPIOF->CR = 0x01;
  GPIOF->DATA = config->PFData.data;
  GPIOF->DIR = config->PFData.dir;
  GPIOF->AFSEL = config->PFData.afsel;
  GPIOF->DR2R = config->PFData.dr2r;
  GPIOF->DR4R = config->PFData.dr4r;
  GPIOF->DR8R = config->PFData.dr8r;
  GPIOF->ODR = config->PFData.odr;
  GPIOF->PUR = config->PFData.pur;
  GPIOF->PDR = config->PFData.pdr;
  GPIOF->SLR = config->PFData.slr;
  GPIOF->DEN = config->PFData.den;
  GPIOF->AMSEL = config->PFData.amsel;
  GPIOF->PCTL = config->PFData.pctl;
  GPIOF->LOCK = 0;
  
#if TIVA_HAS_GPIOG || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 6);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOG->DATA = config->PGData.data;
  GPIOG->DIR = config->PGData.dir;
  GPIOG->AFSEL = config->PGData.afsel;
  GPIOG->DR2R = config->PGData.dr2r;
  GPIOG->DR4R = config->PGData.dr4r;
  GPIOG->DR8R = config->PGData.dr8r;
  GPIOG->ODR = config->PGData.odr;
  GPIOG->PUR = config->PGData.pur;
  GPIOG->PDR = config->PGData.pdr;
  GPIOG->SLR = config->PGData.slr;
  GPIOG->DEN = config->PGData.den;
  GPIOG->AMSEL = config->PGData.amsel;
  GPIOG->PCTL = config->PGData.pctl;
#endif /* TIVA_HAS_GPIOG.*/
  
#if TIVA_HAS_GPIOH || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 7);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOH->DATA = config->PHData.data;
  GPIOH->DIR = config->PHData.dir;
  GPIOH->AFSEL = config->PHData.afsel;
  GPIOH->DR2R = config->PHData.dr2r;
  GPIOH->DR4R = config->PHData.dr4r;
  GPIOH->DR8R = config->PHData.dr8r;
  GPIOH->ODR = config->PHData.odr;
  GPIOH->PUR = config->PHData.pur;
  GPIOH->PDR = config->PHData.pdr;
  GPIOH->SLR = config->PHData.slr;
  GPIOH->DEN = config->PHData.den;
  GPIOH->AMSEL = config->PHData.amsel;
  GPIOH->PCTL = config->PHData.pctl;
#endif /* TIVA_HAS_GPIOH.*/
  
#if TIVA_HAS_GPIOJ || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 8);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOJ->DATA = config->PJData.data;
  GPIOJ->DIR = config->PJData.dir;
  GPIOJ->AFSEL = config->PJData.afsel;
  GPIOJ->DR2R = config->PJData.dr2r;
  GPIOJ->DR4R = config->PJData.dr4r;
  GPIOJ->PUR = config->PJData.pur;
  GPIOJ->PDR = config->PJData.pdr;
  GPIOJ->SLR = config->PJData.slr;
  GPIOJ->DEN = config->PJData.den;
  GPIOJ->AMSEL = config->PJData.amsel;
  GPIOJ->PCTL = config->PJData.pctl;
#endif /* TIVA_HAS_GPIOJ.*/
  
#if TIVA_HAS_GPIOK || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 9);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOK->DATA = config->PKData.data;
  GPIOK->DIR = config->PKData.dir;
  GPIOK->AFSEL = config->PKData.afsel;
  GPIOK->DR2R = config->PKData.dr2r;
  GPIOK->DR4R = config->PKData.dr4r;
  GPIOK->DR8R = config->PKData.dr8r;
  GPIOK->ODR = config->PKData.odr;
  GPIOK->PUR = config->PKData.pur;
  GPIOK->PDR = config->PKData.pdr;
  GPIOK->SLR = config->PKData.slr;
  GPIOK->DEN = config->PKData.den;
  GPIOK->AMSEL = config->PKData.amsel;
  GPIOK->PCTL = config->PKData.pctl;
#endif /* TIVA_HAS_GPIOK.*/
  
#if TIVA_HAS_GPIOL || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 10);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOL->DATA = config->PLData.data;
  GPIOL->DIR = config->PLData.dir;
  GPIOL->AFSEL = config->PLData.afsel;
  GPIOL->DR2R = config->PLData.dr2r;
  GPIOL->DR4R = config->PLData.dr4r;
  GPIOL->DR8R = config->PLData.dr8r;
  GPIOL->ODR = config->PLData.odr;
  GPIOL->PUR = config->PLData.pur;
  GPIOL->PDR = config->PLData.pdr;
  GPIOL->SLR = config->PLData.slr;
  GPIOL->DEN = config->PLData.den;
  GPIOL->AMSEL = config->PLData.amsel;
  GPIOL->PCTL = config->PLData.pctl;
#endif /* TIVA_HAS_GPIOL.*/
  
#if TIVA_HAS_GPIOM || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 11);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOM->DATA = config->PMData.data;
  GPIOM->DIR = config->PMData.dir;
  GPIOM->AFSEL = config->PMData.afsel;
  GPIOM->DR2R = config->PMData.dr2r;
  GPIOM->DR4R = config->PMData.dr4r;
  GPIOM->DR8R = config->PMData.dr8r;
  GPIOM->ODR = config->PMData.odr;
  GPIOM->PUR = config->PMData.pur;
  GPIOM->PDR = config->PMData.pdr;
  GPIOM->SLR = config->PMData.slr;
  GPIOM->DEN = config->PMData.den;
  GPIOM->AMSEL = config->PMData.amsel;
  GPIOM->PCTL = config->PMData.pctl;
#endif /* TIVA_HAS_GPIOM.*/
  
#if TIVA_HAS_GPION || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 12);
  
  __NOP();
  __NOP();
  __NOP();

  GPION->DATA = config->PNData.data;
  GPION->DIR = config->PNData.dir;
  GPION->AFSEL = config->PNData.afsel;
  GPION->DR2R = config->PNData.dr2r;
  GPION->DR4R = config->PNData.dr4r;
  GPION->DR8R = config->PNData.dr8r;
  GPION->ODR = config->PNData.odr;
  GPION->PUR = config->PNData.pur;
  GPION->PDR = config->PNData.pdr;
  GPION->SLR = config->PNData.slr;
  GPION->DEN = config->PNData.den;
  GPION->AMSEL = config->PNData.amsel;
  GPION->PCTL = config->PNData.pctl;
#endif /* TIVA_HAS_GPION.*/
  
#if TIVA_HAS_GPIOP || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 13);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOP->DATA = config->PPData.data;
  GPIOP->DIR = config->PPData.dir;
  GPIOP->AFSEL = config->PPData.afsel;
  GPIOP->DR2R = config->PPData.dr2r;
  GPIOP->DR4R = config->PPData.dr4r;
  GPIOP->DR8R = config->PPData.dr8r;
  GPIOP->ODR = config->PPData.odr;
  GPIOP->PUR = config->PPData.pur;
  GPIOP->PDR = config->PPData.pdr;
  GPIOP->SLR = config->PPData.slr;
  GPIOP->DEN = config->PPData.den;
  GPIOP->AMSEL = config->PPData.amsel;
  GPIOP->PCTL = config->PPData.pctl;
#endif /* TIVA_HAS_GPIOP.*/
  
#if TIVA_HAS_GPIOQ || defined(__DOXYGEN__)
  SYSCTL->RCGCGPIO |= (1 << 14);
  
  __NOP();
  __NOP();
  __NOP();

  GPIOQ->DATA = config->PQData.data;
  GPIOQ->DIR = config->PQData.dir;
  GPIOQ->AFSEL = config->PQData.afsel;
  GPIOQ->DR2R = config->PQData.dr2r;
  GPIOQ->DR4R = config->PQData.dr4r;
  GPIOQ->DR8R = config->PQData.dr8r;
  GPIOQ->ODR = config->PQData.odr;
  GPIOQ->PUR = config->PQData.pur;
  GPIOQ->PDR = config->PQData.pdr;
  GPIOQ->SLR = config->PQData.slr;
  GPIOQ->DEN = config->PQData.den;
  GPIOQ->AMSEL = config->PQData.amsel;
  GPIOQ->PCTL = config->PQData.pctl;
#endif /* TIVA_HAS_GPIOQ.*/
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask
 * @param[in] mode      the mode
 *
 * @notapi
 */
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode)
{
  /* TODO: this is not good implemented yet */
  switch (mode) {
  case PAL_MODE_UNCONNECTED:
  case PAL_MODE_INPUT_PULLUP:
    port->PUR |= mask;
  case PAL_MODE_INPUT:
    port->AFSEL &= ~mask;
    port->DIR &= ~mask;
    port->ODR &= ~mask;
    port->DEN |= mask;
    break;

  case PAL_MODE_INPUT_PULLDOWN:
    port->AFSEL &= ~mask;
    port->DIR &= ~mask;
    port->ODR &= ~mask;
    port->DEN |= mask;
    port->PDR |= mask;
    break;

  case PAL_MODE_RESET:
  case PAL_MODE_INPUT_ANALOG:
    port->AFSEL &= ~mask;
    port->DIR &= ~mask;
    port->ODR &= ~mask;
    port->DEN &= ~mask;
    port->PUR &= ~mask;
    port->PDR &= ~mask;
    break;

  case PAL_MODE_OUTPUT_PUSHPULL:
    port->AFSEL &= ~mask;
    port->DIR |= mask;
    port->ODR &= ~mask;
    port->DEN |= mask;
    break;

  case PAL_MODE_OUTPUT_OPENDRAIN:
    port->AFSEL &= ~mask;
    port->DIR |= mask;
    port->ODR |= mask;
    port->DEN |= mask;
    break;
  }
}

#endif /* HAL_USE_PAL */

/**
 * @}
 */
