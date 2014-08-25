/**
 * @file    Tiva/LLD/st_lld.h
 * @brief   ST Driver subsystem low level driver header.
 * @details This header is designed to be include-able without having to
 *          include other files from the HAL.
 *
 * @addtogroup ST
 * @{
 */

#ifndef _ST_LLD_H_
#define _ST_LLD_H_

#include "mcuconf.h"
#include "tiva_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

// cfg
#define GPTM_CFG_CFG_MASK       (7 << 0)
#define GPTM_CFG_CFG_WHOLE      (0 << 0)
#define GPTM_CFG_CFG_RTC        (1 << 0)
#define GPTM_CFG_CFG_SPLIT      (4 << 0)

// tamr
#define GPTM_TAMR_TAMR_MASK     (3 << 0)
#define GPTM_TAMR_TAMR_ONESHOT  (1 << 0)
#define GPTM_TAMR_TAMR_PERIODIC (2 << 0)
#define GPTM_TAMR_TAMR_CAPTURE  (3 << 0)

#define GPTM_TAMR_TACMR         (1 << 2)

#define GPTM_TAMR_TAAMS         (1 << 3)

#define GPTM_TAMR_TACDIR        (1 << 4)

#define GPTM_TAMR_TAMIE         (1 << 5)

#define GPTM_TAMR_TAWOT         (1 << 6)

#define GPTM_TAMR_TASNAPS       (1 << 7)

#define GPTM_TAMR_TAILD         (1 << 8)

#define GPTM_TAMR_TAPWMIE       (1 << 9)

#define GPTM_TAMR_TAMRSU        (1 << 10)

#define GPTM_TAMR_TAPLO         (1 << 11)

// ctl
#define GPTM_CTL_TAEN           (1 << 0)

#define GPTM_CTL_TASTALL        (1 << 1)

#define GPTM_CTL_TAEVENT_MASK   (3 << 2)
#define GPTM_CTL_TAEVENT_POS    (0 << 2)
#define GPTM_CTL_TAEVENT_NEG    (1 << 2)
#define GPTM_CTL_TAEVENT_BOTH   (3 << 2)

#define GPTM_CTL_RTCEN          (1 << 4)

#define GPTM_CTL_TAOTE          (1 << 5)

#define GPTM_CTL_TAPWML         (1 << 6)

#define GPTM_CTL_TBEN           (1 << 8)

#define GPTM_CTL_TBSTALL        (1 << 9)

#define GPTM_CTL_TBEVENT_MASK   (3 << 10)
#define GPTM_CTL_TBEVENT_POS    (0 << 10)
#define GPTM_CTL_TBEVENT_NEG    (1 << 10)
#define GPTM_CTL_TBEVENT_BOTH   (3 << 10)

#define GPTM_CTL_TBOTE          (1 << 13)

#define GPTM_CTL_TBPWML         (1 << 14)

// imr
#define GPTM_IMR_TATOIM         (1 << 0)

#define GPTM_IMR_CAMIM          (1 << 1)

#define GPTM_IMR_CAEIM          (1 << 2)

#define GPTM_IMR_RTCIM          (1 << 3)

#define GPTM_IMR_TAMIM          (1 << 4)

#define GPTM_IMR_TBTOIM         (1 << 8)

#define GPTM_IMR_CBMIM          (1 << 9)

#define GPTM_IMR_CBEIM          (1 << 10)

#define GPTM_IMR_TBMIM          (1 << 11)

#define GPTM_IMR_WUEIM          (1 << 16)

// icr
#define GPTM_ICR_TATOCINT         (1 << 0)

#define GPTM_ICR_CAMCINT          (1 << 1)

#define GPTM_ICR_CAECINT          (1 << 2)

#define GPTM_ICR_RTCCINT          (1 << 3)

#define GPTM_ICR_TAMCINT          (1 << 4)

#define GPTM_ICR_TBTOCINT         (1 << 8)

#define GPTM_ICR_CBMCINT          (1 << 9)

#define GPTM_ICR_CBECINT          (1 << 10)

#define GPTM_ICR_TBMCINT          (1 << 11)

#define GPTM_ICR_WUECINT          (1 << 16)

#define TIVA_ST_TIM_PRESCALER       ((80000000 / 10000) - 1)

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/**
 * @name    Configuration options
 * @{
 */

/**
 * @brief   SysTick timer IRQ priority.
 */
#if !defined(TIVA_ST_IRQ_PRIORITY) || defined(__DOXYGEN__)
#define TIVA_ST_IRQ_PRIORITY                2
#endif

/**
 * @brief   GPTx unit (by number) to be used for free running operations.
 * @note    You must select a 32 bits timer if a 32 bits @p systick_t type
 *          is required.
 */
#if !defined(TIVA_ST_TIMER_NUMBER) || defined(__DOXYGEN__)
#define TIVA_ST_TIMER_NUMBER                0
#endif

/* TODO: Add description */
#if !defined(TIVA_ST_USE_WIDE_TIMER) || defined(__DOXYGEN__)
#define TIVA_ST_USE_WIDE_TIMER              TRUE
#endif

/**
 * @}
 */

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING

#error "Tickless system tick mode is not working yet! Please use the periodic system tick mode."

#if (TIVA_ST_USE_WIDE_TIMER == TRUE)

#if TIVA_ST_TIMER_NUMBER == 0
#if !TIVA_HAS_WGPT0
#error "WGPT0 not present"
#endif
#define TIVA_ST_TIM                         WGPT0

