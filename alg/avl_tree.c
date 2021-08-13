
#include "avl_tree.h"

static const AVL_TREE_NODE NIL = {NULL, NULL, 0, 0xFFFF};
const AVL_TREE_PTR const NIL_PTR = &NIL;

static AVL_TREE_NODE * __predecessor(AVL_TREE_NODE * root) {

    AVL_TREE_NODE * temp = root->left_node;
    while (temp->right_node != NIL_PTR) {
    
        temp = temp->right_node;
    }

    return temp;
}

static AVL_TREE_NODE * __get_new_node(elem_type key) {

    AVL_TREE_NODE * new_node = (AVL_TREE_NODE *)malloc(sizeof(AVL_TREE_NODE));

    new_node->left_node = NIL_PTR;
    new_node->right_node = NIL_PTR;
    new_node->height = 1;
    new_node->data = key;

    return new_node;
}

static void __visit_tree_node(AVL_TREE_NODE * node) {

    if (node != NIL_PTR) {
    // no good optioin or 
        printf("%c[%d] |\t %c\t %c \r\n", node->data, node->height, node->left_node->data, node->right_node->data);
       // printf("%x[%d] \r\n", node->data, node->height);
    }
}

static elem_type __max(elem_type a, elem_type b) {

    return a>b ? a:b;
}

static void __update_height(AVL_TREE_NODE * root) {

   if (root->left_node == NIL_PTR && root->right_node == NIL_PTR) {
       
        return; 
   } else {
   
       if (root->left_node == NIL_PTR) {
       
           root->height = root->right_node->height + 1;
       } else if (root->right_node == NIL_PTR) {
       
           root->height = root->left_node->height + 1;
       } else {

           root->height = __max(root->left_node->height, root->right_node->height) + 1;
       }
   }
}

AVL_TREE_NODE * __left_rotate(AVL_TREE_NODE * root) {

    AVL_TREE_NODE * new_root = NIL_PTR;

    if (root != NIL_PTR) {
    
        new_root = root->right_node;
        root->right_node = new_root->left_node;
        new_root->left_node = root;

        __update_height(root);
        __update_height(new_root);
    }

    return new_root;
}

AVL_TREE_NODE * __right_rotate(AVL_TREE_NODE * root) {

    AVL_TREE_NODE * new_root = NIL_PTR;

    if (root != NIL_PTR) {
    
        new_root = root->left_node;
        root->left_node = new_root->right_node;
        new_root->right_node = root;

        __update_height(root);
        __update_height(new_root);
    }

    return new_root;
}

AVL_TREE_NODE * __maintain_balance(AVL_TREE_NODE * root) {

    int left_node_height = 0;
    int right_node_height = 0;

    if (root == NIL_PTR) {

        return root;
    }
       /* 
        if (root->left_node) {
        
            left_node_height = root->left_node->height;
        } else {
        
            left_node_height = 0;
        }

        if (root->right_node) {
        
            right_node_height = root->right_node->height;
        } else {
        
            right_node_height = 0;
        }
       
        if (abs(left_node_height - right_node_height) < 2) {
        
            return root;
        }
        */
    if (abs(root->left_node->height - root->right_node->height) < 2) {
    
    } else {
        // L 
        if (root->left_node->height > root->right_node->height) {
        
            if (root->left_node->right_node->height > root->left_node->left_node->height) {
                //LR type
                root->left_node = __left_rotate(root->left_node);
            }

            //LL
            root = __right_rotate(root);
        } else {
        // R 
            if (root->right_node->left_node->height > root->right_node->right_node->height) {
            
                //RL type
                root->right_node = __right_rotate(root->right_node); 
            }
            // RR
            root = __left_rotate(root);
        }
    }

    return root;
}

AVL_TREE_NODE * insert_avl_tree_node(AVL_TREE_NODE * root, elem_type key) {

    if (root == NIL_PTR) {
    
        return __get_new_node(key);
    } else {
    
        if (root->data == key) {
            
        } else if (root->data > key) {
        
            root->left_node = insert_avl_tree_node(root->left_node, key);
        } else {
        
            root->right_node = insert_avl_tree_node(root->right_node, key);
        }
    }

    __update_height(root);

    return __maintain_balance(root);
}

AVL_TREE_NODE * remove_avl_tree_node(AVL_TREE_NODE * root, elem_type key) {

    if (root != NIL_PTR) {
    
        if (root->data > key) {
        
            root->left_node = remove_avl_tree_node(root->left_node, key);
        } else if (root->data < key) {
        
            root->right_node = remove_avl_tree_node(root->right_node, key);
        } else {
        
            // node without children
            if (root->left_node == NIL_PTR && root->right_node == NIL_PTR) {
            
                free(root);
                return NIL_PTR;
            }
            // node with 1 child
            else if (root->left_node == NIL_PTR && root->right_node == NIL_PTR) {
            
                AVL_TREE_NODE * temp = root->left_node != NIL_PTR ? root->left_node: root->right_node;
                free(root);
                return temp;
            }
            // node with 2 children
            else {
                AVL_TREE_NODE * temp = __predecessor(root);
                root->data = temp->data;
                root->left_node = remove_avl_tree_node(root->left_node, temp->data);
            
            }
        }
    }

    __update_height(root);

    return __maintain_balance(root);
}

void clear_avl_tree(AVL_TREE_NODE * root) {

    if (root == NIL_PTR) {

        return;
    }

    if (root->left_node != NIL_PTR) {
    
        clear_avl_tree(root->left_node);
    }

    if (root->right_node != NIL_PTR) {
   
        clear_avl_tree(root->right_node);
    }

    free(root);

}

static void in_order_traverse(AVL_TREE_NODE * root) {

    if (root != NIL_PTR) {

        if (root->left_node != NIL_PTR) {
        
            in_order_traverse(root->left_node);
        }

        __visit_tree_node(root);

        if (root->right_node != NIL_PTR) {
        
            in_order_traverse(root->right_node);
        }
    }
}

static void pre_order_traverse(AVL_TREE_NODE * root) {

    if (root != NIL_PTR) {
         
        __visit_tree_node(root);

        if (root->left_node != NIL_PTR) {
        
            pre_order_traverse(root->left_node);
        }

        if (root->right_node != NIL_PTR) {
        
            pre_order_traverse(root->right_node);
        }
    }
    
}

static void pos_order_traverse(AVL_TREE_NODE * root) {

    if (root != NIL_PTR) {

        if (root->left_node != NIL_PTR) {
        
            pos_order_traverse(root->left_node);
        }

        if (root->right_node != NIL_PTR) {
        
            pos_order_traverse(root->right_node);
        }
         
        __visit_tree_node(root);
    }
    
}

void test_avl_tree_case() {

    AVL_TREE_NODE * root = NIL_PTR;
    char cmd_type = 0;
    char cmd_para = 0;
//    NIL.data = 10;

    while (scanf(" %c %c", &cmd_type, &cmd_para) == 2) {
    
        switch (cmd_type) {
        
            case '0':
                root = insert_avl_tree_node(root, cmd_para);
                break;
        
            case '1':
                root = remove_avl_tree_node(root, cmd_para);
                break;
        
            case '2':
                break;

            default:
                break;
        }

        pre_order_traverse(root);
        printf("\r\n");
    }

    in_order_traverse(root);
        printf("\r\n");
    pre_order_traverse(root);
        printf("\r\n");
    pos_order_traverse(root);
        printf("\r\n");

    clear_avl_tree(root);

}


