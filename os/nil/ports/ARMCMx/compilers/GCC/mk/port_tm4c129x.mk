# List of the ChibiOS/RT Cortex-M4F TM4C129x port files.
PORTSRC = $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/crt0.c \
          $(CHIBIOS)/os/common/ports/ARMCMx/compilers/GCC/vectors.c \
          ${CHIBIOS}/os/nil/ports/ARMCMx/nilcore.c \
          ${CHIBIOS}/os/nil/ports/ARMCMx/nilcore_v7m.c
          
PORTASM = $(CHIBIOS)/os/nil/ports/ARMCMx/compilers/GCC/nilcoreasm_v7m.s

PORTINC = ${CHIBIOS}/os/ext/CMSIS/include \
          ${CHIBIOS}/os/common/ports/ARMCMx/devices/TM4C129x \
          ${CHIBIOS}/os/nil/ports/ARMCMx \
          ${CHIBIOS}/os/nil/ports/ARMCMx/compilers/GCC

PORTLD  = ${CHIBIOS}/os/common/ports/ARMCMx/compilers/GCC/ld
