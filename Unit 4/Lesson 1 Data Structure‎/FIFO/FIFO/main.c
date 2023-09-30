/*
 ==========================================================================
 Name        : main.c
 Author      : Mohammed Hasan
 Created on	 : 9/29/2023
 Description : main.c
 ==========================================================================
 */
#include "fifo.h"

#define buffer_length 5
element_type buffer[buffer_length];

int main()
{
	element_type i, temp = 0;
	fifo_buf_t uart_fifo;

	if (fifo_init(&uart_fifo, buffer, buffer_length) == fifo_no_error)
		printf("============== FIFO INIT IS DONE =============\n");

	for (i = 0; i < 7; i++)
	{
		printf("FIFO Enqueue (%x) \n", i);

		if (fifo_enqueue(&uart_fifo, i) == fifo_no_error)
			printf("\t FIFO Enqueue (%x) ===== Done ====\n", i);
		else
			printf("\t FIFO Enqueue (%x) ===== failed ====\n", i);
	}

	fifo_print(&uart_fifo);

	if (fifo_dequeue(&uart_fifo, &temp) == fifo_no_error)
		printf("\t FIFO Dequeue (%x) ===== Done ====\n", temp);

	if (fifo_dequeue(&uart_fifo, &temp) == fifo_no_error)
		printf("\t FIFO Dequeue (%x) ===== Done ====\n", temp);

	fifo_print(&uart_fifo);

	return 0;
}

