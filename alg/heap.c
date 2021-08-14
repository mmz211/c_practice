

#include <stdio.h>

#define HEAP_MAX_NODE   100

#define HEAP_IS_NULL    -1
#define HEAP_IS_FULL    -2

#define ROOT_LARGE_HEAP 0

// root is 0
int heap_arr[HEAP_MAX_NODE];
int cnt;

int get_arr_length() {

    return cnt;

}

int heap_is_null() {
    
    return get_arr_length() <= 0;
}

int heap_is_full() {
    
    return get_arr_length() >= HEAP_MAX_NODE;
}


int insert(int val) {

    int idx = 0;
    int parent_idx = 0;
    int temp = 0;

    if (heap_is_full()) {
        return HEAP_IS_FULL; 
    }

    heap_arr[cnt] = val;
    cnt++;

    idx = get_arr_length() - 1;

    while (idx) {

        parent_idx = (idx-1)/2;

#if ROOT_LARGE_HEAP
        if (heap_arr[idx] > heap_arr[parent_idx]) {
#else
        if (heap_arr[idx] < heap_arr[parent_idx]) {
#endif
            
            temp = heap_arr[idx];
            heap_arr[idx] = heap_arr[parent_idx];
            heap_arr[parent_idx] = temp;
        }

        idx = parent_idx;
    }

        return 0;
}


int delete() {

    int idx = 0;
    int child_idx = 0;
    int temp = 0;

    if (heap_is_null()) {

        return HEAP_IS_NULL;
    }

    heap_arr[0] = heap_arr[get_arr_length() - 1];
    cnt--;

    while (1) {

        // left child id
        child_idx = idx * 2 + 1;

        if (child_idx > get_arr_length()) {
            break;
        }

#if ROOT_LARGE_HEAP
        // if right child exists and larger than parent
        if (child_idx + 1 <= get_arr_length() - 1 && heap_arr[child_idx + 1] > heap_arr[child_idx]) {
#else
        // if right child exists and larger than parent
        if (child_idx + 1 <= get_arr_length() - 1 && heap_arr[child_idx + 1] < heap_arr[child_idx]) {
#endif
            // target child will be right child
            child_idx += 1;
        }

#if ROOT_LARGE_HEAP
        if (heap_arr[idx] < heap_arr[child_idx]) {
#else
        if (heap_arr[idx] > heap_arr[child_idx]) {
#endif
            temp = heap_arr[idx];
            heap_arr[idx] = heap_arr[child_idx];
            heap_arr[child_idx] = temp;
        }

        idx = child_idx;    
    }

        return 0;
}

int peek() {

    if (heap_is_null()) {
        return HEAP_IS_NULL;
    }
    else {
        return heap_arr[0];
    }
}

int print_arr() {

    int arr_len = get_arr_length();
    printf("array: \t");

    for (int i=0; i<arr_len; i++) {
        printf("%d\t", heap_arr[i]);
    }
    printf("\r\n");
}

#define MENU "\r\n"         \
            "1: insert\r\n"   \
            "2: delete\r\n"                \
            "3: peek\r\n"                \
            "4: get arry length\r\n"    \
            "5: print array\r\n"        \
            "others to exit\r\n"            

int print_menu() {

    printf("MENU\r\n");
}

int test_heap() {

    int op;
    int val;

    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    
    printf(MENU);

    while (1) {

        int ret = scanf("%d", &op);
        if (ret == 0) {
            printf("input incorrect\r\n"); 
//            fflush(stdin);
            continue;
        }

        switch (op) {
            case 1: 
                ret = scanf("%d", &val);
                if (ret == 0) {
                    printf("input incorrect\r\n"); 
                    continue;
                }
                insert(val);
                print_arr();

                break;
            case 2: 
                printf("delete\r\n");
                delete();
                print_arr();
                break;
            case 3: 
                printf("peek %d\r\n", peek());

                break;
            case 4: 
                printf("get_arr_length %d\r\n", get_arr_length());
                break;
            case 5: 

                print_arr();
                break;
            default: 
                return 1;

        }

    }

    return 0;
}

