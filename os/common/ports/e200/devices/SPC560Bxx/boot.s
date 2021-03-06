/*
    ChibiOS - Copyright (C) 2006,2007,2008,2009,2010,
              2011,2012,2013,2014 Giovanni Di Sirio.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    SPC560Bxx/boot.s
 * @brief   SPC560Bxx boot-related code.
 *
 * @addtogroup PPC_BOOT
 * @{
 */

#include "boot.h"

#if !defined(__DOXYGEN__)

        /* BAM record.*/
        .section    .boot, "ax"

        .long       0x015A0000
        .long       _reset_address

        .align      2
        .globl      _reset_address
        .type       _reset_address, @function
_reset_address:
#if BOOT_PERFORM_CORE_INIT
        bl          _coreinit
#endif
        bl          _ivinit

#if BOOT_RELOCATE_IN_RAM
        /*
         * Image relocation in RAM.
         */
        lis         %r4, __ram_reloc_start__@h
        ori         %r4, %r4, __ram_reloc_start__@l
        lis         %r5, __ram_reloc_dest__@h
        ori         %r5, %r5, __ram_reloc_dest__@l
        lis         %r6, __ram_reloc_end__@h
        ori         %r6, %r6, __ram_reloc_end__@l
.relloop:
        cmpl        cr0, %r4, %r6
        bge         cr0, .relend
        lwz         %r7, 0(%r4)
        addi        %r4, %r4, 4
        stw         %r7, 0(%r5)
        addi        %r5, %r5, 4
        b           .relloop
.relend:
        lis         %r3, _boot_address@h
        ori         %r3, %r3, _boot_address@l
        mtctr       %r3
        bctrl
#else
        b           _boot_address
#endif

#if BOOT_PERFORM_CORE_INIT
        .align      2
_coreinit:
        /*
         * RAM clearing, this device requires a write to all RAM location in
         * order to initialize the ECC detection hardware, this is going to
         * slow down the startup but there is no way around.
         */
        xor         %r0, %r0, %r0
        xor         %r1, %r1, %r1
        xor         %r2, %r2, %r2
        xor         %r3, %r3, %r3
        xor         %r4, %r4, %r4
        xor         %r5, %r5, %r5
        xor         %r6, %r6, %r6
        xor         %r7, %r7, %r7
        xor         %r8, %r8, %r8
        xor         %r9, %r9, %r9
        xor         %r10, %r10, %r10
        xor         %r11, %r11, %r11
        xor         %r12, %r12, %r12
        xor         %r13, %r13, %r13
        xor         %r14, %r14, %r14
        xor         %r15, %r15, %r15
        xor         %r16, %r16, %r16
        xor         %r17, %r17, %r17
        xor         %r18, %r18, %r18
        xor         %r19, %r19, %r19
        xor         %r20, %r20, %r20
        xor         %r21, %r21, %r21
        xor         %r22, %r22, %r22
        xor         %r23, %r23, %r23
        xor         %r24, %r24, %r24
        xor         %r25, %r25, %r25
        xor         %r26, %r26, %r26
        xor         %r27, %r27, %r27
        xor         %r28, %r28, %r28
        xor         %r29, %r29, %r29
        xor         %r30, %r30, %r30
        xor         %r31, %r31, %r31
        lis         %r4, __ram_start__@h
        ori         %r4, %r4, __ram_start__@l
        lis         %r5, __ram_end__@h
        ori         %r5, %r5, __ram_end__@l
.cleareccloop:
        cmpl        %cr0, %r4, %r5
        bge         %cr0, .cleareccend
        stmw        %r16, 0(%r4)
        addi        %r4, %r4, 64
        b           .cleareccloop
.cleareccend:

        /*
         * Branch prediction enabled.
         */
        li          %r3, BOOT_BUCSR_DEFAULT
        mtspr       1013, %r3       /* BUCSR */

        blr
#endif /* BOOT_PERFORM_CORE_INIT */

        /*
         * Exception vectors initialization.
         */
        .align      2
_ivinit:
        /* MSR initialization.*/
        lis         %r3, BOOT_MSR_DEFAULT@h
        ori         %r3, %r3, BOOT_MSR_DEFAULT@l
        mtMSR       %r3

        /* IVPR initialization.*/
        lis         %r3, __ivpr_base__@h
        ori         %r3, %r3, __ivpr_base__@l
        mtIVPR      %r3

        blr

        .section    .ivors, "ax"

        .globl      IVORS
IVORS:
IVOR0:  b           IVOR0
        .align      4
IVOR1:  b           _IVOR1
        .align      4
IVOR2:  b           _IVOR2
        .align      4
IVOR3:  b           _IVOR3
        .align      4
IVOR4:  b           _IVOR4
        .align      4
IVOR5:  b           _IVOR5
        .align      4
IVOR6:  b           _IVOR6
        .align      4
IVOR7:  b           _IVOR7
        .align      4
IVOR8:  b           _IVOR8
        .align      4
IVOR9:  b           _IVOR9
        .align      4
IVOR10: b           _IVOR10
        .align      4
IVOR11: b           _IVOR11
        .align      4
IVOR12: b           _IVOR12
        .align      4
IVOR13: b           _IVOR13
        .align      4
IVOR14: b           _IVOR14
        .align      4
IVOR15: b           _IVOR15

        .section    .handlers, "ax"

        /*
         * Default IVOR handlers.
         */
        .align      2
        .weak       _IVOR0,  _IVOR1,  _IVOR2,  _IVOR3,  _IVOR4,  _IVOR5
        .weak       _IVOR6,  _IVOR7,  _IVOR8,  _IVOR9,  _IVOR10, _IVOR11
        .weak       _IVOR12, _IVOR13, _IVOR14, _IVOR15
        .weak       _unhandled_exception
_IVOR0:
_IVOR1:
_IVOR2:
_IVOR3:
_IVOR5:
_IVOR6:
_IVOR7:
_IVOR8:
_IVOR9:
_IVOR11:
_IVOR12:
_IVOR13:
_IVOR14:
_IVOR15:
_unhandled_exception:
        b           _unhandled_exception

#endif /* !defined(__DOXYGEN__) */

/** @} */
