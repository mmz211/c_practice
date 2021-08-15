
#include "stack.h"

stack_ptr s_ptr;

elem_type data_arr[MAX_STACK_SIZE];

int init_stack() {

    s_ptr = (stack_ptr) malloc(sizeof(stack));
    if (!s_ptr) {
    
        return CODE_API_RETURN_ERR;
    }

    s_ptr->count = 0;
    s_ptr->top = data_arr;
    s_ptr->base = data_arr;

    return CODE_OK;
}

int push(elem_type data) {

    if (s_ptr->count >= MAX_STACK_SIZE) {

        return CODE_STACK_FULL;
    }

    *s_ptr->top = data;
    s_ptr->top++;
    s_ptr->count++;

    return CODE_OK;
}

int top(elem_type * data) {

    if (s_ptr->count == 0) {
    //if (s_ptr->top == s_ptr->base) {
    
        return CODE_STACK_EMPTY;
    }

    *data = *(s_ptr->top-1);

    return CODE_OK;
}

int pop(elem_type * data) {

    if (s_ptr->count == 0) {
    //if (s_ptr->top == s_ptr->base) {
    
        return CODE_STACK_EMPTY;
    }

    s_ptr->top--;
    s_ptr->count--;
    *data = *s_ptr->top;

    return CODE_OK;
}

int stack_size(void) {

    return s_ptr->top - s_ptr->base;
}

int clear_stack() {

    s_ptr->top = s_ptr->base;
    s_ptr->count = 0;
}

int destroy_stack() {

    free(s_ptr);
    s_ptr = NULL;

    return CODE_OK;
}

#define OUTPUT_BUFF_SIZE 1024

int stack_to_string(stack_ptr s_ptr, char ** q_str) {

    int total_len = 0;
    int curr_len = 0;
    
    char * output_buff = (char *) malloc(sizeof(char) * OUTPUT_BUFF_SIZE);
    if (!output_buff) {
        return CODE_API_RETURN_ERR;
    }
    
    curr_len = sprintf(output_buff + total_len, "base addr %p\r\n", s_ptr->base); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "top addr %p\r\n", s_ptr->top); 
    total_len += curr_len;
    
    curr_len = sprintf(output_buff + total_len, "stack size %d\r\n", s_ptr->count); 
    total_len += curr_len;

    *q_str = output_buff;
    if (total_len > OUTPUT_BUFF_SIZE) {
        return CODE_BUFF_OVERFLOW; 
    } else {
        return CODE_OK;
    }
}

#define INC_STACK
int traverse_stack(stack_ptr s_ptr) {

    elem_type * curr_ptr = s_ptr->base;

    printf("$ ");
#ifdef INC_STACK    
    while (curr_ptr < s_ptr->top) {
#else
    while (curr_ptr > s_ptr->top) {
#endif
        printf("%d ", *curr_ptr);
        curr_ptr++;
    } 
    printf("\r\n");
}


int test_stack(void) {

    int ret = 0;

    ret = init_stack(); 
    if (ret) {
        print_code_msg(ret);
    }

    char * buff = NULL;

    char cmd_type = 0;
    elem_type cmd_para = 0;

    while (scanf(" %c %d", &cmd_type, &cmd_para) == 2) {

        printf("%c %d\r\n", cmd_type, cmd_para); 
    
        switch (cmd_type) {
        
            case '0':
                ret = push(cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                break;
        
            case '1':
                ret = pop(&cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                printf("pop %d\r\n", cmd_para);
                break;
        
            case '2':
                ret = top(&cmd_para);
                if (ret) {
                    print_code_msg(ret);
                    break;
                }
                printf("top %d\r\n", cmd_para);
                break;

            case '3':
                ret = stack_to_string(s_ptr, &buff);
                if (ret) {
                    print_code_msg(ret);
                }
                puts(buff);
                free(buff);
                break;

            default:
                break;
        }

        traverse_stack(s_ptr);
        
        printf("****\r\n");
    }

    ret = destroy_stack();
    if (ret) {
        print_code_msg(ret);
    }
}


