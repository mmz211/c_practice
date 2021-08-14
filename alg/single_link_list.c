
#include "single_link_list.h"

void print_list(SLL_NODE * list) {

    SLL_NODE * head = list;

    while (head){
        printf("%d\t", head->data); 
        head = head->next;
    }

    printf("\r\n"); 
}

//TODO

SLL_NODE * reverse_list(SLL_NODE * first_list, SLL_NODE * second_list) {

}

//TODO
SLL_NODE * merge_ordered_list(SLL_NODE * first_list, SLL_NODE * second_list) {

    SLL_NODE * result = NULL;
    SLL_NODE * curr = NULL;
    SLL_NODE * first = first_list;
    SLL_NODE * second = second_list;

    if (1) {
    
    }
    
    while (first && second) {
    
        if (first->data < second->data) {
        
           result = first;
           curr = first;
           first = first->next;
        } else {
        
            result = second;
            curr = second;
            second = second->next;
        }

    }
}

SLL_NODE * find_node_by_key(SLL_NODE * list, elem_type key) {

    SLL_NODE * curr = list;

    while (curr) {
    
        if (curr->data == key) {
        
            break;
        }
        curr = curr->next;
    }

/*
    for (curr = list; curr->data != key; curr=curr->next); 
    if (curr) {
    
        result = curr;
    }
    else {
    
        result = NULL;
    }
*/

    return curr;
}

SLL_NODE * remove_node(SLL_NODE * list, SLL_NODE * curr) {

    SLL_NODE * result;
    SLL_NODE * prev;
    SLL_NODE * temp;

    if (curr == list) {
    
        result = curr->next;
        free(curr);
    } else {

        result = list;
        temp = list->next;

        while (temp) {
        
            if (temp == curr) {
            
                break;
            }

            prev = curr;
            temp = curr->next;
        }

        if (temp) {
        
            prev->next = temp->next;
            free(temp);
        }
    }

    return result;

}

SLL_NODE * remove_node_with_prev(SLL_NODE * list, SLL_NODE * prev, SLL_NODE * curr) {

    SLL_NODE * result;

    if (curr == list) {
    
        result = curr->next;
        free(curr);
    } else {
    
        result = list;
        prev->next = curr->next;
        free(curr);
    }

    return result;
}

SLL_NODE * remove_node_by_key(SLL_NODE * list, elem_type key) {

    SLL_NODE * curr = list;
    SLL_NODE * prev = curr;

/*
    while (curr) {

        if (curr->data == key) {
        
            break;
        }
    
        prev = curr;
        curr = curr->next;
    } 

    if (curr) {

        prev->next = curr->next;
        free(curr);
    }
*/
    if (curr && curr->data == key) {
    
        // remove the first node
        list = curr->next;
        free(curr);
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
        }
        // node is not found, return header
    }

    return list;
}

