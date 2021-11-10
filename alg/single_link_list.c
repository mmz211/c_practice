
#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "single_link_list.h"

void print_list(SLL_NODE * list) {

    SLL_NODE * head = list;

    while (head){
        printf("%d ", head->data); 
        head = head->next;
    }

    printf("\r\n"); 
}

// TODO: dummy header

int reverse_list(SLL_NODE ** result) {

    SLL_NODE * curr = *result;
    SLL_NODE * prev = curr;
    SLL_NODE * post = curr;

    while (post) {

        post = curr->next;
        if (prev == curr) {

            curr->next = NULL;
        } else {

            curr->next = prev;
        }
        prev = curr;
        curr = post;
    }

    // ERR: *result = curr;
    *result = prev;

    return CODE_OK;
}

int merge_ordered_list(SLL_NODE * first_list, SLL_NODE * second_list, SLL_NODE ** result) {

    SLL_NODE * first = first_list;
    SLL_NODE * second = second_list;
    SLL_NODE * prev = NULL;

    while (first && second) {

        if (first->data < second->data) {

            // ERR: if(first == first_list)
            if (!*result) {
                *result = first;
                prev = *result; 
            } else {
                prev->next = first;
                prev = prev->next; 
            }
            first = first->next;
        } else {

            // ERR: if(second == second_list)
            if (!*result) {
                *result = second;
                prev = *result; 
            } else {
                prev->next = second;
                prev = prev->next; 
            }
            second = second->next;
        }

    }

    if (first) {
        prev->next = first;
    } else {
        prev->next = second;
    }

    return CODE_OK;
}

int find_node_by_key(SLL_NODE * list, elem_type key, SLL_NODE ** result) {

    SLL_NODE * cur = list;

    while (cur) {

        if (cur->data == key) {

            break;
        }
        cur = cur->next;
    }

    *result = cur;

    if (cur) {

        return CODE_OK;
    } else {

        return CODE_NODE_NOT_IN_LIST;
    }
}

int remove_node(SLL_NODE ** list, SLL_NODE * target) {

    SLL_NODE * curr = *list;
    SLL_NODE * prev = curr;

    if (curr == target) {

        *list = curr->next;
        free(curr);

        return CODE_OK;
    } else {

        while (curr) {

            if (curr == target) {

                break;
            }

            prev = curr;
            curr = curr->next;
        }

        if (curr) {

            prev->next = curr->next;
            free(curr);

            return CODE_OK;
        }
        else {

            return CODE_NODE_NOT_IN_LIST;
        }
    }

}

int remove_node_by_prev(SLL_NODE ** list, SLL_NODE * prev, SLL_NODE * curr) {

    if (curr == *list) {

        *list = curr->next;
        free(curr);

        return CODE_OK;
    } else {

        prev->next = curr->next;
        free(curr);

        return CODE_OK;
    }
}

int remove_node_by_key(SLL_NODE ** list, elem_type key) {

    SLL_NODE * curr = *list;
    SLL_NODE * prev = curr;

    if (curr && curr->data == key) {

        // remove the first node
        *list = curr->next;
        free(curr);

        return CODE_OK;
    } else {

        // find node
        while(curr) {

            if (curr->data == key) {

                break;
            }
            prev = curr; 
            curr = curr->next;
        }

        // node is found
        if (curr) {
            // remove
            prev->next = curr->next;
            free(curr);

            return CODE_OK;
        } else {
            // node is not found, return header

            return CODE_NODE_NOT_IN_LIST;
        }
    }
}


