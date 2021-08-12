
#include "bin_search_tree.h"

static int __visit_tree_node(BIN_TREE_NODE * node) {

    // no good optioin or 
    printf("%c ", node->data);
}

static BIN_TREE_NODE * __predecessor(BIN_TREE_NODE * root) {

    BIN_TREE_NODE * temp = root->left_node;
    while (temp->right_node) {
    
        temp = temp->right_node;
    }

    return temp;
}

static BIN_TREE_NODE * __get_new_node(elem_type key) {

    BIN_TREE_NODE * new_node = (BIN_TREE_NODE *)malloc(sizeof(BIN_TREE_NODE));

    new_node->left_node = NULL;
    new_node->right_node = NULL;
    new_node->data = key;

    return new_node;
}

BIN_TREE_NODE * insert_tree_node(BIN_TREE_NODE * root, elem_type key) {

    if (root == NULL) {
    
        return __get_new_node(key);
    } else {
    
        if (root->data == key) {
            
        } else if (root->data > key) {
        
            root->left_node = insert_tree_node(root->left_node, key);
        } else {
        
            root->right_node = insert_tree_node(root->right_node, key);
        }
    }

    return root;
}

BIN_TREE_NODE * remove_tree_node(BIN_TREE_NODE * root, elem_type key) {

    if (root) {
    
        if (root->data > key) {
        
            root->left_node = remove_tree_node(root->left_node, key);
        } else if (root->data < key) {
        
            root->right_node = remove_tree_node(root->right_node, key);
        } else {
        
            // node without children
            if (root->left_node == NULL && root->right_node == NULL) {
            
                free(root);
                return NULL;
            }
            // node with 1 child
            else if (root->left_node == NULL && root->right_node == NULL) {
            
                BIN_TREE_NODE * temp = root->left_node? root->left_node: root->right_node;
                free(root);
                return temp;
            }
            // node with 2 children
            else {
                BIN_TREE_NODE * temp = __predecessor(root);
                root->data = temp->data;
                root->left_node = remove_tree_node(root->left_node, temp->data);
            
            }
        }
    }

    return root;
}

void clear_tree(BIN_TREE_NODE * root) {

    if (root == NULL) {

        return;
    }

    if (root->left_node) {
    
        clear_tree(root->left_node);
    }

    if (root->right_node) {
   
        clear_tree(root->right_node);
    }

    free(root);

}

void in_order_traverse(BIN_TREE_NODE * root) {

    if (root) {

        if (root->left_node) {
        
            in_order_traverse(root->left_node);
        }

        __visit_tree_node(root);

        if (root->right_node) {
        
            in_order_traverse(root->right_node);
        }
    }
}

void pre_order_traverse(BIN_TREE_NODE * root) {

    if (root) {
         
        __visit_tree_node(root);

        if (root->left_node) {
        
            pre_order_traverse(root->left_node);
        }

        if (root->right_node) {
        
            pre_order_traverse(root->right_node);
        }
    }
    
}

void pos_order_traverse(BIN_TREE_NODE * root) {

    if (root) {

        if (root->left_node) {
        
            pos_order_traverse(root->left_node);
        }

        if (root->right_node) {
        
            pos_order_traverse(root->right_node);
        }
         
        __visit_tree_node(root);
    }
    
}

void test_bin_tree_case() {

    BIN_TREE_NODE * root = NULL;
    char cmd_type = 0;
    char cmd_para = 0;

    while (scanf(" %c %c", &cmd_type, &cmd_para) == 2) {
    
        switch (cmd_type) {
        
            case '0':
                root = insert_tree_node(root, cmd_para);
                break;
        
            case '1':
                root = remove_tree_node(root, cmd_para);
                break;
        
            case '2':
                break;

            default:
                break;
        }

        in_order_traverse(root);
        printf("\r\n");
    }

    in_order_traverse(root);
        printf("\r\n");
    pre_order_traverse(root);
        printf("\r\n");
    pos_order_traverse(root);
        printf("\r\n");

    clear_tree(root);

}


