/*
 ==========================================================================
 Name        : lifo.h
 Author      : Mohammed Hasan
 Created on	 : 9/29/2023
 Description : Lifo.h
 ==========================================================================
 */

#include <stdio.h>
#include <stdint.h>

#ifndef LIFO_H_
#define LIFO_H_

#define element_type 	uint32_t
/*=========== type definitions ===========*/
typedef struct
{
	element_type* base ;
	element_type* head ;
	element_type length ;
	element_type count ;

}lifo_buf_t;

/*=========== Lifo Status ===========*/
typedef enum
{
	lifo_no_error , // 0
	lifo_full ,		// 1
	lifo_empty ,	// 2
	lifo_null		// 3
}lifo_status;

/*=============== APIs ===============*/
lifo_status lifo_add_buf(lifo_buf_t* lifo_buf , element_type item);
lifo_status lifo_get_buf(lifo_buf_t* lifo_buf , element_type* item);
lifo_status lifo_init(lifo_buf_t* lifo_buf , element_type* buf , element_type length);

#endif
