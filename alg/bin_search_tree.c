
#include "bin_search_tree.h"

BIN_TREE_NODE * _predecessor(BIN_TREE_NODE * root) {

    BIN_TREE_NODE * temp = root->left_node;
    while (temp->right_node) {
    
        temp = temp->right_node;
    }

    return temp;
}

BIN_TREE_NODE * _get_new_node(elem_type key) {

    BIN_TREE_NODE * new_node = (BIN_TREE_NODE *)malloc(sizeof(BIN_TREE_NODE));

    new_node->left_node = NULL;
    new_node->right_node = NULL;
    new_node->value = key;

    return new_node;
}

BIN_TREE_NODE * insert_node(BIN_TREE_NODE * root, elem_type key) {

    if (root == NULL) {
    
        return _get_new_node(key);
    } else {
    
        if (root->value > key) {
        
            insert_node(root->left_node, key);

        } else {
        
            insert_node(root->right_node, key);
        }
    }

}

BIN_TREE_NODE * remove_node(BIN_TREE_NODE * root, elem_type key) {

    if (root == NULL) {
    
        return root;
    } else {
    
        if (root->value > key) {
        
            remove_node(root->left_node, key);
        } else if (root->value < key) {
        
            remove_node(root->right_node, key);
        } else {
        
            if (root->left_node == NULL && root->right_node == NULL) {
            
                free(root);
                return NULL;
            }
            else if (root->left_node == NULL && root->right_node == NULL) {
            
                BIN_TREE_NODE * temp = root->left_node? root->left_node: root->right_node;
                free(root);
                return temp;
            }
            else {
                BIN_TREE_NODE * temp = _predecessor(root);
                root->value = temp->value;
                root->left_node = remove_node(root->left_node, temp->value);
            
            }
        }
    }


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

void inorder_tranverse(BIN_TREE_NODE * root) {

    if (root == NULL) {
    
        return;
    }

    if (root->left_node) {
    
        inorder_tranverse(root->left_node);
    }

    // no good optioin or 
    printf("%d ", root->value);

    if (root->right_node) {
    
        inorder_tranverse(root->right_node);
    }
}

