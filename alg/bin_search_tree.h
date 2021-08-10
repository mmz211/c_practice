

#include<stdio.h>
#include<stdlib.h>


//#define elem_type   int

typedef int elem_type;

struct MY_BIN_TREE_NODE {
    
    struct MY_BIN_TREE_NODE * left_node;
    struct MY_BIN_TREE_NODE * right_node;
    elem_type value;
};

typedef struct MY_BIN_TREE_NODE BIN_TREE_NODE; 

BIN_TREE_NODE * _predecessor(BIN_TREE_NODE * root); 

BIN_TREE_NODE * _get_new_node(elem_type key); 

BIN_TREE_NODE * insert_node(BIN_TREE_NODE * root, elem_type key); 

BIN_TREE_NODE * remove_node(BIN_TREE_NODE * root, elem_type key); 

void clear_tree(BIN_TREE_NODE * root); 

void inorder_tranverse(BIN_TREE_NODE * root); 

