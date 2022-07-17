# create variable (cross compilation)
CC = arm-none-eabi-gcc
MACH = cortex-m4
# stands for compiler flags or compiler options
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

#target:dependency
main.o:main.c
	$(CC) $(CFLAGS) main.c -o main.o