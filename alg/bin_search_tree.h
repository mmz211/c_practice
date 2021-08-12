
#ifndef __BIN_SEARCH_TREE_H__
#define __BIN_SEARCH_TREE_H____

#include<stdio.h>
#include<stdlib.h>


//#define elem_type   int

typedef int elem_type;

struct MY_BIN_TREE_NODE {
    
    struct MY_BIN_TREE_NODE * left_node;
    struct MY_BIN_TREE_NODE * right_node;
    elem_type data;
};

typedef struct MY_BIN_TREE_NODE BIN_TREE_NODE; 
typedef struct MY_BIN_TREE_NODE * BIN_TREE_PTR; 

BIN_TREE_NODE * insert_tree_node(BIN_TREE_NODE * root, elem_type key); 

BIN_TREE_NODE * remove_tree_node(BIN_TREE_NODE * root, elem_type key); 

void clear_tree(BIN_TREE_NODE * root); 

void in_order_traverse(BIN_TREE_NODE * root); 

void pre_order_traverse(BIN_TREE_NODE * root);

void pos_order_traverse(BIN_TREE_NODE * root);

void test_bin_tree_case();

#endif //__BIN_SEARCH_TREE_H__

