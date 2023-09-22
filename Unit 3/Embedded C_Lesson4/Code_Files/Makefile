#Learn-In-Depth 
#Eng.Mohammed_Hassan
#Unit 3 ==>> Lesson 4 ==>> Lab(3)
#makefile

CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=Lab3_CORTEX-M4

all: $(Project_name).bin
	@echo "=================== Build is Done ==================="

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -Map=Map_File.map -o $@
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $<  $@

clean_all:
	rm *.bin *.o *.elf

clean:
	rm *.bin *.elf