
#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

//#define DESCENDING

#define DATA_NUM 10

int data[DATA_NUM];
int next[DATA_NUM];

typedef int elem_type;

struct MY_SLL_NODE {

    struct MY_SLL_NODE * next;
    elem_type data;
};

typedef struct MY_SLL_NODE SLL_NODE;


void print_array(int * array, int size); 

void print_list(SLL_NODE * list); 


SLL_NODE * insert_in_order(SLL_NODE * list, int value);

SLL_NODE * insert_at_tail(SLL_NODE * list, int value); 

SLL_NODE * init_list_with_array(int arr[], int size); 

SLL_NODE * init_with_insert_method(int arr[], int size); 

void release_nodelist(SLL_NODE * list); 

void release_list(SLL_NODE * list); 

int test_case2(); 

int test_case1(); 

int test_sigle_link_list(); 