SLL_NODE * insert_in_order(SLL_NODE * list, elem_type value) {

    SLL_NODE * curr = list;
    SLL_NODE * prev = curr;

    SLL_NODE * new_node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
    new_node->data = value;
    new_node->next = NULL;

    if (!curr) {

        list = new_node;
        return list;
    }

    /*
       while (curr) {

       if (curr->data > value) {

       break;
       }
       curr = curr->next;
       prev = curr;
       }

       do {

       if (curr->data > value) {

       break;
       }
       curr = curr->next;
       prev = curr;

       } while (curr->next);


       do {

       curr = curr->next;

       if (curr) {

       prev = curr;
       }

       if (value > curr->data) {

       } else {

       break;
       }

       } while (curr);

*/

    /*
     * works for larger -> smaller order
     *
     for (prev = curr; value < curr->data; curr = curr->next) {

     if (curr) {

     prev = curr;
     } else {

     break;
     }

     }

     if (curr == NULL) {

    // insert at tail
    new_node->next = curr;
    prev->next = new_node;

    return list;
    }

    if (curr == list) {

        // insert at head
        new_node->next = list;
        list = new_node;
        } else {

        new_node->next = curr;
        prev->next = new_node;
    }
    */

#ifdef DESCENDING
    while (curr && value < curr->data) {
#else
    while (curr && value > curr->data) {
#endif

        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {

        // insert at tail
        new_node->next = curr;
        prev->next = new_node;

        return list;
    }

    if (curr == list) {

        // insert at head
        new_node->next = curr;
        list = new_node;
    } else {

        new_node->next = curr;
        prev->next = new_node;
    }

    return list;
}

SLL_NODE * insert_at_tail(SLL_NODE * list, elem_type value) {

    SLL_NODE * head = list;
    SLL_NODE * new_node = NULL;

    // if list is null
    if (head == NULL) {
        new_node = (SLL_NODE *)malloc(sizeof(SLL_NODE));

        new_node->data = value;
        new_node->next = NULL;

        list = new_node;

        return list;
    }

    while (head->next) {
        head = head->next;
    }

    new_node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
    new_node->data = value;
    new_node->next = NULL;

    head->next = new_node;

    return list;
}

//#define DO_WHILE

SLL_NODE * init_list_with_array(int arr[], int size) {

    SLL_NODE * head = NULL;

    SLL_NODE * curr = NULL;

    int i = 0;

#ifdef DO_WHILE

    do {

        SLL_NODE * node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
        node->data = arr[i];
        node->next = NULL;

        if (!curr) {

            curr = node;
            head = curr;
        } else {

            curr->next = node;
            curr = curr->next;
        }

        i++;
    } while (i < size);


#else

    for (; i<size; i++) {

        SLL_NODE * node = (SLL_NODE *)malloc(sizeof(SLL_NODE));
        node->data = arr[i];
        node->next = NULL;

        if (!curr) {

            curr = node;
            head = curr;
        } else {

            curr->next = node;
            curr = curr->next;
        }
    } 

#endif
    return head;
}

SLL_NODE * init_with_insert_method(int arr[], int size) {

    SLL_NODE * list = NULL;

    for (int i = 0; i < size; i++) {

        //list = insert_at_tail(list, arr[i]);
        list = insert_in_order(list, arr[i]);
    }

    return list;
}

void release_node_list(SLL_NODE * list) {

    SLL_NODE * cur = list;
    SLL_NODE * idx = list;

    while (cur) {

        idx = cur->next;
        PR("release %d\r\n", cur->data);
        free(cur);
        cur = idx; 
    }


}

void release_list(SLL_NODE * list) {

    SLL_NODE * prev;
    SLL_NODE * head;

    while (head)  {
        head = (SLL_NODE *) list;
        prev = (SLL_NODE *) list;

        while(head->next) {

            prev = head;
            head = head->next;

        }
        PR("release %d", head->data);
        free(head);
        prev->next = NULL;
        head = (SLL_NODE *)list;
    }
}

int test_remove_node() {

    int init_array[DATA_NUM] = {0,13,22,3,4,45,6,7,8,9};

    print_array(init_array, DATA_NUM);

    SLL_NODE * head;

#ifdef INSERT_AT_TAIL
    head = init_list_with_array(init_array, DATA_NUM);
#else
    head = init_with_insert_method(init_array, DATA_NUM);
#endif

    print_list(head);

#ifdef INSERT_AT_TAIL
    head = insert_at_tail(head, 11);
#else
    head = insert_in_order(head, 11);
#endif

    print_list(head);

    head = remove_node_by_key(head, 45);

    print_list(head);

    head = remove_node_by_key(head, 0);

    print_list(head);

    head = remove_node_by_key(head, 77);

    print_list(head);

    release_node_list(head);

    head = NULL;

    print_list(head);

    return 0;
}

int test_case2() {

    int init_array_2[DATA_NUM] = {13, 0, 22, 3,4,45,6,7,8,9};

    print_array(init_array_2, DATA_NUM);

    SLL_NODE * head;

#ifdef INSERT_AT_TAIL
    head = init_list_with_array(init_array_2, DATA_NUM);
#else
    head = init_with_insert_method(init_array_2, DATA_NUM);
#endif

    print_list(head);

#ifdef INSERT_AT_TAIL 
    head = insert_at_tail(head, 11);
#else
    head = insert_in_order(head, 11);
#endif

    print_list(head);

    release_node_list(head);

    head = NULL;

    print_list(head);

    return 0;
}

int test_case1() {

    int init_array[DATA_NUM] = {0,13,22,3,4,45,6,7,8,9};

    print_array(init_array, DATA_NUM);

    SLL_NODE * head;

#ifdef INSERT_AT_TAIL
    head = init_list_with_array(init_array, DATA_NUM);
#else
    head = init_with_insert_method(init_array, DATA_NUM);
#endif

    print_list(head);

#ifdef INSERT_AT_TAIL
    head = insert_at_tail(head, 11);
#else
    head = insert_in_order(head, 11);
#endif

    print_list(head);

    release_node_list(head);

    head = NULL;

    print_list(head);

    return 0;
}

int init_array[DATA_NUM] = {0,13,22,3,4,45,6,7,8,9};
SLL_NODE * head;

int test_find_node() {

    SLL_NODE * node;

    print_array(init_array, DATA_NUM);

#ifdef INSERT_AT_TAIL
    head = init_list_with_array(init_array, DATA_NUM);
#else
    head = init_with_insert_method(init_array, DATA_NUM);
#endif

    print_list(head);

#ifdef INSERT_AT_TAIL
    head = insert_at_tail(head, 11);
#else
    head = insert_in_order(head, 11);
#endif

    print_list(head);

    node = find_node_by_key(head, 11);
    if (node) {
    
        printf("node found at %p\r\n", node);
    } else {
    
        printf("node not found\r\n");
    }

    node = find_node_by_key(head, 0);
    if (node) {
    
        printf("node found at %p\r\n", node);
    } else {
    
        printf("node not found\r\n");
    }

    node = find_node_by_key(head, 45);
    if (node) {
    
        printf("node found at %p\r\n", node);
    } else {
    
        printf("node not found\r\n");
    }

    node = find_node_by_key(head, 35);
    if (node) {
    
        printf("node found at %p\r\n", node);
    } else {
    
        printf("node not found\r\n");
    }

    release_node_list(head);

    head = NULL;

    print_list(head);

    return 0;
}

int test_sigle_link_list() {

    int ret = 0;

    printf("========\r\n");
    ret = test_case1();

    printf("========\r\n");
    ret = test_case2();

    printf("========\r\n");
    ret = test_remove_node();

    printf("========\r\n");
    ret = test_find_node();

    printf("sizeof struct %ld \r\n", sizeof(SLL_NODE));
    printf("sizeof int %ld \r\n", sizeof(int));

    printf("sizeof struct ptr %ld \r\n", sizeof(SLL_PTR));
    printf("sizeof int *%ld \r\n", sizeof(int *));
    
    /*
     * ## & #
   for (int i=0; i<2; i++) {
       ret = test_case##i();
       if (ret) {

       printf("Test case" #i "passed!\r\n");
       } else {

       printf("Test case" #i "failed!\r\n");
       }

   }
   */


    return 0;
}
