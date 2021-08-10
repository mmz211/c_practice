
#include "single_link_list.h"

void print_list(SLL_NODE * list) {

    SLL_NODE * head = list;

    while (head){
        printf("%d\t", head->data); 
        head = head->next;
    }

    printf("\r\n"); 
}


SLL_NODE * insert_in_order(SLL_NODE * list, int value) {

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

SLL_NODE * insert_at_tail(SLL_NODE * list, int value) {

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

void release_nodelist(SLL_NODE * list) {

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

    SLL_NODE * pre;
    SLL_NODE * head;

    while (head)  {
        head = (SLL_NODE *) list;
        pre = (SLL_NODE *) list;

        while(head->next) {

            pre = head;
            head = head->next;

        }
        PR("release %d", head->data);
        free(head);
        pre->next = NULL;
        head = (SLL_NODE *)list;
    }
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
    insert_at_tail(head, 11);
#else
    insert_in_order(head, 11);
#endif

    print_list(head);

    release_nodelist(head);

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
    insert_at_tail(head, 11);
#else
    insert_in_order(head, 11);
#endif

    print_list(head);

    release_nodelist(head);

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
    /*
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
