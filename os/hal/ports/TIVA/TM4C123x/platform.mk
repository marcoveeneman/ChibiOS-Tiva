# List of all the TM4C123x platform files.
PLATFORMSRC = ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c \
              ${CHIBIOS}/os/hal/ports/TIVA/TM4C123x/hal_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/st_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/pal_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/serial_lld.c \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD/i2c_lld.c

# Required include directories
PLATFORMINC = ${CHIBIOS}/os/hal/ports/common/ARMCMx \
              ${CHIBIOS}/os/hal/ports/TIVA/TM4C123x \
              ${CHIBIOS}/os/hal/ports/TIVA/LLD
