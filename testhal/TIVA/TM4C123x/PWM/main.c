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

#include "ch.h"
#include "hal.h"

static void pwmpcb(PWMDriver *pwmp)
{
  (void)pwmp;
  palClearPad(GPIOF, GPIOF_LED_RED);
  palClearPad(GPIOF, GPIOF_LED_GREEN);
  palClearPad(GPIOF, GPIOF_LED_BLUE);
}

static void pwmc1cb0(PWMDriver *pwmp)
{
  (void)pwmp;
  palSetPad(GPIOF, GPIOF_LED_RED);
}

static void pwmc1cb1(PWMDriver *pwmp)
{
  (void)pwmp;
  palSetPad(GPIOF, GPIOF_LED_GREEN);
}

static void pwmc1cb2(PWMDriver *pwmp)
{
  (void)pwmp;
  palSetPad(GPIOF, GPIOF_LED_BLUE);
}

static PWMConfig pwmcfg = {
  10000,                                    /* 10kHz PWM clock frequency.*/
  10000,                                    /* Initial PWM period 1S.*/
  pwmpcb,
  {
   {PWM_OUTPUT_DISABLED, pwmc1cb0},
   {PWM_OUTPUT_DISABLED, pwmc1cb1},
   {PWM_OUTPUT_DISABLED, pwmc1cb2},
   {PWM_OUTPUT_DISABLED, NULL},
   {PWM_OUTPUT_DISABLED, NULL},
   {PWM_OUTPUT_DISABLED, NULL},
   {PWM_OUTPUT_DISABLED, NULL},
   {PWM_OUTPUT_DISABLED, NULL}
  }
};

/*
 * Application entry point.
 */
int main(void)
{
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
   * Start PWM driver
   */
  pwmStart(&PWMD1, &pwmcfg);

  pwmEnableChannel(&PWMD1, 0, 0);
  pwmEnableChannel(&PWMD1, 1, 0);
  pwmEnableChannel(&PWMD1, 2, 0);
  pwmEnableChannelNotification(&PWMD1, 0);
  pwmEnableChannelNotification(&PWMD1, 1);
  pwmEnableChannelNotification(&PWMD1, 2);
  pwmEnablePeriodicNotification(&PWMD1);

  /*
   * Normal main() thread activity
   */
  while (TRUE) {
    uint16_t rgbColour[3];
    uint8_t decColour;
    uint16_t i;

    // Start off with red.
    rgbColour[0] = pwmcfg.frequency - 2;
    rgbColour[1] = 0;
    rgbColour[2] = 0;

    // Choose the colours to increment and decrement.
    for (decColour = 0; decColour < 3; decColour++) {
      int incColour = decColour == 2 ? 0 : decColour + 1;

      // cross-fade the two colours.
      for(i = 0; i < pwmcfg.frequency - 2; i++) {
        rgbColour[decColour] -= 1;
        rgbColour[incColour] += 1;

        if (!palReadPad(GPIOF, GPIOF_SW1))
        {
          pwmEnableChannel(&PWMD1, 0, 0);
          pwmEnableChannel(&PWMD1, 1, 1);
          pwmEnableChannel(&PWMD1, 2, 2);
        }
        else if (!palReadPad(GPIOF, GPIOF_SW2))
        {
          pwmEnableChannel(&PWMD1, 0, pwmcfg.frequency - 2);
          pwmEnableChannel(&PWMD1, 1, pwmcfg.frequency - 1);
          pwmEnableChannel(&PWMD1, 2, pwmcfg.frequency);
        }
        else
        {
          pwmEnableChannel(&PWMD1, 0, rgbColour[0]);
          pwmEnableChannel(&PWMD1, 1, rgbColour[1]);
          pwmEnableChannel(&PWMD1, 2, rgbColour[2]);
        }

        chThdSleepMilliseconds(1);
      }
    }
  }
  
  return 0;
}
