/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012,2013,2014 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    chmtx.h
 * @brief   Mutexes macros and structures.
 *
 * @addtogroup mutexes
 * @{
 */

#ifndef _CHMTX_H_
#define _CHMTX_H_

#if CH_CFG_USE_MUTEXES || defined(__DOXYGEN__)

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a mutex structure.
 */
typedef struct mutex mutex_t;

/**
 * @brief   Mutex structure.
 */
struct mutex {
  threads_queue_t       m_queue;    /**< @brief Queue of the threads sleeping
                                                on this mutex.              */
  thread_t              *m_owner;   /**< @brief Owner @p thread_t pointer or
                                                @p NULL.                    */
  mutex_t               *m_next;    /**< @brief Next @p mutex_t into an
                                                owner-list or @p NULL.      */
#if CH_CFG_USE_MUTEXES_RECURSIVE || defined(__DOXYGEN__)
  cnt_t                 m_cnt;      /**< @brief Mutex recursion counter.    */
#endif
};

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Data part of a static mutex initializer.
 * @details This macro should be used when statically initializing a mutex
 *          that is part of a bigger structure.
 *
 * @param[in] name      the name of the mutex variable
 */
#if CH_CFG_USE_MUTEXES_RECURSIVE || defined(__DOXYGEN__)
#define _MUTEX_DATA(name) {_THREADS_QUEUE_DATA(name.m_queue), NULL, NULL, 0}
#else
#define _MUTEX_DATA(name) {_THREADS_QUEUE_DATA(name.m_queue), NULL, NULL}
#endif

/**
 * @brief   Static mutex initializer.
 * @details Statically initialized mutexes require no explicit initialization
 *          using @p chMtxInit().
 *
 * @param[in] name      the name of the mutex variable
 */
#define MUTEX_DECL(name) mutex_t name = _MUTEX_DATA(name)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/


#ifdef __cplusplus
extern "C" {
#endif
  void chMtxObjectInit(mutex_t *mp);
  void chMtxLock(mutex_t *mp);
  void chMtxLockS(mutex_t *mp);
  bool chMtxTryLock(mutex_t *mp);
  bool chMtxTryLockS(mutex_t *mp);
  void chMtxUnlock(mutex_t *mp);
  void chMtxUnlockS(mutex_t *mp);
  void chMtxUnlockAll(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Module inline functions.                                                  */
/*===========================================================================*/

/**
 * @brief   Returns @p true if the mutex queue contains at least a waiting
 *          thread.
 *
 * @deprecated
 * @sclass
 */
static inline bool chMtxQueueNotEmptyS(mutex_t *mp) {

  chDbgCheckClassS();

  return queue_notempty(&mp->m_queue);
}

/**
 * @brief   Returns the next mutex in the mutexes stack of the current thread.
 *
 * @return              A pointer to the next mutex in the stack.
 * @retval NULL         if the stack is empty.
 *
 * @sclass
 */
static inline mutex_t *chMtxGetNextMutexS(void) {

  return chThdGetSelfX()->p_mtxlist;
}

#endif /* CH_CFG_USE_MUTEXES */

#endif /* _CHMTX_H_ */

/** @} */
