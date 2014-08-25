//#include "ch.h"
//#include "hal.h"
//#include "test.h"
//
///*
// * LED blinker thread, times are in milliseconds.
// */
//static THD_WORKING_AREA(waThread1, 128);
//static msg_t Thread1(void *arg)
//{
//  (void)arg;
//  chRegSetThreadName("Led blinker1");
//  while (TRUE) {
//    palTogglePad(GPIOF, GPIOF_LED0);
//    chThdSleepMilliseconds(100);
//  }
//
//  return 0;
//}
//
///*
// * LED blinker thread, times are in milliseconds.
// */
//static THD_WORKING_AREA(waThread2, 128);
//static msg_t Thread2(void *arg)
//{
//  (void)arg;
//  chRegSetThreadName("Led blinker2");
//  while (TRUE) {
//    palTogglePad(GPIOF, GPIOF_LED1);
//    chThdSleepMilliseconds(200);
//  }
//
//  return 0;
//}
//
///*
// * LED blinker thread, times are in milliseconds.
// */
//static THD_WORKING_AREA(waThread3, 128);
//static msg_t Thread3(void *arg)
//{
//  (void)arg;
//  chRegSetThreadName("Led blinker3");
//  while (TRUE) {
//    palTogglePad(GPION, GPION_LED2);
//    chThdSleepMilliseconds(400);
//  }
//
//  return 0;
//}
//
///*
// * LED blinker thread, times are in milliseconds.
// */
//static THD_WORKING_AREA(waThread4, 128);
//static msg_t Thread4(void *arg)
//{
//  (void)arg;
//  chRegSetThreadName("Led blinker4");
//  while (TRUE) {
//    palTogglePad(GPION, GPION_LED3);
//    chThdSleepMilliseconds(800);
//  }
//
//  return 0;
//}
//
///*
// * Application entry point.
// */
//int main(void)
//{
//  //uint32_t dummy;
//  /*
//   * System initializations.
//   * - HAL initialization, this also initializes the configured device drivers
//   *   and performs the board-specific initializations.
//   * - Kernel initialization, the main() function becomes a thread and the
//   *   RTOS is active.
//   */
//  halInit();
//  chSysInit();
//
//  /*
//   * Start the serial driver with the default configuration.
//   */
//  sdStart(&SD1, NULL);
//
//  /*
//   * Start the test thread
//   */
//  TestThread(&SD1);
//
//  /*
//   * Creating the blinker threads.
//   */
//  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);
//  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2, NULL);
//  chThdCreateStatic(waThread3, sizeof(waThread3), NORMALPRIO, Thread3, NULL);
//  chThdCreateStatic(waThread4, sizeof(waThread4), NORMALPRIO, Thread4, NULL);
//
//  /*
//   * Normal main() thread activity
//   */
//  while (TRUE) {
//    chThdSleepMilliseconds(500);
//  }
//
//  return 0;
//}

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
static THD_WORKING_AREA(waBlinkLed1, 128);
static THD_WORKING_AREA(waBlinkLed2, 128);
static THD_WORKING_AREA(waBlinkLed3, 128);
static THD_WORKING_AREA(waBlinkLed4, 128);
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
  led_config_t led1, led2, led3, led4;

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  led1.port  = GPIOF;
  led1.pin   = GPIOF_LED0;
  led1.sleep = 100;

  led2.port  = GPIOF;
  led2.pin   = GPIOF_LED1;
  led2.sleep = 101;

  led3.port  = GPION;
  led3.pin   = GPION_LED2;
  led3.sleep = 102;

  led4.port  = GPION;
  led4.pin   = GPION_LED3;
  led4.sleep = 103;

  /*
   * Creating the blinker threads.
   */
  chThdCreateStatic(waBlinkLed1,
                    sizeof(waBlinkLed1),
                    NORMALPRIO,
                    blinkLed,
                    &led1);

  chThdCreateStatic(waBlinkLed2,
                    sizeof(waBlinkLed2),
                    NORMALPRIO,
                    blinkLed,
                    &led2);

  chThdCreateStatic(waBlinkLed3,
                    sizeof(waBlinkLed3),
                    NORMALPRIO,
                    blinkLed,
                    &led3);

  chThdCreateStatic(waBlinkLed4,
                    sizeof(waBlinkLed4),
                    NORMALPRIO,
                    blinkLed,
                    &led4);

  /*
   * Start the serial driver with the default configuration.
   */
  sdStart(&SD1, NULL);

  /*
   * Normal main() thread activity
   */
  while (TRUE) {
    if (!palReadPad(GPIOJ, GPIOJ_SW1)) {
      TestThread(&SD1);
    }
    chThdSleepMilliseconds(100);
  }
  
  return 0;
}
