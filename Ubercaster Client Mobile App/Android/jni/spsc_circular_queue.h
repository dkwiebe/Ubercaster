/*
 * spsc_circular_queue.h - header file for lock-free Single Producer Single
 *                         Consumer Circular Queue
 *
 * Author: Artem Bagautdinov, <artem.bagautdinov@gmail.com>
 * (C) 2013
 */

#ifndef __SPSC_CIRCULAR_QUEUE_H__
#define __SPSC_CIRCULAR_QUEUE_H__

#include <stdint.h>
#include <stdbool.h>

/* Single Producer Single Consumer (SPSC) circular queue */
typedef struct _SpscCircularQueue SpscCircularQueue;

/* Put data into the queue. On success, this function returns true.
   This function returns false if there's no free space to save data. */
bool spsc_circular_queue_push(SpscCircularQueue *queue, const uint8_t *data);

/* Get data from the queue. On success, this function retrieves data from the
   queue and returns true. This function returns false if there's no data
   to read. */
bool spsc_circular_queue_pop(SpscCircularQueue *queue, uint8_t *data);

/* This function allocates memory for SPSC circular queue and initializes all
   internal pointers. On success, this function returns the pointer on the
   allocated queue. On error, this function returns NULL. */
SpscCircularQueue* spsc_circular_queue_alloc(int elements_num, size_t element_size);

/* This function frees all memory, utilized by SPSC circular queue. There's one
   important notice - this function ashould be called when data producer and
   consumer are both completed. */
void spsc_circular_queue_free(SpscCircularQueue *queue);

/* This function returns size (in bytes) of the element in the SPSC circular
   queue. */
size_t spsc_circular_queue_element_size(const SpscCircularQueue *queue);

/* This function returns number of all elements in the SPSC circular queue. */
int spsc_circular_queue_elements_num(const SpscCircularQueue *queue);


#endif      /* __SPSC_CIRCULAR_QUEUE_H__ */
