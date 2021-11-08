

#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MAX_QUEUE_SIZE  3//100

typedef int elem_type;

struct MY_QUEUE {

    elem_type * base;
    elem_type * front;
    elem_type * rear;
};

typedef struct MY_QUEUE queue, *queue_ptr;

queue_ptr q_ptr;

int init_queue();

int enqueue(elem_type data);

int dequeue(elem_type * data);

int clear_queue();

int traverse_queue(queue_ptr q_ptr);

int test_queue();

#endif //__QUEUE_H__

