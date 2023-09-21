/*==========================================================================
 Name        : startup.c
 Author      : Mohammed Hassan
 Created on	 : 9/20/2023
 Description : Unit 3==>> Lesson 3 ==>> Lab(2)
 ==========================================================================*/
#include "Platform_Types.h"

extern int main(void);
extern uint32_t _Stack_Top ;
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



uint32_t vectors[] __attribute__ ((section(".vectors"))) = 
{
	(uint32_t) &_Stack_Top ,
	(uint32_t) &Reset_Handler ,
	(uint32_t) &NMI_Handler ,
	(uint32_t) &H_Fault_Handler ,
	(uint32_t) &MM_Fault_Handler ,
	(uint32_t) &Bus_Fault ,
	(uint32_t) &Usage_Fault_Handler 
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