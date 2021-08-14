
#include "tools.h"

void print_code_msg(int code_id) {

    switch (code_id) {
    
        case CODE_PARA_INCORRECT:
            printf("parameter incorrect!\r\n");
            break;
    
        case CODE_API_RETURN_ERR:
            printf("errors ocurr while call api!\r\n");
            break;
    
        case CODE_BUFF_OVERFLOW:
            printf("buffer overflow!\r\n");
            break;
    
        case CODE_QUEUE_FULL: 
            printf("queue is full!\r\n");
            break;
    
        case CODE_QUEUE_EMPTY:
            printf("queue is empty!\r\n");
            break;

        default:
            printf("parameter incorrect!\r\n");
            break;
    }
}

