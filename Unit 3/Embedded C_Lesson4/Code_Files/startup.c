/*==========================================================================
 Name        : startup.c
 Author      : Mohammed Hassan
 Created on	 : 9/22/2023
 Description : Unit 3 ==>> Lesson 4 ==>> Lab(3)
 ==========================================================================*/
#include "Platform_Types.h"

extern int main(void);
extern uint32_t _E_Text ;
extern uint32_t _S_Data ;
extern uint32_t _E_Data ;
extern uint32_t _S_Bss ;
extern uint32_t _E_Bss ;

void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) 			__attribute__ ((weak, alias("Default_Handler")));
void H_Fault_Handler(void) 		__attribute__ ((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) 	__attribute__ ((weak, alias("Default_Handler")));
void Bus_Fault(void) 			__attribute__ ((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) 	__attribute__ ((weak, alias("Default_Handler")));

// Booking 1024Byte located by .bss through un intialized array of int 256 Element(256*4 = 1024)
static unsigned Stack_Top[255];

void (* const Gl_ptr_fn_vectors[])() __attribute__ ((section(".vectors"))) = 
{
	(void(*)()) ((uint32_t)Stack_Top + sizeof(Stack_Top)),
	 &Reset_Handler ,
	 &NMI_Handler ,
	 &H_Fault_Handler ,
	 &MM_Fault_Handler ,
	 &Bus_Fault ,
	 &Usage_Fault_Handler 
};

void Reset_Handler(void)
{
	//Copy Data From Rom to Ram
	uint32_t Data_Size = (uint8_t*)&_E_Data - (uint8_t*)&_S_Data ; 
	uint8_t* P_src = (uint8_t*)&_E_Text ;
	uint8_t* P_dst = (uint8_t*)&_S_Data ;

	for(int i =0 ; i < Data_Size ; i++)
	{
		*((uint8_t*)P_dst++) = *((uint8_t*)P_src++) ;
	}

	// init the .bss with 0 

	uint32_t Bss_Size = (uint8_t*)&_E_Bss - (uint8_t*)&_S_Bss ;
	P_dst = (uint8_t*)&_S_Bss ;

	for(int i =0 ; i < Bss_Size ; i++)
	{
		*((uint8_t*)P_dst++) = (uint8_t)0 ;
	}

	// jump to main()
	main();
}