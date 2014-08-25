#include "ch.h"
#include "hal.h"
#include "test.h"

typedef struct led_config
{
  ioportid_t port;
  uint32_t sleep;
  uint8_t  pin;
} led_config_t;

/*
 * LED blinker thread.
 */
static THD_WORKING_AREA(waBlinkLedRed, 128);
static THD_WORKING_AREA(waBlinkLedGreen, 128);
static THD_WORKING_AREA(waBlinkLedBlue, 128);
static msg_t blinkLed(void *arg)
{
  led_config_t *ledConfig = (led_config_t*) arg;

  chRegSetThreadName("Blinker");

  while (TRUE) {
    chThdSleepMilliseconds(ledConfig->sleep);
    palTogglePad(ledConfig->port, ledConfig->pin);
  }

  return (msg_t) 0;
}

/*
 * Application entry point.
 */
int main(void)
{
  led_config_t ledRed, ledGreen, ledBlue;

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  ledRed.port    = GPIOF;
  ledRed.pin     = GPIOF_LED_RED;
  ledRed.sleep   = 100;

  ledGreen.port  = GPIOF;
  ledGreen.pin   = GPIOF_LED_GREEN;
  ledGreen.sleep = 101;

  ledBlue.port   = GPIOF;
  ledBlue.pin    = GPIOF_LED_BLUE;
  ledBlue.sleep  = 102;

  /*
   * Creating the blinker threads.
   */
  chThdCreateStatic(waBlinkLedRed,
                    sizeof(waBlinkLedRed),
                    NORMALPRIO,
                    blinkLed,
                    &ledRed);

  chThdCreateStatic(waBlinkLedGreen,
                    sizeof(waBlinkLedGreen),
                    NORMALPRIO,
                    blinkLed,
                    &ledGreen);

  chThdCreateStatic(waBlinkLedBlue,
                    sizeof(waBlinkLedBlue),
                    NORMALPRIO,
                    blinkLed,
                    &ledBlue);

  /*
   * Start the serial driver with the default configuration.
   */
  sdStart(&SD1, NULL);

  /*
   * Normal main() thread activity
   */
  while (TRUE) {
    if (!palReadPad(GPIOF, GPIOF_SW2)) {
      TestThread(&SD1);
    }
    chThdSleepMilliseconds(100);
  }
  
  return 0;
}
