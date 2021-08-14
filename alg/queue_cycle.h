

#ifndef __QUEUE_CYCLE_H__
#define __QUEUE_CYCLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

#define MAX_QUEUE_SIZE  3//100

typedef int elem_type;

struct MY_CYCLE_QUEUE {
};

int front;
int rear;
int count;

int init_cycle_queue(void);

int en_cycle_queue(elem_type data);

int de_cycle_queue(elem_type * data);

int clear_cycle_queue(void);

int traverse_cycle_queue(void);

int cycle_queue_to_string(char ** q_str);

int test_cycle_queue(void);

#endif //__QUEUE_H__

