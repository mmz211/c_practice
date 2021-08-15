

#include "heap.h" 

elem_type heap_arr[MAX_HEAP_NODE];

int count;

int get_heap_size() {

    return count;
}

int insert(elem_type val) {

    int idx = 0;
    int parent_idx = 0;
    int temp = 0;

    if (count >= MAX_HEAP_NODE) {
        return CODE_HEAP_FULL;
    }

    heap_arr[count] = val;
    count++;

    idx = get_heap_size() - 1;

    while (idx) {

        parent_idx = (idx-1)/2;

#if LARGE_ROOT_HEAP
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

    return CODE_OK;
}

int delete(elem_type * data) {

    int idx = 0;
    int child_idx = 0;
    int temp = 0;

    if (count <= 0) {

        return CODE_HEAP_EMPTY;
    }

    *data = heap_arr[0];
    heap_arr[0] = heap_arr[get_heap_size() - 1];
    count--;

    while (1) {

        // left child id
        child_idx = idx * 2 + 1;

        if (child_idx > get_heap_size()) {
            // no child
            break;
        }

#if LARGE_ROOT_HEAP
        // if right child exists and larger than parent
        if (child_idx + 1 <= get_heap_size() - 1 
                && heap_arr[child_idx + 1] > heap_arr[child_idx]) {
#else
        // if right child exists and larger than parent
        if (child_idx + 1 <= get_heap_size() - 1 
                && heap_arr[child_idx + 1] < heap_arr[child_idx]) {
#endif
            // target child will be right child
            child_idx += 1;
        }

#if LARGE_ROOT_HEAP
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

    return CODE_OK;
}

int peek(elem_type * data) {

    if (count <= 0) {
        return CODE_HEAP_EMPTY;
    }

    *data = heap_arr[0];

    return CODE_OK;
}

int print_heap_arr(void) {

    int arr_len = get_heap_size();
    printf("$ ");

    for (int i=0; i<arr_len; i++) {
        printf("%d ", heap_arr[i]);
    }
    printf("\r\n");
}

int print_menu() {

    printf(MENU);
}

int test_heap() {

    int ret = 0;

    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
//  fflush(stdin);

    char * buff = NULL;

    char cmd_type = 0;
    elem_type cmd_para = 0;

    while (scanf(" %c %d", &cmd_type, &cmd_para) == 2) {

        printf(GREEN("%c %d\r\n"), cmd_type, cmd_para); 

        switch (cmd_type) {

            case '1': 

                ret = insert(cmd_para);
                if (ret) {
                    print_code_msg(ret);
                }
                break;
            case '2': 

                ret = delete(&cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                printf("delete %d\r\n", cmd_para);
                break;
            case '3': 

                ret = peek(&cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                printf("peek %d\r\n", cmd_para);
                break;
            case '4': 
                
                printf("get_heap_size %d\r\n", get_heap_size());
                break;
            case '5': 

                print_heap_arr();
                break;
                
            default: 

                print_menu();
                break;

        }

        print_heap_arr();
    }

    return 0;
}

