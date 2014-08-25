/*
    ChibiOS/RT - Copyright (C) 2006-2014 Giovanni Di Sirio

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

#include "ch.h"
#include "hal.h"

__attribute__ ((section(".cfmconfig")))
const uint8_t _cfm[0x10] = {
  0xFF,  /* NV_BACKKEY3: KEY=0xFF */
  0xFF,  /* NV_BACKKEY2: KEY=0xFF */
  0xFF,  /* NV_BACKKEY1: KEY=0xFF */
  0xFF,  /* NV_BACKKEY0: KEY=0xFF */
  0xFF,  /* NV_BACKKEY7: KEY=0xFF */
  0xFF,  /* NV_BACKKEY6: KEY=0xFF */
  0xFF,  /* NV_BACKKEY5: KEY=0xFF */
  0xFF,  /* NV_BACKKEY4: KEY=0xFF */
  0xFF,  /* NV_FPROT3: PROT=0xFF */
  0xFF,  /* NV_FPROT2: PROT=0xFF */
  0xFF,  /* NV_FPROT1: PROT=0xFF */
  0xFF,  /* NV_FPROT0: PROT=0xFF */
  0xBE,  /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */
  0xFF,  /* NV_FOPT: ??=1,??=1,FAST_INIT=1,LPBOOT1=1,RESET_PIN_CFG=1,
                      NMI_DIS=1,EZPORT_DIS=1,LPBOOT0=1 */
  0xFF,
  0xFF
};

void spicb(SPIDriver *spip) {

  (void)spip;

  palClearPad(GPIOB, GPIOB_LED);
}

/*
 * SPI1 configuration structure.
 * The slave select line is the PCS4 pin also assigned to GPIOC pin 0.
 */
static const SPIConfig spi1cfg = {
  spicb,
  /* HW dependent part.*/
  KINETIS_SPI_PCS4,
  GPIOC,
  0,
  KINETIS_SPI_TAR_8BIT_SLOW
};

static THD_WORKING_AREA(waThread1, 64);
static THD_FUNCTION(Thread1, arg) {
  static uint8_t txbuf[5];
  static uint8_t rxbuf[5];

  (void)arg;
  chRegSetThreadName("Blinker");
  while (TRUE) {
    palSetPad(GPIOB, GPIOB_LED);

    /* Send the Manufacturer and Device ID Read command */
    txbuf[0] = 0x9F;

    spiSelect(&SPID1);
    spiExchange(&SPID1, sizeof(txbuf), txbuf, rxbuf);
    spiUnselect(&SPID1);

    chThdSleepMilliseconds(1000);
  }

  return 0;
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Activates SPID1. Slave select is configured on GPIOC pin 0. This is
   * PCS4 for the KINETIS DSPI managed slave select.
   */
  palSetPadMode(GPIOC, 5, PAL_MODE_ALTERNATIVE_2);  /* SCK  */
  palSetPadMode(GPIOC, 6, PAL_MODE_ALTERNATIVE_2);  /* MOSI */
  palSetPadMode(GPIOD, 3, PAL_MODE_ALTERNATIVE_2);  /* MISO */
  palSetPadMode(GPIOC, 0, PAL_MODE_ALTERNATIVE_2);  /* SS   */

  /*
   *  Initializes the SPI driver 1.
   */
  spiStart(&SPID1, &spi1cfg);

  /*
   * Creates the blinker threads.
   */
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  while (1) {
    chThdSleepMilliseconds(500);
  }
}
