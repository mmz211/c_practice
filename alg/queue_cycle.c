

#include "queue_cycle.h"

elem_type data_arr[MAX_QUEUE_SIZE];

int init_cycle_queue(void) {

    count = 0;
    front = 0;
    rear = 0;

    return CODE_OK;
}

int en_cycle_queue(elem_type data) {

    if (count >= MAX_QUEUE_SIZE) {
        return CODE_QUEUE_FULL;
    }

    data_arr[rear] = data;
    rear = (rear+1)%MAX_QUEUE_SIZE;
    count++;

    return CODE_OK;
}

int de_cycle_queue(elem_type * data) {

    if (count == 0) {
    
        return CODE_QUEUE_EMPTY;
    }

    *data = data_arr[front];
    front = (front+1)%MAX_QUEUE_SIZE;
    count--;

    return CODE_OK;
}

int clear_cycle_queue(void) {

    memset(data_arr, 0 , MAX_QUEUE_SIZE);

    return CODE_OK;
}

#define OUTPUT_BUFF_SIZE 1024

int cycle_queue_to_string(char ** q_str) {

    int total_len = 0;
    int curr_len = 0;
    
    char * output_buff = (char *) malloc(sizeof(char) * OUTPUT_BUFF_SIZE);
    if (!output_buff) {
        return CODE_API_RETURN_ERR;
    }
    
    curr_len = sprintf(output_buff + total_len, "front %d\r\n", front); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "rear %d\r\n", rear); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "count %d\r\n", count); 
    total_len += curr_len;

    *q_str = output_buff;
    if (total_len > OUTPUT_BUFF_SIZE) {
        return CODE_BUFF_OVERFLOW; 
    } else {
        return CODE_OK;
    }
}

#define INC_STACK
int traverse_cycle_queue(void) {

    for (int i=0; i<MAX_QUEUE_SIZE; i++) {
        printf("%d ", data_arr[i]);
    }
    printf("\r\n");
}


int test_cycle_queue(void) {

    int ret = 0;

    ret = init_cycle_queue(); 
    if (ret) {
        print_code_msg(ret);
    }

    char * buff = NULL;

    char cmd_type = 0;
    elem_type cmd_para = 0;

    while (scanf(" %c %d", &cmd_type, &cmd_para) == 2) {
    
        switch (cmd_type) {
        
            case '0':
                ret = en_cycle_queue(cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                break;
        
            case '1':
                ret = de_cycle_queue(&cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                printf("dequeue %d\r\n", cmd_para);
                break;
        
            case '2':
                ret = cycle_queue_to_string(&buff);
                if (ret) {
                    print_code_msg(ret);
                }
                puts(buff);
                free(buff);
                break;

            default:
                break;
        }

        traverse_cycle_queue();
        
        ret = cycle_queue_to_string(&buff);
        if (ret) {
            print_code_msg(ret);
        }
        puts(buff);
        free(buff);

        printf("****\r\n");
    }

    ret = clear_cycle_queue();
    if (ret) {
        print_code_msg(ret);
    }
}


