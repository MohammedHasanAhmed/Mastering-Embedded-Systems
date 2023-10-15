/*==========================================================================
 Name        : linker_script.ld
 Author      : Mohammed Hasan
 Created on	 : Oct 10, 2023
 Description : First Term Project 1 ==>> Pressure Controller
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
		_E_Text = . ;
	}>flash

	.data : {
		_S_Data = . ;
		*(.data*)
		. = ALIGN(4);
		_E_Data = . ;
	}>sram AT> flash
	
	.bss : {
		_S_Bss = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_Bss = . ;

		. = ALIGN(4);
		. = . + 0x1000 ;
		_Stack_Top = . ;
	}>sram
}