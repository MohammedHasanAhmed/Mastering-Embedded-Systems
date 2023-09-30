/*
 ==========================================================================
 Name        : fifo.c
 Author      : Mohammed Hasan
 Created on  : 9/29/2023
 Description : Fifo.c
 ==========================================================================
 */
#include "fifo.h"

fifo_status fifo_init(fifo_buf_t *fifo_buf, element_type *buf, unsigned int buffer_length)
{
    if (buf == NULL)
        return fifo_null;

    fifo_buf->base = buf;
    fifo_buf->head = buf;
    fifo_buf->tail = buf;
    fifo_buf->length = buffer_length;
    fifo_buf->count = 0;

    return fifo_no_error;
}

fifo_status fifo_enqueue(fifo_buf_t *fifo_buf, element_type item)
{
    // fifo_buffer is valid ?
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return fifo_null;

    // fifo_buffer is full ?
    if (fifo_is_full(fifo_buf) == fifo_full)
        return fifo_full;

    // enqueue
    *(fifo_buf->head) = item;
    fifo_buf->count++;

    // circler fifo
    if (fifo_buf->head == (fifo_buf->base + (fifo_buf->length * sizeof(element_type))))
        fifo_buf->head = fifo_buf->base;
    else
        fifo_buf->head++;

    return fifo_no_error;
}
fifo_status fifo_dequeue(fifo_buf_t *fifo_buf, element_type* item)
{
    // fifo_buffer is valid ?
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return fifo_null;

    // fifo_buffer is empty ?
    if (fifo_buf->count == 0)
        return fifo_empty;

    // dequeue
    *item = *(fifo_buf->tail);
    fifo_buf->count--;

    // circler fifo
    if (fifo_buf->tail == (fifo_buf->base + (fifo_buf->length * sizeof(element_type))))
        fifo_buf->tail = fifo_buf->base;
    else
        fifo_buf->tail++;

    return fifo_no_error;
}
fifo_status fifo_is_full(fifo_buf_t *fifo_buf)
{
    // fifo_buffer is valid ?
    if (!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return fifo_null;
    // fifo_buffer is full ?
    if (fifo_buf->count == fifo_buf->length)
        return fifo_full;
    else
        return fifo_no_error;
}
void fifo_print(fifo_buf_t *fifo_buf)
{
    element_type *temp;
    int i;

    if (fifo_buf->count == 0)
        printf("FIFO is empty.\n");
    else
    {
        temp = fifo_buf->tail;
        printf("\n============fifo_print========\n");
        for (i = 0; i < fifo_buf->count; i++)
        {
            printf("\t %X \n", *temp);
            temp++;
        }
    }
    printf("========================================\n");
}
