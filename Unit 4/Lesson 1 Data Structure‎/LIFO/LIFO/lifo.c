/*
 ==========================================================================
 Name        : lifo.c
 Author      : Mohammed Hasan
 Created on	 : 9/29/2023
 Description : Lifo.c
 ==========================================================================
 */

#include "lifo.h"

lifo_status lifo_add_buf(lifo_buf_t* lifo_buf , element_type item)
{
	// check lifo is valid ?
	if(!lifo_buf->base || !lifo_buf->head)
		return lifo_null ;

	//check lifo is full ?
	if(lifo_buf->count == lifo_buf->length)
		return lifo_full ;

	//add item
	*(lifo_buf->head) = item ;
	lifo_buf->head++ ;
	lifo_buf->count++ ;

	return lifo_no_error ;

}

lifo_status lifo_get_buf(lifo_buf_t* lifo_buf , element_type* item)
{
	// check lifo is valid ?
	if(!lifo_buf->base || !lifo_buf->head)
		return lifo_null ;

	//check lifo is empty ?
	if(lifo_buf->count == 0)
		return lifo_empty ;

	// get item
	lifo_buf->head-- ;
	*item = *(lifo_buf->head) ;
	lifo_buf->count-- ;

	return lifo_no_error ;

}

lifo_status lifo_init(lifo_buf_t* lifo_buf , element_type* buf , element_type length)
{
	if(buf == NULL)
		return lifo_null ;

	lifo_buf->base = buf ;
	lifo_buf->head = buf ;
	lifo_buf->length = length ;
	lifo_buf->count = 0 ;

	return lifo_no_error ;

}