#elif TIVA_ST_TIMER_NUMBER == 1
#if !TIVA_HAS_WGPT1
#error "WGPT1 not present"
#endif
#define TIVA_ST_TIM                         WGPT1

#elif TIVA_ST_TIMER_NUMBER == 2
#if !TIVA_HAS_WGPT2
#error "WGPT2 not present"
#endif
#define TIVA_ST_TIM                         WGPT2

#elif TIVA_ST_TIMER_NUMBER == 3
#if !TIVA_HAS_WGPT3
#error "WGPT3 not present"
#endif
#define TIVA_ST_TIM                         WGPT3

#elif TIVA_ST_TIMER_NUMBER == 4
#if !TIVA_HAS_WGPT4
#error "WGPT4 not present"
#endif
#define TIVA_ST_TIM                         WGPT4

#elif TIVA_ST_TIMER_NUMBER == 5
#if !TIVA_HAS_WGPT5
#error "WGPT5 not present"
#endif
#define TIVA_ST_TIM                         WGPT5

#else
#error "TIVA_ST_USE_TIMER specifies an unsupported timer"
#endif

#elif (TIVA_ST_USE_WIDE_TIMER == FALSE)

#if TIVA_ST_TIMER_NUMBER == 0
#if !TIVA_HAS_GPT0
#error "GPT0 not present"
#endif
#define TIVA_ST_TIM                         GPT0

#elif TIVA_ST_TIMER_NUMBER == 1
#if !TIVA_HAS_GPT1
#error "GPT1 not present"
#endif
#define TIVA_ST_TIM                         GPT1

#elif TIVA_ST_TIMER_NUMBER == 2
#if !TIVA_HAS_GPT2
#error "GPT2 not present"
#endif
#define TIVA_ST_TIM                         GPT2

#elif TIVA_ST_TIMER_NUMBER == 3
#if !TIVA_HAS_GPT3
#error "GPT3 not present"
#endif
#define TIVA_ST_TIM                         GPT3

#elif TIVA_ST_TIMER_NUMBER == 4
#if !TIVA_HAS_GPT4
#error "GPT4 not present"
#endif
#define TIVA_ST_TIM                         GPT4

#elif TIVA_ST_TIMER_NUMBER == 5
#if !TIVA_HAS_GPT5
#error "GPT5 not present"
#endif
#define TIVA_ST_TIM                         GPT5

#else
#error "TIVA_ST_TIMER_NUMBER specifies an unsupported timer"
#endif

#else
#error "wrong value defined for TIVA_ST_USE_WIDE_TIMER"
#endif

#endif

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void st_lld_init(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Returns the time counter value.
 *
 * @return              The counter value.
 *
 * @notapi
 */
static inline systime_t st_lld_get_counter(void)
{
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  return (systime_t) TIVA_ST_TIM->TAV;
#else
  return (systime_t) 0;
#endif
}

/**
 * @brief   Starts the alarm.
 * @note    Makes sure that no spurious alarms are triggered after
 *          this call.
 *
 * @param[in] time      the time to be set for the first alarm
 *
 * @notapi
 */
static inline void st_lld_start_alarm(systime_t time)
{
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint64_t temp;

  temp = (uint64_t) time * TIVA_ST_TIM_PRESCALER;

  TIVA_ST_TIM->TAMATCHR = (uint32_t) temp;

  temp = temp >> 32;

  TIVA_ST_TIM->TAPMR = (uint16_t) temp;

  TIVA_ST_TIM->ICR = 0xffffffff;
  TIVA_ST_TIM->IMR = GPTM_IMR_TAMIM;
#else
  (void)time;
#endif
}

/**
 * @brief   Stops the alarm interrupt.
 *
 * @notapi
 */
static inline void st_lld_stop_alarm(void)
{
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  TIVA_ST_TIM->IMR = 0;
#endif
}

/**
 * @brief   Sets the alarm time.
 *
 * @param[in] time      the time to be set for the next alarm
 *
 * @notapi
 */
static inline void st_lld_set_alarm(systime_t time)
{
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint64_t temp;

  temp = (uint64_t) time * TIVA_ST_TIM_PRESCALER;

  TIVA_ST_TIM->TAMATCHR = (uint32_t) temp;

  temp = temp >> 32;

  TIVA_ST_TIM->TAPMR = (uint16_t) temp;
#else
  (void)time;
#endif
}

/**
 * @brief   Returns the current alarm time.
 *
 * @return              The currently set alarm time.
 *
 * @notapi
 */
static inline systime_t st_lld_get_alarm(void)
{
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  uint64_t temp;

  temp = TIVA_ST_TIM->TAPR;
  temp = temp << 32;
  temp = TIVA_ST_TIM->TAR;

  temp = temp / TIVA_ST_TIM_PRESCALER;

  return (systime_t) temp;
#else
  return (systime_t) 0;
#endif
}

/**
 * @brief   Determines if the alarm is active.
 *
 * @return              The alarm status.
 * @retval false        if the alarm is not active.
 * @retval true         is the alarm is active
 *
 * @notapi
 */
static inline bool st_lld_is_alarm_active(void)
{
#if OSAL_ST_MODE == OSAL_ST_MODE_FREERUNNING
  return (bool) ((TIVA_ST_TIM->IMR & GPTM_IMR_TAMIM) !=0);
#else
  return (bool) false;
#endif
}

#endif /* _ST_LLD_H_ */

/**
 * @}
 */
