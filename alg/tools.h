
#ifndef __TOOLS_H__
#define __TOOLS_H__

//#define DEBUG_LOG

#ifdef DEBUG_LOG
    #define PR(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define PR(format, ...) 
#endif



#define COLOR(msg, code) \
    "\033[0;" #code "m"  \
    msg                  \
    "\033[0m\n" 

#define RED(msg)    COLOR(msg, 31)
#define GREEN(msg)  COLOR(msg, 32) 
#define YELLOW(msg) COLOR(msg, 33)
#define BLUE(msg)   COLOR(msg, 34)


extern void print_array(int * array, int size);


#endif //__TOOLS_H__

