
#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>


#define COLOR(msg, code) \
    "\033[0;" #code "m"  \
    msg                  \
    "\033[0m\n" 

#define RED(msg)    COLOR(msg, 31)
#define GREEN(msg)  COLOR(msg, 32) 
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg)   COLOR(msg, 34)


#define COLOR_HL(msg, code) "\033[1;" #code "m" msg "\033[0m\n"

#define RED_HL(msg)     COLOR_HL(msg, 31)
#define GREEN_HL(msg)   COLOR_HL(msg, 32)
#define YELLOW_HL(msg)  COLOR_HL(msg, 33)
#define BLUE_HL(msg)    COLOR_HL(msg, 34)


#define TYPE_OF_VAR(a) \
                _Generic((a),     \
                int : "%d",    \
                double : "%lf",    \
                float : "%f",    \
                char : "%c", \
                char *: "%s", \
                long int : "%ld"\
                )

#define DISP(a) {    char frm[1000];    sprintf(frm, "%s = %s\r\n", #a, TYPE_OF_VAR(a));    printf(frm, a);}

#define DEBUG_LOG

#ifdef DEBUG_LOG
    #define PR(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define PR(format, ...) 
#endif



enum RETURN_CODE {

    CODE_OK = 0,
    CODE_PARA_INCORRECT,
    CODE_API_RETURN_ERR,
    CODE_BUFF_OVERFLOW,

    // QUEUE
    CODE_QUEUE_FULL,
    CODE_QUEUE_EMPTY,

    // STACK
    CODE_STACK_FULL,
    CODE_STACK_EMPTY,

    // HEAP
    CODE_HEAP_FULL,
    CODE_HEAP_EMPTY,


    // TRIE
    CODE_TRIE_WORD_ALREADY_EXISTS,
    CODE_TRIE_INSERT_NEW_WORD,
    CODE_TRIE_NOT_FOUND,
    CODE_TRIE_FOUND,


    CODE_TOTAL_NUM,
};

void print_code_msg(int code_id);

extern void print_array(int * array, int size);


#endif //__TOOLS_H__


