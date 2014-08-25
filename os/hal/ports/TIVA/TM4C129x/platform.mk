# List of all the TM4C129x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS}/os/hal/ports/TIVA/TM4C129x/hal_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/st_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/GPIOv2/pal_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/UARTv2/serial_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS}/os/hal/ports/TIVA/TM4C129x \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/GPIOv2 \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/UARTv2