int insert_in_order(SLL_NODE ** list, elem_type value) {

    SLL_NODE * curr = *list;
    SLL_NODE * prev = curr;

    SLL_NODE * new_node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
    new_node->data = value;
    new_node->next = NULL;

    if (!curr) {

        *list = new_node;
        return CODE_OK;
    }

    while (curr && value > curr->data) {

        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {

        // insert at tail
        new_node->next = curr;
        prev->next = new_node;

        return CODE_OK;
    }

    if (curr == *list) {

        // insert at head
        new_node->next = curr;
        *list = new_node;
    } else {

        // insert in the middle
        new_node->next = curr;
        prev->next = new_node;
    }

    return CODE_OK;

}

int insert_at_tail(SLL_NODE ** list, elem_type value) {

    SLL_NODE * head = *list;
    SLL_NODE * new_node = NULL;

    new_node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
    new_node->data = value;
    new_node->next = NULL;

    // if list is null
    if (head == NULL) {

        *list = new_node;

        return CODE_OK;
    }

    while (head->next) {
        head = head->next;
    }

    head->next = new_node;

    return CODE_OK;
}

//#define DO_WHILE

int get_element(elem_type * data) {

    // TODO general type
    int val = scanf("%d", data);
    getchar();

    if (val == 1) {
        return CODE_OK;
    } else {
        return CODE_INVALID_INPUT;
    }
}

int init_sll_at_tail (SLL_NODE ** list) {

    int ret = CODE_OK;
    elem_type data;

    while(1) {

        ret = get_element(&data);
        if (ret) {
            return ret;
        }

        ret = insert_at_tail(list, data);
        if (ret) {
            return ret;
        }
    }

    return ret;
}

int init_sll_in_order (SLL_NODE ** list) {

    int ret = CODE_OK;
    elem_type data;

    while(1) {

        ret = get_element(&data);
        if (ret) {
            return ret;
        }

        insert_in_order(list, data);
        if (ret) {
            return ret;
        }
    }

    return ret;
}

int init_sll(SLL_NODE ** list) {

    int ret = CODE_OK;
    SLL_NODE * curr = NULL;
    SLL_NODE * new_node = NULL;
    elem_type data;

    while(1) {

        ret = get_element(&data);
        if (ret) {
            return ret;
        }

        new_node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
        if (new_node == NULL) {

            return CODE_API_RETURN_ERR;
        }
        new_node->data = data;
        new_node->next = NULL;

        if (*list == NULL) {
            *list = new_node;
            // RM: curr = new_node;
        } else {
            curr->next = new_node;
        }

        curr = new_node;
    }

    return CODE_OK;
}

int deinit_sll(SLL_NODE * list) {

    SLL_NODE * cur = list;
    SLL_NODE * tmp = cur;

    while (cur) {

        tmp = cur->next;
        PR("release %d\r\n", cur->data);
        free(cur);
        cur = tmp; 
    }

}

int test_remove_node(void) {}

int test_find_node(void) {}

int test_init_with_insert_at_tail (void) {

    int ret = CODE_OK;

    SLL_NODE * head = NULL;

    printf("input numbers to init a list, others to exit\r\n");

    ret = init_sll_at_tail(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = reverse_list(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = deinit_sll(head);
    printf("ret = %d\r\n", ret);

    return ret;
}

int test_init_with_insert_in_order (void) {

    int ret = CODE_OK;

    SLL_NODE * head = NULL;

    printf("input numbers to init a list, others to exit\r\n");

    ret = init_sll_in_order(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = reverse_list(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = deinit_sll(head);
    printf("ret = %d\r\n", ret);

    return ret;
}

int test_init(void) {

    int ret = CODE_OK;

    SLL_NODE * head = NULL;

    printf("input numbers to init a list, others to exit\r\n");

    ret = init_sll(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = reverse_list(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = deinit_sll(head);
    printf("ret = %d\r\n", ret);

    return ret;
} 

int test_merge_list (void) {

    int ret = CODE_OK;
    elem_type data;

    SLL_NODE * first = NULL;
    SLL_NODE * second = NULL;
    SLL_NODE * head = NULL;

    printf("input numbers to init a list, others to exit\r\n");

    ret = init_sll_in_order(&first);
    printf("ret = %d\r\n", ret);
    print_list(first);

    ret = init_sll_in_order(&second);
    printf("ret = %d\r\n", ret);
    print_list(second);

    ret = merge_ordered_list(first, second, &head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = deinit_sll(head);
    printf("ret = %d\r\n", ret);

    return ret;

}

int test_sigle_link_list(void) {

    int ret = CODE_OK;
    elem_type data;

    ret = test_merge_list();
    return CODE_OK;

    SLL_NODE * head = NULL;
    SLL_NODE * target = NULL;

    printf("input numbers to init a list, others to exit\r\n");

    //ret = init_sll(&head);
    //ret = init_sll_in_order(&head);
    ret = init_sll_at_tail(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    ret = reverse_list(&head);
    printf("ret = %d\r\n", ret);

    print_list(head);

    printf("input numbers to search in a list, others to exit\r\n");
    while (1) {
    
        ret = get_element(&data);
        if (ret) {
            break;
        }

        ret = find_node_by_key(head, data, &target);
        if (ret) {
        
            printf("node not found, ret = %d\r\n", ret);
        } else {
        
            printf("node found at %p\r\n", target);
        }

        printf("remove node at %p\r\n", target);
        
        //ret = remove_node(&head, target);
        ret = remove_node_by_key(&head, data);
        if (ret) {
        
            printf("node not removed, ret = %d\r\n", ret);
        } else {
        
            printf("node at %p removed\r\n", target);
        }

    }

    print_list(head);

    ret = deinit_sll(head);
    printf("ret = %d\r\n", ret);

    return ret;

}



