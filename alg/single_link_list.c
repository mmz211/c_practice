#include <stdio.h>
#include <stdlib.h>


//#define DESCENDING

//#define DEBUG_LOG

#ifdef DEBUG_LOG
    #define PR(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define PR(format, ...) 
#endif

#define DATA_NUM 10

int data[DATA_NUM];
int next[DATA_NUM];

typedef int elem_type;

struct My_Node_T {

    struct My_Node_T * next;
    elem_type data;
};

typedef struct My_Node_T My_Node;


void print_array(int * array, int size) {


    for (int i = 0; i < size; i++) {

        printf("%d\t", array[i]);
    }

    printf("\r\n");
}

void print_list(My_Node * list) {

    My_Node * head = list;

    while (head){
        printf("%d\t", head->data); 
        head = head->next;
    }

    printf("\r\n"); 
}


My_Node * insert_in_order(My_Node * list, int value) {
    
    My_Node * curr = list;
    My_Node * prev = curr;
    
    My_Node * new_node = (My_Node *)malloc(sizeof(My_Node));
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

My_Node * insert_at_tail(My_Node * list, int value) {

    My_Node * head = list;
    My_Node * new_node = NULL;

    // if list is null
    if (head == NULL) {
        new_node = (My_Node *)malloc(sizeof(My_Node));

        new_node->data = value;
        new_node->next = NULL;

        list = new_node;

        return list;
    }

    while (head->next) {
        head = head->next;
    }

    new_node = (My_Node *)malloc(sizeof(My_Node));
    new_node->data = value;
    new_node->next = NULL;

    head->next = new_node;

    return list;
}

//#define DO_WHILE

My_Node * init_list_with_array(int arr[], int size) {

    My_Node * head = NULL;

    My_Node * curr = NULL;

    int i = 0;

#ifdef DO_WHILE

    do {

        My_Node * node = (My_Node *)malloc(sizeof(My_Node));
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

        My_Node * node = (My_Node *)malloc(sizeof(My_Node));
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

My_Node * init_with_insert_method(int arr[], int size) {

    My_Node * list = NULL;

    for (int i = 0; i < size; i++) {

        //list = insert_at_tail(list, arr[i]);
        list = insert_in_order(list, arr[i]);
    }

    return list;
}

void release_nodelist(My_Node * list) {

    My_Node * cur = list;
    My_Node * idx = list;

    while (cur) {

        idx = cur->next;
        PR("release %d\r\n", cur->data);
        free(cur);
        cur = idx; 
    }


}

void release_list(My_Node * list) {

    My_Node * pre;
    My_Node * head;

    while (head)  {
        head = (My_Node *) list;
        pre = (My_Node *) list;

        while(head->next) {

            pre = head;
            head = head->next;

        }
        PR("release %d", head->data);
        free(head);
        pre->next = NULL;
        head = (My_Node *)list;
    }
}

int test_case2() {

    int init_array_2[DATA_NUM] = {13, 0, 22, 3,4,45,6,7,8,9};

    print_array(init_array_2, DATA_NUM);

    My_Node * head;
    
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

    My_Node * head;

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

int main () {

    int ret = 0;
    
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
