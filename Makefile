MCU=atmega328p
F_CPU=16000000
NAME=Thermostat
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
SRCS=Main.c lcd.c ds18b20.c onewire.c
INCDIR=./inc/
SRCDIR=./src/
OBJDIR=./bin/
TARGET=${addprefix ${OBJDIR},${NAME}}

compile:
	@echo "Making object directory..."
	mkdir -p ${OBJDIR}
	@echo "Compiling..."
	${CC} ${CFLAGS} -o ${TARGET}.bin ${addprefix ${SRCDIR},${SRCS}} -I ${INCDIR}
	@echo "Making hex file.."
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	@echo "Flashing the MCU"
	avrdude -p ${MCU} -c usbasp -U flash:w:${TARGET}.hex:i -F -P usb

re:	clean compile

clean:
	rm -rf ${OBJDIR}

qflash: clean compile flash
