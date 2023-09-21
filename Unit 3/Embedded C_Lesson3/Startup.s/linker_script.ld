/*==========================================================================
 Name        : linker_script.ld
 Author      : Mohammed Hassan
 Created on	 : 9/20/2023
 Description : Unit 3 ==>> Lesson 3 ==>> Lab(2)
 ==========================================================================*/
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_TEXT = . ;
	}>flash

	.data : {
		_S_DATA = . ;
		*(.data*)
		. = ALIGN(4);
		_E_DATA = . ;
	}>sram AT>flash
	
	.bss : {
		_S_BSS = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_BSS = . ;

		. = ALIGN(4);
		. = . + 0x1000 ;
		_STACK_TOP = . ;
	}>sram
}
