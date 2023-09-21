#Learn-In-Depth 
#Eng.Mohammed_Hassan
#Unit 3==>> Lesson 3 ==>> Lab(2)
#makefile

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=learn-in-depth

all: $(Project_name).bin
	@echo "=================== Build is Done ==================="

%.o: %.s
	$(CC)as.exe  $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -Map=Map_File.map -o $@

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $<  $@

clean_all:
	rm *.bin *.o *.elf

clean:
	rm *.bin *.elf