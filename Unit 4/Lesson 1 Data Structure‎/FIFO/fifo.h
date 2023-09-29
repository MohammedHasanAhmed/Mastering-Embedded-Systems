/*
 ==========================================================================
 Name        : fifo.h
 Author      : Mohammed Hasan
 Created on	 : Sep 29, 2023
 Description : Fifo.h
 ==========================================================================
 */
#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>

#define element_type uint8_t

//=========>> FIFO Data types <<=========
typedef struct
{
	element_type *base;
	element_type *head;
	element_type *tail;
	unsigned int length;
	unsigned int count;

} fifo_buf_t;

//=========>> FIFO Stauts <<=========
typedef enum
{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
} fifo_status;

//=========>> FIFO APIS <<=========
fifo_status fifo_init(fifo_buf_t *fifo_buf, element_type *buf, unsigned int buffer_length);
fifo_status fifo_enqueue(fifo_buf_t* fifo_buf, element_type item);
fifo_status fifo_dequeue(fifo_buf_t* fifo_buf, element_type* item);
fifo_status fifo_is_full(fifo_buf_t* fifo_buf);
void fifo_print(fifo_buf_t *fifo_buf);

#endif
