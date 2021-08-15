
#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

typedef int elem_type;

#define MAX_HEAP_NODE   5//100
#define LARGE_ROOT_HEAP 0

#define MENU "Menu\r\n"                 \
            "1: insert\r\n"             \
            "2: delete\r\n"             \
            "3: peek\r\n"               \
            "4: get heap size\r\n"      \
            "5: print heap array\r\n"   \
            "others to print menu\r\n"  \
            "Ctrl D to exit\r\n"            

int insert(elem_type data);

int delete(elem_type * data);

int peek(elem_type * data); 

int get_heap_size(void); 

int print_heap_arr(void); 

int print_menu(void);

int test_heap(void); 

#endif // __HEAP_H__

