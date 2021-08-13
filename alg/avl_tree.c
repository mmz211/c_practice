
#include "avl_tree.h"

static const AVL_TREE_NODE NIL = {NULL, NULL, 0, 0x23};
//there is a warning for this line
AVL_TREE_PTR NIL_PTR = &NIL;
/* 
avl_tree.c:7:24: warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
 AVL_TREE_PTR NIL_PTR = &NIL;
*/

//#define NIL_PTR (&NIL)

static AVL_TREE_NODE * __predecessor(AVL_TREE_NODE * root) {

    AVL_TREE_NODE * temp = root->left_node;
    while (temp->right_node != NIL_PTR) {
    
        temp = temp->right_node;
    }

    return temp;
}

#define OUTPUT_BUFF_SIZE    1024

static void output_node(AVL_TREE_NODE * node) {

    int curr_len = 0;
    int total_len = 0;
    char output_buff[OUTPUT_BUFF_SIZE];
    memset(output_buff, 0, OUTPUT_BUFF_SIZE);
    
    curr_len = sprintf(output_buff + total_len, "node addr: %p\r\n", node);
    total_len += curr_len;

    curr_len = sprintf(output_buff + total_len, "node left child addr: %p\r\n", node->left_node);
    total_len += curr_len;

    curr_len = sprintf(output_buff + total_len, "node right child addr: %p\r\n", node->right_node);
    total_len += curr_len;

    curr_len = sprintf(output_buff + total_len, "node height: %d\r\n", node->height);
    total_len += curr_len;

    curr_len = sprintf(output_buff + total_len, "node data: %c\r\n", node->data);
    total_len += curr_len;

    puts(output_buff);
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
    }
}

static elem_type __max(elem_type a, elem_type b) {

    return a>b ? a:b;
}

static void __update_height(AVL_TREE_NODE * root) {
    
    root->height = __max(root->left_node->height, root->right_node->height) + 1;
    return;
}

AVL_TREE_NODE * __left_rotate(AVL_TREE_NODE * root) {

    AVL_TREE_NODE * new_root = NIL_PTR;

    new_root = root->right_node;
    root->right_node = new_root->left_node;
    new_root->left_node = root;

    __update_height(root);
    __update_height(new_root);

    return new_root;
}

AVL_TREE_NODE * __right_rotate(AVL_TREE_NODE * root) {

    AVL_TREE_NODE * new_root = NIL_PTR;

    new_root = root->left_node;
    root->left_node = new_root->right_node;
    new_root->right_node = root;

    __update_height(root);
    __update_height(new_root);

    return new_root;
}

const char * type_str[5] = {"", "LL", "LR", "RL", "RR"};

AVL_TREE_NODE * __maintain_balance(AVL_TREE_NODE * root) {

    int type = 0;

    if (root == NIL_PTR) {

        return root;
    }

    if (abs(root->left_node->height - root->right_node->height) < 2) {
    
    } else {
        // L 
        if (root->left_node->height > root->right_node->height) {
        
            if (root->left_node->right_node->height > root->left_node->left_node->height) {
                //LR type
                type = 2;
                PR("%c: left rotate\r\n", root->left_node->data);
                root->left_node = __left_rotate(root->left_node);
            }

            //LL
            if (type == 0) type = 1;
            PR("%c: right rotate\r\n", root->data);
            root = __right_rotate(root);
        } else {
        // R 
            if (root->right_node->left_node->height > root->right_node->right_node->height) {
            
                //RL type
                type = 3;
                PR("%c: right rotate\r\n", root->right_node->data);
                root->right_node = __right_rotate(root->right_node); 
            }
            // RR
            if (type == 0) type = 4;
            PR("%c: left rotate\r\n", root->data);
            root = __left_rotate(root);
        }
        PR("maintain type = %s\r\n", type_str[type]);
    }

    return root;
}

AVL_TREE_NODE * insert_avl_tree_node(AVL_TREE_NODE * root, elem_type key) {

    if (root == NIL_PTR) {
    
        return __get_new_node(key);
    } else {
    
        if (root->data == key) {
            
            return root;
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

    if (root == NIL_PTR) {
    
        return root;
    }

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
        else if (root->left_node == NIL_PTR || root->right_node == NIL_PTR) {
        
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

    PR("clear %c\r\n", root->data);
    free(root);

}

static void in_order_traverse(AVL_TREE_NODE * root) {

    if (root == NIL_PTR) {

        return;
    }

    if (root->left_node != NIL_PTR) {
    
        in_order_traverse(root->left_node);
    }

    __visit_tree_node(root);

    if (root->right_node != NIL_PTR) {
    
        in_order_traverse(root->right_node);
    }
}

static void pre_order_traverse(AVL_TREE_NODE * root) {

    if (root == NIL_PTR) {
        return;
    }
         
    __visit_tree_node(root);

    if (root->left_node != NIL_PTR) {
    
        pre_order_traverse(root->left_node);
    }

    if (root->right_node != NIL_PTR) {
    
        pre_order_traverse(root->right_node);
    }
    
}

static void pos_order_traverse(AVL_TREE_NODE * root) {

    if (root == NIL_PTR) {

        return;
    }
    
    if (root->left_node != NIL_PTR) {
    
        pos_order_traverse(root->left_node);
    }

    if (root->right_node != NIL_PTR) {
    
        pos_order_traverse(root->right_node);
    }
     
    __visit_tree_node(root);
    
}

void test_avl_tree_case() {

    AVL_TREE_NODE * root = NIL_PTR;
    char cmd_type = 0;
    char cmd_para = 0;
    //NIL.data = 10;
    //NIL_PTR->data = 0x31;
    //output_node(NIL_PTR);

    while (scanf(" %c %c", &cmd_type, &cmd_para) == 2) {
    
        PR("========start=============\r\n");
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
        PR("========end=============\r\n");
        printf("****\r\n");
    }

    clear_avl_tree(root);

}

