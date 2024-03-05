
/*
 ==========================================================================
 Name        : Memory_Map.h
 Author      : Mohammed Hassan
 Created on	 : Feb 28, 2024
 Description : Atmega32
 ==========================================================================
 */


#ifndef MEMMAP_H_
#define MEMMAP_H_

#define SET_BIT(ADD , BIT)		ADD |=(1 << BIT)
#define RESET_BIT(ADD , BIT)	ADD &= ~(1 << BIT)
#define TOGGLE_BIT(ADD , BIT)	ADD ^= (1 << BIT)

#define PORTA	*((volatile unsigned char *)0x3B)
#define DDRA	*((volatile unsigned char *)0x3A)
#define PINA	*((volatile unsigned char *)0x39)




#endif /* MEMMAP_H_ */