
#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>


#define DEBUG_LOG

#ifdef DEBUG_LOG
    #define PR(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define PR(format, ...) 
#endif



#define COLOR(msg, code) \
    "\033[0;" #code "m"  \
    msg                  \
    "\033[0m\n" 

#define RED(msg)    COLOR(msg, 31)
#define GREEN(msg)  COLOR(msg, 32) 
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg)   COLOR(msg, 34)

enum RETURN_CODE {

    CODE_OK = 0,
    CODE_PARA_INCORRECT,
    CODE_API_RETURN_ERR,
    CODE_BUFF_OVERFLOW,

    // QUEUE
    CODE_QUEUE_FULL,
    CODE_QUEUE_EMPTY,

    // STACK
    CODE_STACK_FULL,
    CODE_STACK_EMPTY,

    // HEAP
    CODE_HEAP_FULL,
    CODE_HEAP_EMPTY,


    CODE_TOTAL_NUM,
};

void print_code_msg(int code_id);

extern void print_array(int * array, int size);


#endif //__TOOLS_H__

