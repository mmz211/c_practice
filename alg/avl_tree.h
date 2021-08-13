
#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

//#define elem_type   int

typedef int elem_type;

struct MY_AVL_TREE_NODE {
    
    struct MY_AVL_TREE_NODE * left_node;
    struct MY_AVL_TREE_NODE * right_node;
    int height;
    elem_type data;
};

typedef struct MY_AVL_TREE_NODE AVL_TREE_NODE; 
typedef struct MY_AVL_TREE_NODE * AVL_TREE_PTR; 

AVL_TREE_NODE * insert_avl_tree_node(AVL_TREE_NODE * root, elem_type key); 

AVL_TREE_NODE * remove_avl_tree_node(AVL_TREE_NODE * root, elem_type key); 

void clear_avl_tree(AVL_TREE_NODE * root); 

void test_avl_tree_case();

#endif // __AVL_TREE_H__


