
#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

//#define DESCENDING

#define DATA_NUM 10

#define DUMMY_DATA 0xFF

int data[DATA_NUM];
int next[DATA_NUM];

typedef int elem_type;

//#pragma pack(1)

struct MY_SLL_NODE {

    struct MY_SLL_NODE * next;
    elem_type data;
};

typedef struct MY_SLL_NODE SLL_NODE;
typedef struct MY_SLL_NODE * SLL_PTR;


extern void print_array(int * array, int size); 

void print_list(SLL_NODE * list); 

SLL_NODE * merge_ordered_list(SLL_NODE * first_list, SLL_NODE * second_list);

SLL_NODE * find_node_by_key(SLL_NODE * list, elem_type key);

SLL_NODE * remove_node_with_prev(SLL_NODE * list, SLL_NODE * prev, SLL_NODE * curr);

SLL_NODE * remove_node(SLL_NODE * list, SLL_NODE * curr);

SLL_NODE * insert_in_order(SLL_NODE * list, elem_type value);

SLL_NODE * insert_at_tail(SLL_NODE * list, elem_type value); 

SLL_NODE * init_list_with_array(int arr[], int size); 

SLL_NODE * init_with_insert_method(int arr[], int size); 

SLL_NODE * init_with_user_input(void); 

void release_nodelist(SLL_NODE * list); 

void release_list(SLL_NODE * list); 

int test_case2(void); 

int test_case1(void); 

int test_sigle_link_list(void); 

