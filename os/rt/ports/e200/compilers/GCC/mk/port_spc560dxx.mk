# List of the ChibiOS/RT e200z0 SPC560Dxx port files.
PORTSRC = ${CHIBIOS}/os/rt/ports/e200/chcore.c
          
PORTASM = $(CHIBIOS)/os/common/ports/e200/devices/SPC560Dxx/boot.s \
          $(CHIBIOS)/os/common/ports/e200/compilers/GCC/vectors.s \
          $(CHIBIOS)/os/common/ports/e200/compilers/GCC/crt0.s \
          $(CHIBIOS)/os/rt/ports/e200/compilers/GCC/ivor.s

PORTINC = ${CHIBIOS}/os/common/ports/e200/compilers/GCC \
          ${CHIBIOS}/os/common/ports/e200/devices/SPC560Dxx \
          ${CHIBIOS}/os/rt/ports/e200 \
          ${CHIBIOS}/os/rt/ports/e200/compilers/GCC

PORTLD  = ${CHIBIOS}/os/common/ports/e200/compilers/GCC/ld
