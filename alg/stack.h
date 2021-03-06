

#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

#define MAX_STACK_SIZE  3//100

typedef int elem_type;

struct MY_STACK {

    elem_type * base;
    elem_type * top;
    int count;
};

typedef struct MY_STACK stack, *stack_ptr;

int init_stack(void);

int push(elem_type data);

int pop(elem_type * data);

int top(elem_type * data);

int stack_size(void);

int clear_stack(void);

int destroy_stack(void);

int traverse_stack(stack_ptr s_ptr);

int test_stack();

#endif //__STACK_H__

