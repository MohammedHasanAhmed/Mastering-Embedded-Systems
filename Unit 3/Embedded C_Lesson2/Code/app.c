#include "uart.h"

unsigned char String_Buffer[100] = "learn-in-depth:Mohammed_Hasan";
unsigned char const String_Buffer2[100] = "learn-in-depth:Mohammed_Hasan"; // " to creat a rodata section "

void main(void)
{
	Uart_Send_String(String_Buffer);
}