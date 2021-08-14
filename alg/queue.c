

#include "queue.h"

elem_type data_arr[MAX_QUEUE_SIZE];

int init_queue() {

    q_ptr = (queue_ptr) malloc(sizeof(queue));
    if (!q_ptr) {
    
        return CODE_API_RETURN_ERR;
    }

    q_ptr->front = data_arr;
    q_ptr->rear = data_arr;
    q_ptr->base = data_arr;

    return CODE_OK;
}

int enqueue(elem_type data) {

    if ((q_ptr->rear - q_ptr->front) >= MAX_QUEUE_SIZE) {
        return CODE_QUEUE_FULL;
    }

    *q_ptr->rear = data;
    q_ptr->rear++;

    return CODE_OK;
}

int dequeue(elem_type * data) {

    if (q_ptr->rear == q_ptr->front) {
    
        return CODE_QUEUE_EMPTY;
    }

    *data = *q_ptr->front;
    q_ptr->front++;

    return CODE_OK;
}

int clear_queue() {

    free(q_ptr);
    q_ptr = NULL;

    return CODE_OK;
}

#define OUTPUT_BUFF_SIZE 1024

int to_string(queue_ptr q_ptr, char ** q_str) {

    int total_len = 0;
    int curr_len = 0;
    
    char * output_buff = (char *) malloc(sizeof(char) * OUTPUT_BUFF_SIZE);
    if (!output_buff) {
        return CODE_API_RETURN_ERR;
    }
    
    curr_len = sprintf(output_buff + total_len, "base addr %p\r\n", q_ptr->base); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "front addr %p\r\n", q_ptr->front); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "rear addr %p\r\n", q_ptr->rear); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "queue size %ld\r\n", (q_ptr->rear - q_ptr->front)); 
    total_len += curr_len;

    *q_str = output_buff;
    if (total_len > OUTPUT_BUFF_SIZE) {
        return CODE_BUFF_OVERFLOW; 
    } else {
        return CODE_OK;
    }
}

#define INC_STACK
int traverse_queue(queue_ptr q_ptr) {

    elem_type * curr_ptr = q_ptr->front;
#ifdef INC_STACK    
    while (curr_ptr < q_ptr->rear) {
#else
    while (curr_ptr > q_ptr->rear) {
#endif
        printf("%d ", *curr_ptr);
        curr_ptr++;
    } 
    printf("\r\n");
}


int test_queue(void) {

    int ret = 0;

    ret = init_queue(); 
    if (ret) {
        print_code_msg(ret);
    }

    char * buff = NULL;
/*
    ret = to_string(q_ptr, &buff);
    if (ret) {
        print_code_msg(ret);
    }
    puts(buff);
    free(buff);
*/
    char cmd_type = 0;
    elem_type cmd_para = 0;

    while (scanf(" %c %d", &cmd_type, &cmd_para) == 2) {
    
        PR("========start===========\r\n");
        switch (cmd_type) {
        
            case '0':
                ret = enqueue(cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                break;
        
            case '1':
                ret = dequeue(&cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                printf("dequeue %d\r\n", cmd_para);
                break;
        
            case '2':
                ret = to_string(q_ptr, &buff);
                if (ret) {
                    print_code_msg(ret);
                }
                puts(buff);
                free(buff);
                break;

            default:
                break;
        }

        traverse_queue(q_ptr);
        
        PR("========end=============\r\n");
        printf("****\r\n");
    }

    ret = clear_queue();
    if (ret) {
        print_code_msg(ret);
    }
}


