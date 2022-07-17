# create variable (cross compilation)
CC = arm-none-eabi-gcc
MACH = cortex-m4
# stands for compiler flags or compiler options
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

#target:dependency
all:main.o led.o
main.o:main.c
	$(CC) $(CFLAGS) main.c -o main.o

led.o:led.c
	$(CC) $(CFLAGS) -o $@ $^
