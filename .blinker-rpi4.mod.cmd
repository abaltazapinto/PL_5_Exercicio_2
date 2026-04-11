savedcmd_/home/abaltaza/rpi_lab/blinker-rpi4.mod := printf '%s\n'   blinker.o gpio.o | awk '!x[$$0]++ { print("/home/abaltaza/rpi_lab/"$$0) }' > /home/abaltaza/rpi_lab/blinker-rpi4.mod
